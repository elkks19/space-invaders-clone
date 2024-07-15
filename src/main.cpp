#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>


//Function that logs gl errors
void logError(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
	std::cout << "[OpenGL Error]: (" << type << ") " << message << std::endl;
	exit(-1);
}


int main(void){
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Space invaders", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	// despues de iniciar un contexto valido de opengl
	if(glewInit() != GLEW_OK)
		std::cout << "GLEW no se inició correctamente" << std::endl;


	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
	glDebugMessageCallback(logError, nullptr);


	float positions[] {
		-0.5f, -0.5f, // index 0
		 0.5f, -0.5f, // index 1
		 0.5f,  0.5f, // index 2
		-0.5f,  0.5f  // index 3
	};

	unsigned int indices[] {
		0, 1, 2,
		2, 3, 0
	};

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// ID del buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	// Seleccionar el buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	// Datos del buffer
	glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
	// Habilitar el buffer en el indice 0
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	unsigned int ibo; // index buffer object
	glGenBuffers(1, &ibo);
	// Seleccionar el buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	// Datos del buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	/* Loop until the user closes the window */

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
