#include "Time.hpp"
#include "Math.hpp"

namespace kn::time
{
double Clock::tick(int frameRate)
{
    if (frameRate < 1)
        frameRate = 1;

    m_targetFrameTime = 1000.0 / frameRate;
    m_frameTime = (static_cast<double>(SDL_GetPerformanceCounter()) / m_frequency - m_last / m_frequency) * 1000.0;
    if (m_frameTime < m_targetFrameTime)
        SDL_Delay(static_cast<uint32_t>(m_targetFrameTime - m_frameTime));

    m_now = static_cast<double>(SDL_GetPerformanceCounter());
    m_deltaTime = m_now / m_frequency - m_last / m_frequency;
    m_last = m_now;

    return m_deltaTime;
}
} // namespace kn::time