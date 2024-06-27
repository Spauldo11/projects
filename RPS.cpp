#include <iostream>
#include <cctype>
#include <time.h>
using namespace std;
void play_again();
/*
    This function is the main game loop for the rock, paper, scissors game.
    It takes user input for their choice of rock, paper, or scissors and then
    determines the outcome of the game based on the randomly generated computer
    choice. The function then prints the outcome of the game and either asks
    the user if they want to play again or ends the game.
*/
void play() {
    // Declare variables to store user input and the choices that result in a win, tie, or loss
    string input;
    string win;
    string tied;
    string loss;
    
    // Ask the user for their choice of rock, paper, or scissors
    cout << "Please make your choice; Rock, Paper, or Scissors: ";
    cin >> input;
    
    // Based on the user's input, determine the outcome of the game
    if (input == "R" || input == "r" || input == "Rock" || input == "rock") {
        // If the user picked rock, the computer will win with scissors
        win = "scissors";
        tied = "rock";
        loss = "paper";
    } else if (input == "P" || input == "p" || input == "Paper" || input == "paper") {
        // If the user picked paper, the computer will lose with rock
        win = "rock";
        tied = "paper";
        loss = "scissors";
    } else if (input == "S" || input == "s" || input == "Scissors" || input == "scissors") {
        // If the user picked scissors, the computer will lose with paper
        win = "paper";
        tied = "scissors";
        loss = "rock";
    } else {
        // If the user inputted something other than rock, paper, or scissors, tell them to try again
        cout << "Your input may have been mispelled or inputted incorreclty. Please try again\n";
        play(); // Recursively call the play function to allow the user to try again
        return; // Exit the function
    }
    
    // Generate a random number between 0 and 2 to determine the computer's choice
    srand(time(0));
    int outcome = rand() % 3;
    
    // Based on the outcome, determine the result of the game and print the outcome
    if (outcome == 0) {
        cout << "You won! Your opponent picked " << win << "\n";
       play_again();
    } else if (outcome == 1) {
        cout << "You tied! Your opponent picked " << tied << "\n";
       play_again();
    } else {
        cout << "You lost! Your opponent picked " << loss << "\n";
       play_again();
    }
    
    // Ask the user if they want to play again
    play_again();
}
/**
 * This function asks the user if they want to play again.
 * If the user inputs 'Y' or 'y', it calls the play function to start a new game.
 * If the user inputs 'N' or 'n', it prints a farewell message.
 * If the user inputs anything other than 'Y' or 'N', it asks the user to try again.
 */
void play_again() {
    // Declare a string variable to store the user's answer
    string ans;
    
    // Print a message asking the user if they want to play again
    cout << "Would you like to play again? Y/N\n";
    
    // Read the user's answer and store it in the ans variable
    cin >> ans;
    
    // Check the user's answer and take appropriate action
    if (ans == "y" || ans == "Y") {
        // If the user wants to play again, call the play function to start a new game
        play();
    } else if (ans == "n" || ans == "N") {
        // If the user does not want to play again, print a farewell message
        cout << "Okay, come back later!";
    } else {
        // If the user inputted something other than 'Y' or 'N', ask them to try again
        cout << "Please try again, you may have inputted the wrong answer\n";
        play_again();
    }
}
int main() {
     play();
return 0;
}