#ifndef LOG_H
#define LOG_H

#include <string>

class ILoggable;

//INFO: Esto es una especie de interfaz xd, que se puede llamar para imprimir cosas en la terminal, 
//como info o errores.

class Log{
public:
	Log() = delete;
	static const void init();

	static const void info(std::string message);
	static const void error(std::string message);
	static const void warning(std::string message);
	static const void text(std::string message);


	static const void info(ILoggable& object);
	static const void error(ILoggable& object);
	static const void warning(ILoggable& object);
};

#endif

