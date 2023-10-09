#include <iostream>

using namespace std;


void printBinaryUnInt(unsigned int value) {
    const int size = sizeof(unsigned int) * 8;
    for (int i = size - 1; i >= 0; i--) {
        cout << ((value >> i) & 1);
    }
    cout << endl;
}


void printBinaryDoub(double value) {
    unsigned long long double_bits = *reinterpret_cast<unsigned long long*>(&value);
    const int size = sizeof(double) * 8;
    for (int i = size - 1; i >= 0; i--) {
        if (i == 31 || i == 62) {
            cout << ' ';
        }
        cout << ((double_bits >> i) & 1);
    }
    cout << endl;
}

void setBitsUn(unsigned int& value, int startBit, int numBits) {
    if (startBit < 0 || startBit >= sizeof(unsigned int) * 8) {
        cout << "Неверный номер начального бита." << endl;
        return;
    }

    if (numBits < 1 || numBits > sizeof(unsigned int) * 8) {
        cout << "Неверное количество бит." << endl;
        return;
    }

    unsigned int mask = 0;
    for (int i = startBit; i < startBit + numBits; i++) {
        mask |= (1u << i);
    }

    value |= mask;
}

void setBitsDou(double& value, int startBit, int numBits) {
    if (startBit < 0 || startBit >= sizeof(double) * 8) {
        cout << "Неверный номер начального бита." << endl;
        return;
    }

    if (numBits < 1 || numBits > sizeof(double) * 8) {
        cout << "Неверное количество бит." << endl;
        return;
    }

    unsigned long long* doubleBits = reinterpret_cast<unsigned long long*>(&value);

    unsigned long long mask = 0;
    for (int i = startBit; i < startBit + numBits; i++) {
        mask |= (1ull << i);
    }

    *doubleBits |= mask;
}



int main() {
    setlocale(LC_ALL, "Russian");

    unsigned int uint_value;
    double double_value;
    int x;
    while (true)
    {

        cout << "Выберете число: \n " <<
            "1. Двоичное представление типа unsigned int. \n" <<
            " 2. Двоичное представление типа double. \n" <<
            " 3. Задание для usnsigned int. \n" <<
            " 4. Задание для double. \n" <<
            " 0. Закрыть программу." << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Введите значение типа unsigned int: ";
            cin >> uint_value;

            cout << "Внутреннее представление unsigned int в двоичной системе: ";
            printBinaryUnInt(uint_value);
            break;
        case 2:
            cout << "Введите значение типа double: ";
            cin >> double_value;

            cout << "Внутреннее представление double в двоичной системе: ";
            printBinaryDoub(double_value);
            break;
        case 3:
            int startBit, numBits;

            cout << "Введите номер младшего бита для установки: ";
            cin >> startBit;

            cout << "Введите количество бит для установки: ";
            cin >> numBits;

            setBitsUn(uint_value, startBit, numBits);

            cout << "Значение после установки битов: " << uint_value << endl;

            cout << "Внутреннее представление unsigned int в двоичной системе: ";
            printBinaryUnInt(uint_value);
            break;

        case 4:
            int startBit1, numBits2;

            cout << "Введите номер младшего бита для установки: ";
            cin >> startBit1;

            cout << "Введите количество бит для установки: ";
            cin >> numBits2;

            setBitsDou(double_value, startBit1, numBits2);

            cout << "Значение после установки битов: " << double_value << endl;

            cout << "Внутреннее представление double в двоичной системе: ";
            printBinaryDoub(double_value);
            break;

        case 0:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}
