#include "layout.h"
#include "player.h"
using namespace std;

void initRoom(t_Room& room) {
	room.x = (rand() % (QuadrantDimX  - 20)) + 6;
	room.xOffset = ((rand()) % (QuadrantDimX  - room.x - 3)) + 1;
	room.y = (rand() % (QuadrantDimY - 8)) + 5;
	room.yOffset = ((rand()) % (QuadrantDimY - room.y - 3)) + 3;

	for (int i = 0; i < QuadrantDimY; i++) {
		for (int j = 0; j < QuadrantDimX ; j++) {
			if (j == room.xOffset && i == room.yOffset)
				room.content[i][j] = upperLeftCorner;
			else if (j == room.xOffset + room.x && i == room.yOffset)
				room.content[i][j] = upperRightCorner;
			else if ((i == room.yOffset || i == room.yOffset + room.y) && j > room.xOffset && j < room.xOffset + room.x)
				room.content[i][j] = horizontalWall;
			else if (j == room.xOffset + room.x && i == room.yOffset + room.y) 
				room.content[i][j] = lowerRightCorner; 
			else if (j == room.xOffset && i == room.yOffset + room.y)
				room.content[i][j] = lowerLeftCorner;
			else if ((j == room.xOffset || j == room.xOffset + room.x) && i > room.yOffset && i < room.yOffset + room.y)
				room.content[i][j] = verticalWall;
			else
				room.content[i][j] = emptyCell;
		}

		room.pathed = false;
	}
}

void initRooms(t_RoomList rooms) {

	for (int i = 0; i < NumRooms; i++) {

			initRoom(rooms[i]);
	}
}

