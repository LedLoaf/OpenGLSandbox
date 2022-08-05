#pragma once

#include "GLCore/Core/Input.h"

namespace GLCore {

	class WindowsInput final : public Input
	{
	public:
		virtual ~WindowsInput() = default;

	protected:
		virtual bool isKeyPressedImpl(int keycode) override;

		virtual bool isMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> getMousePositionImpl() override;
		virtual float getMouseXImpl() override;
		virtual float getMouseYImpl() override;
	};

}
