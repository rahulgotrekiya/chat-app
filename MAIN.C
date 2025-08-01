/*
	File: main.c
	Compiler: Turbo C 3.0
	Description: A simple terminal-based chat application demonstrating
		     fundamental C programming concepts for college students.

	Author: Rahul Gotrekiya
	Date: 28/07/2025
	GitHub: @rahulgotrekiya
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
struct Message messages[50];
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
void showStats(void);
int countUnreadMessages(void);
void getPassword(char password[]);

int main()
{
	int choice;

	loadData();

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
				showStats();
				break;
			case 0:
				clearScreen();
				saveData();
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
	Menu functions
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
	printf("3. View system Statistics\n");
	gotoxy(25, 10);
	printf("0. Exit\n");
	gotoxy(25, 11);
	printLine();
}
void showChatMenu(void) {
	int choice, unreadCount;

	while(1) {
		unreadCount = countUnreadMessages();


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
		if(unreadCount > 0) {
			printf("You have %d unread messages!\n", unreadCount);
			gotoxy(25, 6);
		}

		printLine();
		gotoxy(25, 7);
		printf("1. Send Message\n");
		gotoxy(25, 8);
		printf("2. View My Messages\n");
		gotoxy(25, 9);
		printf("3. View All Users\n");
		gotoxy(25, 10);
		printf("4. View Your Statistics\n");
		gotoxy(25, 11);
		printf("0. Logout\n");
		gotoxy(25, 12);
		printLine();

		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				sendMessage();
				break;
			case 2:
				viewMessages();
				break;
			case 3:
				viewAllUsers();
				break;
			case 4:
				showStats();
				break;
			case 0:
				saveData();
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
	getPassword(password);

	if(strlen(password) < 3) {
		printf("\nPassword must be at least 3 characters!.\n");
		pressAnyKey();
		return;
	}

	printf("\nConfirm password: ");
	getPassword(confirm);

	if(strcmp(password, confirm) != 0) {
		printf("\nPasswords don't match!.\n");
		pressAnyKey();
		return;
	}

	printf("\nEnter full name: ");
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
		getPassword(password);

		// Check login credentials
		for(i = 0; i < userCount; i++) {
			if(strcmp(users[i].username, username) == 0 &&
			   strcmp(users[i].password, password) == 0) {
				strcpy(currentUser, username);
				printf("\nLogin successful!\n");
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
	Messaging Functions
*/
void sendMessage(void) {
	char receiver[20], text[100];

	clearScreen();
	printf("\n");
	gotoxy(25, 1);
	printLine();
	gotoxy(35, 2);
	printf("SEND MESSAGE\n");
	gotoxy(25, 3);
	printLine();

	if(msgCount >= 50) {
		printf("Message storage full!\n");
		pressAnyKey();
		return;
	}

	printf("Enter receiver username: ");
	fflush(stdin);
	gets(receiver);

	// Check if receiver exists
	if(findUser(receiver) == -1) {
		printf("\nUser '%s' not found!\n", receiver);
		pressAnyKey();
		return;
	}

	// Check self-messaging
	if(strcmp(receiver, currentUser) == 0) {
		printf("\nYou Cannot send messae to yourself!\n");
		pressAnyKey();
		return;
	}

	printf("Enter your message: ");
	gets(text);

	if(strlen(text) == 0) {
		printf("\nMessage cannot be empty!\n");
		pressAnyKey();
		return;
	}

	// store messge
	strcpy(messages[msgCount].sender, currentUser);
	strcpy(messages[msgCount].receiver, receiver);
	strcpy(messages[msgCount].text, text);
	messages[msgCount].isRead = 0;
	msgCount++;

	printf("\nMessage sent to %s!\n", receiver);
	pressAnyKey();
}

void viewMessages(void) {
	int i, found = 0, unread = 0;

	clearScreen();
	printf("\n");
	gotoxy(25, 1);
	printLine();
	gotoxy(35, 2);
	printf("YOUR MESSAGES\n");
	gotoxy(25, 3);
	printLine();
	gotoxy(25, 4);
	printf("Message for: %s\n", currentUser);
	gotoxy(25, 5);
	printLine();

	// Show receied messages
	printf("RECEIVED MESSAGE\n");
	printLine();
	for(i = 0; i < msgCount; i++) {
		if(strcmp(messages[i].receiver, currentUser) == 0) {
			found++;
			printf("[%d] From: %s\n", found, messages[i].sender);
			printf("    Message: %s\n", messages[i].text);
			if(messages[i].isRead == 0) {
				printf("    Status: NEW\n");
				messages[i].isRead = 1; // mark as read
				unread++;
			} else {
				printf("    Status: Read\n");
			}
			printLine();
		}
	}

	if(found == 0){
		printf("No messages received.\n");
	}

	// Show sent mesages
	printf("\nSENT MESSAGE\n");
	printLine();
	found = 0;
	for(i = 0; i < msgCount; i++) {
		if(strcmp(messages[i].sender, currentUser) == 0) {
			found++;
			printf("[%d] To: %s\n", found, messages[i].receiver);
			printf("    Message: %s\n", messages[i].text);
			printf("    Status: %s\n", messages[i].isRead ? "Read" : "Unread");
			printLine();
		}
	}

	if(found == 0){
		printf("No messages sent.\n");
	}

	if(unread > 0){
		printf("\n%d new messages marked as read.\n", unread);
	}

	pressAnyKey();
}

