#ifndef INTERFACE_STORAGE_CLASS_HPP
#define INTERFACE_STORAGE_CLASS_HPP
#include "Key.hpp"
#include "Value.hpp"
#include <optional>


class IStorage {
public:
	virtual ~IStorage() = default;

	virtual void set(const Key& key, const Value& value) = 0;	
	[[nodiscard]] virtual std::optional<Value> get(const Key& key) = 0;
	virtual void del(const Key& key) = 0;
};


#endif
