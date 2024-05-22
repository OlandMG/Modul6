#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Fungsi untuk menghapus spasi dan mengubah huruf menjadi huruf kecil
string preprocessString(const string &str) {
    string result;
    for (char ch : str) {
        if (isalnum(ch)) {
            result += tolower(ch);
        }
    }
    return result;
}

// Fungsi untuk mengecek apakah string adalah palindrom
bool isPalindrome(const string &str) {
    string processedStr = preprocessString(str);
    stack<char> charStack;

    // Masukkan semua karakter ke dalam stack
    for (char ch : processedStr) {
        charStack.push(ch);
    }

    // Periksa apakah string sama ketika dibaca dari depan dan dari stack
    for (char ch : processedStr) {
        if (ch != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string input;
    char choice;

    do {
        // Input kalimat dari pengguna
        cout << "Masukkan kalimat: ";
        getline(cin, input);

        // Periksa apakah kalimat adalah palindrom
        if (isPalindrome(input)) {
            cout << "Kalimat tersebut adalah palindrom" << endl;
        } else {
            cout << "Kalimat tersebut bukan palindrom" << endl;
        }

        // Tanya pengguna apakah ingin mengecek kalimat lain
        cout << "Apakah Anda ingin mengecek kalimat lain? (y/n): ";
        cin >> choice;
        cin.ignore();  // Mengabaikan karakter newline setelah pilihan

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
