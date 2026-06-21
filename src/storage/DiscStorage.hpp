#ifndef DISC_STORAGE_CLASS_HPP
#define DISC_STORAGE_CLASS_HPP
#include "IStorage.hpp"
#include <filesystem>


class DiscStorage final : public IStorage {
private:
	// const std::filesystem::path& m_directory_path 
	std::filesystem::path m_directory_path;

	[[nodiscard]] std::filesystem::path makeFilePath(const Key& key);
	void ensureDirectoryExists() const;
public:
	explicit DiscStorage(const std::filesystem::path& directory_path);
	~DiscStorage() override = default;

	DiscStorage(const DiscStorage& other) = delete;
	DiscStorage& operator=(const DiscStorage&) = delete;

	DiscStorage(DiscStorage&&) = default;
	DiscStorage& operator=(DiscStorage&&) = default; 

	void set(const Key& key, const Value& value) override;
	[[nodiscard]] std::optional<Value> get(const Key& key) override;
	void del(const Key& key) override;
};

#endif
