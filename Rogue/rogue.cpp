#include "layout.h"

int main() {
	srand(time(NULL));
	
	t_RoomList rooms;
	t_Player player1;

	initRooms(rooms);
	initPlayerPosition(rooms, player1);
	initStairPosition(rooms, player1);
	generatePath(rooms, player1);
	printRooms(rooms);
	return 0;
}