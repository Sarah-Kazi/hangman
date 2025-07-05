#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class HangmanGame {
private:
    vector<string> words;
    string currentWord;
    string guessedWord;
    vector<char> guessedLetters;
    int maxAttempts;
    int currentAttempts;
    bool gameWon;
    
    
    vector<string> hangmanStages = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };

public:
    HangmanGame() {
        maxAttempts = 6;
        initializeWords();
        srand(time(0));
    }
    
    void initializeWords() {
        words = {
            "PROGRAMMING", "COMPUTER", "ALGORITHM", "DATABASE", "NETWORK",
            "SOFTWARE", "HARDWARE", "INTERFACE", "FUNCTION", "VARIABLE",
            "CONSTANT", "LOOP", "ARRAY", "STRING", "POINTER",
            "CLASS", "OBJECT", "METHOD", "INHERITANCE", "POLYMORPHISM",
            "ABSTRACTION", "ENCAPSULATION", "EXCEPTION", "TEMPLATE", "NAMESPACE",
            "CINNAMON", "ELEPHANT", "BUTTERFLY", "MOUNTAIN", "OCEAN",
            "SUNSHINE", "RAINBOW", "LIBRARY", "UNIVERSITY", "TECHNOLOGY"
        };
    }
    
    void startNewGame() {
        currentWord = words[rand() % words.size()];
        guessedWord = string(currentWord.length(), '_');
        guessedLetters.clear();
        currentAttempts = 0;
        gameWon = false;
        
        cout << "\n=== HANGMAN GAME ===\n";
        cout << "Try to guess the word before the hangman is complete!\n\n";
    }
    
    void displayGame() {
        system("cls"); 
        
        
        cout << hangmanStages[currentAttempts] << "\n\n";
        cout << "Word: ";
        for (char c : guessedWord) {
            cout << c << " ";
        }
        cout << "\n\n";
        
        cout << "Guessed letters: ";
        if (guessedLetters.empty()) {
            cout << "None";
        } else {
            for (char c : guessedLetters) {
                cout << c << " ";
            }
        }
        cout << "\n";
        
        cout << "Attempts remaining: " << (maxAttempts - currentAttempts) << "\n\n";
    }
    
    char getPlayerGuess() {
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        return toupper(guess);
    }
    
    bool isValidGuess(char guess) {
        if (guess < 'A' || guess > 'Z') {
            cout << "Please enter a valid letter (A-Z)!\n";
            return false;
        }
        
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You already guessed that letter! Try again.\n";
            return false;
        }
        
        return true;
    }
    
    void processGuess(char guess) {
        guessedLetters.push_back(guess);
        
        bool found = false;
        for (size_t i = 0; i < currentWord.length(); i++) {
            if (currentWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }
        
        if (!found) {
            currentAttempts++;
            cout << "Wrong guess! The letter '" << guess << "' is not in the word.\n";
        } else {
            cout << "Correct! The letter '" << guess << "' is in the word.\n";
        }
        
        
        if (guessedWord == currentWord) {
            gameWon = true;
        }
    }
    
    void displayResult() {
        cout << "\n";
        if (gameWon) {
            cout << "CONGRATULATIONS! You won! \n";
            cout << "The word was: " << currentWord << "\n";
        } else {
            cout << " GAME OVER! You lost! \n";
            cout << "The word was: " << currentWord << "\n";
        }
        cout << "\n";
    }
    
    bool playAgain() {
        char choice;
        cout << "Would you like to play again? (y/n): ";
        cin >> choice;
        return (toupper(choice) == 'Y');
    }
    
    void run() {
        bool continuePlaying = true;
        
        while (continuePlaying) {
            startNewGame();
            
            while (currentAttempts < maxAttempts && !gameWon) {
                displayGame();
                char guess = getPlayerGuess();
                
                if (isValidGuess(guess)) {
                    processGuess(guess);
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
            }
            
            displayGame();
            displayResult();
            continuePlaying = playAgain();
        }
        
        cout << "Thanks for playing Hangman! Goodbye!\n";
    }
    
    
    bool loadWordsFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Could not open file: " << filename << "\n";
            return false;
        }
        
        words.clear();
        string word;
        while (getline(file, word)) {
           
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
            
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        
        file.close();
        cout << "Loaded " << words.size() << " words from file.\n";
        return true;
    }
};

int main() {
    cout << "Welcome to Hangman!\n";
    
    HangmanGame game;
    
    
    game.run();
    
    return 0;
} 