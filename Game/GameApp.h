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
	Entity mGameLabel{ {"Assets/Images/GameLabel.png"} };
	Entity mHelpPoster{ {"Assets/Images/HelpPoster.png"} };
	Entity mButtons{ {"Assets/Images/StartButton.png", "Assets/Images/StartButtonActive.png", 
		"Assets/Images/HelpButton.png", "Assets/Images/HelpButtonActive.png", 
		"Assets/Images/ExitButton.png", "Assets/Images/ExitButtonActive.png"}};

	Entity mOnes{ {"Assets/Images/0Label.png", "Assets/Images/1Label.png", "Assets/Images/2Label.png",
		"Assets/Images/3Label.png", "Assets/Images/4Label.png", "Assets/Images/5Label.png",
		"Assets/Images/6Label.png", "Assets/Images/7Label.png", "Assets/Images/8Label.png", "Assets/Images/9Label.png"} };
	Entity mTens{ {"Assets/Images/0Label.png", "Assets/Images/1Label.png", "Assets/Images/2Label.png",
		"Assets/Images/3Label.png", "Assets/Images/4Label.png", "Assets/Images/5Label.png",
		"Assets/Images/6Label.png", "Assets/Images/7Label.png", "Assets/Images/8Label.png", "Assets/Images/9Label.png"} };

	int mState{ 0 };	// 0: game menu		1: in game		2: game over	3: help menu	4: exit	
	
	int mButton{ 0 };	// 0: start		1: help			2: exit

	int mPositive{ 0 };

	int mScore{ 0 };

	int mDelay{ 0 };

	int mBouncerSpeed{ 8 };	// initial speed measured in pixels per frame (30 frames per second)

	int mBallSpeed{ 5 };	// speed measured in pixels per frame (30 frames per second)
};