#include <raylib.h>

const int windowHeight = 640;
const int windowWidth = 800;
const int FPS = 60;

int velocity = 0;
// pixels per second per second
int jumpHeight = -600;
// pixels per second
int gravity = 1000;

// speed of hazards - pixels per second
int nebulaVelocity = 100;

bool isInAir{false};

int main(int argc, char const *argv[])
{
    /* code */
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");
    SetTargetFPS(FPS);

    // create and load character
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6; // 6 frames/images
    scarfyRec.height = scarfy.height;   // 1 row of image
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowHeight / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    // create and load hazards
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebulaRec;
    nebulaRec.width = nebula.width / 8;   // 8 frames/images
    nebulaRec.height = nebula.height / 8; // 8 rows of images
    nebulaRec.x = 0;
    nebulaRec.y = 0;
    Vector2 nebulaPos;
    nebulaPos.x = windowWidth;
    nebulaPos.y = windowHeight - nebulaRec.height;

    // animation frame
    int frame{};
    // time to update animation frame e.g., 12 fps
    const float updateTime = 1.0 / 12.0;
    float runningTime{};

    while (!WindowShouldClose())
    {
        // Time since last frame
        const float deltaTime{GetFrameTime()};

        /* code */
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        DrawTextureRec(nebula, nebulaRec, nebulaPos, WHITE);

        runningTime += deltaTime;

        if (!isInAir)
        {
            /* code */
            if (runningTime >= updateTime)
            {
                /* code */
                // reset
                runningTime = 0.0;
                // Update animation frames
                scarfyRec.x = frame * scarfyRec.width;
                frame++;

                // only six frames for Scarfy animation
                if (frame > 5)
                {
                    /* code */
                    frame = 0;
                }
            }
        }

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

        nebulaPos.x -= nebulaVelocity * deltaTime;

        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
    return 0;
}
