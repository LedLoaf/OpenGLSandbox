#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

class ExampleLayer final : public GLCore::Layer
{
public:
	ExampleLayer();

	~ExampleLayer() override;

	virtual void onAttach() override;
	virtual void onDetach() override;
	virtual void onEvent(GLCore::Event& event) override;
	virtual void onUpdate(GLCore::Timestep ts) override;
	virtual void onImGuiRender() override;
private:
	GLCore::Utils::Shader* m_shader;
	GLCore::Utils::OrthographicCameraController m_cameraController;
	
	GLuint m_quadVA, m_quadVB, m_quadIB;

	glm::vec4 m_squareBaseColor = { 0.8f, 0.2f, 0.3f, 1.0f };
	glm::vec4 m_squareAlternateColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	glm::vec4 m_squareColor = m_squareBaseColor;
};