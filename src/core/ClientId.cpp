#include "ClientId.hpp"

ClientId::ClientId(uint64_t id) : m_id(id) {}

bool ClientId::operator==(const ClientId& other) const {
	return m_id == other.m_id;
}

uint64_t ClientId::clientId() const {
	return m_id;
}
