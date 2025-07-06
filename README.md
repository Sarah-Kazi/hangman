# Hangman Game in C++

A simple, terminal-based hangmane game in c++.

### Compilation

#### Using MinGW-w64:
```bash
# Install MinGW-w64 if not already installed
# Download from: https://www.mingw-w64.org/
cd hangman-cpp
g++ -o hangman.exe hangman.cpp
./hangman.exe
```
## Customization

### Using Custom Word List
Uncomment this line in `main()`:
```cpp
game.loadWordsFromFile("words.txt");
```

### Creating Word List
Create a text file with one word per line:
```
LALALA
HAHAHA
BABABA
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

