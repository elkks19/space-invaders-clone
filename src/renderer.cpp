#include <cassert>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderer.h"
#include <iostream>
#include <string>

std::string Renderer::info(){
	return "";
}

std::string Renderer::warning(){
	return "";
}

std::string Renderer::error(){
	return "";
}


Renderer::Renderer(){
		
}

Renderer::~Renderer(){

}

int Renderer::init(){
	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Space invaders", NULL, NULL);
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	// despues de iniciar un contexto valido de opengl
	if(glewInit() != GLEW_OK)
		std::cout << "GLEW no se inició correctamente" << std::endl;

	return 0;
}
