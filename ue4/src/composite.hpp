#pragma once

#include <vector>
#include <memory>

class CommandComponent {

public:

	virtual void exec() = 0;
	virtual void add(std::unique_ptr<CommandComponent> cmp) = 0;
	virtual void remove(std::unique_ptr<CommandComponent> cmp) = 0;
};

class CommandComposite : public CommandComponent {

public:

	virtual void exec() override;
	virtual void add(std::unique_ptr<CommandComponent> cmp) override;
	virtual void remove(std::unique_ptr<CommandComponent> cmp) override;

private:

	std::vector<std::unique_ptr<CommandComponent>> children;
};
