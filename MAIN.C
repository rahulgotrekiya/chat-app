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
void printLine(void);

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
	int choice;

	userCount = 0;
	msgCount = 0;
	strcpy(currentUser, "");

	while(1) {
		showMainMenu();
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				break;
			case 2:
				registerUser();
				break;
			case 3:
				clearScreen();
				gotoxy(36, 12);
				printf("Goodbye !");
				gotoxy(30, 12);
				pressAnyKey();
				exit(0);
			default:
				printf("\nInvalid choice !");
				pressAnyKey();
		}
	}

	return 0;
}

/*
	Menu
*/

void showMainMenu(void) {
	clearScreen();
	printf("\n");
	gotoxy(25, 1);
	printLine();
	gotoxy(33, 2);
	printf("SIMPLE CHAT SYSTEM\n");
	gotoxy(25, 3);
	printLine();
	gotoxy(25, 4);
	printf("Total Users: %d\n", userCount);
	gotoxy(25, 5);
	printf("Total Messages: %d\n", msgCount);
	gotoxy(25, 6);
	printLine();
	gotoxy(25, 7);
	printf("1. Login\n");
	gotoxy(25, 8);
	printf("2. Register New User\n");
	gotoxy(25, 9);
	printf("3. Exit\n");
	gotoxy(25, 10);
	printLine();
}

/*
	User Management Functions
*/
void registerUser(void) {
	char username[20], password[15], confirm[15];
	int i;

	clearScreen();
	gotoxy(25, 1);
	printLine();
	gotoxy(33, 2);
	printf("SIMPLE CHAT SYSTEM\n");
	gotoxy(25, 3);
	printLine();

	if(userCount >= 20) {
		printf("\n    			  Sorry! Maximum user reached.\n");
		pressAnyKey();
		return;
	}

	printf("Enter username: ");
	fflush(stdin);
	gets(username);

	// Check if username already exist
	for(i = 0; i < userCount; i++) {
		if(strcmp(users[i].username, username) == 0) {
			printf("\nUsername aready exist! Try another.\n");
			pressAnyKey();
			return;
		}
	}

	if(strlen(username) < 3) {
		printf("\nUsername must be at least 3 characters!.\n");
		pressAnyKey();
		return;
	}

	printf("Enter password: ");
	gets(password);

	if(strlen(password) < 3) {
		printf("\nPassword must be at least 3 characters!.\n");
		pressAnyKey();
		return;
	}

	printf("Confirm password: ");
	gets(confirm);

	if(strcmp(password, confirm) != 0) {
		printf("\nPasswords don't match!.\n");
		pressAnyKey();
		return;
	}

	printf("Enter full name: ");
	gets(users[userCount].fullname);

	// Save user data
	strcpy(users[userCount].fullname, username);
	strcpy(users[userCount].password, password);
	userCount++;

	printf("\nUser registered successfully!\n");
	printf("Username: %s\n", username);

	pressAnyKey();
}

/*
	Helper Functions
*/
void clearScreen(void) {
	clrscr();
}

void printLine(void) {
	printf("--------------------------------\n");
}

void pressAnyKey(void) {
	printf("\nPress any key to continue...");
	getch();
}