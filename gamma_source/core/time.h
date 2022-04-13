#include <time.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WIN64)
#define OS_WINDOWS
#elif defined(__linux__)
#define OS_LINUX
#elif __cplusplus >= 201103L
#define OS_OTHER_CPP11
#else
#define OS_OTHER
#endif

#ifdef OS_WINDOWS

#include <Windows.h>
#include <iostream>

static double g_freq;
static bool g_timerInitialized = false;

#endif

#ifdef OS_LINUX
#include <sys/time.h>

static const long NANOSECONDS_PER_SECOND = 1000000000L;

#endif

#ifdef OS_OTHER
#include <GLFW/glfw3.h>
#endif

#ifdef OS_OTHER_CPP11
#include <chrono>

static std::chrono::system_clock::time_point m_epoch = std::chrono::high_resolution_clock::now();

#endif

namespace Gamma
{
	/**
	 * @brief Utility function that returns the system time in nanoseconds. Derived from BennyQBD's C++ Game Engine.
	 * 
	 * @return double 
	 */
	static double getTime()
	{
		#ifdef OS_WINDOWS

		if (!g_timerInitialized)
		{
			LARGE_INTEGER li;
			if (!QueryPerformanceFrequency(&li))
				info("QueryPerformanceFrequency failed in timer initialization.");

			g_freq = double(li.QuadPart);
			g_timerInitialized = true;
		}

		LARGE_INTEGER li;
		if (!QueryPerformanceCounter(&li))
			info("QueryPerformanceCounter failed in get time!.");

		return double(li.QuadPart) / g_freq;

		#endif

		#ifdef OS_LINUX

		timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		return (double)(((long)ts.tv_sec * NANOSECONDS_PER_SECOND) + ts.tv_nsec) / ((double)(NANOSECONDS_PER_SECOND));

		#endif

		#ifdef OS_OTHER_CPP11

		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_epoch).count() / 1000000000.0;

		#endif

		#ifdef OS_OTHER

		return (double) glfwGetTime() / 1000.0;
        
		#endif
	}
}