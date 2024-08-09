#include <iostream>
#include <cctype>
#include <time.h>
using namespace std;
string roulette[38] = {"00", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36"};
int colors[38] = {2, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0};
int doubleOptions[62][2] = {{-1, 0}, {0, 1}, {0, 2}, {-1, 2}, {-1, 3}, {1, 2}, {2, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 5}, {5, 6}, {4, 7}, {5, 8}, {6, 9}, {7, 8}, {8, 9}, {7, 10}, {8, 11}, {9, 12}, {10, 11}, {11, 12}, {10, 13}, {11, 14}, {12, 15}, {13, 14}, {14, 15}, {13, 16}, {14, 17}, {15, 18}, {16, 17}, {17, 18}, {16, 19}, {17, 20}, {18, 21}, {19, 20}, {20, 21}, {19, 22}, {20, 23}, {21, 24}, {22, 23}, {23, 24}, {22, 25}, {23, 26}, {24, 27}, {25, 26}, {26, 27}, {25, 28}, {26, 29}, {27, 30}, {28, 29}, {29, 30}, {28, 31}, {29, 32}, {30, 33}, {31, 32}, {32, 33}, {31, 34}, {32, 35}, {33, 36}, {34, 35}, {35, 36}};
int tripleOptions[12][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30}, {31, 32, 33}, {34, 35, 36}};
int quadOptions[22][4] = {{1, 2, 4, 5}, {2, 3, 5, 6}, {4, 5, 7, 8}, {5, 6, 8, 9}, {7, 8, 10, 11}, {8, 9, 11, 12}, {10, 11, 13, 14}, {11, 12, 14, 15}, {13, 14, 16, 17}, {14, 15, 17, 18}, {16, 17, 19, 20}, {17, 18, 20, 21}, {19, 20, 22, 23}, {20, 21, 23, 24}, {22, 23, 25, 26}, {23, 24, 26, 27}, {25, 26, 28, 29}, {26, 27, 29, 30}, {28, 29, 31, 32}, {29, 30, 32, 33}, {21, 32, 34, 35}, {32, 33, 35, 36}};
int sixNumOptions[11][6] = {{1, 2, 3, 4, 5, 6}, {4, 5, 6, 7, 8, 9}, {7, 8, 9, 10, 11, 12}, {10, 11, 12, 13, 14, 15}, {13, 14, 15, 16, 17, 18}, {16, 17, 18, 19, 20, 21}, {19, 20, 21, 22, 23, 24}, {22, 23, 24, 25, 26, 27}, {25, 26, 27, 28, 29, 30}, {28, 29, 30, 31, 32, 33}, {31, 32, 33, 34, 35, 36}};
int dozenOptions[3][12] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36}};
int columnOptions[3][12] = {{1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34}, {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35}, {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36}};
vector<int> singleBetChoices;
vector<int> singleBetAmounts;
vector<int> doubleBetChoices;
vector<int> doubleBetAmounts;
vector<int> tripleBetChoices;
vector<int> tripleBetAmounts;
vector<int> quadBetChoices;
vector<int> quadBetAmounts;
int fiveBetChoices = 0;
vector<int> fiveBetAmounts;
vector<int> sixBetChoices;
vector<int> sixBetAmounts;
vector<int> dozenBetChoices;
vector<int> dozenBetAmounts;
vector<int> columnBetChoices;
vector<int> columnBetAmounts;
vector<int> eighteenBetChoices;
vector<int> eighteenBetAmounts;
vector<int> colorBetChoices;
vector<int> colorBetAmounts;
vector<int> oddEvenBetChoices;
vector<int> oddEvenBetAmounts;
vector<int> types;
float balance = 0.0;
void processBet();
void bet();
void singleBet();
void doubleBet();
void tripleBet();
void fourNumBet();
void fiveNumBet();
void sixNumBet();
void dozenBet();
void columnBet();
void eighteenNumBet();
void colorBet();
void oddEvenBet();
void update_balance();
void update_balance() {
    string choices;
    cout << "Your balance is " << balance << ". Would you like to update your balance? (Y/N) ";
    cin >> choices;
    if (choices == "Y" || choices == "y") {
        int balance_add;
        cout << "How much would you like to add to your balance? ";
        cin >> balance_add;
        balance = balance + balance_add;
        update_balance();
    } else {
        bet();
    }
}
void singleBet() {
    int choice;
    int bet_amount;
    for(int i = 0; i < 38; i++) {
        cout << "[" << i << "]" << " " << roulette[i] << "\n";
    }
    cin >> choice;
    cout << "\n";
        cout << "Please enter how much you would like to bet on " << roulette[choice] << ": ";
        cin >> bet_amount;
        if (bet_amount > balance) {
            cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
            update_balance();
        } else {
            singleBetChoices.push_back(choice);
            balance = balance - bet_amount;
        singleBetAmounts.push_back(bet_amount);
        cout << "\n";
        cout << "You have bet " << bet_amount << " on " << roulette[choice] << ".\n";
        }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
     
}
void doubleBet() {
    int choice;
    int bet_amount;
    for (int i = 0; i < 62; i++) {
        if (doubleOptions[i][0] == -1) {
        cout << "[" << i << "]" << " 00" << " and " << doubleOptions[i][1] << "\n";
        } else {
        cout << "[" << i << "]" << " " << doubleOptions[i][0] << " and " << doubleOptions[i][1] << "\n";
        }
    }
    cin >> choice;
    if (doubleOptions[choice][0] == -1) {
    cout << "How much would you like to bet on 00 and " << doubleOptions[choice][1] << ": ";
    } else {
    cout << "How much would you like to bet on " << doubleOptions[choice][0] << " and " << doubleOptions[choice][1] << ": ";
    }
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
    doubleBetChoices.push_back(choice);
        balance = balance - bet_amount;
    doubleBetAmounts.push_back(bet_amount);
    cout << "\n";
    if (doubleOptions[choice][0] == -1) {
    cout << "You have bet " << bet_amount << " on 00 and " << doubleOptions[choice][1] << ".\n";
    } else {
    cout << "You have bet " << bet_amount << " on " << doubleOptions[choice][0] << " and " << doubleOptions[choice][1] << ".\n";
    }
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }

}
void tripleBet() {
    int choice;
    int bet_amount;
    for (int i = 0; i < 12; i++) {
        cout << "[" << i << "] " << tripleOptions[i][0] << ", " << tripleOptions[i][1] << ", and " << tripleOptions[i][2] << "\n";
    }
    cin >> choice;
    cout << "How much would you like to bet on " << tripleOptions[choice][0] << ", " << tripleOptions[choice][1] << ", and " << tripleOptions[choice][2] << ": ";
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        tripleBetChoices.push_back(choice);
        balance = balance - bet_amount;
        cout << "You have bet " << bet_amount << " on " << tripleOptions[choice][0] << ", " << tripleOptions[choice][1] << ", and " << tripleOptions[choice][2] << ".\n";
        tripleBetAmounts.push_back(bet_amount);
     }
     string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void fourNumBet() {
    int choice;
    int bet_amount;
    for (int i = 0; i < 22; i++) {
        cout << "[" << i << "] " << quadOptions[i][0] << ", " << quadOptions[i][1] << ", " << quadOptions[i][2] << ", and " << quadOptions[i][3] << "\n";
    }
    cin >> choice;
    cout << "How much would you like to bet on " << quadOptions[choice][0] << ", " << quadOptions[choice][1] << ", " << quadOptions[choice][2] << ", and " << quadOptions[choice][3] << ": ";
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        quadBetChoices.push_back(choice);
        balance = balance - bet_amount;
        cout << "You have bet " << bet_amount << " on " << quadOptions[choice][0] << ", " << quadOptions[choice][1] << ", " << quadOptions[choice][2] << ", and " << quadOptions[choice][3] << ".\n";
        quadBetAmounts.push_back(bet_amount);
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void fiveNumBet() {
    int bet_amount;
    cout << "How much would you like to bet on 0, 00, 1, 2, and 3: ";
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        if (fiveBetChoices < 1) {
        balance = balance - bet_amount;
        cout << "You have bet " << bet_amount << " on 0, 00, 1, 2, and 3.\n";
        fiveBetAmounts.push_back(bet_amount);
        } else {
        balance = balance - bet_amount;
        cout << "You have added " << bet_amount << " to your bet of 0, 00, 1, 2, and 3.\n";
        fiveBetAmounts[0] = fiveBetAmounts[0] + bet_amount;
        }
        fiveBetChoices = fiveBetChoices + 1;
    }
     string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void sixNumBet() {
    int choice;
    int bet_amount;
    for (int i = 0; i < 11; i++) {
        cout << "[" << i << "] " << sixNumOptions[i][0] << ", " << sixNumOptions[i][1] << ", " << sixNumOptions[i][2] << ", " << sixNumOptions[i][3] << ", " << sixNumOptions[i][4] << ", and " << sixNumOptions[i][5] << "\n";
    }
    cin >> choice;
    cout << "How much would you like to bet on " << sixNumOptions[choice][0] << ", " << sixNumOptions[choice][1] << ", " << sixNumOptions[choice][2] << ", " << sixNumOptions[choice][3] << ", " << sixNumOptions[choice][4] << ", and " << sixNumOptions[choice][5] << ": ";
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "Sorry, you do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        sixBetAmounts.push_back(bet_amount);
        sixBetChoices.push_back(choice);
        balance = balance - bet_amount;
        cout << "You have bet " << bet_amount << " on " << sixNumOptions[choice][0] << ", " << sixNumOptions[choice][1] << ", " << sixNumOptions[choice][2] << ", " << sixNumOptions[choice][3] << ", " << sixNumOptions[choice][4] << ", and " << sixNumOptions[choice][5] << ".\n";
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void dozenBet() {
    int choice;
    int bet_amount;
    for (int i = 0; i < 3; i++) {
        cout << "[" << i << "] ";
        for (int j = 0; j < 11; j++) {
            cout << dozenOptions[i][j] << ", ";
        }
        cout << "and " << dozenOptions[i][11] << "\n";
    }
    cin >> choice;
    cout << "How much would you like to bet on ";
    for (int i = 0; i < 11; i++) {
            cout << dozenOptions[choice][i] << ", ";
    }
    cout << "and " << dozenOptions[choice][11] << ": ";
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance <<  ") for that bet.\n";
        update_balance();
    } else {
        dozenBetAmounts.push_back(bet_amount);
        dozenBetChoices.push_back(choice);
        balance = balance - bet_amount;
        cout << "You have bet " << bet_amount << " on ";
        for (int i = 0; i < 11; i++) {
            cout << dozenOptions[choice][i] << ", ";
        }
        cout << "and " << dozenOptions[choice][11] << ".\n";
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void columnBet() {
    int choice;
    int bet_amount;
    for (int i = 0; i < 3; i++) {
        cout << "[" << i << "] ";
        for (int j = 0; j < 11; j++) {
            cout << columnOptions[i][j] << ", ";
        }
        cout << "and " << columnOptions[i][11] << "\n";
    }
    cin >> choice;
    cout << "How much would you like to bet on ";
    for (int i = 0; i < 11; i++) {
            cout << columnOptions[choice][i] << ", ";
        }
        cout << "and " << columnOptions[choice][11] << ": ";
    cin >> bet_amount;
     if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance <<  ") for that bet.\n";
        update_balance();
    } else {
        balance = balance - bet_amount;
        columnBetChoices.push_back(choice);
        columnBetAmounts.push_back(bet_amount);
        cout << "You have bet " << bet_amount << " on ";
        for (int i = 0; i < 11; i++) {
            cout << columnOptions[choice][i] << ", ";
        }
        cout << "and " << columnOptions[choice][11] << ".\n";
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void eighteenNumBet() {
    int choice;
    int bet_amount;
    cout << "[0] First Eighteen (1-18)\n";
    cout << "[1] Second Eighteen (19-36)\n";
    cin >> choice;
    if (choice == 0) {
        cout << "How much would you like to bet on the first eighteen: ";
    } else {
        cout << "How much would you like to bet on the second eighteen: ";
    }
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        eighteenBetAmounts.push_back(bet_amount);
        eighteenBetChoices.push_back(choice);
        balance = balance - bet_amount;
        if (choice == 0) {
            cout << "You have bet " << bet_amount << " on the first eighteen.\n";
        } else {
            cout << "You have bet " << bet_amount << " on the second eighteen.\n";
        }
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void colorBet() {
    int choice;
    int bet_amount;
    cout << "[0] Red\n";
    cout << "[1] Black\n";
    cout << "[2] Green\n";
    cin >> choice;
    cout << "How much would you like to bet on ";
    if (choice == 0) {
        cout << "red: ";
    } else if (choice == 1) {
        cout << "black: ";
    } else {
        cout << "green: ";
    }
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        balance = balance - bet_amount;
        colorBetChoices.push_back(choice);
        colorBetAmounts.push_back(bet_amount);
        cout << "You have bet " << bet_amount << " on ";
        if (choice == 0) {
            cout << "red.\n";
        } else if (choice == 1) {
            cout << "black.\n";
        } else {
            cout << "green.\n";
        }
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void oddEvenBet() {
    int choice;
    int bet_amount;
    cout << "[0] Even\n";
    cout << "[1] Odd\n";
    cin >> choice;
    cout << "How much would you like to bet on ";
    if (choice == 0) {
        cout << "even: ";
    } else {
        cout << "odd: ";
    }
    cin >> bet_amount;
    if (bet_amount > balance) {
        cout << "You do not have a great enough balance (" << balance << ") for that bet.\n";
        update_balance();
    } else {
        balance = balance - bet_amount;
        oddEvenBetAmounts.push_back(bet_amount);
        oddEvenBetChoices.push_back(choice);
        cout << "You have bet " << bet_amount << " on ";
        if (choice == 0) {
            cout << "even.\n";
        } else {
            cout << "odd.\n";
        }
    }
    string anything_else;
    cout << "Anything else you would like to bet on? (Y/N)";
    cin >> anything_else;
    cout << "\n";
    if (anything_else == "Y" || anything_else == "y") {
        bet();
    } else {
        processBet();
    }
}
void bet() {
    int type;
    cout << "Which of the following bets would you like to make?\n";
    cout << "[1] Single (35 to 1 payout)\n";
    cout << "[2] Double (17 to 1 payout)\n";
    cout << "[3] Triple (11 to 1 payout)\n";
    cout << "[4] Four Number Bet (8 to 1 payout)\n";
    cout << "[5] Five Number Bet (6 to 1 payout)\n";
    cout << "[6] Six Number Bet (5 to 1 payout)\n";
    cout << "[7] Dozens Bet (2 to 1 payout)\n";
    cout << "[8] Column Bet (2 to 1 payout)\n";
    cout << "[9] Eighteen Number Bet (pays even money)\n";
    cout << "[10] Red or Black (pays even money)\n";
    cout << "[11] Odd or Even (pays even money)\n";
    cin >> type;
    cout << "Please select what you would like to bet on: \n";
    switch (type) {
        case 1:
            singleBet();
            break;
        case 2:
            doubleBet();
            break;
        case 3:
            tripleBet();
            break;
        case 4:
            fourNumBet();
            break;
        case 5:
            fiveNumBet();
            break;
        case 6:
            sixNumBet();
            break;
        case 7:
            dozenBet();
            break;
        case 8:
            columnBet();
            break;
        case 9:
            eighteenNumBet();
            break;
        case 10:
            colorBet();
            break;
        case 11:
            oddEvenBet();
            break;
    }

    types.push_back(type);
}
void processBet() {
    srand(time(0));
    int outcome = rand() % 38;
    string color;
    if (colors[outcome] == 0) {
        color = "red";
    } else if (colors[outcome] == 1) {
        color = "black";
    } else {
        color = "green";
    }
    cout << "The ball landed on " << roulette[outcome] << " (" << color << ")\n";
    int decision;
        if (singleBetChoices.size() > 0) {
            for (int i = 0; i < singleBetChoices.size(); i++) {
                if (singleBetChoices[i] == outcome) {
                    balance = balance + singleBetAmounts[i] * 36;
                    cout << "You won! You bet on " << roulette[singleBetChoices[i]] << ", so you win " << singleBetAmounts[i] * 35 << ". Your new balance is " << balance << ".\n";
                } else {
                    cout << "Your bet of " << roulette[singleBetChoices[i]] << " did not hit.\n";
                }
            }
            singleBetChoices.clear();
            singleBetAmounts.clear();
        }
        if (doubleBetChoices.size() > 0) {
            for (int i = 0; i < doubleBetChoices.size(); i++)  {
                for (int j = 0; j < 2; j++) {
                if (doubleOptions[doubleBetChoices[i]][j] == outcome - 1) {
                    balance = balance + doubleBetAmounts[i] * 18;
                    if (doubleOptions[doubleBetChoices[i]][0] == -1) {
                    cout << "You won! You bet " << doubleBetAmounts[i] << " on 00 and " << doubleOptions[doubleBetChoices[i]][1] << ", so you win " << doubleBetAmounts[i] * 17 << ". Your new balance is " << balance << ".\n";
                    break;
                    } else {
                    cout << "You won! You bet " << doubleBetAmounts[i] << " on " <<   doubleOptions[doubleBetChoices[i]][0] << " and " << doubleOptions[doubleBetChoices[i]][1] << ", so you win " << doubleBetAmounts[i] * 17 << ". Your new balance is " << balance << ".\n";
                    break;
                    }                
                } else if (j == 1 && doubleOptions[doubleBetChoices[i]][j] != outcome - 1) {
                    if (doubleOptions[doubleBetChoices[i]][0] == -1) {
                    cout << "Your bet of 00 and " << doubleOptions[doubleBetChoices[i]][1] << " did not hit.\n";
                    break;
                    } else {
                    cout << "Your bet of " << doubleOptions[doubleBetChoices[i]][0] << " and " << doubleOptions[doubleBetChoices[i]][1] << " did not hit.\n";
                    break;
                    }
                }
                }
            }
            doubleBetAmounts.clear();
            doubleBetChoices.clear();
        }
        if (tripleBetChoices.size() > 0) {
            for (int i = 0; i < tripleBetChoices.size(); i++) {
                for(int j = 0; j < 3; j++) {
                if (tripleOptions[tripleBetChoices[i]][j] == outcome - 1) {
                    balance = balance + tripleBetAmounts[i] * 12;
                    cout << "You won! You bet " << tripleBetAmounts[i] << " on " << tripleOptions[tripleBetChoices[i]][0] << ", " << tripleOptions[tripleBetChoices[i]][1] << ", and " << tripleOptions[tripleBetChoices[i]][2] << ", so you win " << tripleBetAmounts[i] * 11 << ". Your new balance is " << balance << ".\n";
                    break;
                } else if (j == 2 && tripleOptions[tripleBetChoices[i]][j] != outcome - 1) {
                    cout << "Your bet of " << tripleOptions[tripleBetChoices[i]][0] << ", " << tripleOptions[tripleBetChoices[i]][1] << ", and " << tripleOptions[tripleBetChoices[i]][2] << " did not hit.\n";
                    break;
                }
                }
            }
            tripleBetAmounts.clear();
            tripleBetChoices.clear();
        }
        if (quadBetChoices.size() > 0) {
            for (int i = 0; i < quadBetChoices.size(); i++) {
                for (int j = 0; j < 4; j++) {
                    if (quadOptions[quadBetChoices[i]][j] == outcome - 1) {
                        balance = balance + quadBetAmounts[i] * 9;
                        cout << "You won! You bet " << quadBetAmounts[i] << " on " << quadOptions[quadBetChoices[i]][0] << ", " << quadOptions[quadBetChoices[i]][1] << ", " << quadOptions[quadBetChoices[i]][2] << ", and " << quadOptions[quadBetChoices[i]][3] << ", so you win " << quadBetAmounts[i] * 8 << ". Your new balance is " << balance << ".\n";
                        break;
                    } else if (j == 3 && quadOptions[quadBetChoices[i]][j] != outcome - 1) {
                        cout << "Your bet of " << quadBetAmounts[i] << " on " << quadOptions[quadBetChoices[i]][0] << ", " << quadOptions[quadBetChoices[i]][1] << ", " << quadOptions[quadBetChoices[i]][2] << ", and " << quadOptions[quadBetChoices[i]][3] << " did not hit.\n";
                        break;
                    }
                }
            }
            quadBetChoices.clear();
            quadBetAmounts.clear();
        }
        if (fiveBetChoices > 0) {
            for (int i = 0; i < fiveBetChoices; i++) {
                if (outcome - 1 == -1 || outcome - 1 == 0 || outcome - 1 == 1 || outcome - 1 == 2 || outcome - 1 == 3) {
                    balance = balance + fiveBetAmounts[i] * 7;
                    cout << "You won! You bet " << fiveBetAmounts[i] << " on 0, 00, 1, 2, and 3, so you win " << fiveBetAmounts[i] * 6 << ". Your new balance is " << balance << ".\n";
                    break;
                } else {
                    cout << "Your bet of 0, 00, 1, 2, and 3 did not hit.\n";
                    break;
                }
            }
            fiveBetChoices = 0;
            fiveBetAmounts.clear();
        }
        if (sixBetChoices.size() > 0) {
            for (int i = 0; i < sixBetChoices.size(); i++) {
                for (int j = 0; j < 6; j++) {
                    if (sixNumOptions[sixBetChoices[i]][j] == outcome - 1) {
                        balance = balance + sixBetAmounts[i] * 6;
                        cout << "You won! You bet " << sixBetAmounts[i] << " on " << sixNumOptions[sixBetChoices[i]][0] << ", " << sixNumOptions[sixBetChoices[i]][1] << ", " << sixNumOptions[sixBetChoices[i]][2] << ", " << sixNumOptions[sixBetChoices[i]][3] << ", " << sixNumOptions[sixBetChoices[i]][4] << ", and " << sixNumOptions[sixBetChoices[i]][5] << ", so you win " << sixBetAmounts[i] * 5 << ". Your new balance is " << balance << ".\n";
                        break;
                    } else if (j == 5 && sixNumOptions[sixBetChoices[i]][j] != outcome - 1) {
                        cout << "Your bet of " << sixBetAmounts[i] << " on " << sixNumOptions[sixBetChoices[i]][0] << ", " << sixNumOptions[sixBetChoices[i]][1] << ", " << sixNumOptions[sixBetChoices[i]][2] << ", " << sixNumOptions[sixBetChoices[i]][3] << ", " << sixNumOptions[sixBetChoices[i]][4] << ", and " << sixNumOptions[sixBetChoices[i]][5] << " did not hit.\n";
                        break;
                    }
                }
            }
            sixBetChoices.clear();
            sixBetAmounts.clear();
        }
        if (dozenBetChoices.size() > 0) {
            int ans;
                if (1 < outcome && outcome < 13) {
                    ans = 0;
                } else if (12 < outcome && outcome < 25) {
                    ans = 1;
                } else if (outcome > 24) {
                    ans = 2;
                }
                for (int i = 0; i < dozenBetChoices.size(); i++) {
                    if (ans == dozenBetChoices[i]) {
                        balance = balance + dozenBetAmounts[i] * 3;
                        cout << "You won! You bet " << dozenBetAmounts[i] << " on ";
                        for (int j = 0; j < 11; j++) {
                            cout << dozenOptions[dozenBetChoices[i]][j] << ", ";
                        }
                        cout << "and " << dozenOptions[dozenBetChoices[i]][11] << ", so you win " << dozenBetAmounts[i] * 2 << ". Your new balance is " << balance << ".\n";
                    } else {
                        cout << "Your bet of " << dozenBetAmounts[i] << " on ";
                        for (int j = 0; j < 11; j++) {
                            cout << dozenOptions[dozenBetChoices[i]][j] << ", ";
                        }
                        cout << "and " << dozenOptions[dozenBetChoices[i]][11] << " did not hit.\n";
                    }
                }
                dozenBetAmounts.clear();
                dozenBetChoices.clear();
        }
        if (columnBetChoices.size() > 0) {
            for (int i = 0; i < columnBetChoices.size(); i++) {
                for (int j = 0; j < 12; j++) {
                    if (columnOptions[columnBetChoices[i]][j] == outcome - 1) {
                        balance = balance + columnBetAmounts[i] * 3;
                        cout << "You won! You bet " << columnBetAmounts[i] << " on ";
                        for (int k = 0; k < 11; k++) {
                            cout << columnOptions[columnBetChoices[i]][k] << ", ";
                        }
                        cout << "and " << columnOptions[columnBetChoices[i]][11] << ", so you win " << columnBetAmounts[i] * 2 << ". Your new balance is " << balance << ".\n";
                        break;                    
                    } else if (j == 11 && columnOptions[columnBetChoices[i]][j] != outcome - 1) {
                        cout << "Your bet of " << columnBetAmounts[i] << " on ";
                         for (int k = 0; k < 11; k++) {
                            cout << columnOptions[columnBetChoices[i]][k] << ", ";
                        }
                        cout << "and " << columnOptions[columnBetChoices[i]][11] << " did not hit.\n";
                        break;
                    }
                }
            }
            columnBetAmounts.clear();
            columnBetChoices.clear();
        }
        if (eighteenBetChoices.size() > 0) {
            int ans;
            if (outcome > 1 && outcome < 19) {
                ans = 0;
            } else if (outcome > 18) {
                ans = 1;
            }
            for (int i = 0; i < eighteenBetChoices.size(); i++) {
                if (ans == eighteenBetChoices[i]) {
                    balance = balance + eighteenBetAmounts[i] * 2;
                    cout << "You won! You bet " << eighteenBetAmounts[i] << " on the ";
                    if (eighteenBetChoices[i] == 0) {
                        cout << "first eighteen";
                    } else {
                        cout << "second eighteen";
                    }
                    cout << ", so you win " << eighteenBetAmounts[i] << ". Your new balance is " << balance << ".\n";
                } else {
                    cout << "Your bet of " << eighteenBetAmounts[i] << " on ";
                    if (eighteenBetChoices[i] == 0) {
                        cout << "first eighteen";
                    } else {
                        cout << "second eighteen";
                    }
                    cout << " did not hit.\n";
                }
            }
            eighteenBetChoices.clear();
            eighteenBetAmounts.clear();
        }
        if (colorBetChoices.size() > 0) {
            for (int i = 0; i < colorBetChoices.size(); i++) {
                if (colors[outcome] == colorBetChoices[i]) {
                    balance = balance + colorBetAmounts[i] * 2;
                    cout << "You won! You bet " << colorBetAmounts[i] << " on ";
                    if (colorBetChoices[i] == 0) {
                        cout << "red";
                    } else if (colorBetChoices[i] == 1) {
                        cout << "black";
                    } else {
                        cout << "green";
                    }
                    cout << ", so you win " << colorBetAmounts[i] << ". Your new balance is " << balance << ".\n";
                } else {
                    cout << "Your bet of " << colorBetAmounts[i] << " on ";
                    if (colorBetChoices[i] == 0) {
                        cout << "red";
                    } else if (colorBetChoices[i] == 1) {
                        cout << "black";
                    } else {
                        cout << "green";
                    }
                    cout << " did not hit.\n";
                }
            }
            colorBetChoices.clear();
            colorBetAmounts.clear();
        }
        if (oddEvenBetChoices.size() > 0) {
            int ans;
            for (int i = 0; i < oddEvenBetChoices.size(); i++) {
            if (outcome > 1) {
                if ((outcome - 1) % 2 == 0) {
                    ans = 0;
                } else {
                    ans = 1;
                }
                if (ans == oddEvenBetChoices[i]) {
                    balance = balance + oddEvenBetAmounts[i] * 2;
                    cout << "You won! You bet " << oddEvenBetAmounts[i] << " on ";
                    if (oddEvenBetChoices[i] == 0) {
                    cout << "even";
                    } else {
                        cout << "odd";
                    }
                    cout << ", so you win " << oddEvenBetAmounts[i] << ". Your new balance is " << balance << ".\n"; 
                } else {
                    cout << "Your bet of " << oddEvenBetAmounts[i] << " on ";
                    if (oddEvenBetChoices[i] == 0) {
                        cout << "even";
                    } else {
                        cout << "odd";
                    }
                    cout << " did not hit.\n";
                }
            } else {
                cout << "Your bet of " << oddEvenBetAmounts[i] << " on ";
                if (oddEvenBetChoices[i] == 0) {
                    cout << "even";
                } else {
                    cout << "odd";
                }
                cout << " did not hit.\n";
            }
        }
        oddEvenBetChoices.clear();
        oddEvenBetAmounts.clear();
        }
    cout << "Your balance is now " << balance << ". Would you like to: \n";
    cout << "[1] Keep playing\n";
    cout << "[2] Cash out\n";
    cin >> decision;
    if (decision == 1) {
        update_balance();
    } else {
        cout << "Thank you! We look forward to seeing you again.\n";
    }

}
int main() {
    update_balance();
    return 0;
}