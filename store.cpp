#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include<time.h>
using namespace std;

class Item
{
public:
    string name;
    int price;
    int quantity;
    Item(string get_name, int get_price, int quantity) : name(get_name), price(get_price), quantity(quantity) {}
    int get_price() {
        return price;
    }
    int get_quantity() {
        return quantity;
    }
    string get_name() {
        return name;
    }
};

class User
{
    string username;
    string password;
    int balance;

public:
    User(string get_username, string get_password, int get_balance) : username(get_username), password(get_password), balance(get_balance) {}
    int get_balance()
    {
        return balance;
    }
    string get_username()
    {
        return username;
    }
    string get_password()
    {
        return password;
    }
    int increase_balance()
    {
        double added_money;
        cout << "Your current balance is " << balance << ", how much would you like to add to it?\n";
        cin >> added_money;
        balance = balance + added_money;
        cout << "Perfect, your new balance is " << balance << "\n";
        return balance;
    }
};

Item sweatshirt("sweatshirt", 35, 818);
Item jeans("jeans", 15, 241);
Item shoes("shoes", 50, 2);
Item socks("socks", 5, 852);
User Spauldo11("Spauldo11", "applebad", 150);
User whatAguy("whatAguy", "skibidi_rizz", 12000);
vector<string> items;
/* work in progress
vector<string> usernames = {"Spauldo11", "whatAguy"};
vector<string> passwords = {Spauldo11.get_password(), whatAguy.get_password()};
vector<int> balances = {Spauldo11.get_balance(), whatAguy.get_balance()}; */
int price = 0;
string user;
string password;
void watchu_want();
void finish_purchase();
// sign in/up is a work in progress
/* string sign_in()
{
    cout << "Please enter your username: ";
    cin >> user;
    for (int i = 0; i < usernames.size(); i++)
    {
        if (user == usernames[i])
        {
            cin >> password;
            if (password == passwords[i])
            {
                cout << "Welcome" << user << ", your balance is " << balances[i];
            }
        }
        else
        {
            cout << "Sorry, we could not find your username. Please try again\n";
        }
    };
    return user;
} */
void generate_shipping_num() {
    srand(time(0));
    int num = rand() % 10000000;
    cout << "Order placed, your shipping number is " << num << "\n";
}

void finish_purchase()
{
    if (items.size() > 0)
    {
        string ans;
        string balance_ans;
        cout << "Your cart currently has:\n";
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << "\n";
        };
        cout << "That will be $" << price << ", would you like to complete the purchase? Y/N\n";
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            if (Spauldo11.get_balance() >= price)
            {
                generate_shipping_num();
            }
            else
            {
                cout << "Sorry, your balance is too low ($" << Spauldo11.get_balance() << "). Would you like to update it and try again? Y/N\n";
                cin >> balance_ans;
                if (balance_ans == "Y" || balance_ans == "y")
                {
                    Spauldo11.increase_balance();
                    cout << "Your new balance is " << Spauldo11.get_balance() << ".\n";
                    finish_purchase();
                }
                else
                {
                    cout << "Okay, come back later\n";
                }
            }
        }
        else
        {
            cout << "Okay, we hope to see you again soon!\n";
        }
    }
};

void watchu_want()
{
    string wanted_item;
    cout << "Your balance is $" << Spauldo11.get_balance() << ". What would you like to purchase? We have sweatshirts($35), jeans($15), shoes($50), and socks($5). Also, you can either type no to exit, or type \'increase\' to increase your balance\n";
    cin >> wanted_item;
    if (wanted_item == "sweatshirt" || wanted_item == "Sweatshirt" || wanted_item == "sweatshirts" || wanted_item == "Sweatshirts")
    {
        cout << "How many would you like?\n";
        int count;
        cin >> count;
        if (count > sweatshirt.get_quantity()) {
            cout << "Sorry, we only have " << sweatshirt.get_quantity() << " in stock. Please update your order and try again\n";
            watchu_want();
        } else {
        for (int i = 0; i < count; i++)
        {
            items.push_back("sweatshirt");
        }
        sweatshirt.quantity = sweatshirt.get_quantity() - count;
        price = price += count *= sweatshirt.get_price();
        string ans;
        cout << "Would you like anything else? Y/N\n";
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            watchu_want();
        }
        else
        {
            finish_purchase();
        };
        }
    }
    else if (wanted_item == "jeans" || wanted_item == "Jeans")
    {
        cout << "How many would you like?\n";
        int count;
        cin >> count;
         if (count > jeans.get_quantity()) {
            cout << "Sorry, we only have " << jeans.get_quantity() << " in stock. Please update your order and try again\n";
            watchu_want();
        } else {
        for (int i = 0; i < count; i++)
        {
            items.push_back("jeans");
        }
        jeans.quantity = jeans.get_quantity() - count;
        price = price += count *= jeans.get_price();
        string ans;
        cout << "Would you like anything else? Y/N\n";
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            watchu_want();
        }
        else
        {
            finish_purchase();
        };
        } 
    }
    else if (wanted_item == "shoes" || wanted_item == "Shoes")
    {
        cout << "How many would you like?\n";
        int count;
        cin >> count;
         if (count > shoes.get_quantity()) {
            cout << "Sorry, we only have " << shoes.get_quantity() << " in stock. Please update your order and try again\n";
            watchu_want();
        } else  {
        for (int i = 0; i < count; i++)
        {
            items.push_back("shoes");
        }
        shoes.quantity = shoes.get_quantity() - count;
        price = price += count *= shoes.get_price();
        string ans;
        cout << "Would you like anything else? Y/N\n";
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            watchu_want();
        }
        else
        {
            finish_purchase();
        };
        } 
    }
    else if (wanted_item == "socks" || wanted_item == "Socks")
    {
        cout << "How many would you like?\n";
        int count;
        cin >> count;
         if (count > socks.get_quantity()) {
            cout << "Sorry, we only have " << socks.get_quantity() << " in stock. Please update your order and try again\n";
            watchu_want();
        } else {
        for (int i = 0; i < count; i++)
        {
            items.push_back("socks");
        }
        socks.quantity = socks.get_quantity() - count;
        price = price += count *= socks.get_price();
        string ans;
        cout << "Would you like anything else? Y/N\n";
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            watchu_want();
        }
        else
        {
            finish_purchase();
        };
        } 
    }
    else if (wanted_item == "no" || wanted_item == "No") {}
    else if (wanted_item == "increase" || wanted_item == "Increase") {
        Spauldo11.increase_balance();
        watchu_want();
    } else {
        cout << "Sorry, we couldn\'t find the item you are looking for. Please search for something else. Please try again\n";
        watchu_want();
    }
}

int main()
{
    watchu_want();
    return 0;
}