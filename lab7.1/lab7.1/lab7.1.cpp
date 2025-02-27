#include <iostream>
#include <clocale>
using namespace std;


double add(double a, double b) {
    return a + b;
}

// Перегруженная функция для сложения обыкновенных дробей
void add(int num1, int den1, int num2, int den2, int& resNum, int& resDen) {
    // Находим общий знаменатель
    resDen = den1 * den2;
    // Складываем числители
    resNum = num1 * den2 + num2 * den1;

    // Упрощаем дробь (находим наибольший общий делитель)
    int g = 1;
    int small = (resNum < resDen) ? resNum : resDen;
    for (int i = 2; i <= small; ++i) {
        if (resNum % i == 0 && resDen % i == 0) {
            g = i;
        }
    }

    // Упрощаем дробь
    resNum /= g;
    resDen /= g;
}

int main() {
    setlocale(LC_ALL, "russian");
    // Пример вызова функции для сложения десятичных дробей
    double dec1, dec2;
    cout << "Введите первую десятичную дробь: ";
    cin >> dec1;
    cout << "Введите вторую десятичную дробь: ";
    cin >> dec2;
    cout << "Сумма десятичных дробей: " << add(dec1, dec2) << endl;

    // Пример вызова функции для сложения обыкновенных дробей
    int num1, den1, num2, den2, resNum, resDen;
    cout << "Введите первый числитель: ";
    cin >> num1;
    cout << "Введите первый знаменатель: ";
    cin >> den1;
    cout << "Введите второй числитель: ";
    cin >> num2;
    cout << "Введите первый знаменатель: ";
    cin >> den2;
    add(num1, den1, num2, den2, resNum, resDen);
    cout << "Сумма обыкновенных дробей: " << resNum << "/" << resDen << endl;

    return 0;
}