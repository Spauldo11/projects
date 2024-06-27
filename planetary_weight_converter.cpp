#include <iostream>
using namespace std;

int main()
{
    double weight;
    int planet;
    cout << "How much do you weight in pounds?";
    cin >> weight;
    cout << "Which planet would you like to convert your weight to?\n";
    cout << "[1] Mercury\n";
    cout << "[2] Venus\n";
    cout << "[3] Mars\n";
    cout << "[4] Jupiter\n";
    cout << "[5] Saturn\n";
    cout << "[6] Uranus\n";
    cout << "[7] Neptune\n";
    cin >> planet;
    switch (planet)
    {
    case 1:
        planet = weight * 0.38;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Mercury\n";
        break;
    case 2:
        planet = weight * 0.91;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Venus\n";
        break;
    case 3:
        planet = weight * 0.38;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Mars\n";
        break;
    case 4:
        planet = weight * 2.34;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Jupiter\n";
        break;
    case 5:
        planet = weight * 1.06;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Saturn\n";
        break;
    case 6:
        planet = weight * 0.92;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Uranus\n";
        break;
    case 7:
        planet = weight * 1.19;
        cout << "You weigh ";
        cout << planet;
        cout << " pounds on Neptune\n";
        break;
    default:
        cout << "That number does not correspond to a planet. Please insert a valid number next time.\n";
    }
}