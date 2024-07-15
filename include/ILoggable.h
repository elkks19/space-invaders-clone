#ifndef ILOGGABLE_H
#define ILOGGABLE_H

#include <string>

//INFO: Interfaz para clases cuya informacion pueda ser impresa en la terminal.
class ILoggable{
public:
	virtual std::string info() = 0;
	virtual std::string warning() = 0;
	virtual std::string error() = 0;
};


#endif
