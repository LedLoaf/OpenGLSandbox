#include "SandboxLayer.h"

using namespace GLCore;
using namespace GLCore::Utils;

void SandboxLayer::onAttach()
{
	enableGLDebugging();

	// Init here
}

void SandboxLayer::onDetach()
{
	// Shutdown here
}

void SandboxLayer::onEvent(Event& event)
{
	// Events here
}

void SandboxLayer::onUpdate(Timestep ts)
{
	// Render here
}

void SandboxLayer::onImGuiRender()
{
	// ImGui here
}
