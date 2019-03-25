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

	explicit Game(const std::string& name);
	virtual ~Game();

	Game(const Game& rhs) :name(rhs.name), state(rhs.state) {

	}

	void buy();
	void install();
	void start();
	void stop();
	void update();
	void uninstall();

	const std::string name;

private:

	std::shared_ptr<IGameState> state;

	friend class NotBoughtGameState;
	friend class BoughtGameState;
	friend class InstalledGameState;
	friend class RunningGameState;
};
