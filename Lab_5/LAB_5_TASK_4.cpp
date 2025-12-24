#include <iostream>
using namespace std;

string shifr(string text, int key){
    string res = "";
    for (char c : text){
        if (c >= 65 && c <= 122 && c!=91 && c!= 92 && c!= 93 && c!= 94 && c!= 95 && c!=96){
            c = (c+key >122) ? (c+key - 50) : (c+key);

        }
        res+=c;
    }
    return res;
}


string un_shifr (string text, int key){
    string res = "";
    for (char c : text){
        if (c >= 65 && c<=122 && c!=91 && c!= 92 && c!= 93 && c!= 94 && c!= 95 && c!=96){
            c = (c - key < 65) ? (c - key + 50) : (c - key);

        }
        res += c;
    }
    return res;
}


int main() {
    int ch;
    while (true){
        cout << "What do you want to do?\n1. Unshifr text\n2. Shifr text\n0. Exit" << endl;
        cin >> ch;
        switch (ch){
        case 1:{
            string text;
            cout << "Enter your string: ";
            cin.ignore();
            getline(cin, text);
            int key;
            cout << "enter key: ";
            cin >> key;
            cout << endl;
            cout << "unshifred text:\n" <<un_shifr(text, key) <<endl;
            cout << endl;
            break;
        }
        case 2:{
            string text;
            cout << "Enter your string: ";
            cin.ignore();
            getline(cin, text);
            int key;
            cout << "Enter key (letter shift): ";
            cin >> key;
            cout << endl;
            cout << "shifred text:\n" <<shifr(text, key) << endl;
            cout << endl;
            break;
        }
        case 0:{
            return 0;
        }
        default:{
            cout << "Invalid input" << endl;
            break;
                }

            }
        }
}