void printRooms(t_RoomList rooms) {
	
	for (int i = 3; i < TotalDimY; i++) {
		for (int j = 0; j < TotalDimX; j++) {
			if (j == 0) {
				for (int k = 0; k < 60; k++)
					cout << " ";
			}
				
			if (i < QuadrantDimY && j < QuadrantDimX ) {
				switch (rooms[0].content[i][j]) {
				case 0:		
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}
			
			else if (i < 1 * QuadrantDimY && j < 2 * QuadrantDimX ) {
				switch (rooms[1].content[i][j - (QuadrantDimX)]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}			
			}

			else if (i < 1 * QuadrantDimY && j < 3 * QuadrantDimX ) {
				switch (rooms[2].content[i][j - (2* QuadrantDimX )]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}

			else if (i < 2 * QuadrantDimY && j < 1 * QuadrantDimX ) {
				switch (rooms[3].content[i - QuadrantDimY][j]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}

			else if (i < 2 * QuadrantDimY && j < 2 * QuadrantDimX ) {
				switch (rooms[4].content[i - QuadrantDimY][j - (QuadrantDimX)]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}

			else if (i < 2 * QuadrantDimY && j < 3 * QuadrantDimX ) {
				switch (rooms[5].content[i - QuadrantDimY][j - (2 * QuadrantDimX )]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}

			else if (i < 3 * QuadrantDimY && j < 1 * QuadrantDimX ) {
				switch (rooms[6].content[i - 2 * QuadrantDimY][j]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}

			else if (i < 3 * QuadrantDimY && j < 2 * QuadrantDimX ) {
				switch (rooms[7].content[i - 2 * QuadrantDimY][j - (QuadrantDimX )]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}

			else if (i < 3 * QuadrantDimY && j < 3 * QuadrantDimX ) {
				switch (rooms[8].content[i - 2 * QuadrantDimY][j - (2 * QuadrantDimX )]) {
				case 0:
					cout << HWall;
					break;
				case 1:
					cout << VWall;
					break;
				case 2:
					cout << URCorner;
					break;
				case 3:
					cout << ULCorner;
					break;
				case 4:
					cout << LLCorner;
					break;
				case 5:
					cout << LRCorner;
					break;
				case 6:
					cout << EmptyCell;
					break;
				case 7:
					cout << PlayerToken;
					break;
				case 8:
					cout << StairToken;
					break;
				case 9:
					cout << PathToken;
					break;
				}
			}
		}

		cout << endl;
	}

}

void initPlayerPosition(t_RoomList rooms, t_Player& player1) {
	player1.room = rand() % NumRooms;

	player1.xPlayer = rand() % (rooms[player1.room].x - 1) + 1 + rooms[player1.room].xOffset;
	player1.yPlayer = rand() % (rooms[player1.room].y - 1) + 1 + rooms[player1.room].yOffset;
	rooms[player1.room].content[player1.yPlayer][player1.xPlayer] = playerChar;
}

void initStairPosition(t_RoomList rooms, t_Player player1) {
	int stairRoom = player1.room, xStair, yStair;

	while (stairRoom == player1.room) {
		stairRoom = rand() % NumRooms;
		if (stairRoom != player1.room) {
			xStair = rand() % (rooms[stairRoom].x - 1) + 1 + rooms[stairRoom].xOffset;
			yStair = rand() % (rooms[stairRoom].y - 1) + 1 + rooms[stairRoom].yOffset;
			rooms[stairRoom].content[yStair][xStair] = stair;
			rooms[stairRoom].stair = true;
		}
	}
}

void generatePath(t_RoomList rooms, t_Player player1) {
	int stairRoom = 0, roomCounter = 0, direction = 0, moveDirection = 0, destinedRoom = 0, xPath = 0, yPath = 0, tmpRoom = 0;

	for (int i = 0; i < NumRooms; i++)
		if (rooms[i].stair)
			stairRoom = i;
	
	while ((!(rooms[player1.room].pathed) || !(rooms[stairRoom].pathed)) && ((roomCounter == 3 && !(rooms[0].pathed && rooms[4].pathed && rooms[6].pathed)) && (roomCounter == 5 && !(rooms[2].pathed && rooms[4].pathed && rooms[8].pathed)) && (roomCounter == 1 && !(rooms[0].pathed && rooms[4].pathed && rooms[2].pathed)) && (roomCounter == 7 && !(rooms[6].pathed && rooms[4].pathed && rooms[8].pathed)))) {
		do {
			destinedRoom = -1;
			if (rooms[roomCounter].stair || rooms[destinedRoom].pathed) {
				destinedRoom = -1;
				rooms[roomCounter].pathed = true;
				rooms[player1.room].pathed;
				do {
					direction = rand() % 4;
					
					switch (direction) {
					case 0:
						if ((roomCounter + 1) % 3 != 0) 
							destinedRoom = roomCounter + 1;
						break;
					case 1:
						destinedRoom = roomCounter + 3;
						break;
					case 2:
						if ((roomCounter + 1) % 3 != 1)
							destinedRoom = roomCounter - 1;
						break;
					case 3:
						destinedRoom = roomCounter - 3;
						break;
					}
				} while (destinedRoom < 0 || destinedRoom >= NumRooms || rooms[destinedRoom].pathed);

				switch (direction) {
				case 0:
					xPath = rooms[roomCounter].xOffset + rooms[roomCounter].x;
					yPath = rand() % (rooms[roomCounter].y - 1) + rooms[roomCounter].yOffset + 1;
					rooms[roomCounter].content[yPath][xPath] = path;
					xPath++;
					rooms[roomCounter].content[yPath][xPath] = path;
					while (xPath < QuadrantDimX - 1) {
						moveDirection = rand() % 8;
						if (yPath < rooms[destinedRoom].yOffset + 2) {
							if (moveDirection < 6)
								yPath++;
							else
								xPath++;
						}

						else if (yPath > rooms[destinedRoom].yOffset - 2) {
							if (moveDirection < 6)
								yPath--;
							else
								xPath++;
						}

						else {
							if (moveDirection < 4)
								xPath++;
							else if (moveDirection < 6)
								yPath++;
							else
								yPath--;
						}

						rooms[roomCounter].content[yPath][xPath] = path;
					}

					rooms[roomCounter].content[yPath][xPath++] = path;

					xPath = 0;

					while (xPath < rooms[destinedRoom].xOffset - 1) {
						rooms[destinedRoom].content[yPath][xPath] = path;

						moveDirection = rand() % 8;
						if (yPath < rooms[destinedRoom].yOffset + 2) {
							if (moveDirection < 6)
								yPath++;
							else
								xPath++;
						}

						else if (yPath > rooms[destinedRoom].yOffset - 2) {
							if (moveDirection < 6)
								yPath--;
							else
								xPath++;
						}

						else {
							if (moveDirection < 4)
								xPath++;
							else if (moveDirection < 6)
								yPath++;
							else
								yPath--;
						}
					}

					if (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y)
						while (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y - rand() % rooms[destinedRoom].y)
							rooms[destinedRoom].content[yPath--][xPath] = path;
					else if (yPath <= rooms[destinedRoom].yOffset)
						while (yPath <= rooms[destinedRoom].yOffset + rand() % rooms[destinedRoom].y)
							rooms[destinedRoom].content[yPath++][xPath] = path;

					rooms[destinedRoom].content[yPath][rooms[destinedRoom].xOffset - 1] = path;
					rooms[destinedRoom].content[yPath][rooms[destinedRoom].xOffset] = path;
					break;

				case 1:
					xPath = rand() % (rooms[roomCounter].x - 1) + rooms[roomCounter].xOffset + 1;
					yPath = rooms[roomCounter].yOffset + rooms[roomCounter].y;
					rooms[roomCounter].content[yPath][xPath] = path;
					cout << yPath << xPath << endl;
					yPath++;	
					rooms[roomCounter].content[yPath][xPath--] = path;
					cout << yPath << xPath << endl;
					while (yPath < QuadrantDimY - 1) {
						moveDirection = rand() % 8;
						if (xPath < rooms[destinedRoom].xOffset + 2) {
							if (moveDirection < 6)
								xPath++;
							else
								yPath++;
						}

						else if (xPath > rooms[destinedRoom].xOffset - 2) {
							if (moveDirection < 6)
								xPath--;
							else
								yPath++;
						}

						else {
							if (moveDirection < 4)
								yPath++;
							else if (moveDirection < 6)
								xPath++;
							else
								xPath--;
						}

						rooms[roomCounter].content[yPath][xPath] = path;
					}

					rooms[roomCounter].content[yPath][xPath++] = path;

					yPath = 0;

					while (yPath < rooms[destinedRoom].yOffset - 1) {
						rooms[destinedRoom].content[yPath][xPath] = path;

						moveDirection = rand() % 8;
						if (xPath < rooms[destinedRoom].xOffset + 2) {
							if (moveDirection < 6)
								xPath++;
							else
								yPath++;
						}

						else if (xPath > rooms[destinedRoom].xOffset - 2) {
							if (moveDirection < 6)
								xPath--;
							else
								yPath++;
						}

						else {
							if (moveDirection < 4)
								yPath++;
							else if (moveDirection < 6)
								xPath++;
							else
								xPath--;
						}
					}

					rooms[destinedRoom].content[rooms[destinedRoom].yOffset - 1][xPath] = path;

					if (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x) {
						while (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x - rand() % rooms[destinedRoom].x) {
							xPath--;
							rooms[destinedRoom].content[yPath][xPath] = path;
						}
					}
					else if (xPath <= rooms[destinedRoom].xOffset) {
						while (xPath <= rooms[destinedRoom].xOffset + rand() % rooms[destinedRoom].x) {
							xPath++;
							rooms[destinedRoom].content[yPath][xPath] = path;
						}
					}
					rooms[destinedRoom].content[rooms[destinedRoom].yOffset][xPath] = path;
					break;

				case 2:
					xPath = rooms[roomCounter].xOffset;
					yPath = rand() % (rooms[roomCounter].y - 1) + rooms[roomCounter].yOffset + 1;
					rooms[roomCounter].content[yPath][xPath] = path;
					xPath--;
					rooms[roomCounter].content[yPath][xPath] = path;
					while (xPath > 0) {
						moveDirection = rand() % 8;
						if (yPath < rooms[destinedRoom].yOffset + 2) {
							if (moveDirection < 6)
								yPath++;
							else
								xPath--;
						}

						else if (yPath > rooms[destinedRoom].yOffset - 2) {
							if (moveDirection < 6)
								yPath--;
							else
								xPath--;
						}

						else {
							if (moveDirection < 4)
								xPath--;
							else if (moveDirection < 6)
								yPath++;
							else
								yPath--;
						}

						rooms[roomCounter].content[yPath][xPath] = path;
					}

					rooms[roomCounter].content[yPath][xPath--] = path;

					xPath = QuadrantDimX - 1;

					while (xPath > rooms[destinedRoom].xOffset + rooms[destinedRoom].x) {
						rooms[destinedRoom].content[yPath][xPath] = path;

						moveDirection = rand() % 8;
						if (yPath < rooms[destinedRoom].yOffset + 2) {
							if (moveDirection < 6)
								yPath++;
							else
								xPath--;
						}

						else if (yPath > rooms[destinedRoom].yOffset - 2) {
							if (moveDirection < 6)
								yPath--;
							else
								xPath--;
						}

						else {
							if (moveDirection < 4)
								xPath--;
							else if (moveDirection < 6)
								yPath++;
							else
								yPath--;
						}
					}

					if (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y)
						while (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y - rand() % rooms[destinedRoom].y)
							rooms[destinedRoom].content[yPath--][xPath] = path;
					else if (yPath <= rooms[destinedRoom].yOffset)
						while (yPath <= rooms[destinedRoom].yOffset + rooms[destinedRoom].y + rand() % rooms[destinedRoom].y)
							rooms[destinedRoom].content[yPath++][xPath] = path;

					rooms[destinedRoom].content[yPath][rooms[destinedRoom].xOffset + rooms[destinedRoom].x] = path;
					break;

				case 3:
					xPath = rand() % (rooms[roomCounter].x - 1) + rooms[roomCounter].xOffset + 1;
					yPath = rooms[roomCounter].yOffset;
					rooms[roomCounter].content[yPath][xPath] = path;
					yPath--;
					rooms[roomCounter].content[yPath][xPath] = path;
					while (yPath > 0) {
						moveDirection = rand() % 8;
						if (xPath < rooms[destinedRoom].xOffset + 2) {
							if (moveDirection < 6)
								xPath++;
							else
								yPath--;
						}

						else if (xPath > rooms[destinedRoom].xOffset - 2) {
							if (moveDirection < 6)
								xPath--;
							else
								yPath--;
						}

						else {
							if (moveDirection < 4)
								yPath--;
							else if (moveDirection < 6)
								xPath++;
							else
								xPath--;
						}

						rooms[roomCounter].content[yPath][xPath] = path;
					}

					rooms[roomCounter].content[yPath][xPath++] = path;

					yPath = QuadrantDimY - 1;

					while (yPath > rooms[destinedRoom].yOffset + rooms[destinedRoom].y + 1) {
						rooms[destinedRoom].content[yPath][xPath] = path;

						moveDirection = rand() % 8;
						if (xPath < rooms[destinedRoom].xOffset + 2) {
							if (moveDirection < 6)
								xPath++;
							else
								yPath--;
						}

						else if (xPath > rooms[destinedRoom].xOffset - 2) {
							if (moveDirection < 6)
								xPath--;
							else
								yPath--;
						}

						else {
							if (moveDirection < 4)
								yPath--;
							else if (moveDirection < 6)
								xPath++;
							else
								xPath--;
						}
					}

					if (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x) {
						while (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x - rand() % rooms[destinedRoom].x) {
							xPath--;
							rooms[destinedRoom].content[yPath][xPath--] = path;
						}
					}

					else if (xPath <= rooms[destinedRoom].xOffset) {
						while (xPath <= rooms[destinedRoom].xOffset + rand() % rooms[destinedRoom].x) {
							xPath++;
							rooms[destinedRoom].content[yPath][xPath] = path;
						}
					}

					xPath--;
					rooms[destinedRoom].content[rooms[destinedRoom].yOffset + rooms[destinedRoom].y][xPath--] = path;
					break;
				}
			}

			roomCounter++;
			
		} while (!rooms[roomCounter - 1].pathed);

		tmpRoom = destinedRoom;
		destinedRoom = roomCounter;
		roomCounter = tmpRoom;
	}
	
	for (int roomCounter = 0; roomCounter < NumRooms; roomCounter++) {
		if (!rooms[roomCounter].pathed) {
			destinedRoom = -1;
			rooms[roomCounter].pathed = true;
			rooms[player1.room].pathed;
			do {
				direction = rand() % 4;

				switch (direction) {
				case 0:
					if ((roomCounter + 1) % 3 != 0)
						destinedRoom = roomCounter + 1;
					break;
				case 1:
					destinedRoom = roomCounter + 3;
					break;
				case 2:
					if ((roomCounter + 1) % 3 != 1)
						destinedRoom = roomCounter - 1;
					break;
				case 3:
					destinedRoom = roomCounter - 3;
					break;
				}
			} while (destinedRoom < 0 || destinedRoom >= NumRooms);

			switch (direction) {
			case 0:
				xPath = rooms[roomCounter].xOffset + rooms[roomCounter].x;
				yPath = rand() % (rooms[roomCounter].y - 1) + rooms[roomCounter].yOffset + 1;
				rooms[roomCounter].content[yPath][xPath] = path;
				xPath++;
				rooms[roomCounter].content[yPath][xPath] = path;
				while (xPath < QuadrantDimX - 1) {
					moveDirection = rand() % 8;
					if (yPath < rooms[destinedRoom].yOffset + 2) {
						if (moveDirection < 6)
							yPath++;
						else
							xPath++;
					}

					else if (yPath > rooms[destinedRoom].yOffset - 2) {
						if (moveDirection < 6)
							yPath--;
						else
							xPath++;
					}

					else {
						if (moveDirection < 4)
							xPath++;
						else if (moveDirection < 6)
							yPath++;
						else
							yPath--;
					}

					rooms[roomCounter].content[yPath][xPath] = path;
				}

				rooms[roomCounter].content[yPath][xPath++] = path;

				xPath = 0;

				while (xPath < rooms[destinedRoom].xOffset - 1) {
					rooms[destinedRoom].content[yPath][xPath] = path;

					moveDirection = rand() % 8;
					if (yPath < rooms[destinedRoom].yOffset + 2) {
						if (moveDirection < 6)
							yPath++;
						else
							xPath++;
					}

					else if (yPath > rooms[destinedRoom].yOffset - 2) {
						if (moveDirection < 6)
							yPath--;
						else
							xPath++;
					}

					else {
						if (moveDirection < 4)
							xPath++;
						else if (moveDirection < 6)
							yPath++;
						else
							yPath--;
					}
				}

				if (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y)
					while (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y - rand() % rooms[destinedRoom].y)
						rooms[destinedRoom].content[yPath--][xPath] = path;
				else if (yPath <= rooms[destinedRoom].yOffset)
					while (yPath <= rooms[destinedRoom].yOffset + rand() % rooms[destinedRoom].y)
						rooms[destinedRoom].content[yPath++][xPath] = path;

				rooms[destinedRoom].content[yPath][rooms[destinedRoom].xOffset - 1] = path;
				rooms[destinedRoom].content[yPath][rooms[destinedRoom].xOffset] = path;
				break;

			case 1:
				xPath = rand() % (rooms[roomCounter].x - 1) + rooms[roomCounter].xOffset + 1;
				yPath = rooms[roomCounter].yOffset + rooms[roomCounter].y;
				rooms[roomCounter].content[yPath][xPath] = path;
				cout << yPath << xPath << endl;
				yPath++;
				rooms[roomCounter].content[yPath][xPath--] = path;
				cout << yPath << xPath << endl;
				while (yPath < QuadrantDimY - 1) {
					moveDirection = rand() % 8;
					if (xPath < rooms[destinedRoom].xOffset + 2) {
						if (moveDirection < 6)
							xPath++;
						else
							yPath++;
					}

					else if (xPath > rooms[destinedRoom].xOffset - 2) {
						if (moveDirection < 6)
							xPath--;
						else
							yPath++;
					}

					else {
						if (moveDirection < 4)
							yPath++;
						else if (moveDirection < 6)
							xPath++;
						else
							xPath--;
					}

					rooms[roomCounter].content[yPath][xPath] = path;
				}

				rooms[roomCounter].content[yPath][xPath++] = path;

				yPath = 0;

				while (yPath < rooms[destinedRoom].yOffset - 1) {
					rooms[destinedRoom].content[yPath][xPath] = path;

					moveDirection = rand() % 8;
					if (xPath < rooms[destinedRoom].xOffset + 2) {
						if (moveDirection < 6)
							xPath++;
						else
							yPath++;
					}

					else if (xPath > rooms[destinedRoom].xOffset - 2) {
						if (moveDirection < 6)
							xPath--;
						else
							yPath++;
					}

					else {
						if (moveDirection < 4)
							yPath++;
						else if (moveDirection < 6)
							xPath++;
						else
							xPath--;
					}
				}

				rooms[destinedRoom].content[rooms[destinedRoom].yOffset - 1][xPath] = path;

				if (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x) {
					while (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x - rand() % rooms[destinedRoom].x) {
						xPath--;
						rooms[destinedRoom].content[yPath][xPath] = path;
					}
				}
				else if (xPath <= rooms[destinedRoom].xOffset) {
					while (xPath <= rooms[destinedRoom].xOffset + rand() % rooms[destinedRoom].x) {
						xPath++;
						rooms[destinedRoom].content[yPath][xPath] = path;
					}
				}
				rooms[destinedRoom].content[rooms[destinedRoom].yOffset][xPath] = path;
				break;

			case 2:
				xPath = rooms[roomCounter].xOffset;
				yPath = rand() % (rooms[roomCounter].y - 1) + rooms[roomCounter].yOffset + 1;
				rooms[roomCounter].content[yPath][xPath] = path;
				xPath--;
				rooms[roomCounter].content[yPath][xPath] = path;
				while (xPath > 0) {
					moveDirection = rand() % 8;
					if (yPath < rooms[destinedRoom].yOffset + 2) {
						if (moveDirection < 6)
							yPath++;
						else
							xPath--;
					}

					else if (yPath > rooms[destinedRoom].yOffset - 2) {
						if (moveDirection < 6)
							yPath--;
						else
							xPath--;
					}

					else {
						if (moveDirection < 4)
							xPath--;
						else if (moveDirection < 6)
							yPath++;
						else
							yPath--;
					}

					rooms[roomCounter].content[yPath][xPath] = path;
				}

				rooms[roomCounter].content[yPath][xPath--] = path;

				xPath = QuadrantDimX - 1;

				while (xPath > rooms[destinedRoom].xOffset + rooms[destinedRoom].x) {
					rooms[destinedRoom].content[yPath][xPath] = path;

					moveDirection = rand() % 8;
					if (yPath < rooms[destinedRoom].yOffset + 2) {
						if (moveDirection < 6)
							yPath++;
						else
							xPath--;
					}

					else if (yPath > rooms[destinedRoom].yOffset - 2) {
						if (moveDirection < 6)
							yPath--;
						else
							xPath--;
					}

					else {
						if (moveDirection < 4)
							xPath--;
						else if (moveDirection < 6)
							yPath++;
						else
							yPath--;
					}
				}

				if (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y)
					while (yPath >= rooms[destinedRoom].yOffset + rooms[destinedRoom].y - rand() % rooms[destinedRoom].y)
						rooms[destinedRoom].content[yPath--][xPath] = path;
				else if (yPath <= rooms[destinedRoom].yOffset)
					while (yPath <= rooms[destinedRoom].yOffset + rooms[destinedRoom].y + rand() % rooms[destinedRoom].y)
						rooms[destinedRoom].content[yPath++][xPath] = path;

				rooms[destinedRoom].content[yPath][rooms[destinedRoom].xOffset + rooms[destinedRoom].x] = path;
				break;

			case 3:
				xPath = rand() % (rooms[roomCounter].x - 1) + rooms[roomCounter].xOffset + 1;
				yPath = rooms[roomCounter].yOffset;
				rooms[roomCounter].content[yPath][xPath] = path;
				yPath--;
				rooms[roomCounter].content[yPath][xPath] = path;
				while (yPath > 0) {
					moveDirection = rand() % 8;
					if (xPath < rooms[destinedRoom].xOffset + 2) {
						if (moveDirection < 6)
							xPath++;
						else
							yPath--;
					}

					else if (xPath > rooms[destinedRoom].xOffset - 2) {
						if (moveDirection < 6)
							xPath--;
						else
							yPath--;
					}

					else {
						if (moveDirection < 4)
							yPath--;
						else if (moveDirection < 6)
							xPath++;
						else
							xPath--;
					}

					rooms[roomCounter].content[yPath][xPath] = path;
				}

				rooms[roomCounter].content[yPath][xPath++] = path;

				yPath = QuadrantDimY - 1;

				while (yPath > rooms[destinedRoom].yOffset + rooms[destinedRoom].y + 1) {
					rooms[destinedRoom].content[yPath][xPath] = path;

					moveDirection = rand() % 8;
					if (xPath < rooms[destinedRoom].xOffset + 2) {
						if (moveDirection < 6)
							xPath++;
						else
							yPath--;
					}

					else if (xPath > rooms[destinedRoom].xOffset - 2) {
						if (moveDirection < 6)
							xPath--;
						else
							yPath--;
					}

					else {
						if (moveDirection < 4)
							yPath--;
						else if (moveDirection < 6)
							xPath++;
						else
							xPath--;
					}
				}

				if (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x) {
					while (xPath >= rooms[destinedRoom].xOffset + rooms[destinedRoom].x - rand() % rooms[destinedRoom].x) {
						xPath--;
						rooms[destinedRoom].content[yPath][xPath--] = path;
					}
				}

				else if (xPath <= rooms[destinedRoom].xOffset) {
					while (xPath <= rooms[destinedRoom].xOffset + rand() % rooms[destinedRoom].x) {
						xPath++;
						rooms[destinedRoom].content[yPath][xPath] = path;
					}
				}

				xPath--;
				rooms[destinedRoom].content[rooms[destinedRoom].yOffset + rooms[destinedRoom].y][xPath--] = path;
				break;
			}
		}
	}
}