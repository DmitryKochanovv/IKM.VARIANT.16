#pragma once
#include <string>
using namespace std;

//структура для обработки больших чисел в виде строк
struct BigChislo {
    string value;
};

//создание числа в виде строки
BigChislo createBigChislo(const string& num = "0");

//проверка на корректность ввода пользователем
bool isValid(const BigChislo& num, string& errorMessage);

//сравнение двух чисел
int Sravnenie(const BigChislo& num1, const BigChislo& num2);

//сложение двух чисел
BigChislo Summa(const BigChislo& num1, const BigChislo& num2);

//вычитание двух чисел
BigChislo Subtract(const BigChislo& num1, const BigChislo& num2);

//умножение двух чисел
BigChislo Multiply(const BigChislo& num1, const BigChislo& num2);

//деление числа на 2
BigChislo Split(const BigChislo& num);

//извлечение квадратного корня
string Koren(const BigChislo& num);

//функция для ожидания ввода от пользователя
void waitForEnter();
