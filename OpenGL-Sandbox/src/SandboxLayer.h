#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

class SandboxLayer : public GLCore::Layer
{
public:
	SandboxLayer() = default;

	virtual void onAttach() override;
	virtual void onDetach() override;
	virtual void onEvent(GLCore::Event& event) override;
	virtual void onUpdate(GLCore::Timestep ts) override;
	virtual void onImGuiRender() override;
private:
};