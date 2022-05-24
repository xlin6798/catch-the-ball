#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace Engine
{
	void OpenGLRenderer::Draw(Engine::Sprite& picture, int xPos, int yPos, int zPos, Engine::Shader shader)
	{
		int winWidth{ GameWindow::GetWindow()->GetWidth() };
		int winHeight{ GameWindow::GetWindow()->GetHeight() };

		picture.Bind();
		shader.Bind();

		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}
	
	void OpenGLRenderer::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}