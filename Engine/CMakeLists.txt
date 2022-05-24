set(HEADER_FILES
	Engine.h
	EngineApp.h
	EngineUtil.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	Sprite.h
	Shader.h
	Renderer.h
	SpriteImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	specificOpenGL/OpenGLSprite.h
	specificOpenGL/OpenGLShader.h
	specificOpenGL/OpenGLRenderer.h
	)

set(SOURCE_FILES 
	EngineApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	Sprite.cpp
	Shader.cpp
	Renderer.cpp
	specificOpenGL/OpenGLSprite.cpp
	specificOpenGL/OpenGLShader.cpp
	specificOpenGL/OpenGLRenderer.cpp
	)

add_library(Engine SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DENGINE_LIB)
add_definitions(-DENGINE_DEBUG)
add_definitions(-DENGINE_OPENGL)

include_directories(../glfw/include)
include_directories(../Engine)
include_directories(../stbi)
include_directories(../glad)

target_precompile_headers(Engine PRIVATE pch.h)

target_link_libraries(Engine glfw)