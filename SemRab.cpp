#include <iostream>   // Подключаем библиотеку для ввода/вывода (cin, cout)
#include <vector>     // Подключаем вектор — динамический массив для временного хранения данных
#include <fstream>    // Подключаем работу с файлами (чтение/запись)
#include <sstream>    // Подключаем строковые потоки (для разбора строк по запятым)
#include <string>     // Подключаем работу со строками (std::string)
#include <algorithm>  // Подключаем алгоритмы (например, find, sort — пока не используется, но может пригодиться)

using namespace std;  // Используем стандартное пространство имён, чтобы не писать std:: перед каждым типом

// Перечисление для типа часов: кварцевые, механические, электронные
enum class TipChasov {
    quartz,      // кварцевые часы
    mechanical,  // механические часы
    electronic   // электронные часы
};

// Структура "Часы" — описывает одну запись о часах
struct Chasy {
    string model;              // Модель часов (например, "Casio A1")
    double cena;               // Цена в рублях (дробное число)
    int kolichestvo;           // Количество на складе (целое число)
    string magazin;            // Адрес магазина (например, "Ленина, 15")
    TipChasov tip;             // Тип часов (одно из значений из TipChasov)
};

// Функция для вывода информации об одном экземпляре часов
void vivod(const Chasy& chas) {
    string tipStr;  // Переменная для хранения текстового представления типа часов

    // Преобразуем enum TipChasov в строку для вывода
    if (chas.tip == TipChasov::quartz) {
        tipStr = "quartz";      // если тип — кварцевые
    } else if (chas.tip == TipChasov::mechanical) {
        tipStr = "mechanical";  // если тип — механические
    } else {
        tipStr = "electronic";  // иначе — электронные
    }

    // Выводим всю информацию о часах в читаемом виде
    cout << "Модель: " << chas.model
         << ", Цена: " << chas.cena << " руб."
         << ", На складе: " << chas.kolichestvo << " шт."
         << ", Магазин: " << chas.magazin
         << ", Тип: " << tipStr << endl;
}

// Функция вывода меню на экран
void printMenu() {
    cout << "=== Меню ===\n"
         << "1. Вывести весь список\n"
         << "2. Добавить новый товар\n"
         << "3. Удалить товар по модели\n"
         << "4. Очистить весь список\n"
         << "5. Сохранить список в файл\n"
         << "6. Загрузить список из файла (заменит текущий)\n"
         << "0. Выход\n"
         << "Выберите действие: ";
}

// Функция преобразования строки в тип часов (TipChasov)
TipChasov stringToTip(const string& s) {
    if (s == "quartz") return TipChasov::quartz;      // если строка "quartz" → возвращаем кварцевые
    if (s == "mechanical") return TipChasov::mechanical;  // если "mechanical" → механические
    if (s == "electronic") return TipChasov::electronic;  // если "electronic" → электронные
    return TipChasov::quartz; // если строка неизвестна — возвращаем кварцевые по умолчанию
}

