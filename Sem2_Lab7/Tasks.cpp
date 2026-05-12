#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>
#include <sstream>

using namespace std;

// ==================== ÇÀÄÀÍÈÅ 1 ====================
template <typename Container>
void Print(const Container& container, const string& delimiter) {
    bool first = true;
    for (const auto& elem : container) {
        if (!first) cout << delimiter;
        cout << elem;
        first = false;
    }
    cout << endl;
}

void task1() {
    cout << "\n========== ÇÀÄÀÍÈÅ 1 ==========" << endl;
    vector<int> data = { 1, 2, 3 };
    cout << "vector<int>: ";
    Print(data, ", ");

    vector<string> words = { "apple", "banana", "cherry" };
    cout << "vector<string>: ";
    Print(words, " | ");
}

// ==================== ÇÀÄÀÍÈÅ 2 ====================
void task2() {
    cout << "\n========== ÇÀÄÀÍÈÅ 2 ==========" << endl;
    cout << "Ââåäèòå öåëûå ÷èñëà (äëÿ âûõîäà ââåäèòå '0' è íàæìèòå Enter):" << endl;

    set<int> seen;
    int x;

    while (cin >> x && x != 0) {  // 0 - ïðèçíàê âûõîäà
        if (seen.find(x) != seen.end()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            seen.insert(x);
        }
    }
    cin.clear();  // î÷èùàåì ôëàãè îøèáîê
    cin.ignore(32767, '\n');  // î÷èùàåì áóôåð
}

// ==================== ÇÀÄÀÍÈÅ 3 ====================
void task3() {
    cout << "\n========== ÇÀÄÀÍÈÅ 3 ==========" << endl;
    cout << "Ââåäèòå ñëîâà (äëÿ âûõîäà ââåäèòå ïóñòóþ ñòðîêó):" << endl;

    vector<string> words;
    string line;

    while (getline(cin, line) && !line.empty()) {
        words.push_back(line);
    }

    if (words.empty()) {
        cout << "Íåò ñëîâ äëÿ àíàëèçà" << endl;
        return;
    }

    set<char> common;
    for (char ch : words[0]) {
        common.insert(ch);
    }

    for (size_t i = 1; i < words.size(); ++i) {
        set<char> current;
        for (char ch : words[i]) {
            current.insert(ch);
        }

        set<char> intersection;
        for (char ch : common) {
            if (current.find(ch) != current.end()) {
                intersection.insert(ch);
            }
        }
        common = intersection;
    }

    cout << "Îáùèå áóêâû: ";
    for (char ch : common) {
        cout << ch;
    }
    cout << endl;
}

// ==================== ÇÀÄÀÍÈÅ 4 ====================
void task4() {
    cout << "\n========== ÇÀÄÀÍÈÅ 4 ==========" << endl;
    cout << "Ââåäèòå ñëîâà (äëÿ âûõîäà ââåäèòå 'exit'):" << endl;

    map<string, int> counter;
    string word;

    while (cin >> word && word != "exit") {
        counter[word]++;
        cout << counter[word] << endl;
    }
    cin.clear();
    cin.ignore(32767, '\n');
}

// ==================== ÇÀÄÀÍÈÅ 5 ====================
template <typename T>
void Duplicate(vector<T>& v) {
    size_t original_size = v.size();
    for (size_t i = 0; i < original_size; ++i) {
        v.push_back(v[i]);
    }
}

void task5() {
    cout << "\n========== ÇÀÄÀÍÈÅ 5 ==========" << endl;
    vector<int> data = { 1, 2, 3 };

    cout << "Èñõîäíûé âåêòîð: ";
    Print(data, ", ");

    Duplicate(data);

    cout << "Ïîñëå Duplicate: ";
    Print(data, ", ");
}

// ==================== ÇÀÄÀÍÈÅ 6 ====================
template <typename Iter>
void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it) {
        cout << *it << endl;
    }
}

template <typename T>
void Process(const vector<T>& data) {
    vector<T> filtered;
    copy_if(data.begin(), data.end(),
        back_inserter(filtered),
        [](const T& x) { return x > 0; });
    PrintResults(filtered.begin(), filtered.end());
}

void task6() {
    cout << "\n========== ÇÀÄÀÍÈÅ 6 ==========" << endl;
    vector<int> data = { -1, 5, -3, 2, 0, 7 };

    cout << "Èñõîäíûå äàííûå: ";
    Print(data, " ");
    cout << "Ïîëîæèòåëüíûå ýëåìåíòû:" << endl;
    Process(data);
}

// ==================== ÇÀÄÀÍÈÅ 7 ====================
template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;

    Iter result = first;
    ++first;

    for (; first != last; ++first) {
        if (!(*result == *first)) {
            ++result;
            *result = *first;
        }
    }
    ++result;
    return result;
}

void task7() {
    cout << "\n========== ÇÀÄÀÍÈÅ 7 ==========" << endl;
    vector<int> data = { 1, 1, 2, 3, 3, 3, 4, 5, 5 };

    cout << "Èñõîäíûé âåêòîð: ";
    Print(data, " ");

    auto it = Unique(data.begin(), data.end());
    data.erase(it, data.end());

    cout << "Ïîñëå Unique: ";
    Print(data, " ");
}

