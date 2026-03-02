#include <iostream>
using namespace std;
struct Bell {
    int b = 0;
    void sound() {
        cout << ((b = !b) ? "ding\n" : "dong\n"); //b=!b это сразу и замена b на противоположное и сравнение (не иначе как магия)
    }
};
int main(){
    Bell soudbell;
    soudbell.sound(); //Динь
    soudbell.sound(); //Дон
    soudbell.sound(); //Динь
}
 
