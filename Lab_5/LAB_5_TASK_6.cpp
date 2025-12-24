#include <iostream>  
#include <string>    
#include <vector>    

using namespace std; 

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Сколько строк ты хочешь ввести? ";
    cin >> n;
    vector<string> stroki; 
    cout << "Теперь вводи " << n << " строки, по одной на строку:\n";

    for (int i = 0; i < n; i++) {
        string s;           
        getline(cin, s);   
        stroki.push_back(s); 
    }

    string poisk;
    cout << "\nчто хочешь буквы фразы: ";
    getline(cin, poisk);
    cout << "\nвот что нашлось:\n";
    bool nashli_chto_to = false; 

    for (int i = 0; i < stroki.size(); i++) {
        
        if (stroki[i].find(poisk) != string::npos) {
            cout << stroki[i] << endl;  
            nashli_chto_to = true;      
        }
    }
    if (!nashli_chto_to) {
        cout << "Ничего не найдено :(\n";
    }

    return 0;
}
