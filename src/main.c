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
  Texture2D store_table = LoadTexture("../assets/map/store/store-table.png");
  Texture2D monitor = LoadTexture("../assets/map/store/Monitor.png");
  Texture2D mouse = LoadTexture("../assets/map/store/mouse.png");
  Texture2D laptop = LoadTexture("../assets/map/store/laptop.png");
  Texture2D store_walls = LoadTexture("../assets/map/store/store-walls.png");
  int PosX = 0;
  int PosY = 0;

  while (!WindowShouldClose()) {
    int TableCount = 0;

    BeginTextureMode(target);
    ClearBackground(BLACK);
    for (PosX = 0; PosX < GAME_WIDTH; PosX += 16) {
      for (PosY = 0; PosY < GAME_HEIGHT; PosY += 16) {
        DrawTexture(store_tile, PosX, PosY, RAYWHITE);
      }
    }
    for (PosX = 45; PosX < GAME_WIDTH; PosX += 145) {
      for (PosY = 150;PosY < GAME_HEIGHT; PosY += 50) {
        if (TableCount < 5 && PosY <= 200) {
          DrawTexture(store_table, PosX, PosY, RAYWHITE);
          TableCount++;
        }
      }
    }
    DrawTexture(monitor, 65, 130, RAYWHITE);
    DrawTexture(mouse, 100, 155, RAYWHITE);
    DrawTexture(laptop, 70, 185, RAYWHITE);

    DrawTexture(monitor, 210, 130, RAYWHITE);
    DrawTexture(mouse, 245, 155, RAYWHITE);
    DrawTexture(laptop, 215, 185, RAYWHITE);
    DrawTexture(store_walls, 0, 0, RAYWHITE);
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawGame(target);
    EndDrawing();
  }
  UnloadRenderTexture(target);
  UnloadTexture(store_tile);
  UnloadTexture(store_table);
  UnloadTexture(monitor);
  UnloadTexture(mouse);
  UnloadTexture(laptop);
  UnloadTexture(store_walls);
  return 0;
}
