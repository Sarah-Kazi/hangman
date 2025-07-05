# Hangman Game in C++

A complete, interactive Hangman game implemented in C++ with ASCII art graphics and a comprehensive word list.

## Features

- Interactive console-based gameplay
- ASCII art hangman stages
- 100+ programming and general words included
- Replayability with different words
- Custom word list support
- Input validation and error handling
- Progress tracking with guessed letters and remaining attempts

## Game Rules

1. Computer randomly selects a word from the word list
2. You have 6 attempts to guess the word
3. For each incorrect guess, the hangman drawing progresses
4. Correct guesses reveal the letter(s) in the word
5. Win by guessing the complete word before the hangman is complete

## Compilation Instructions

### Prerequisites
- C++ compiler (GCC, Clang, or Visual Studio)
- Windows: MinGW-w64 or Visual Studio Build Tools
- Linux: GCC or Clang
- macOS: Xcode Command Line Tools

### Windows Compilation

#### Using MinGW-w64:
```bash
# Install MinGW-w64 if not already installed
# Download from: https://www.mingw-w64.org/

# Navigate to project directory
cd hangman-cpp

# Compile with GCC
g++ -std=c++11 -Wall -Wextra -o hangman.exe hangman.cpp

# Run the game
./hangman.exe
```

#### Using Visual Studio:
```bash
# Open Developer Command Prompt for VS
# Navigate to project directory
cd hangman-cpp

# Compile with MSVC
cl /EHsc /std:c++11 hangman.cpp /Fe:hangman.exe

# Run the game
hangman.exe
```

### Linux Compilation
```bash
# Install GCC if not already installed
sudo apt-get install g++  # Ubuntu/Debian
sudo yum install gcc-c++  # CentOS/RHEL

# Navigate to project directory
cd hangman-cpp

# Compile with GCC
g++ -std=c++11 -Wall -Wextra -o hangman hangman.cpp

# Run the game
./hangman
```

### macOS Compilation
```bash
# Install Xcode Command Line Tools if not already installed
xcode-select --install

# Navigate to project directory
cd hangman-cpp

# Compile with Clang
clang++ -std=c++11 -Wall -Wextra -o hangman hangman.cpp

# Run the game
./hangman
```

### Compiler Flags Explained
- `-std=c++11`: Use C++11 standard
- `-Wall`: Enable all common warning messages
- `-Wextra`: Enable extra warning messages
- `-o hangman.exe`: Specify output executable name

## How to Play

1. Start the game by running the compiled executable
2. Enter single letters (A-Z, case insensitive)
3. Watch the hangman drawing and word reveal progress
4. Complete the word or run out of attempts
5. Choose to start a new game

## Customization

### Using Custom Word List
Uncomment this line in `main()`:
```cpp
game.loadWordsFromFile("words.txt");
```

### Creating Word List
Create a text file with one word per line:
```
WORD1
WORD2
WORD3
```

### Modifying Game Settings
In the `HangmanGame` constructor:
- Change `maxAttempts` for different difficulty
- Modify words in `initializeWords()`

## File Structure
```
hangman-cpp/
├── hangman.cpp      # Main game source code
├── words.txt        # Extended word list
└── README.md        # This file
```

## Game Screenshots

### Game Start
```
=== HANGMAN GAME ===
Try to guess the word before the hangman is complete!

  +---+
  |   |
      |
      |
      |
      |
=========

Word: _ _ _ _ _ _ _ _ _ _

Guessed letters: None
Attempts remaining: 6

Enter a letter:
```

### During Gameplay
```
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========

Word: P _ _ _ _ _ _ _ _ _

Guessed letters: P E A
Attempts remaining: 3

Enter a letter:
```

### Game Win
```
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========

Word: P R O G R A M M I N G

Guessed letters: P R O G A M I N
Attempts remaining: 3

CONGRATULATIONS! You won!
The word was: PROGRAMMING
```

### Game Over
```
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========

Word: P _ _ _ _ _ _ _ _ _

Guessed letters: P E A S T U V W X Y Z
Attempts remaining: 0

GAME OVER! You lost!
The word was: PROGRAMMING
```

## Troubleshooting

### Compilation Errors
- Ensure C++11 compatible compiler is installed
- Check compiler is in system PATH
- Verify all source files are in the same directory

### Runtime Issues
- Windows: Game uses `system("cls")` for screen clearing
- Unix/Linux: Uncomment `system("clear")` in code
- Ensure terminal supports UTF-8 for proper display

## Technical Details
- Language: C++11
- Dependencies: Standard C++ library only
- Platform: Cross-platform (Windows, Linux, macOS) 