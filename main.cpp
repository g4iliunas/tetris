#include "src/renderer.h"
#include <fmt/base.h>

int main(void)
{
    Renderer renderer("Tetris", 500, 500);
    renderer.run();
    return 0;
}