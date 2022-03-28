#include "pch.h"
#include "EngineApp.h" 
#include "GameWindow.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	void EngineApp::Run()
	{

		ENGINE_LOG("Engine running…\n");

		Engine::GameWindow::Init();

		Engine::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		while (true)
		{
			OnUpdate();
			Engine::GameWindow::GetWindow()->SwapBuffers();
			Engine::GameWindow::GetWindow()->CollectEvents();
		}

	}
	void EngineApp::OnUpdate()
	{
	}

}