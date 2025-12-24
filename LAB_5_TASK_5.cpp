#include <iostream>
#include <vector>

using namespace std;

int main() {
  setlocale(LC_ALL, "RU");

  vector<string> names = {
    "Алексей", "Дмитрий", "Сергей", "Андрей", "Иван",
    "Михаил", "Павел", "Николай", "Владимир", "Александр",
    "Евгений", "Максим", "Артем", "Денис", "Константин", "Роман",
    "Виталий", "Олег", "Юрий", "Григорий"
  };
  vector<string> surnames = {
    "Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов",
    "Попов", "Васильев", "Соколов", "Михайлов", "Новиков",
    "Фёдоров", "Морозов", "Волков", "Алексеев", "Лебедев",
    "Семёнов", "Егоров", "Павлов", "Козлов", "Орлов"

  };
  int count;
  cout << "количество народа"<<"  ";
  cin >> count;

  if (count <= 0) {
    cout << "только положительные";
    return 1;
  }

  for (int i = 0; i < count; i++) {
    int namesd = rand() % names.size();
    int surnamesd = rand() % surnames.size();

    cout << (i + 1) << " " << names[namesd] << " " << surnames[surnamesd] << endl;


  }


}
