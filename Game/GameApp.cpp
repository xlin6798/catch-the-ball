#include "GameApp.h"

GameApp::GameApp()
{
	SetKeyPressedCallback([this](const Engine::KeyPressedEvent& e)
	{
		switch (e.GetKeyCode())
		{
		case ENGINE_KEY_LEFT:
			mHorizontalSpeed = -2;
			mHero.SetActiveImage(0);
			break;
		case ENGINE_KEY_RIGHT:
			mHorizontalSpeed = 2;
			mHero.SetActiveImage(1);
			break;
		}
	});

	SetKeyReleasedCallback([this](const Engine::KeyReleasedEvent& e)
	{
		mHorizontalSpeed = 0;
	});

	mDangers[0].SetX(300);
	mDangers[0].SetY(300);
}

void GameApp::OnUpdate()
{
	mHero.SetX(mHero.GetX() + mHorizontalSpeed);

	if ((mDangers[0].GetY() < 0) || 
		(mDangers[0].GetY() > Engine::GameWindow::GetWindow()->GetHeight() - mDangers[0].GetHeight()))
		mEnemyVSpeed *= -1;

	mDangers[0].SetY(mDangers[0].GetY() + mEnemyVSpeed);

	if (Collide(mHero, mDangers[0]))
		exit(0);

	mDangers[0].Draw();
	mHero.Draw();
}


bool GameApp::Collide(const Entity& one, const Entity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetX() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	bool collideX{ false };
	if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
		(anotherLeft <= oneLeft && oneLeft <= anotherRight))
		collideX = true;

	bool collideY{ false };
	if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
		(anotherBottom <= oneBottom && oneBottom <= anotherTop))
		collideY = true;

	return collideX && collideY;
}
