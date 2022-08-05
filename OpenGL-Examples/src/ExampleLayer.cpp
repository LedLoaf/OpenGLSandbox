#include "ExampleLayer.h"

using namespace GLCore;
using namespace GLCore::Utils;

ExampleLayer::ExampleLayer()
	: m_cameraController(16.0f / 9.0f)
{

}

ExampleLayer::~ExampleLayer()
{

}

void ExampleLayer::onAttach()
{
	enableGLDebugging();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_shader = Shader::fromGlslTextFiles(
		"assets/shaders/test.vert.glsl",
		"assets/shaders/test.frag.glsl"
	);

	glCreateVertexArrays(1, &m_quadVA);
	glBindVertexArray(m_quadVA);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	glCreateBuffers(1, &m_quadVB);
	glBindBuffer(GL_ARRAY_BUFFER, m_quadVB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };
	glCreateBuffers(1, &m_quadIB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_quadIB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void ExampleLayer::onDetach()
{
	glDeleteVertexArrays(1, &m_quadVA);
	glDeleteBuffers(1, &m_quadVB);
	glDeleteBuffers(1, &m_quadIB);
}

void ExampleLayer::onEvent(Event& event)
{
	m_cameraController.onEvent(event);

	EventDispatcher dispatcher(event);
	dispatcher.dispatch<MouseButtonPressedEvent>(
		[&](MouseButtonPressedEvent& e)
		{
			m_squareColor = m_squareAlternateColor;
			return false;
		});
	dispatcher.dispatch<MouseButtonReleasedEvent>(
		[&](MouseButtonReleasedEvent& e)
		{
			m_squareColor = m_squareBaseColor;
			return false;
		});
}

void ExampleLayer::onUpdate(Timestep ts)
{
	m_cameraController.onUpdate(ts);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_shader->getRendererID());

	int location = glGetUniformLocation(m_shader->getRendererID(), "u_ViewProjection");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(m_cameraController.getCamera().getViewProjectionMatrix()));

	location = glGetUniformLocation(m_shader->getRendererID(), "u_Color");
	glUniform4fv(location, 1, glm::value_ptr(m_squareColor));

	glBindVertexArray(m_quadVA);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void ExampleLayer::onImGuiRender()
{
	ImGui::Begin("Controls");
	if (ImGui::ColorEdit4("Square Base Color", glm::value_ptr(m_squareBaseColor)))
		m_squareColor = m_squareBaseColor;
	ImGui::ColorEdit4("Square Alternate Color", glm::value_ptr(m_squareAlternateColor));
	ImGui::End();
}
