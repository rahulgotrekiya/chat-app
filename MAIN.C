/*
	File: main.c
	Compiler: Turbo C 3.0
	Description: A simple terminal-based chat application demonstrating
		fundamental C programming concepts for college students.

	Author: Rahul Gotrekiya
	Date: 28/07/2025
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/* Structure Definitions */
struct User {
	char username[20];
	char password[15];
	char fullname[30];
};

struct Message {
	char sender[20];
	char receiver[20];
	char text[100];
	int isRead;
};

/* Global Variables */
struct User users[20];
struct Message message[50];
int userCount = 0;
int msgCount = 0;
char currentUser[20];

/* Function Prototypes */
void showMainMenu(void);
void registerUser(void);
void loginUser(void);
void showChatMenu(void);
void sendMessage(void);
void viewMessages(void);
void viewAllUsers(void);
void saveData(void);
void loadData(void);
void findUser(char name[]);
void clearScreen(void);
void pressAnyKey(void);

/* Helper Functions */
void clearScreen(void) {
	clrscr();
}

void pressAnyKey(void) {
	printf("\nPress any key to continue...");
	getch();
}

void findUser(char name[]) {
	int i;
	for(i = 0; i < userCount; i++) {
		if(strcmp(users[i].username, name) == 0) {
			return i;
		}
	}
	return -1;
}

int main()
{
	clearScreen();
	printf("Chat application in c");
	pressAnyKey();
	return 0;
}
