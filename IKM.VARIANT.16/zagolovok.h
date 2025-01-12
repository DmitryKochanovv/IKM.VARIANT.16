#pragma once
#include <string>
using namespace std;

//��������� ��� ��������� ������� ����� � ���� �����
struct BigChislo {
    string value;
};

//�������� ����� � ���� ������
BigChislo createBigChislo(const string& num = "0");

//�������� �� ������������ ����� �������������
bool isValid(const BigChislo& num, string& errorMessage);

//��������� ���� �����
int Sravnenie(const BigChislo& num1, const BigChislo& num2);

//�������� ���� �����
BigChislo Summa(const BigChislo& num1, const BigChislo& num2);

//��������� ���� �����
BigChislo Subtract(const BigChislo& num1, const BigChislo& num2);

//��������� ���� �����
BigChislo Multiply(const BigChislo& num1, const BigChislo& num2);

//������� ����� �� 2
BigChislo Split(const BigChislo& num);

//���������� ����������� �����
string Koren(const BigChislo& num);

//������� ��� �������� ����� �� ������������
void waitForEnter();
