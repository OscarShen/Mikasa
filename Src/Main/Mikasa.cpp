#include <iostream>

#include <Windows.h>

#include "glad/glad.h"

#include "CoreMinimal.h"
#include "Render/RenderManager.h"
#include "Render/Display/Display.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);

int main()
{
    FRenderManager::Get().InitRenderStatus();

    FDisplayPtr Display = FRenderManager::Get().GetDisplay();
    
    // render loop
    // -----------
    while (!Display->ShouldCloseDisplay())
    {
        Display->RefreshDisplay();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        Display->SwapBuffers();

    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    Display->DestroyDisplay();
    return 0;
}

//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
