#ifndef DEL_HANDLER_CLASS_HPP
#define DEL_HANDLER_CLASS_HPP
#include "ICommandHandler.hpp"

class DelHandler final : public ICommandHandler {
private:
	static constexpr CommandName m_command_name = CommandName::DEL;
public:
	~DelHandler() override = default;
	CommandName getCommandName() const override;
	std::string executeCommand(const Command& cotrmmand, IStorage& storage) override;	
};


#endif
