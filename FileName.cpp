#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void setConsoleColor(const string& color) {
    if (color == "blue") {
        system("color 01");
    }
    else if (color == "green") {
        system("color 02");
    }
    else if (color == "yellow") {
        system("color 06");
    }
    else if (color == "red") {
        system("color 04");
    }
    else {
        system("color 07");
    }
}

void saveSettings(const string& quote, const string& color) {
    ofstream fout("settings.txt");
    fout << quote << "\n" << color;
    fout.close();
}

int main() {
    setlocale(0, "");

    string quote;
    string color;

    ifstream fin("settings.txt");

    if (fin.is_open()) {

        getline(fin, quote);
        getline(fin, color);
        fin.close();

        setConsoleColor(color);

        cout << "Сохраненные настройки:\n";
        cout << "Любимая цитата: " << quote << endl;
        cout << "Цвет текста: " << color << endl;

        char choice;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;
        cin.ignore();

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новую любимую цитату: ";
            getline(cin, quote);

            cout << "Введите цвет текста (blue, green, yellow, red): ";
            cin >> color;

            saveSettings(quote, color);
            setConsoleColor(color);

            cout << "Настройки обновлены!\n";
        }
    }
    else {

        cout << "Введите любимую цитату: ";
        getline(cin, quote);

        cout << "Введите цвет текста (blue, green, yellow, red): ";
        cin >> color;

        saveSettings(quote, color);
        setConsoleColor(color);

        cout << "Настройки сохранены!\n";
    }

    cout << "\nИтог:\n";
    cout << "Любимая цитата: " << quote << endl;
    cout << "Цвет текста: " << color << endl;

    return 0;
}