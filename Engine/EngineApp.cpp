#include "pch.h"

#include "EngineApp.h" 
#include "GameWindow.h"

#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

namespace Engine
{
	void EngineApp::Run()
	{

		ENGINE_LOG("Engine running");

		GameWindow::Init();

		GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		Renderer::Init();

		Sprite star{"../Engine/Assets/Images/Star.png"};

		int xPos{ -star.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, xPos, 20, 1);

			xPos = (xPos + 5);

			std::this_thread::sleep_until(mNextFrameTime);

			GameWindow::GetWindow()->SwapBuffers();
			GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}

	}
	void EngineApp::OnUpdate()
	{
	}

}