#ifndef MEMORY_STORAGE_CLASS_HPP
#define MEMORY_STORAGE_CLASS_HPP
#include "IStorage.hpp"
#include <unordered_map>
#include <optional>

class MemoryStorage final : public IStorage {
private:
	std::unordered_map<Key, Value, KeyHash> m_storage;
public:
	MemoryStorage() = default;
	~MemoryStorage() override = default;

	void del(const Key& key) override;
	void set(const Key& key, const Value& value) override;
	[[nodiscard]] std::optional<Value> get(const Key& key) override;
};


#endif
