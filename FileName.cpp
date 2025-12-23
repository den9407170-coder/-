#include <iostream>
#include <stdexcept>
using namespace std;

// Функция вычисления средней скорости: v = s / t
double averageSpeed(double distance, double time) {
    if (time == 0.0) {
        throw invalid_argument("Время не может быть равно 0 (деление на ноль).");
    }
    return distance / time;
}

int main() {
    setlocale(LC_ALL, "RUS");

    double distance, time;
    cout << "Введите общее расстояние (например, км): ";
    cin >> distance;
    cout << "Введите общее время (например, ч): ";
    cin >> time;
    if (distance < 0 || time < 0)
    {
        cout << "Ошибка!" << endl;
    }
    else {
        double speed = averageSpeed(distance, time);
        cout << "Средняя скорость: " << speed << endl;
    }


    return 0;
}