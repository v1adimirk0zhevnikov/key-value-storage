#ifndef DISC_STORAGE_CLASS_HPP
#define DISC_STORAGE_CLASS_HPP
#include "IStorage.hpp"
#include <filesystem>


class DiscStorage final : public IStorage {
private:
	const std::string& m_directory_path;
public:
	DiscStorage();
	~DiscStorage() override = default;

	void set(const Key& key, const Value& value) override;
	[[nodiscard]] std::optional<Value> get(const Key& key) override;
	void del(const Key& key) override;
};

#endif