// ==================== ÇÀÄÀÍÈÅ 8 ====================
void task8() {
    cout << "\n========== ÇÀÄÀÍÈÅ 8 ==========" << endl;

    // Ñîçäà¸ì ôàéë input.txt åñëè åãî íåò
    ofstream outfile("input.txt");
    if (outfile.is_open()) {
        outfile << "10 25 10 30 25 40 25 50 60" << endl;
        outfile.close();
        cout << "Ñîçäàí ôàéë input.txt ñ òåñòîâûìè äàííûìè" << endl;
    }

    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cerr << "Îøèáêà: íå óäàëîñü îòêðûòü ôàéë input.txt" << endl;
        return;
    }

    vector<int> data;
    int x;
    while (infile >> x) {
        data.push_back(x);
    }
    infile.close();

    if (data.empty()) {
        cout << "Ôàéë ïóñò" << endl;
        return;
    }

    cout << "Èñõîäíûé íàáîð äàííûõ: ";
    Print(data, " ");

    // 8a
    int n;
    cout << "Ââåäèòå ÷èñëî n: ";
    cin >> n;

    size_t count_n = count(data.begin(), data.end(), n);
    cout << "×èñëî " << n << " âñòðå÷àåòñÿ " << count_n << " ðàç(à)" << endl;

    cout << "Ïîçèöèè (èíäåêñû îò 0): ";
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == n) {
            cout << i << " ";
        }
    }
    cout << endl;

    // 8b
    int even_count = count_if(data.begin(), data.end(),
        [](int v) { return v % 2 == 0; });
    int odd_count = data.size() - even_count;

    cout << "Êîëè÷åñòâî ÷¸òíûõ ýëåìåíòîâ: " << even_count << endl;
    cout << "Íîìåðà ÷¸òíûõ ýëåìåíòîâ (1-èíäåêñàöèÿ): ";
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] % 2 == 0) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;

    int sum;
    if (even_count > odd_count) {
        sum = accumulate(data.begin(), data.end(), 0,
            [](int acc, int v) { return acc + (v % 2 == 0 ? v : 0); });
        cout << "Ñóììà ÷¸òíûõ ýëåìåíòîâ: " << sum << endl;
    }
    else {
        sum = accumulate(data.begin(), data.end(), 0);
        cout << "Ñóììà âñåõ ýëåìåíòîâ: " << sum << endl;
    }

    // 8c
    vector<int> sorted = data;
    sort(sorted.begin(), sorted.end());

    cout << "Îòñîðòèðîâàííûé íàáîð: ";
    Print(sorted, " ");

    // 8d
    if (data.size() >= 2) {
        swap(data.front(), data.back());
    }

    cout << "Ïîñëå ïåðåñòàíîâêè ïåðâîãî è ïîñëåäíåãî: ";
    Print(data, " ");
}

// ==================== ÃËÀÂÍÎÅ ÌÅÍÞ ====================
void showMenu() {
    cout << "\n========================================" << endl;
    cout << "   ËÀÁÎÐÀÒÎÐÍÀß ÐÀÁÎÒÀ ¹7" << endl;
    cout << "========================================" << endl;
    cout << "1. Çàäàíèå 1 - Print" << endl;
    cout << "2. Çàäàíèå 2 - Ïîâòîðÿþùèåñÿ ÷èñëà" << endl;
    cout << "3. Çàäàíèå 3 - Îáùèå áóêâû" << endl;
    cout << "4. Çàäàíèå 4 - Ñ÷¸ò÷èê ñëîâ" << endl;
    cout << "5. Çàäàíèå 5 - Duplicate" << endl;
    cout << "6. Çàäàíèå 6 - Process" << endl;
    cout << "7. Çàäàíèå 7 - Unique" << endl;
    cout << "8. Çàäàíèå 8 - Àíàëèç âåêòîðà" << endl;
    cout << "0. ÂÛÏÎËÍÈÒÜ ÂÑÅ ÇÀÄÀÍÈß ÏÎ Î×ÅÐÅÄÈ" << endl;
    cout << "9. Âûõîä" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Âàø âûáîð: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 0:
            cout << "\n*** ÇÀÏÓÑÊ ÂÑÅÕ ÇÀÄÀÍÈÉ ÏÎ Î×ÅÐÅÄÈ ***" << endl;
            task1();
            task5();  // çàäàíèå 5 íå òðåáóåò ââîäà
            task6();
            task7();
            // çàäàíèÿ 2,3,4,8 òðåáóþò ââîäà - ïðîïóñêàåì â àâòîìàòè÷åñêîì ðåæèìå
            cout << "\nÇàäàíèÿ 2,3,4,8 òðåáóþò ðó÷íîãî ââîäà." << endl;
            cout << "Çàïóñòèòå èõ îòäåëüíî ÷åðåç ìåíþ." << endl;
            break;
        case 9:
            cout << "Äî ñâèäàíèÿ!" << endl;
            break;
        default:
            cout << "Íåâåðíûé ââîä. Ïîïðîáóéòå ñíîâà." << endl;
            break;
        }

        if (choice != 9 && choice != 0) {
            cout << "\nÍàæìèòå Enter äëÿ ïðîäîëæåíèÿ...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 9);

    return 0;
}
