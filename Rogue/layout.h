#ifndef layout_h
#define layout_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"

const int QuadrantDimX = 30, QuadrantDimY = 10, LinedRooms = 3, TotalDimX = LinedRooms * QuadrantDimX, TotalDimY = LinedRooms * QuadrantDimY, NumRooms = 9;

const char HWall = char(205), VWall = char(186), URCorner = char(187), ULCorner = char(201), LLCorner = char(200), LRCorner = char(188), EmptyCell = ' ', PlayerToken = '@', StairToken = '%', PathToken = '#';

enum cellContent { horizontalWall, verticalWall, upperRightCorner, upperLeftCorner, lowerLeftCorner, lowerRightCorner, emptyCell, playerChar, stair, path };

typedef cellContent t_RoomContent[QuadrantDimY][QuadrantDimX];

struct t_Room {
	int x = 0;
	int xOffset = 0;
	int y = 0;
	int yOffset = 0;
	t_RoomContent content;
	t_RoomContent lowerLayer;
	bool pathed = false;
	bool stair = false;
};

typedef t_Room t_RoomList[NumRooms];

void initRoom(t_Room& room);
void initRooms(t_RoomList rooms);
void printRooms(t_RoomList rooms);
void initPlayerPosition(t_RoomList rooms, t_Player& player1);
void initStairPosition(t_RoomList rooms, t_Player player1);
void generatePath(t_RoomList rooms, t_Player player1);

#endif