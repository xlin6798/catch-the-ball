#pragma once

#include "Engine.h"
#include "Entity.h"

class GameApp : public Engine::EngineApp
{
public:
	GameApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);

private:
	Entity mHero{ {"Assets/Images/RightHero.png", "Assets/Images/LeftHero.png"} };
	std::vector<Entity> mDangers{ { {"Assets/Images/Danger.png"}} };
	int mEnemyVSpeed{ 3 };

	int mHorizontalSpeed{ 0 };	// speed measured in pixels per frame (60 frames per second)
};