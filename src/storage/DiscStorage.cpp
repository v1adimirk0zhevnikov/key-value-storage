#include "DiscStorage.hpp"
#include "StorageException.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

DiscStorage::DiscStorage(const std::filesystem::path& directory_path)
    : m_directory_path(directory_path) {
    ensureDirectoryExists();
}

void DiscStorage::ensureDirectoryExists() const {
    if (!std::filesystem::exists(m_directory_path)) {
        if (!std::filesystem::create_directories(m_directory_path)) {
            throw StorageException("Failed to create directory");
        }
    }
}


std::filesystem::path DiscStorage::makeFilePath(const Key& key) {
    std::string key_s = std::string(key.key());
    const std::string invalid_chars = "<>:\"/\\|?*!";
    
    std::replace_if(key_s.begin(), key_s.end(),
        [&invalid_chars](char c) {
        return invalid_chars.find(c) != std::string::npos;
        },
        '_');
    
    return m_directory_path / std::filesystem::path(key_s + ".txt");
}

void DiscStorage::set(const Key& key, const Value& value) {


	std::cout << "Try key " << key.key() << std::endl;
    const auto file_path = makeFilePath(key);
    
    std::ofstream file(file_path, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        throw StorageException("Cannot open file for writing");
    }
    
    file.write(value.value().data(), value.value().size());
    if (!file.good()) {
        throw StorageException("Failed to write value to file");
    }
}

std::optional<Value> DiscStorage::get(const Key& key) {
    auto file_path = makeFilePath(key);
    
    if (!std::filesystem::exists(file_path)) {
        return std::nullopt;
    }
    
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw StorageException("Cannot open file for reading");
    }
    
    const auto file_size = static_cast<size_t>(file.tellg());
    file.seekg(0, std::ios::beg);

    std::string buffer(file_size, '\0');
    file.read(buffer.data(), file_size);
    
    if (!file.good() && !file.eof()) {
        throw StorageException("Failed to read value from file");
    }
    
    return Value(buffer);
}

void DiscStorage::del(const Key& key) {
    auto file_path = makeFilePath(key);
    
    if (std::filesystem::exists(file_path)) {
        if (!std::filesystem::remove(file_path)) {
            throw StorageException("Failed to delete file");
        }
    }
}
