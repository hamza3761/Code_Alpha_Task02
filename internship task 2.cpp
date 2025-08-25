#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            cout << "Username already exists. Try again.\n";
            return false;
        }
    }
    file.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << "\n";
    outfile.close();
    cout << "Registration successful!\n";
    return true;
}

bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful! Welcome " << username << "\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
