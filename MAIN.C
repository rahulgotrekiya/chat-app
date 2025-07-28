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
int loginUser(void);
void showChatMenu(void);
void sendMessage(void);
void viewMessages(void);
void viewAllUsers(void);
void saveData(void);
void loadData(void);
int findUser(char name[]);
void clearScreen(void);
void pressAnyKey(void);
void printLine(void);

int main()
{
	int choice;

	userCount = 1;
	msgCount = 0;
	strcpy(currentUser, "");

	// Add default user for testing
	strcpy(users[0].username, "test");
	strcpy(users[0].password, "1111");
	strcpy(users[0].fullname, "Test User");

	while(1) {
		showMainMenu();
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				if(loginUser()) {
					showChatMenu();
				}
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
void showChatMenu(void) {
	int choice;

	while(1) {
		clearScreen();
		printf("\n");
		gotoxy(25, 1);
		printLine();
		gotoxy(36, 2);
		printf("CHAT MENU\n");
		gotoxy(25, 3);
		printLine();
		gotoxy(25, 4);
		printf("Welcome, %s!\n", currentUser);
		gotoxy(25, 5);
		printLine();
		gotoxy(25, 6);
		printf("1. Send Message\n");
		gotoxy(25, 7);
		printf("2. View My Messages\n");
		gotoxy(25, 8);
		printf("3. View All Users\n");
		gotoxy(25, 9);
		printf("4. Logout\n");
		gotoxy(25, 10);
		printLine();

		printf("Ener choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("\nSend msg");
				pressAnyKey();
				break;
			case 2:
				printf("\nView msg");
				pressAnyKey();
				break;
			case 3:
				printf("\nView Users");
				pressAnyKey();
				break;
			case 4:
				strcpy(currentUser, "");
				printf("\nLogged out successfully!");
				pressAnyKey();
				return;
			default:
				printf("\nInvalid choice!");
				pressAnyKey();
		}
	}
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
	strcpy(users[userCount].username, username);
	strcpy(users[userCount].password, password);
	userCount++;

	printf("\nUser registered successfully!\n");
	printf("Username: %s\n", username);

	pressAnyKey();
}

int loginUser(void) {
	char username[20], password[15];
	int i, attempts;

	clearScreen();
	gotoxy(25, 1);
	printLine();
	gotoxy(36, 2);
	printf("USER LOGIN\n");
	gotoxy(25, 3);
	printLine();

	if(userCount == 0) {
		printf("\n    			    No users registered yet!\n");
		printf("\n    			     Please register first\n");
		pressAnyKey();
		return 0;
	}

	for(attempts = 0; attempts < 3; attempts++) {
		printf("Enter username: ");
		fflush(stdin);
		gets(username);

		printf("Enter password: ");
		gets(password);

		// Check login credentials
		for(i = 0; i < userCount; i++) {
			if(strcmp(users[i].username, username) == 0 &&
			   strcmp(users[i].password, password) == 0) {
				strcmp(currentUser, username);
				printf("\nLogin succesful!\n");
				printf("Welcome %s!\n", users[i].fullname);
				pressAnyKey();
				return 1;
			}
		}
		printf("\nInvalid username of password!\n");
		if(attempts < 2) {
			printf("Try again (%d attempts left) \n", 2-attempts);
			pressAnyKey();
			clearScreen();
			printf("\n");
			gotoxy(25, 1);
			printLine();
			gotoxy(36, 2);
			printf("USER LOGIN\n");
			gotoxy(25, 3);
			printLine();
		}
	}

	printf("Too many failed attempts!\n");
	pressAnyKey();
	return 0;
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

int findUser(char name[]) {

	int i;
	for(i = 0; i < userCount; i++) {
		if(strcmp(users[i].username, name) == 0) {
			return i;
		}
	}
	return -1;
}
