#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


class Client{
    private:
        string name;
        double money;
    public:
        Client(string n, double m)
        {
            name = n;
            money = m;
        }
        void deposit(int amount)
        {
            money+=amount;
        }
        void withDrawl(int amount)
        {
            while(amount > money)
            {
                cout << "You current only have balance of $" << money << endl<< "please enter another amount:";
                cin >> amount;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }

                money-=amount;

        }

        int returnBalance() const
        {
            return money;
        };
        string returnName() const
        {
            return name;
        }

};

class Bank
{
    private:
        unordered_map<string, Client*> storage;
    public:
        void createAccount(string name)
        {
            if(storage.find(name)== storage.end())
            {
                double initialDeposit;
                cout << "How much would you like to deposit?";
                cin >> initialDeposit;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                Client* clientInfo = new Client{name,initialDeposit};
                storage[name] = clientInfo;
                cout << endl;2
                cout << "I have successfully created an account for you " << clientInfo->returnName() << " , and I have deposited $" << initialDeposit << " for you." << endl;

            }
            else
            {
               cout<<  "It appears you already have an account with us" << endl;
            }


        }
        Client * getClientInfo(string name)
        {
            if(storage.find(name) != storage.end())
            {
                Client *holder = storage[name];
                return holder;
            }
           else
            {
               string answer;
               cout << "It looks like you do not have an account with us!" <<endl
               << "Would you like to create one?" ;
               cin >> answer;
               cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
               transform(answer.begin(),answer.end(), answer.begin(),:: toupper);
               if(answer == "YES")
               {
                   createAccount(name);
               }
               else if(answer == "NO")
               {
                   throw invalid_argument ("Goodbye!");
               }
            }
        }

};



int openMenu(string name) {
    int option;
    cout << endl;
    cout << "Hi, " << name << " how can I help you today? Please select from one of the following" << endl;
    cout << "1. Open an account " << endl;
    cout << "2. Check Balance" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdrawal" << endl;
    cout << "5. Exit"<< endl;
    cin >> option;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    return option;
}

int main()
{
    Bank temp;
    int option = 0;
    string answer,name, answerTwo;
    while(option!=5)
    {


        cout << "What is your name:";

        getline(cin, name);

        transform(name.begin(), name.end(), name.begin(), ::toupper);
        option = openMenu(name);

        if (option == 1) {
            temp.createAccount(name);
        } else if (option == 2) {
            Client *a = temp.getClientInfo(name);
            Client *c = temp.getClientInfo(name);
            int b = c->returnBalance();
            cout << "You have a balance of $" << b << endl;
        } else if (option == 3) {
            Client *a = temp.getClientInfo(name);
            int depositAmount;
            cout << "Please enter the amount you would like to deposit today:" << endl;
            cin >> depositAmount;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "You previously had a balance of: $" << a->returnBalance() << endl
                 << "After depositing, you have a balance of: $";
            a->deposit(depositAmount);
            cout << a->returnBalance() << endl;
        } else if (option == 4) {
            int withdrawalAmount;
            Client *a = temp.getClientInfo(name);
            cout << "You have a balance of: $" << a->returnBalance() << endl;
            cout << "How much would you like to withdrawal today?";
            cin >> withdrawalAmount;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            a->withDrawl(withdrawalAmount);
            cout << "You have a new balance of: $" << a->returnBalance() << endl;
        } else if (option == 5){
            cout << "Pleasure to help you today!" << name << endl;

        }
        }
    return 0;
    }



int main()
{
    Bank temp;
    int option = 0;
    string answer,name, answerTwo;
    while(option!=5)
    {


        cout << "What is your name:";

        getline(cin, name);

        transform(name.begin(), name.end(), name.begin(), ::toupper);
        option = openMenu(name);

        if (option == 1) {
            temp.createAccount(name);
        } else if (option == 2) {
            Client *a = temp.getClientInfo(name);
            int b = a->returnBalance();
            cout << "You have a balance of $" << b << endl;
        } else if (option == 3) {
            Client *a = temp.getClientInfo(name);
            int depositAmount;
            cout << "Please enter the amount you would like to deposit today:" << endl;
            cin >> depositAmount;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "You previously had a balance of: $" << a->returnBalance() << endl
                 << "After depositing, you have a balance of: $";
            a->deposit(depositAmount);
            cout << a->returnBalance() << endl;
        } else if (option == 4) {
            int withdrawalAmount;
            Client *a = temp.getClientInfo(name);
            cout << "You have a balance of: $" << a->returnBalance() << endl;
            cout << "How much would you like to withdrawal today?";
            cin >> withdrawalAmount;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            a->withDrawl(withdrawalAmount);
            cout << "You have a new balance of: $" << a->returnBalance() << endl;
        } else if (option == 5){
            cout << "Pleasure to help you today!" << name << endl;

        }
        }
    return 0;
    }
