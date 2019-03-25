#pragma once

class IGameState {

private:
	virtual void buy() = 0;
	virtual void install() = 0;
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void uninstall() = 0;
};
