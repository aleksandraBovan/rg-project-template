#include <iostream>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "prva_nedelja", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window\n" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);
        glfwSwapBuffers(window);
    }

    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void UpdateWindow(GLFWwindow *window, int widthOff, int heightOff) {
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    glfwSetWindowSize(window, w + widthOff, h + heightOff);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        glClearColor(1, 0, 0, 1);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        glClearColor(0, 1, 0, 1);
    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
        glClearColor(0, 0, 1, 1);
    }

    bool leftControlPressed = (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS);
    bool rightControlPressed = (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);

    bool ctrlPressed = leftControlPressed || rightControlPressed;

    if (ctrlPressed && (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)) {
        UpdateWindow(window, 0, -1);
    }
    if (ctrlPressed && (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)) {
        UpdateWindow(window, 0, 1);
    }
    if (ctrlPressed && (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)) {
        UpdateWindow(window, -1, 0);
    }
    if (ctrlPressed && (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)) {
        UpdateWindow(window, 1, 0);
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS ||
            glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            int w, h;
            glfwGetWindowSize(window, &w, &h);

            float x = (float) (xpos / w);
            float y = 1.0f - (float) (ypos / h);

            glClearColor(x, y, 0, 1);
        } else {
            glClearColor(rand() / (float) RAND_MAX, rand() / (float) RAND_MAX, rand() / (float) RAND_MAX, 1);
        }
    }
}
