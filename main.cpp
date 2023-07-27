#include<raylib.h>

const int windowHeight = 640;
const int windowWidth = 800;
const int FPS = 60;

int main(int argc, char const *argv[])
{
    /* code */
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");
    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        /* code */
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
