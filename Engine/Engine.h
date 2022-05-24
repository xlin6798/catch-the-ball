#pragma once

#include "EngineApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define ENGINE_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}