void viewAllUsers(void) {
	int i;

	clearScreen();
	printf("\n");
	gotoxy(25, 1);
	printLine();
	gotoxy(35, 2);
	printf("ALL USERS\n");
	gotoxy(25, 3);
	printLine();

	if(userCount == 0) {
		printf("No users registered.\n");
	} else {
		printf("Total Users: %d\n\n", userCount);
		for(i = 0; i < userCount; i++) {
			printf("[%d] Username: %s\n", i+1, users[i].username);
			printf("    Full Name: %s\n", users[i].fullname);
			if(strcmp(users[i].username, currentUser) == 0) {
				printf("    Status: YOU\n");
			}
			printLine();
		}
	}
	pressAnyKey();
}

void showStats(void) {
	int i, totalSent = 0, totalReceived = 0;

	clearScreen();
	printf("\n");
	gotoxy(25, 1);
	printLine();
	gotoxy(32, 2);
	printf("SYSTEM STATISTICS\n");
	gotoxy(25, 3);
	printLine();

	printf("=== Overall Statistics ===\n");
	printf("Total Users: %d\n", userCount);
	printf("Total Messages: %d\n", msgCount);
	printf("Max Users Allowed: 20\n");
	printf("Max Messages Allowed: 100\n");
	printLine();

	if(strlen(currentUser) > 0) {
		/* Count messages for current user */
		for(i = 0; i < msgCount; i++) {
			if(strcmp(messages[i].sender, currentUser) == 0) {
				totalSent++;
			}
			if(strcmp(messages[i].receiver, currentUser) == 0) {
				totalReceived++;
			}
		}

		printf("=== Your Statistics ===\n");
		printf("Messages Sent: %d\n", totalSent);
		printf("Messages Received: %d\n", totalReceived);
		printf("Unread Messages: %d\n", countUnreadMessages());
	}

	pressAnyKey();
}

int countUnreadMessages(void) {
	int i, count = 0;
	
	for(i = 0; i < msgCount; i++) {
		if(strcmp(messages[i].receiver, currentUser) == 0 && messages[i].isRead == 0) {
			count++;
		}
	}
	return count;
}

/*
	File Functions
*/
void saveData(void) {
	FILE *userFile, *msgFile;
	int i;

	// Save users
	userFile = fopen("project/chat/data/users.dat", "w");
	if(userFile != NULL) {
		fprintf(userFile, "%d\n", userCount);
		for(i = 0; i < userCount; i++) {
			fprintf(userFile, "%s %s %s\n",
				users[i].username,
				users[i].password,
				users[i].fullname);
		}
		fclose(userFile);
	}

	// Save messages
	msgFile = fopen("project/chat/data/messages.dat", "w");
	if(msgFile != NULL) {
		fprintf(msgFile, "%d\n", msgCount);
		for(i = 0; i < msgCount; i++) {
			fprintf(msgFile, "%s %s %d %s\n",
				messages[i].sender,
				messages[i].receiver,
				messages[i].isRead,
				messages[i].text);
		}
		fclose(msgFile);
	}
}

void loadData(void) {
	FILE *userFile, *msgFile;
	int i;

	// Load users
	userFile = fopen("project/chat/data/users.dat", "r");
	if(userFile != NULL) {
		fscanf(userFile, "%d", &userCount);
		for(i = 0; i < userCount && i < 20; i++) {
			fscanf(userFile, "%s %s %s",
				users[i].username,
				users[i].password,
				users[i].fullname);
		}
		fclose(userFile);
	} else {
		userCount = 0;
	}

	// Load messages
	msgFile = fopen("project/chat/data/messages.dat", "r");
	if(msgFile != NULL) {
		fscanf(msgFile, "%d", &msgCount);
		for(i = 0; i < msgCount && i < 50; i++) {
			fscanf(msgFile, "%s %s %d",
				messages[i].sender,
				messages[i].receiver,
				&messages[i].isRead);
			fgets(messages[i].text, 100, msgFile); // Read rest of lines
			// Remove newline from message text
			if(messages[i].text[0] == ' ') {
				strcpy(messages[i].text, messages[i].text + 1);
			}
			if(messages[i].text[strlen(messages[i].text) - 1] == '\n') {
				messages[i].text[strlen(messages[i].text) - 1] = '\0';
			}
		}
		fclose(msgFile);
	} else {
		msgCount = 0;
	}
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

void getPassword(char password[]) {
	char ch;
	int i = 0;

	while(1) {
		ch = getch();

		if(ch == '\r'){
			password[i] = '\0';
			break;
		} else if(ch == '\b') {
			if(i > 0) {
				i--;
				printf("\b \b");
			}
		} else {
			password[i++] = ch;
			printf("*");
		}
	}
}

