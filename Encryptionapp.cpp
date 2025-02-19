#include <iostream>
#include <string>
#include <limits>

using namespace std;

string encrypt(const string& text, int shift) {
    string encrypted = text;
    for (char& c : encrypted) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
    }
    return encrypted;
}

string decrypt(const string& text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    int choice, shift = 0;
    string text, encryptedText;
    bool hasEncryptedText = false;
    int lastShift = 0; // Store last shift value
    
    while (true) {
        cout << "\nText Encryptor/Decryptor" << endl;
        cout << "1. Encrypt Text" << endl;
        cout << "2. Decrypt Text" << endl;
        if (hasEncryptedText) {
            cout << "3. Decrypt Last Encrypted Text" << endl;
        }
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 4." << endl;
            continue;
        }
        
        if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }
        
        if (choice == 3 && hasEncryptedText) {
            cout << "Decrypted Text: " << decrypt(encryptedText, lastShift) << endl;
            continue;
        }
        
        cout << "Enter shift value (1-25): ";
        if (!(cin >> shift) || shift < 1 || shift > 25) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid shift value! Please enter a number between 1 and 25." << endl;
            continue;
        }
        cin.ignore(); // Ignore newline
        
        cout << "Enter text: ";
        getline(cin, text);
        
        if (choice == 1) {
            encryptedText = encrypt(text, shift);
            hasEncryptedText = true;
            lastShift = shift; // Store last used shift value
            cout << "Original Text: " << text << endl;
            cout << "Encrypted Text: " << encryptedText << endl;
        } else if (choice == 2) {
            string decryptedText = decrypt(text, shift);
            cout << "Original Text: " << text << endl;
            cout << "Decrypted Text: " << decryptedText << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
