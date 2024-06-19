#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "Winmm.lib")

int main() {
	char note = 'a';

	cout << "-PRESS Z-";
	note = _getch();
	system("cls");

	while (!(note == char(27))) {
		if (note == 'z') {
			PlaySound(TEXT("piano-a"), NULL, SND_ASYNC);
		}

		if (note == 'x') {
			PlaySound(TEXT("piano-b"), NULL, SND_ASYNC);
		}

		if (note == 'c') {
			PlaySound(TEXT("piano-c"), NULL, SND_ASYNC);
		}

		if (note == 'v') {
			PlaySound(TEXT("piano-d"), NULL, SND_ASYNC);
		}

		if (note == 'b') {
			PlaySound(TEXT("piano-e"), NULL, SND_ASYNC);
		}

		if (note == 'n') {
			PlaySound(TEXT("piano-f"), NULL, SND_ASYNC);
		}

		if (note == 'm') {
			PlaySound(TEXT("piano-g"), NULL, SND_ASYNC);
		}

		note = _getch();
	}

	return 0;
}