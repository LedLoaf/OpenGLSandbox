#pragma once

namespace GLCore {

	class Timestep
	{
	public:
		Timestep(const float time = 0.0f)
			: m_time(time)
		{
		}

		operator float() const { return m_time; }

		float getSeconds() const { return m_time; }
		float getMilliseconds() const { return m_time * 1000.0f; }
		float getMicroseconds() const { return m_time * 1000000.f; }
	private:
		float m_time;
	};

}