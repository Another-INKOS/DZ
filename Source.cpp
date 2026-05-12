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

// ==================== ЗАДАНИЕ 1 ====================
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
    cout << "\n========== ЗАДАНИЕ 1 ==========" << endl;
    vector<int> data = { 1, 2, 3 };
    cout << "vector<int>: ";
    Print(data, ", ");

    vector<string> words = { "apple", "banana", "cherry" };
    cout << "vector<string>: ";
    Print(words, " | ");
}

// ==================== ЗАДАНИЕ 2 ====================
void task2() {
    cout << "\n========== ЗАДАНИЕ 2 ==========" << endl;
    cout << "Введите целые числа (для выхода введите '0' и нажмите Enter):" << endl;

    set<int> seen;
    int x;

    while (cin >> x && x != 0) {  // 0 - признак выхода
        if (seen.find(x) != seen.end()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            seen.insert(x);
        }
    }
    cin.clear();  // очищаем флаги ошибок
    cin.ignore(32767, '\n');  // очищаем буфер
}

// ==================== ЗАДАНИЕ 3 ====================
void task3() {
    cout << "\n========== ЗАДАНИЕ 3 ==========" << endl;
    cout << "Введите слова (для выхода введите пустую строку):" << endl;

    vector<string> words;
    string line;

    while (getline(cin, line) && !line.empty()) {
        words.push_back(line);
    }

    if (words.empty()) {
        cout << "Нет слов для анализа" << endl;
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

    cout << "Общие буквы: ";
    for (char ch : common) {
        cout << ch;
    }
    cout << endl;
}

// ==================== ЗАДАНИЕ 4 ====================
void task4() {
    cout << "\n========== ЗАДАНИЕ 4 ==========" << endl;
    cout << "Введите слова (для выхода введите 'exit'):" << endl;

    map<string, int> counter;
    string word;

    while (cin >> word && word != "exit") {
        counter[word]++;
        cout << counter[word] << endl;
    }
    cin.clear();
    cin.ignore(32767, '\n');
}

// ==================== ЗАДАНИЕ 5 ====================
template <typename T>
void Duplicate(vector<T>& v) {
    size_t original_size = v.size();
    for (size_t i = 0; i < original_size; ++i) {
        v.push_back(v[i]);
    }
}

void task5() {
    cout << "\n========== ЗАДАНИЕ 5 ==========" << endl;
    vector<int> data = { 1, 2, 3 };

    cout << "Исходный вектор: ";
    Print(data, ", ");

    Duplicate(data);

    cout << "После Duplicate: ";
    Print(data, ", ");
}

// ==================== ЗАДАНИЕ 6 ====================
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
    cout << "\n========== ЗАДАНИЕ 6 ==========" << endl;
    vector<int> data = { -1, 5, -3, 2, 0, 7 };

    cout << "Исходные данные: ";
    Print(data, " ");
    cout << "Положительные элементы:" << endl;
    Process(data);
}

// ==================== ЗАДАНИЕ 7 ====================
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
    cout << "\n========== ЗАДАНИЕ 7 ==========" << endl;
    vector<int> data = { 1, 1, 2, 3, 3, 3, 4, 5, 5 };

    cout << "Исходный вектор: ";
    Print(data, " ");

    auto it = Unique(data.begin(), data.end());
    data.erase(it, data.end());

    cout << "После Unique: ";
    Print(data, " ");
}

// ==================== ЗАДАНИЕ 8 ====================
void task8() {
    cout << "\n========== ЗАДАНИЕ 8 ==========" << endl;

    // Создаём файл input.txt если его нет
    ofstream outfile("input.txt");
    if (outfile.is_open()) {
        outfile << "10 25 10 30 25 40 25 50 60" << endl;
        outfile.close();
        cout << "Создан файл input.txt с тестовыми данными" << endl;
    }

    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл input.txt" << endl;
        return;
    }

    vector<int> data;
    int x;
    while (infile >> x) {
        data.push_back(x);
    }
    infile.close();

    if (data.empty()) {
        cout << "Файл пуст" << endl;
        return;
    }

    cout << "Исходный набор данных: ";
    Print(data, " ");

    // 8a
    int n;
    cout << "Введите число n: ";
    cin >> n;

    size_t count_n = count(data.begin(), data.end(), n);
    cout << "Число " << n << " встречается " << count_n << " раз(а)" << endl;

    cout << "Позиции (индексы от 0): ";
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

    cout << "Количество чётных элементов: " << even_count << endl;
    cout << "Номера чётных элементов (1-индексация): ";
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
        cout << "Сумма чётных элементов: " << sum << endl;
    }
    else {
        sum = accumulate(data.begin(), data.end(), 0);
        cout << "Сумма всех элементов: " << sum << endl;
    }

    // 8c
    vector<int> sorted = data;
    sort(sorted.begin(), sorted.end());

    cout << "Отсортированный набор: ";
    Print(sorted, " ");

    // 8d
    if (data.size() >= 2) {
        swap(data.front(), data.back());
    }

    cout << "После перестановки первого и последнего: ";
    Print(data, " ");
}

// ==================== ГЛАВНОЕ МЕНЮ ====================
void showMenu() {
    cout << "\n========================================" << endl;
    cout << "   ЛАБОРАТОРНАЯ РАБОТА №7" << endl;
    cout << "========================================" << endl;
    cout << "1. Задание 1 - Print" << endl;
    cout << "2. Задание 2 - Повторяющиеся числа" << endl;
    cout << "3. Задание 3 - Общие буквы" << endl;
    cout << "4. Задание 4 - Счётчик слов" << endl;
    cout << "5. Задание 5 - Duplicate" << endl;
    cout << "6. Задание 6 - Process" << endl;
    cout << "7. Задание 7 - Unique" << endl;
    cout << "8. Задание 8 - Анализ вектора" << endl;
    cout << "0. ВЫПОЛНИТЬ ВСЕ ЗАДАНИЯ ПО ОЧЕРЕДИ" << endl;
    cout << "9. Выход" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Ваш выбор: ";
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
            cout << "\n*** ЗАПУСК ВСЕХ ЗАДАНИЙ ПО ОЧЕРЕДИ ***" << endl;
            task1();
            task5();  // задание 5 не требует ввода
            task6();
            task7();
            // задания 2,3,4,8 требуют ввода - пропускаем в автоматическом режиме
            cout << "\nЗадания 2,3,4,8 требуют ручного ввода." << endl;
            cout << "Запустите их отдельно через меню." << endl;
            break;
        case 9:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный ввод. Попробуйте снова." << endl;
            break;
        }

        if (choice != 9 && choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 9);

    return 0;
}