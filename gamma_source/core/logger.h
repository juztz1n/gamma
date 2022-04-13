#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

#define GAMMA_INFO_PREFIX "[GAMMA | INF]"
#define GAMMA_WARNING_PREFIX "[GAMMA | WRN]"
#define GAMMA_ERROR_PREFIX "[GAMMA | ERR]"


namespace Gamma
{
	/**
	 * @brief Simple utility function to print out information regarding processes going on in the engine.
	 * 
	 * @param msg 
	 */
	static void info(std::string msg)
	{
		std::cout << GAMMA_INFO_PREFIX << " " << msg << std::endl;
	}

	/**
	 * @brief Simple utility function to print out warning information regarding processes going on in the engine.
	 * 
	 * @param msg 
	 */
	static void warn(std::string msg)
	{
		std::cout << GAMMA_WARNING_PREFIX << " " << msg << std::endl;
	}

	/**
	 * @brief Simple utility function to print out error information regarding processes going on in the engine.
	 * 
	 * @param msg 
	 */
	static void err(std::string msg)
	{
		std::cerr << GAMMA_ERROR_PREFIX << " " << msg << std::endl;
	}
}

#endif