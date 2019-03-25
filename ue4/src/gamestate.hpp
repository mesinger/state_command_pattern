#pragma once

#include "Game.hpp"
#include <iostream>

class IGameState {

public:
	virtual ~IGameState() = default;

	virtual void buy(Game* const pgame) = 0;
	virtual void install(Game* const pgame) = 0;
	virtual void start(Game* const pgame) = 0;
	virtual void stop(Game* const pgame) = 0;
	virtual void update(Game* const pgame) = 0;
	virtual void uninstall(Game* const pgame) = 0;
};

class BoughtGameState : public IGameState {

public:
	virtual ~BoughtGameState() = default;

	virtual void buy(Game* const pgame) override;
	virtual void install(Game* const pgame) override;
	virtual void start(Game* const pgame) override;
	virtual void stop(Game* const pgame) override;
	virtual void update(Game* const pgame) override;
	virtual void uninstall(Game* const pgame) override;
};

class InstalledGameState : public IGameState {

public:
	virtual ~InstalledGameState() = default;

	virtual void buy(Game* const pgame) override;
	virtual void install(Game* const pgame) override;
	virtual void start(Game* const pgame) override;
	virtual void stop(Game* const pgame) override;
	virtual void update(Game* const pgame) override;
	virtual void uninstall(Game* const pgame) override;
};

class NotBoughtGameState : public IGameState {

public:
	virtual ~NotBoughtGameState() = default;

	virtual void buy(Game* const pgame) override;
	virtual void install(Game* const pgame) override;
	virtual void start(Game* const pgame) override;
	virtual void stop(Game* const pgame) override;
	virtual void update(Game* const pgame) override;
	virtual void uninstall(Game* const pgame) override;
};

class RunningGameState : public IGameState {

public:
	virtual ~RunningGameState() = default;

	virtual void buy(Game* const pgame) override;
	virtual void install(Game* const pgame) override;
	virtual void start(Game* const pgame) override;
	virtual void stop(Game* const pgame) override;
	virtual void update(Game* const pgame) override;
	virtual void uninstall(Game* const pgame) override;
};