// Функция чтения данных из файла
// Параметры: имя файла и ссылка на переменную n (количество записей)
Chasy* readChasyFromFile(const string& filename, int& n) {
    ifstream file(filename);  // Открываем файл для чтения
    if (!file.is_open()) {    // Если файл не удалось открыть
        cerr << "Ошибка открытия файла для чтения: " << filename << endl;
        n = 0;                // количество записей = 0
        return nullptr;       // возвращаем пустой указатель
    }

    vector<Chasy> chasyList;  // Временный вектор для хранения загруженных часов
    string line;              // Переменная для хранения одной строки из файла

    // Читаем файл построчно
    while (getline(file, line)) {
        // Удаляем символ возврата каретки (\r), если он есть (для совместимости с Windows)
        size_t cr = line.find('\r');
        if (cr != string::npos) line.erase(cr);

        stringstream ss(line);  // Создаём строковый поток из строки
        Chasy chas;             // Временная переменная для одной записи
        string model_str, cena_str, kolichestvo_str, magazin_str, tip_str;

        // Извлекаем поля, разделённые запятыми
        getline(ss, model_str, ',');
        getline(ss, cena_str, ',');
        getline(ss, kolichestvo_str, ',');
        getline(ss, magazin_str, ',');
        getline(ss, tip_str);   // последнее поле — тип (до конца строки)

        // Заполняем структуру
        chas.model = model_str;
        chas.cena = stod(cena_str);           // stod — строка в double
        chas.kolichestvo = stoi(kolichestvo_str); // stoi — строка в int
        chas.magazin = magazin_str;
        chas.tip = stringToTip(tip_str);      // преобразуем строку в тип часов

        chasyList.push_back(chas);  // Добавляем запись в вектор
    }

    file.close();  // Закрываем файл
    n = chasyList.size();  // Сохраняем количество загруженных записей

    // Если файл пуст
    if (n == 0) {
        cout << "Файл пуст." << endl;
        return nullptr;
    }

    // Создаём динамический массив и копируем в него данные из вектора
    Chasy* chasyArray = new Chasy[n];  // Выделяем память под n элементов
    for (int i = 0; i < n; ++i) {
        chasyArray[i] = chasyList[i];  // Копируем каждый элемент
    }

    return chasyArray;  // Возвращаем указатель на массив
}

// Функция сохранения массива часов в файл
void saveToFile(const Chasy* chasy, int n, const string& filename) {
    ofstream file(filename);  // Открываем файл для записи
    if (!file.is_open()) {    // Если не удалось открыть
        cerr << "Ошибка открытия файла для записи: " << filename << endl;
        return;  // Выходим из функции
    }

    // Проходим по всем элементам массива
    for (int i = 0; i < n; ++i) {
        string tipStr;
        if (chasy[i].tip == TipChasov::quartz) tipStr = "quartz";
        else if (chasy[i].tip == TipChasov::mechanical) tipStr = "mechanical";
        else tipStr = "electronic";

        // Записываем данные в файл в формате CSV: модель,цена,количество,магазин,тип
        file << chasy[i].model << ","
             << chasy[i].cena << ","
             << chasy[i].kolichestvo << ","
             << chasy[i].magazin << ","
             << tipStr << endl;
    }

    file.close();  // Закрываем файл
    cout << "Данные сохранены в файл: " << filename << endl;
}

