#include <iostream>

using namespace std;


int klen(const char* s) {
    int count = 0;            
    int i = 0;               

    while (s[i] != '\0') { count++; i++;}
    return count;            
}


int main() {
    setlocale(LC_ALL, "RU");
    char text[1000];
    cout << "Дай строку:";
    cin.getline(text, 1000);
    cout << "ты ввел: " << text << endl;
    cout << "длинна: " << klen(text) << endl;
    return 0;
}
