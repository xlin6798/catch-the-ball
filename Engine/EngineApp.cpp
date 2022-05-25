#include "pch.h"

#include "EngineApp.h" 
#include "GameWindow.h"

#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

namespace Engine
{
	EngineApp::EngineApp()
	{
		ENGINE_LOG("Engine running");

		GameWindow::Init();

		GameWindow::GetWindow()->CreateWindow(1000, 800, "Game Window - Ball Collector");

		Renderer::Init();
	}

	void EngineApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			Renderer::ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			GameWindow::GetWindow()->SwapBuffers();
			GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}

	}
	void EngineApp::OnUpdate()
	{
	}

	void EngineApp::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> &keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}

	void EngineApp::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}

}