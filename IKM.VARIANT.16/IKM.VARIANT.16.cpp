#include "zagolovok.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите число для извлечения квадратного корня (n > 40):" << endl;
    string numStr;
    getline(cin, numStr); //используем getline для ввода числа

    BigChislo num = createBigChislo(numStr);

    string errorMessage;
    if (!isValid(num, errorMessage)) {
        cout << errorMessage << endl;
        waitForEnter();
        return 1;
    }

    string sqrtResult = Koren(num); //сама функция корня,бинарный поиск
    cout << "Квадратный корень из числа " << num.value << " равен: " << sqrtResult << endl;
    waitForEnter();
    return 0;
}