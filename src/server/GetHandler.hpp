#ifndef GET_HANDLET_CLASS_HPP
#define GET_HANDLET_CLASS_HPP
#include "ICommandHandler.hpp"


class GetHandler final : public ICommandHandler {
private:
	static constexpr CommandName m_command_name = CommandName::GET;
public:
	GetHandler() = default;
	~GetHandler() override = default;

	CommandName getCommandName() const override;
	std::string executeCommand(const Command& command, IStorage& storage) override;
};

#endif

