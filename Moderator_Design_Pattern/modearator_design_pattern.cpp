#include<bits/stdc++.h>
using namespace std;

class user;

class moderator {
private:
    map<string, user*> users;
public:
    void registerUser(const string& userID, user* user) {
        users[userID] = user;
    }

    void sendMessage(const string& from_user, const string& to_user, const string& message) {
        if (users.find(to_user) != users.end()) {
            users[to_user]->receive(from_user, message);
        } else {
            cout << "User not found: " << to_user << endl;
        }
    }
};

class user {
private:
    string userID;
    moderator* mod;
public:
    user(const string& ID, moderator* mod) : userID(ID), mod(mod) {
        mod->registerUser(userID, this);
    }

    void send(const string& to_user, const string& message) {
        mod->sendMessage(userID, to_user, message);
    }

    void receive(const string& from_user, const string& message) {
        cout << from_user << " sent to " << userID << " -> " << message << endl;
    }
};

int main() {
    moderator Aryan;

    user prasoon("prasoon", &Aryan);
    user hemant("hemant", &Aryan);

    prasoon.send("hemant", "Good morning sir, I did the Moderator Design Pattern.");
    hemant.send("prasoon", "Good, where are the other design patterns?");
    prasoon.send("hemant", "I'm doing them too, sir :)");

    return 0;
}