// Основная функция программы
int main() {
    setlocale(LC_ALL, "RU");  // Включаем поддержку русского языка в консоли

    Chasy* chasy = nullptr;   // Указатель на массив часов (изначально пуст)
    int n = 0;                // Количество записей в массиве
    bool dataLoaded = false;  // Флаг: загружены ли данные (вне зависимости от источника)

    int ch;  // Переменная для хранения выбора пользователя в меню

    // Основной цикл программы — работает до выхода (выбор 0)
    while (true) {
        printMenu();  // Печатаем меню
        cin >> ch;    // Считываем выбор пользователя

        // Обработка выбора через оператор switch
        switch (ch) {
            // === КЕЙС 1: Вывод всего списка ===
            case 1: {
                if (!dataLoaded || n == 0) {
                    cout << "Список пуст." << endl;  // Если нет данных
                } else {
                    cout << "\n--- Список всех часов ---" << endl;
                    for (int i = 0; i < n; ++i) {
                        vivod(chasy[i]);  // Выводим каждый элемент
                    }
                }
                break;  // Выходим из case
            }

            // === КЕЙС 2: Добавить новый товар ===
            case 2: {
                Chasy newChas;        // Новая структура для ввода
                string tipInput;      // Временная строка для ввода типа

                cout << "Введите модель: ";
                cin >> newChas.model;
                cout << "Введите цену: ";
                cin >> newChas.cena;
                cout << "Введите количество: ";
                cin >> newChas.kolichestvo;
                cout << "Введите адрес магазина: ";
                cin >> newChas.magazin;
                cout << "Введите тип (quartz, mechanical, electronic): ";
                cin >> tipInput;
                newChas.tip = stringToTip(tipInput);  // Преобразуем строку в тип

                // Создаём временный массив на 1 элемент больше
                Chasy* temp = new Chasy[n + 1];
                // Копируем старые данные
                for (int i = 0; i < n; ++i) {
                    temp[i] = chasy[i];
                }
                temp[n] = newChas;  // Добавляем новую запись в конец

                delete[] chasy;     // Удаляем старый массив
                chasy = temp;       // Перенаправляем указатель на новый
                ++n;                // Увеличиваем счётчик
                dataLoaded = true;  // Данные теперь загружены (в памяти)

                cout << "Товар добавлен." << endl;
                break;
            }

            // === КЕЙС 3: Удалить по модели ===
            case 3: {
                if (n == 0) {
                    cout << "Список пуст, удалять нечего." << endl;
                    break;
                }

                string model;
                cout << "Введите модель для удаления: ";
                cin >> model;

                int index = -1;  // Индекс найденной модели (-1 = не найдена)
                for (int i = 0; i < n; ++i) {
                    if (chasy[i].model == model) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    cout << "Модель '" << model << "' не найдена." << endl;
                } else {
                    // Создаём временный массив на 1 элемент меньше
                    Chasy* temp = new Chasy[n - 1];
                    for (int i = 0, j = 0; i < n; ++i) {
                        if (i != index) {  // Пропускаем удаляемый элемент
                            temp[j++] = chasy[i];
                        }
                    }

                    delete[] chasy;  // Удаляем старый массив
                    chasy = temp;    // Перенаправляем указатель
                    --n;             // Уменьшаем счётчик

                    if (n == 0) dataLoaded = false;  // Если список пуст — снимаем флаг

                    cout << "Модель '" << model << "' удалена." << endl;
                }
                break;
            }

            // === КЕЙС 4: Очистить весь список ===
            case 4: {
                if (n == 0) {
                    cout << "Список уже пуст." << endl;
                } else {
                    delete[] chasy;     // Освобождаем память
                    chasy = nullptr;    // Обнуляем указатель
                    n = 0;              // Обнуляем счётчик
                    dataLoaded = false; // Снимаем флаг
                    cout << "Список очищен." << endl;
                }
                break;
            }

            // === КЕЙС 5: Сохранить в файл ===
            case 5: {
                if (n == 0) {
                    cout << "Список пуст, нечего сохранять." << endl;
                } else {
                    cout << "Сохраняем";
                    _sleep(750);  // Пауза 0.75 сек (только в Windows)
                    cout << ".";
                    _sleep(750);
                    cout << ".";
                    _sleep(750);
                    cout << "." << endl;
                    _sleep(500);

                    saveToFile(chasy, n, "chasy.txt");  // Вызываем функцию сохранения
                }
                break;
            }

            // === КЕЙС 6: Загрузить из файла ===
            case 6: {
                cout << "Загружаем";
                _sleep(750);
                cout << ".";
                _sleep(750);
                cout << ".";
                _sleep(750);
                cout << ".";
                _sleep(500);
                cout << endl;

                if (dataLoaded) {
                    delete[] chasy;  // Если данные уже были — удаляем старый массив
                }

                Chasy* loaded = readChasyFromFile("chasy.txt", n);  // Загружаем из файла
                chasy = loaded;           // Перенаправляем указатель
                dataLoaded = (chasy != nullptr);  // Если загрузка успешна — ставим флаг

                if (dataLoaded) {
                    cout << "Загружено " << n << " записей из файла chasy.txt" << endl;
                } else {
                    cout << "Не удалось загрузить данные из файла chasy.txt" << endl;
                    n = 0;  // Гарантируем, что n = 0 при ошибке
                }
                break;
            }

            // === КЕЙС 0: Выход ===
            case 0: {
                if (dataLoaded) {
                    delete[] chasy;  // Освобождаем память перед выходом
                }
                cout << "До свидания!" << endl;
                return 0;  // Завершаем программу
            }

            // === Неверный ввод ===
            default: {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
            }
        }

        // Пауза перед следующим действием: пользователь нажимает Enter
        cout << "\nНажмите Enter, чтобы продолжить...";
        cin.ignore();  // Игнорируем символ новой строки после cin
        cin.get();     // Ждём нажатия Enter
    }

    return 0;  // Точка выхода (достигается только при выходе через case 0)
}
