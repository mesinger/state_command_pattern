#pragma once

#include <string>
#include <memory>

class IGameState;
class NotBoughtGameState;
class BoughtGameState;
class InstalledGameState;
class RunningGameState;

class Game {

public:

	const std::string name;

public:

	Game(const std::string& name);
	virtual ~Game();

	void buy();
	void install();
	void start();
	void stop();
	void update();
	void uninstall();

private:

	std::unique_ptr<IGameState> state;

	friend class NotBoughtGameState;
	friend class BoughtGameState;
	friend class InstalledGameState;
	friend class RunningGameState;
};
