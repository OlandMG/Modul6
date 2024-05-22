#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

// Fungsi untuk membalikkan sebuah kata menggunakan stack
string reverseWord(const string &word) {
    stack<char> charStack;
    for (char ch : word) {
        charStack.push(ch);
    }

    string reversedWord;
    while (!charStack.empty()) {
        reversedWord += charStack.top();
        charStack.pop();
    }

    return reversedWord;
}

// Fungsi untuk membalikkan setiap kata dalam kalimat
string reverseWordsInSentence(const string &sentence) {
    stringstream ss(sentence);
    string word;
    string reversedSentence;

    // Memproses setiap kata dalam kalimat
    while (ss >> word) {
        reversedSentence += reverseWord(word) + " ";
    }

    // Menghapus spasi ekstra di akhir kalimat
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }

    return reversedSentence;
}

int main() {
    string input;

    // Input kalimat dari pengguna
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, input);

    // Mengecek apakah kalimat memiliki minimal 3 kata
    stringstream ss(input);
    int wordCount = 0;
    string word;
    while (ss >> word) {
        wordCount++;
    }

    if (wordCount < 3) {
        cout << "Kalimat harus memiliki minimal 3 kata." << endl;
    } else {
        // Membalikkan setiap kata dalam kalimat
        string reversedSentence = reverseWordsInSentence(input);
        cout << "Kebalikan: " << reversedSentence << endl;
    }

    return 0;
}
