#pragma once

#include <string>

#include <glad/glad.h>

namespace GLCore::Utils {

	class Shader
	{
	public:
		~Shader();

		GLuint getRendererID() { return m_rendererID; }

		static Shader* fromGlslTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	private:
		Shader() = default;

		void loadFromGlslTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		GLuint compileShader(GLenum type, const std::string& source);
	private:
		GLuint m_rendererID;
	};

}