#include "pch.h"
#include "EngineApp.h" 
#include "GLFW/glfw3.h"

namespace Engine
{
	void EngineApp::Run()
	{

		ENGINE_LOG("Engine running…\n");

		if (!glfwInit())
		{
			ENGINE_LOG("GLFW failed to initialize");
		}

		GLFWwindow* window;

		window = glfwCreateWindow(800, 600, "game window", NULL, NULL);

		while (true)
		{
			OnUpdate();

			
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

	}
	void EngineApp::OnUpdate()
	{
	}

}