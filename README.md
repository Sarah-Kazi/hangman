# Hangman Game in C++

A simple, terminal-based hangmane game in c++.

### Compilation

#### Using MinGW-w64:
```bash
# Install MinGW-w64 if not already installed
# Download from: https://www.mingw-w64.org/
cd hangman-cpp
g++ -std=c++11 -Wall -Wextra -o hangman.exe hangman.cpp
./hangman.exe
```

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

