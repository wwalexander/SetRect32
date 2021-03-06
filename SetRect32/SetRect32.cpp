// SetRect32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("The syntax of the command is incorrect.\n", stderr);
		return 1;
	}


	char *leftString = argv[1];
	char *end;
	long left = strtol(leftString, &end, 10);
	long top = strtol(end + 1, &end, 10);
	char *widthString = argv[2];
	long width = strtol(widthString, &end, 10);

	if (*end != 'x') {
		fputs("The syntax of the command is incorrect.\n", stderr);
		return 1;
	}

	long height = strtol(end + 1, &end, 10);

	if (*end != '\0') {
		fputs("The syntax of the command is incorrect.\n", stderr);
		return 1;
	}

	HWND consoleWindow = GetConsoleWindow();

	if (consoleWindow == NULL) {
		return 1;
	}

	HWND foregroundWindow;

	while (1) {
		foregroundWindow = GetForegroundWindow();

		if (foregroundWindow != NULL && foregroundWindow != consoleWindow) {
			break;
		}

		Sleep(0);
	}

	RECT foregroundWindowRect;

	if (GetWindowRect(
		foregroundWindow,
		&foregroundWindowRect
	) == FALSE) {
		return 1;
	}

	if (MoveWindow(
		foregroundWindow,
		left,
		top,
		width,
		height,
		TRUE
	) == FALSE) {
		return 1;
	}

	return 0;
}

