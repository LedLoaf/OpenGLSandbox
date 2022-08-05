#pragma once

#include "GLCore/Core/Window.h"

#include <GLFW/glfw3.h>

namespace GLCore {

	class WindowsWindow final : public Window
	{
	public:
		explicit WindowsWindow(const WindowProps& props);

		~WindowsWindow() override;

		void onUpdate() override;

		inline uint32_t getWidth() const override { return m_data.width; }
		inline uint32_t getHeight() const override { return m_data.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { m_data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline void* getNativeWindow() const override { return m_window; }
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();
	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string title;
			uint32_t width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_data;
	};

}