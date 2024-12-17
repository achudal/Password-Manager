#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the password
string encryptPassword(string password, int key) {
    string encrypted = "";
    for (char ch : password) {
        // Encrypt only alphabetic characters
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encrypted += char(int(base + (ch - base + key) % 26));
        } 
        // Encrypt numeric characters
        else if (isdigit(ch)) {
            encrypted += char(int('0' + (ch - '0' + key) % 10));
        } else {
            // Leave special characters unchanged
            encrypted += ch;
        }
    }
    return encrypted;
}

// Function to decrypt the password
string decryptPassword(string encrypted, int key) {
    string decrypted = "";
    for (char ch : encrypted) {
        // Decrypt only alphabetic characters
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            decrypted += char(int(base + (ch - base - key + 26) % 26));
        } 
        // Decrypt numeric characters
        else if (isdigit(ch)) {
            decrypted += char(int('0' + (ch - '0' - key + 10) % 10));
        } else {
            // Leave special characters unchanged
            decrypted += ch;
        }
    }
    return decrypted;
}

int main() {
    string password;
    int key;

    cout << "Enter the password to encrypt: ";
    getline(cin, password);

    cout << "Enter the encryption key (integer): ";
    cin >> key;

    // Encrypt the password
    string encryptedPassword = encryptPassword(password, key);
    cout << "\nEncrypted Password: " << encryptedPassword << endl;

    // Decrypt the password
    string decryptedPassword = decryptPassword(encryptedPassword, key);
    cout << "Decrypted Password: " << decryptedPassword << endl;

    return 0;
}
