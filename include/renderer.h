#ifndef RENDERER_H
#define RENDERER_H

#include "ILoggable.h"
#include <string>

class Renderer : public ILoggable {
public:
	Renderer();
	~Renderer();

	int init();
	virtual std::string info() override;
	virtual std::string warning() override;
	virtual std::string error() override;
private:

};

#endif
