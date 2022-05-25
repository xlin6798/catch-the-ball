#pragma once

#include "Engine.h"
#include "Entity.h"

class GameApp : public Engine::EngineApp
{
public:
	GameApp();

	virtual void OnUpdate() override;

	bool Score(const Entity& one, const Entity& another);

	bool Status(const Entity& one);

	bool InBound(int begin, int end);

private:
	Entity mBouncer{ {"Assets/Images/Bouncer.png"} };
	Entity mBall{ {"Assets/Images/Ball.png"} };
	Entity mLabel{ {"Assets/Images/ScoreLabel.png"} };
	Entity mGameOverLabel{ {"Assets/Images/GameOverLabel.png"} };
	Entity mOnes{ {"Assets/Images/0Label.png", "Assets/Images/1Label.png", "Assets/Images/2Label.png",
		"Assets/Images/3Label.png", "Assets/Images/4Label.png", "Assets/Images/5Label.png",
		"Assets/Images/6Label.png", "Assets/Images/7Label.png", "Assets/Images/8Label.png", "Assets/Images/9Label.png"} };
	Entity mTens{ {"Assets/Images/0Label.png", "Assets/Images/1Label.png", "Assets/Images/2Label.png",
		"Assets/Images/3Label.png", "Assets/Images/4Label.png", "Assets/Images/5Label.png",
		"Assets/Images/6Label.png", "Assets/Images/7Label.png", "Assets/Images/8Label.png", "Assets/Images/9Label.png"} };

	bool mStatus{ true };

	bool mPositive{ true };

	int mScore{ 0 };

	int mBouncerSpeed{ 0 };	// speed measured in pixels per frame (60 frames per second)

	int mBallSpeed{ 5 };	// speed measured in pixels per frame (60 frames per second)
};