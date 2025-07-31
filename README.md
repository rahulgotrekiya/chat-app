# Simple Chat System

A terminal-based chat application written in C, created as part of my programming studies to demonstrate fundamental C programming concepts.

## 📚 Educational Purpose

**⚠️ This project is part of my programming studies and demonstrates essential C programming concepts.**

This application helps practice:
- **Data Structures**: Structures (`struct User`, `struct Message`)
- **File I/O Operations**: Reading from and writing to files
- **String Manipulation**: Using string functions like `strcmp()`, `strcpy()`, `strlen()`
- **Functions**: Function prototypes, definitions, and calling
- **Control Structures**: Loops, conditional statements, switch cases
- **Arrays**: Working with arrays of structures
- **Memory Management**: Basic understanding of variable scope
- **User Input/Output**: Console-based I/O operations
- **Program Flow Control**: Menu-driven programming

## ⚠️ Important Disclaimers

### Not for Real-World Usage
This application is **NOT intended for real-world deployment** due to several limitations:

1. **Data Storage**: Uses plain text `.dat` files instead of secure databases
2. **Security Concerns**:
   - Passwords are stored in plain text without encryption
   - No input validation for buffer overflow protection
   - No secure authentication mechanisms
   - File permissions are not handled securely
3. **Platform Dependency**: Built specifically for Turbo C compiler
4. **Limited Scalability**: Hard-coded limits (20 users, 50 messages)
5. **No Network Functionality**: Local terminal-based operation only

### Compiler Compatibility
This project was developed using **Turbo C 3.0** and may not compile or run correctly with modern C compilers due to:
- Use of deprecated functions (`gets()`, `clrscr()`, `gotoxy()`, `getch()`)
- Non-standard header files (`conio.h`)
- Platform-specific implementations

## 🚀 Features

- **User Registration & Login System**
- **Message Sending & Receiving**
- **User Management**
- **Message History Viewing**
- **System Statistics**
- **Data Persistence** (using file storage)
- **Password Masking** (displays asterisks)
- **Unread Message Counter**

## 📁 Project Structure

```
Simple-Chat-System/
│
├── main.c                 # Main source code file
├── data/
│   ├── users.dat         # User data storage (plain text)
│   └── messages.dat      # Message data storage (plain text)
└── README.md             # This file
```

## 🛠️ How to Run in Turbo C

### Prerequisites
- Turbo C 3.0 or compatible DOS-based C compiler
- DOS environment or DOSBox emulator

### Steps to Compile and Run

1. **Setup Turbo C Environment**:
   - Install Turbo C 3.0 on your system
   - Or use DOSBox with Turbo C for modern systems

2. **Navigate to Turbo C Project Directory**:
    ```
    cd [TURBO_C_PATH]\BIN\project\
    ```
   **Note:** The exact path may vary depending on your Turbo C installation:
    - Windows: C:\TC\BIN\project\ or C:\TURBOC3\BIN\project\
    - DOSBox: C:\TC\BIN\project\
    - Other installations: [Your_TC_Path]\BIN\project\

4. **Clone the Repository**:
   ```
   git clone https://github.com/rahulgotrekiya/chat-app/ chat
   ```
   Or manually create the directory structure:
   ```
   [TURBO_C_PATH]\BIN\project\chat\
   ```

5. **⚠️ IMPORTANT - Create Data Directory**:
   The `data` folder is **mandatory** for the application to work:
   ```
   [TURBO_C_PATH]\BIN\project\chat\data\
   ```
   **Note**: If the path `project/chat/data` does not exist, the application will NOT be able to create or save the `.dat` files, and data persistence will fail.

6. **Verify Directory Structure**:
   Ensure your folder structure looks like this:
   ```
   C:\TC\BIN\project\chat\
   ├── main.c
   └── data/          ← This folder MUST exist
   ```

7. **Compile in Turbo C**:
   - Open Turbo C
   - Press `Alt + F` → `Open` → Navigate to your `main.c` file
   - Press `Ctrl + F9` to compile and run
   - Or use menu: `Compile` → `Make EXE file`

8. **Run the Application**:
   - If compilation successful, press `Ctrl + F9` to run
   - Or run the generated `.exe` file from DOS prompt

### Alternative for Modern Systems

If you want to run this on modern systems:

1. **Using DOSBox**:
   - Install DOSBox emulator
   - Mount Turbo C directory
   - Follow the above compilation steps

2. **Code Adaptation** (for learning):
   - Replace `conio.h` functions with standard alternatives
   - Use `system("cls")` instead of `clrscr()`
   - Implement custom `gotoxy()` function
   - Replace `getch()` with `getchar()`
   - Use `fgets()` instead of deprecated `gets()`

## 🎯 How to Use

1. **First Run**: Register a new user account
2. **Login**: Use your credentials to access the chat system
3. **Send Messages**: Choose recipients from registered users
4. **View Messages**: Check your inbox for received messages
5. **Statistics**: View system and personal usage statistics

## 📝 Sample Data Format

### users.dat
```
2
user1 1111 Test User One
user2 1111 Test User Two
```

### messages.dat
```
3
user1 user2 1 Hi ! this is test message !!!
user1 user2 1 Hi 
user2 user1 0 Hi user 1
```

## 🎓 Learning Outcomes

After studying and working with this code, one can gain practical experience in:

- Structuring a complete C program
- Implementing user authentication systems
- File-based data persistence
- Menu-driven program design
- Error handling and input validation
- Modular programming with functions
- Working with arrays of structures

## 🔧 Possible Enhancements (Learning Exercises)

This project can be extended by adding:

1. **Message Categories** (Personal, Group, Broadcast)
2. **User Profiles** with additional information
3. **Message Search Functionality**
4. **Data Encryption** for passwords
5. **Export/Import Features**
6. **Better Input Validation**
7. **Color-coded Interface** (using Turbo C graphics)

## 📄 License

This project is created for educational purposes. Feel free to use, modify, and distribute for learning and teaching C programming concepts.

## 👨‍💻 Author

**Rahul Gotrekiya**  
GitHub: [@rahulgotrekiya](https://github.com/rahulgotrekiya)  
Date: 28/07/2025

---

**Remember**: This is a learning project. For real-world applications, consider using modern programming languages, secure databases, encryption, and proper security practices.
