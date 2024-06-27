#include <iostream>
#include <cctype>
#include <time.h>
using namespace std;
string roulette[40] = {"00", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "Red", "Black"};
vector<int> choices;
vector<int> bet_amounts;
float balance = 0.0;
void play();
void bet();
void update_balance();
void update_balance() {
    string choices;
    std::cout << "Your balance is " << balance << ". Would you like to update your balance? (Y/N) ";
    std::cin >> choices;
    if (choices == "Y" || choices == "y") {
        int balance_add;
        cout << "How much would you like to add to your balance? ";
        cin >> balance_add;
        balance = balance + balance_add;
        update_balance();
    } else {
        cout << "On with the game\n";
    }
}

void bet() {
    int choice;
    int bet_amount;
    for(int i = 0; i < 40; i++) {
        std::cout << "[" << i << "]" << " " << roulette[i] << "\n";
    }
    std::cin >> choice;
    choices.push_back(choice);
    std::cout << "\n";
        std::cout << "Please enter how much you would like to bet on " << roulette[choice] << ": ";
        std::cin >> bet_amount;
        if (bet_amount > balance) {
            std::cout << "You do not have a great enough balance (" << balance << ") to play.\n";
            update_balance();
        } else {
            balance = balance - bet_amount;
        bet_amounts.push_back(bet_amount);
        std::cout << "\n";
        std::cout << "You have bet " << bet_amount << " on " << roulette[choice] << ".\n";
        }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        std::cout << "On with the game\n";
    }
}
void play() {
    for (int i = 0; i < choices.size(); i++) {
        choices.pop_back();
        bet_amounts.pop_back();
    }
    srand(time(0));
    int outcome = rand() % 38;
    std::cout << "Please select what you want to bet on\n";
    bet();
    for (int i = 0; i < choices.size(); i++) {
        if (outcome == choices[i]) {
            int balance_added = bet_amounts[i] * 35;
            balance = balance + balance_added;
            std::cout << "The ball landed on " << roulette[outcome] << "\n";
            std::cout << "One of your bets won! You bet " << bet_amounts[i] << " on it and your new balance is " << balance << ". Would you like to cash out or keep playing?\n";
            std::cout << "[1] Cash out\n";
            std::cout << "[2] Keep playing\n";
            int choice;
            std::cin >> choice;
            std::cout << "\n";
            if (choice == 1) {
                std::cout << "Thank you for playing, we hope to see you back soon!";
            } else {
                std::cout << "On with the game\n";
                play();
            }
            
        } else if (choices[i] == 38) {
                if (outcome % 2 != 0 && outcome > 1) {
                int balance_added = bet_amounts[i] * 1.5;
                balance = balance + balance_added;
                std::cout << "The ball landed on a red number (" << roulette[outcome] << "). That means you won! You bet " << bet_amounts[i] << " on it and your new balance is " << balance << ". Would you like to cash out or keep playing?\n";
                std::cout << "[1] Cash out\n";
                std::cout << "[2] Keep playing\n";
                int choice;
                std::cin >> choice;
                std::cout << "\n";
            if (choice == 1) {
                std::cout << "Thank you for playing, we hope to see you back soon!";
            } else {
                std::cout << "On with the game\n";
                play();
            }
                }
            } else if (choices[i] == 39 && outcome > 1) {
                if (outcome % 2 == 0) {
                int balance_added = bet_amounts[i] * 1.5;
                balance = balance + balance_added;
                std::cout << "The ball landed on a black number (" << roulette[outcome] << "). That means you won! You bet " << bet_amounts[i] << " on it and your new balance is " << balance << ". Would you like to cash out or keep playing?\n";
                std::cout << "[1] Cash out\n";
                std::cout << "[2] Keep playing\n";
                int choice;
                std::cin >> choice;
                std::cout << "\n";
            if (choice == 1) {
                std::cout << "Thank you for playing, we hope to see you back soon!";
            } else {
                std::cout << "On with the game\n";
                play();
            }
        }
        } else {
            std::cout << "Your bet (" << roulette[choices[i]] << ") did not hit\n";
            std::cout << "Would you like to play again? \n";
            std::cout << "[1] Cash out\n";
                std::cout << "[2] Keep playing\n";
                int choice;
                std::cin >> choice;
                std::cout << "\n";
            if (choice == 1) {
                std::cout << "Thank you for playing, we hope to see you back soon!";
            } else {
                std::cout << "On with the game\n";
                play();
            }
        }
    }
}
int main() {
    update_balance();
    play();
    return 0;
}