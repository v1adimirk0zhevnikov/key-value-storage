#ifndef SET_HANDLER_CLASS_HPP
#define SET_HANDLER_CLASS_HPP
#include "ICommandHandler.hpp"
#include "Command.hpp"

class SetHandler final : public ICommandHandler {
private:
	static constexpr CommandName m_command_name = CommandName::SET;
public:
	CommandName getCommandName() const override;
	std::string executeCommand(const Command& command, IStorage& storage) override;
};


#endif
