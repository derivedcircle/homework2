#include "part4.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void part4() {
    glewExperimental = true; // Needed for core profile
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return; // return if it fails to initialize
    }
    // some settings for creating a window, not always required


    GLFWwindow* window = glfwCreateWindow(1024, 768, "AERSP 424", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }
    // Ensure we can capture the escape key being pressed below
    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        // Draw X and Y axis
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
        glVertex2f(0.0, 1.0);
        glVertex2f(0.0, -1.0);
        glEnd();

        glBegin(GL_LINES);
        // Draw X and Y axis
        glColor3f(0, 0, 1.0);
        for (int i = 0; i < 2000; i++)
        {
            double xPrev = i * 1.0 / 1000.0 - 1;
            double yPrev = 0.5* exp(-xPrev) * (cos(xPrev * 5));

            double x = (i+1.0) * 1.0 / 1000.0 - 1;
            double y = 0.5* exp(-x) * (cos(x * 5));

            glVertex2f(xPrev, yPrev);
            glVertex2f(x, y);
            

        }
        
        
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    
}