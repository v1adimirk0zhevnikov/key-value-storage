#include "MemoryStorage.hpp"
#include "StorageException.hpp"

void MemoryStorage::set(const Key& key, const Value& value) {
	m_storage.insert_or_assign(key, value);
}

void MemoryStorage::del(const Key& key) {
	if (m_storage.find(key) != m_storage.end()) {
		m_storage.erase(key);
	}
	throw StorageException("No key in storage");
}

std::optional<Value> MemoryStorage::get(const Key& key) {
	auto it = m_storage.find(key);
	if (it != m_storage.end()) {
		return it->second;
	}
	return std::nullopt;
}
