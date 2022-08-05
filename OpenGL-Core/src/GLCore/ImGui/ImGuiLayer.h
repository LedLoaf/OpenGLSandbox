#pragma once

#include "GLCore/Core/Layer.h"

#include "GLCore/Events/ApplicationEvent.h"
#include "GLCore/Events/KeyEvent.h"
#include "GLCore/Events/MouseEvent.h"

namespace GLCore {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override = default;

		virtual void onAttach() override;
		virtual void onDetach() override;

		void begin();
		void end();

		void onEvent(Event& event) override;
		bool onMouseButtonPressed(MouseButtonPressedEvent& e);
	private:
		float m_time = 0.0f;
	};

}