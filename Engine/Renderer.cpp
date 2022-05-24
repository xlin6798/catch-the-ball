#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "specificOpenGL/OpenGLRenderer.h"

namespace Engine
{
	void Renderer::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Renderer;
	}

	void Renderer::Draw(Engine::Sprite& picture, int xPos, int yPos, int zPos)
	{
		assert(mInstance != nullptr);

		/*int winWidth{ GameWindow::GetWindow()->GetWidth() };
		int winHeight{ GameWindow::GetWindow()->GetHeight() };

		mInstance->mShader.SetUniform2Ints("windowSize", winWidth, winHeight);
		mInstance->mShader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);*/

		mInstance->mImplementation->Draw(picture, xPos, yPos, zPos, mInstance->mShader);
	}

	void Renderer::ClearScreen()
	{
		mInstance->mImplementation->ClearScreen();
	}

	Renderer::Renderer() :
		mShader("../Engine/Assets/Shaders/defaultVertex.glsl", "../Engine/Assets/Shaders/defaultFragment.glsl")
	{
#ifdef ENGINE_OPENGL
		mImplementation = new OpenGLRenderer;
#else
		#Only_OpenGL_is_supported_for_now
#endif
	}
}
