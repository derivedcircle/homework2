//#include "part4.h"
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <cmath>
//#include <iostream>
//
//// fix eventually
//void part4() {
//	// Initialise GLFW
//	glewExperimental = true; // Needed for core profile
//	if (!glfwInit())
//	{
//		fprintf(stderr, "Failed to initialize GLFW\n");
//		return -1; // return if it fails to initialize
//	}
//	// some settings for creating a window, not always required
//	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
//	// Open a window and create its OpenGL context
//	GLFWwindow* window; // OpenGL variable for a window
//	window = glfwCreateWindow(1024, 768, "My Window", NULL, NULL);
//	if (window == NULL) {
//		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version\n");
//		glfwTerminate();
//		return -1;
//	}
//	// Initialize other interfaces with OpenGL
//	glfwMakeContextCurrent(window); // Initialize GLEW
//	glewExperimental = true; // Needed in core profile
//	if (glewInit() != GLEW_OK) {
//		fprintf(stderr, "Failed to initialize GLEW\n");
//		return -1;
//	}
//	// Ensure we can capture the escape key being pressed below
//	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//	do {
//		// Clear the screen.
//		glClear(GL_COLOR_BUFFER_BIT);
//		
//		glBegin(GL_LINES);
//		// Draw X and Y axis
//		glColor3f(1.0, 1.0, 1.0);
//		glVertex2f(-1.0, 0.0);
//		glVertex2f(1.0, 0.0);
//		glVertex2f(0.0, 1.0);
//		glVertex2f(0.0, -1.0);
//		// Plot sine curve
//		glColor3f(0.0, 1.0, 0.0);
//		float prev_x = -1;
//		float prev_y = 0;
//		for (float i = 0; i < 3.14159; i += 0.001) {
//			float x = (2 * i - 3.14159) / 3.14159;
//			float y = i*i*i;
//			glVertex2f(prev_x, prev_y);
//			glVertex2f(x, y);
//			prev_x = x;
//			prev_y = y;
//		}
//		glEnd();
//
//		glfwSwapBuffers(window); // Swap buffers
//		glfwPollEvents(); // Process Events
//	} // Check if the ESC key was pressed or the window was closed
//	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
//		glfwWindowShouldClose(window) == 0);
//	
//}
