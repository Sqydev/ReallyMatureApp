/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press Shift+F10 for Android Studio.
*
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5) and reviewed by Victor Le Juez
*
********************************************************************************************/

//Masz w gradle.properties

#include "raymob.h"
#include <stdio.h>

int main(void) {
    InitWindow(0, 0, "TEST");
    SetTargetFPS(60);

    Texture2D HomeIcon = LoadTexture("HomeIcon.png");
    Texture2D SettingsIcon = LoadTexture("SettingsIcon.png");
    Texture2D StatsIcon = LoadTexture("StatsIcon.png");

    float screenWidth = (float)GetScreenWidth();
    float screenHeight = (float)GetScreenHeight();

    int Mode = 0;

    Rectangle Homebutton = {
            screenWidth * 0.5f - screenWidth * 0.3f / 2,
            screenHeight * 0.75f,
            screenWidth * 0.3f,
            screenHeight * 0.1f
    };
    Rectangle Settingsbutton = {
            screenWidth * 0.5f - screenWidth * 0.3f / 2,
            screenHeight * 0.75f,
            screenWidth * 0.3f,
            screenHeight * 0.1f
    };
    Rectangle Statsbutton = {
            screenWidth * 0.5f - screenWidth * 0.3f / 2,
            screenHeight * 0.75f,
            screenWidth * 0.3f,
            screenHeight * 0.1f
    };

    while(!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        bool hoveringHomeButton = CheckCollisionPointRec(mouse, Homebutton);
        bool clickedHomeButton = hoveringHomeButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        bool hoveringSettingsButton = CheckCollisionPointRec(mouse, Settingsbutton);
        bool clickedSettingsButton = hoveringSettingsButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        bool hoveringStatsButton = CheckCollisionPointRec(mouse, Statsbutton);
        bool clickedStatsButton = hoveringStatsButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        if(clickedHomeButton) {
            Mode = 0;
        }
        if(clickedSettingsButton) {
            Mode = 1;
        }
        if(clickedStatsButton) {
            Mode = 2;
        }


        BeginDrawing();
        ClearBackground(BLACK);

        if(Mode == 0) {
            //HomePageStuff
            DrawCircle((int)screenWidth / 2, (int)(screenHeight * 0.38), screenWidth / 3, WHITE);
            DrawText("Start", (int)(screenWidth / 2.7), (int)(screenHeight * 0.37), 100, BLACK);
        }
        if(Mode == 1) {
            //SettingsStuff
            DrawText("Settings", 100, 100, 50, WHITE);
        }
        if(Mode == 2) {
            //StatsMode
            DrawText("Stats", 100, 100, 50, WHITE);
        }

        //MenuBackgroung
        DrawRectangle((int)(screenWidth * 0.2), (int)(screenHeight * 0.90f), (int)(screenWidth  * 0.6), (int)(screenHeight * 0.07), WHITE);
        DrawCircle((int)(screenWidth * 0.2), (int)(screenHeight * 0.935f), (float)(screenHeight * (0.07 / 2)), WHITE);
        DrawCircle((int)(screenWidth * 0.8), (int)(screenHeight * 0.935f), (float)(screenHeight * (0.07 / 2)), WHITE);

        DrawRectangle((int)(screenWidth * 0.2), (int)(screenHeight * 0.90f) + 5, (int)(screenWidth  * 0.6), (int)(screenHeight * 0.07) - 10, BLACK);
        DrawCircle((int)(screenWidth * 0.2), (int)(screenHeight * 0.935f), (float)(screenHeight * (0.07 / 2)) - 5, BLACK);
        DrawCircle((int)(screenWidth * 0.8), (int)(screenHeight * 0.935f), (float)(screenHeight * (0.07 / 2)) - 5, BLACK);

        //MenuIcons
        DrawTexture(HomeIcon, (int)(screenWidth - screenWidth / 2) - HomeIcon.width / 2, (int)(screenHeight * 0.935f) - HomeIcon.height / 2, WHITE);
        DrawLine(((int)(screenWidth - screenWidth / 2) - HomeIcon.width / 2) + 112, (int)(screenHeight * 0.935f) - HomeIcon.height / 2 + 15,
                 ((int)(screenWidth - screenWidth / 2) - HomeIcon.width / 2) + 112, (int)(screenHeight * 0.935f) + HomeIcon.height / 2 - 15, WHITE);
        DrawLine(((int)(screenWidth - screenWidth / 2) - HomeIcon.width / 2) - 15, (int)(screenHeight * 0.935f) - HomeIcon.height / 2 + 15,
                 ((int)(screenWidth - screenWidth / 2) - HomeIcon.width / 2) - 15, (int)(screenHeight * 0.935f) + HomeIcon.height / 2 - 15, WHITE);

        DrawTexture(SettingsIcon, (int)(screenWidth - screenWidth * 0.30) - HomeIcon.width / 2, (int)(screenHeight * 0.935f) - SettingsIcon.height / 2, WHITE);
        DrawLine(((int)(screenWidth - screenWidth * 0.30) - SettingsIcon.width / 2) + 112, (int)(screenHeight * 0.935f) - SettingsIcon.height / 2 + 15,
                 ((int)(screenWidth - screenWidth * 0.30) - SettingsIcon.width / 2) + 112, (int)(screenHeight * 0.935f) + SettingsIcon.height / 2 - 15, WHITE);
        DrawLine(((int)(screenWidth - screenWidth * 0.30) - SettingsIcon.width / 2) - 15, (int)(screenHeight * 0.935f) - SettingsIcon.height / 2 + 15,
                 ((int)(screenWidth - screenWidth * 0.30) - SettingsIcon.width / 2) - 15, (int)(screenHeight * 0.935f) + SettingsIcon.height / 2 - 15, WHITE);

        DrawTexture(StatsIcon, (int)(screenWidth - screenWidth * 0.70) - HomeIcon.width / 2, (int)(screenHeight * 0.935f) - HomeIcon.height / 2, WHITE);
        DrawLine(((int)(screenWidth - screenWidth * 0.70) - StatsIcon.width / 2) + 112, (int)(screenHeight * 0.935f) - StatsIcon.height / 2 + 15,
                 ((int)(screenWidth - screenWidth * 0.70) - StatsIcon.width / 2) + 112, (int)(screenHeight * 0.935f) + StatsIcon.height / 2 - 15, WHITE);
        DrawLine(((int)(screenWidth - screenWidth * 0.70) - StatsIcon.width / 2) - 15, (int)(screenHeight * 0.935f) - StatsIcon.height / 2 + 15,
                 ((int)(screenWidth - screenWidth * 0.70) - StatsIcon.width / 2) - 15, (int)(screenHeight * 0.935f) + StatsIcon.height / 2 - 15, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
