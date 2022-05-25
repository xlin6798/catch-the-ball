#include "GameApp.h"

GameApp::GameApp()
{
	SetKeyPressedCallback([this](const Engine::KeyPressedEvent& e)
	{
		switch (e.GetKeyCode())
		{
		case ENGINE_KEY_LEFT:
			mBouncerSpeed = -10;
			break;
		case ENGINE_KEY_RIGHT:
			mBouncerSpeed = 10;
			break;
		}
	});

	SetKeyReleasedCallback([this](const Engine::KeyReleasedEvent& e)
	{
		switch (e.GetKeyCode())
		{
		case ENGINE_KEY_LEFT:
			mBouncerSpeed = 0;
			break;
		case ENGINE_KEY_RIGHT:
			mBouncerSpeed = 0;
			break;
		}
	});

	mLabel.SetX(50);
	mLabel.SetY(Engine::GameWindow::GetWindow()->GetHeight() - 50);

	mTens.SetX(130);
	mTens.SetY(Engine::GameWindow::GetWindow()->GetHeight() - 50);

	mOnes.SetX(150);
	mOnes.SetY(Engine::GameWindow::GetWindow()->GetHeight() - 50);

	mBall.SetX(rand() % (Engine::GameWindow::GetWindow()->GetWidth() - 100) + 50);		//50 to width - 100
	mBall.SetY(Engine::GameWindow::GetWindow()->GetHeight() + 200);

	mBouncer.SetX(Engine::GameWindow::GetWindow()->GetWidth() / 2 - mBouncer.GetWidth() / 2);		// center
	mBouncer.SetY(100);

	mGameOverLabel.SetX(Engine::GameWindow::GetWindow()->GetWidth() / 2 - mGameOverLabel.GetWidth() / 2);	// center
	mGameOverLabel.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mGameOverLabel.GetHeight() / 2);	// center
}

void GameApp::OnUpdate()
{
	if (mStatus) 
	{
		mBouncer.SetX(mBouncer.GetX() + mBouncerSpeed);	

		mBall.SetY(mBall.GetY() - mBallSpeed);

		if (Score(mBall, mBouncer)) {
			mBall.SetX(rand() % (Engine::GameWindow::GetWindow()->GetWidth() - 100) + 50);
			mBall.SetY(Engine::GameWindow::GetWindow()->GetHeight() + 200);
			mBallSpeed++;
			mScore++;
			mOnes.SetActiveImage(mScore % 10);
			mTens.SetActiveImage(mScore / 10);
		}

		if (Status(mBall))
			mStatus = false;
		
		mBouncer.Draw();
		mBall.Draw();
	}
	else
	{
		mGameOverLabel.Draw();
	}
	mLabel.Draw();
	mOnes.Draw();
	mTens.Draw();
}


bool GameApp::Score(const Entity& one, const Entity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	return ((oneRight >= anotherLeft && oneLeft <= anotherRight) && (oneBottom <= anotherTop && oneTop >= anotherBottom));
}

bool GameApp::Status(const Entity& one)
{
	return (one.GetY() <= 0);
}
