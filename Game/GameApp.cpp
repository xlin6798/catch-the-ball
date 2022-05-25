#include "GameApp.h"

GameApp::GameApp()
{
	SetKeyPressedCallback([this](const Engine::KeyPressedEvent& e)
		{
			switch (mState)
			{
			case -1:
				switch (e.GetKeyCode())
				{
				case ENGINE_KEY_SPACE:
					mState = 0;
					break;
				case ENGINE_KEY_ENTER:
					mState = 0;
					break;
				}
				break;

			case 0:
				switch (e.GetKeyCode())
				{
				case ENGINE_KEY_ENTER:
					switch (mButton)
					{
					case 0:
						mState = 1;
						break;
					case 1:
						mState = 3;
						break;
					case 2:
						mState = 4;
						break;
					}
					break;

				case ENGINE_KEY_SPACE:
					switch (mButton)
					{
					case 0:
						mState = 1;
						break;
					case 1:
						mState = 3;
						break;
					case 2:
						mState = 4;
						break;
					}
					break;

				case ENGINE_KEY_UP:
					if (mButton >= 1)
						mButton--;
					break;
				case ENGINE_KEY_DOWN:
					if (mButton <= 1)
						mButton++;
					break;

				case ENGINE_KEY_W:
					if (mButton >= 1)
						mButton--;
					break;
				case ENGINE_KEY_S:
					if (mButton <= 1)
						mButton++;
					break;
				}
				break;

			case 1:
				switch (e.GetKeyCode())
				{
				case ENGINE_KEY_LEFT:
					mPositive = -1;
					break;
				case ENGINE_KEY_RIGHT:
					mPositive = 1;
					break;
				case ENGINE_KEY_A:
					mPositive = -1;
					break;
				case ENGINE_KEY_D:
					mPositive = 1;
					break;
				}
				break;

			case 3:
				switch (e.GetKeyCode())
				{
				case ENGINE_KEY_SPACE:
					mState = 0;
					break;
				case ENGINE_KEY_ENTER:
					mState = 0;
					break;
				}
				break;
			}
		});

	SetKeyReleasedCallback([this](const Engine::KeyReleasedEvent& e)
		{
			/*switch (e.GetKeyCode())
			{
			case ENGINE_KEY_LEFT:
				mPositive = 0;
				break;
			case ENGINE_KEY_RIGHT:
				mPositive = 0;
				break;
			}*/
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

	mGameLabel.SetX(Engine::GameWindow::GetWindow()->GetWidth() / 2 - mGameLabel.GetWidth() / 2);	// center
	mGameLabel.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mGameLabel.GetHeight() / 2 + 200);	// center + 200 pixels up

	mButtons.SetX(Engine::GameWindow::GetWindow()->GetWidth() / 2 - mButtons.GetWidth() / 2);	// center

	mHelpPoster.SetX(Engine::GameWindow::GetWindow()->GetWidth() / 2 - mHelpPoster.GetWidth() / 2);	// center
	mHelpPoster.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mHelpPoster.GetHeight() / 2);	// center

	mStartPoster.SetX(Engine::GameWindow::GetWindow()->GetWidth() / 2 - mStartPoster.GetWidth() / 2);	// center
	mStartPoster.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mStartPoster.GetHeight() / 2);	// center
}

void GameApp::OnUpdate()
{
	switch (mState)
	{
	case -1:
		mStartPoster.Draw();

		mStart++;

		if(mStart % 15 == 0)
			mStartPoster.SetActiveImage(std::abs(mStartPoster.GetActiveImage()-1));

		break;
	case 0:
		mGameLabel.Draw();
		mButtons.SetActiveImage(mButton == 0 ? 1 : 0);
		mButtons.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mButtons.GetHeight() / 2);	// center
		mButtons.Draw();

		mButtons.SetActiveImage(mButton == 1 ? 3 : 2);
		mButtons.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mButtons.GetHeight() / 2 - 120);	// center - 120 pixels down
		mButtons.Draw();

		mButtons.SetActiveImage(mButton == 2 ? 5 : 4);
		mButtons.SetY(Engine::GameWindow::GetWindow()->GetHeight() / 2 - mButtons.GetHeight() / 2 - 240);	// center - 240 pixels= down
		mButtons.Draw();

		break;

	case 1:
		for (int i = 0; i < mBouncerSpeed; i++) {
			int newX = mBouncer.GetX() + mPositive;
			if (InBound(newX, newX + mBouncer.GetWidth()))
				mBouncer.SetX(newX);
		}

		mBall.SetY(mBall.GetY() - mBallSpeed);

		if (Score(mBall, mBouncer)) {
			mBall.SetX(rand() % (Engine::GameWindow::GetWindow()->GetWidth() - 100) + 50);
			mBall.SetY(Engine::GameWindow::GetWindow()->GetHeight() + 200);
			mBallSpeed++;
			mScore++;
			mOnes.SetActiveImage(mScore % 10);
			mTens.SetActiveImage(mScore / 10);
			if (mScore % 3 == 0)
				mBouncerSpeed++;
		}

		if (Status(mBall))
			mState = 2;

		mBouncer.Draw();
		mBall.Draw();
		mLabel.Draw();
		mOnes.Draw();
		mTens.Draw();

		break;

	case 2:
		mLabel.Draw();
		mOnes.Draw();
		mTens.Draw();
		mGameOverLabel.Draw();
		mDelay++;
		if (mDelay >= 30 * 4)	// frames * seconds = time delayed (in seconds)
			mState = 0;

		break;

	case 3:
		mHelpPoster.Draw();
		break;

	case 4:
		exit(0);
		break;
	}
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

bool GameApp::InBound(int begin, int end)
{
	return (begin >= 0 && end <= Engine::GameWindow::GetWindow()->GetWidth());
}