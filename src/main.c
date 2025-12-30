#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#define INIT_WINDOW_W 1600
#define INIT_WINDOW_H 900

struct {
    GLFWwindow *window;
} state;

static void on_glfw_error(int error_code, const char *description) {
    (void)error_code;
    fprintf(stderr, "GLFW Error: %s\n", description);
}

static bool on_init(void) {
    glfwSetErrorCallback(on_glfw_error);
    if (!glfwInit()) {
        fprintf(stderr, "glfwInit() failed\n");
        return false;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    state.window = glfwCreateWindow(INIT_WINDOW_W, INIT_WINDOW_H, "Voxel Factory Game", NULL, NULL);
    if (!state.window) {
        fprintf(stderr, "glfwCreateWindow() failed\n");
        return false;
    }

    return true;
}

static void on_quit(void) {
    glfwDestroyWindow(state.window);
    glfwTerminate();
}

static void on_update(float delta_time) {
    (void)delta_time;
}

static void on_draw(float delta_time) {
    (void)delta_time;
}

int main(void) {
    if (!on_init()) {
        fprintf(stderr, "Failed to initialize.\n");
        return EXIT_FAILURE;
    }

    float prev_time = glfwGetTime();

    while (!glfwWindowShouldClose(state.window)) {
        glfwPollEvents();

        float curr_time = glfwGetTime();
        float delta_time = curr_time - prev_time;
        prev_time = curr_time;

        on_update(delta_time);
        on_draw(delta_time);
    }

    on_quit();
}
