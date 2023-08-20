#include <raylib.h>

const int windowHeight = 640;
const int windowWidth = 800;
const int FPS = 60;

int velocity = 0;
// pixels per second per second
int jumpHeight = -600;
// pixels per second
int gravity = 1000;

bool isInAir{false};

int main(int argc, char const *argv[])
{
    /* code */
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");
    SetTargetFPS(FPS);

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowHeight/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    while (!WindowShouldClose())
    {
        // Time since last frame
        const float deltaTime{GetFrameTime()};

        /* code */
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        // Check if Player is on Ground
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            /* code */
            velocity = 0;
            isInAir = false;
        }
        // Player is in Air
        else
        {
            velocity += gravity * deltaTime;
            isInAir = true;
        }

        // Player jumps
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            /* code */
            velocity += jumpHeight;
        }

        scarfyPos.y += velocity * deltaTime;

        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
    return 0;
}
