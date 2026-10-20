#include <raylib.h>

#define GAME_WIDTH 320
#define GAME_HEIGHT 320

static void DrawGame(RenderTexture2D target)
{
    float scale = (float)GetScreenWidth() / GAME_WIDTH;

    float scaleY = (float)GetScreenHeight() / GAME_HEIGHT;
    if (scaleY < scale) scale = scaleY;

    Rectangle src = {
        0, 0,
        (float)target.texture.width,
        (float)-target.texture.height
    };

    Rectangle dst = {
        (GetScreenWidth() - GAME_WIDTH * scale) / 2,
        (GetScreenHeight() - GAME_HEIGHT * scale) / 2,
        GAME_WIDTH * scale,
        GAME_HEIGHT * scale
    };

    DrawTexturePro(target.texture, src, dst,
                   (Vector2){0, 0}, 0, WHITE);
}

int main()
{
  InitWindow(1080, 1080, "CD");
  SetTargetFPS(60);
  RenderTexture2D target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);
  SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
  
  // Variables
  Texture2D store_tile = LoadTexture("../assets/map/store/store_tile.png");
  int TilePosX = 0;
  int TilePosY = 0;

  while (!WindowShouldClose()) {
    BeginTextureMode(target);
    ClearBackground(BLACK);
    for (TilePosX = 0; TilePosX < GAME_WIDTH; TilePosX += 16) {
      for (TilePosY = 0; TilePosY < GAME_HEIGHT; TilePosY += 16) {
        DrawTexture(store_tile, TilePosX, TilePosY, RAYWHITE);
      }
    }
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawGame(target);
    EndDrawing();
  }
  UnloadRenderTexture(target);
  UnloadTexture(store_tile);
  return 0;
}
