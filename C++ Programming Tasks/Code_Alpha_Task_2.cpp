#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "Error: Username and password cannot be empty.\n";
        return;
    }

    if (password.length() < 6) {
        cout << "Error: Password must be at least 6 characters long.\n";
        return;
    }

    // Check duplicate
    ifstream readFile("users.txt");
    string fileUser, filePass;

    while (readFile >> fileUser >> filePass) {
        if (fileUser == username) {
            cout << "Error: Username already exists.\n";
            readFile.close();
            return;
        }
    }
    readFile.close();

    // Store new user
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream readFile("users.txt");
    string fileUser, filePass;
    bool found = false;

    while (readFile >> fileUser >> filePass) {
        if (fileUser == username) {
            found = true;
            if (filePass == password) {
                cout << "Login successful!\n";
            } else {
                cout << "Incorrect password.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "User does not exist.\n";
    }

    readFile.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice != 3);

    return 0;
}