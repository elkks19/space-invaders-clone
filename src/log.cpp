#include "log.h"
#include "ILoggable.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#define color inline static const std::string
#define logFunc const void

struct Colors
{
	color DEFAULT = "\033[0;39m\033[49m";
	// TEXT COLORS
	color BOLD_WHITE = "\033[1;97m";
	color BOLD_BLACK = "\033[1;30m";
	color WHITE = "\033[97m";
	color BLACK = "\033[30m";

	// BACKGROUND COLORS
	color BG_WHITE = "\033[107m";
	color BG_BLACK = "\033[40m";

	color BG_DARK_RED = "\033[41m";
	color BG_DARK_GREEN =  "\033[42m";
	color BG_DARK_YELLOW = "\033[43m";
	color BG_DARK_BLUE = "\033[44m";
	color BG_DARK_MAGENTA = "\033[45m";
	color BG_DARK_CYAN = "\033[46m";

	color INFO = BG_DARK_BLUE + BOLD_WHITE;
	color WARNING = BG_DARK_YELLOW + BOLD_BLACK;
	color ERROR = BG_DARK_RED + BOLD_WHITE;
	color TEXT = BG_BLACK + WHITE;
};


using namespace std;

logFunc Log::init(){
	system("clear");
	cout << Colors::TEXT;
	cout << "Log iniciado." << Colors::DEFAULT << endl;
}

logFunc Log::info(string message){
	cout << Colors::INFO;
	cout << "INFO: ";
	cout << message << Colors::DEFAULT << endl;
}

logFunc Log::warning(string message){
	cout << Colors::WARNING;
	cout << "WARNING: ";
	cout << message << Colors::DEFAULT << endl;
}

logFunc Log::error(string message){
	cout << Colors::ERROR;
	cout << "ERROR: ";
	cout << message << Colors::DEFAULT << endl;
}

logFunc Log::text(string message){
	cout << Colors::TEXT;
	cout << message;
	cout << Colors::DEFAULT << endl;
}


logFunc Log::info(ILoggable& object){
	cout << Colors::INFO;
	cout << "INFO: ";
	cout << object.info() << Colors::DEFAULT << endl;
}

logFunc Log::warning(ILoggable& object){
	cout << Colors::WARNING;
	cout << "WARNING: " << object.warning();
	cout << Colors::DEFAULT << endl;
}

logFunc Log::error(ILoggable& object){
	cout << Colors::ERROR;
	cout << "ERROR: " << object.error();
	cout << Colors::DEFAULT << endl;
}

