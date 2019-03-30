#include "composite.h"

void CommandComposite::exec()
{
	for (const auto& child : children)
		child->exec();
}

void CommandComposite::add(std::unique_ptr<CommandComponent> cmp)
{
	children.push_back(std::move(cmp));
}

void CommandComposite::remove(std::unique_ptr<CommandComponent> cmp)
{
	//overload operator== missing
}
