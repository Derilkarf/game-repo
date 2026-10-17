#include "raylib.h"
#include "raymath.h"

typedef enum TextAllign {
  TEXT_ALIGN_LEFT = 0,
  TEXT_ALIGN_TOP = 0,
  TEXT_ALIGN_CENTRE = 1,
  TEXT_ALIGN_MIDDLE = 1,
  TEXT_ALIGN_RIGHT = 2,
  TEXT_ALIGN_BOTTOM = 2,
} TextAllign;

int main(void){
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "raylib testing");

  Rectangle textContainerRect = (Rectangle){
    (float)screenWidth/2 - (float)screenWidth/4,
    (float)screenHeight/2 - (float)screenHeight/3,
    (float)screenWidth/2, (float)screenHeight * 2/3
  };

  const char *textAllignNameH[] = { "Left", "Centre", "Right" };
  const char *textAllignNameV[] = { "Top", "Middle", "Bottom" };

  int wordIndex = 0;
  int wordCount = 0;
  char **words = TextSplit("Testing Raylib library to study its behavior", ' ', &wordCount);

  int fontSize = 30;

  Font font = GetFontDefault();

  TextAllign hAllign = TEXT_ALIGN_CENTRE;
  TextAllign vAllign = TEXT_ALIGN_MIDDLE;

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {

    if (IsKeyPressed(KEY_LEFT)) 
    {
      if(hAllign > 0) hAllign = hAllign - 1;
    }

    if (IsKeyPressed(KEY_RIGHT)) {
      hAllign = hAllign + 1;
      if (hAllign > 2) hAllign = 2;
    }

    if (IsKeyPressed(KEY_UP)){
      if (vAllign > 0) vAllign = vAllign - 1;
    }

    if (IsKeyPressed(KEY_DOWN)){
      vAllign = vAllign + 1;
      if (vAllign > 2) vAllign = 2;
    }

    if (wordCount > 0) wordIndex = (int)GetTime()%wordCount;
    else wordIndex = 0;
  
    BeginDrawing();

    ClearBackground(DARKGREEN);

    DrawText("Use Arrow Keys To Change text Allignment", 20, 20, 20, LIGHTGRAY);
    DrawText(TextFormat("Allignment: Horizontal = %s\nAllignment: Vertical = %s\n", textAllignNameH[hAllign], textAllignNameV[vAllign]), 20, 40, 20, LIGHTGRAY);

    DrawRectangleRec(textContainerRect, GREEN);

    Vector2 textSize = MeasureTextEx(font, words[wordIndex], (float)fontSize, fontSize*.1f);

    Vector2 textPos = (Vector2){
      textContainerRect.x + Lerp(0.0f, textContainerRect.width - textSize.x, ((float)hAllign)*0.5f),
      textContainerRect.y + Lerp(0.0f, textContainerRect.height - textSize.y, ((float)vAllign)*0.5f)
    };

    DrawTextEx(font, words[wordIndex], textPos, (float)fontSize, fontSize*.1f, RAYWHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
