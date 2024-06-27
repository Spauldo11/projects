#include <iostream>
#include <vector>
using namespace std;
//Can't make global array for some reason
void visitor() {
string data[4][3] = {{"John", "Scott", "1"}, {"Kevin", "Magnussen", "2"}, {"Vacant", "Vacant", "3"}, {"Donald", "Trump", "4"}};
    string first_name;
    string last_name;
    cout << "Who are you visiting today? \n";
    cout << "First name: ";
    cin >> first_name;
    for (int i = 0; i < sizeof(data); i++) {
        if (first_name == data[i][0]) {
            cout << "Last name: ";
            cin >> last_name;
            if(last_name == data[i][1]) {
                cout << "You are looking for " << first_name << " " << last_name << ". They are in room " << data[i][2] << "\n";
                break;
            }
        } else if (first_name != data[i][0] && i == 3) {
            cout << "Sorry, that person isn't in our system. Please try again\n";
            visitor();
            break;
        }
    }
}
void attention_soon() {
string data[4][3] = {{"John", "Scott", "1"}, {"Kevin", "Magnussen", "2"}, {"Vacant", "Vacant", "3"}, {"Donald", "Trump", "4"}};
    string first_name;
    string last_name;
    for (int i = 0; i < sizeof(data); i++) {
        if ("Vacant" == data[i][0]) {
            cout << "Room " << data[i][2] << " is available.\n";
            cout << "What is your name? \n";
            cout << "First name: ";
            cin >> first_name;
            cout << "Last name: ";
            cin >> last_name;
            data[i][0] = first_name;
            data[i][1] = last_name;
            cout << "Welcome " << first_name << ", we will take you to room " << data[i][2] << " now";
            break;
        } else if (data[i][0] != "Vacant" && i == 3) {
            cout << "Apologies, there are no vacant rooms at the moment. Someone will be right with you\n";
        }
    }
}
void attention_asap() {
cout << "We will take you to our urgent care facility immediately. Our trained medical professionals will figure the rest out with you.\n";
}
void start() {
int start_question;
    cout << "Welcome to Spaulding's Medical Care. What is the purpose of your visit?\n";
    cout << "[1] I am visiting\n";
    cout << "[2] I need medical attention soon\n";
    cout << "[3] I need medical attention ASAP\n";
    cin >> start_question;
    switch(start_question) {
        case 1:
            visitor();
            break;
        case 2:
            attention_soon();
            break;
        case 3:
            attention_asap();
            break;
    }
}
int main() {
    start();
}