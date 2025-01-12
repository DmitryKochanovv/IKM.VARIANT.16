#include "zagolovok.h"
#include <iostream>

using namespace std;

//�������������� � ������
BigChislo createBigChislo(const string& num) {
    BigChislo result;
    result.value = num;
    return result;
}

//�������� �� ������������ ����� �������������
bool isValid(const BigChislo& num, string& errorMessage) {

    //���� ������ �����
    if (num.value.empty()) {
        errorMessage = "������: ������� ������ ������! ������������� ���������!";
        return false;
    }

    //�������� �� ������������� �����,���� ������ ������� -
    if (num.value[0] == '-') {
        errorMessage = "������: ������� ������������� �����. ������ �� �������������� ����� �� ����������!������������� ���������!";
        return false;
    }

    //�������� �� ������� ����/����
    for (size_t i = 0; i < num.value.length(); i++) {
        if (num.value[i] < '0' || num.value[i] > '9') {
            errorMessage = "������: ������� ������������ �������. ����������, ������� ������ �����!������������� ���������!";
            return false;
        }
    }

    //�������� �� ����� �����
    if (num.value.length() < 40) {
        errorMessage = "������: ����� ������ ��������� ����� 40 ����.������������� ���������!";
        return false;
    }

    //���� ��� �������� ��������
    errorMessage = "";
    return true;
}





//�������� ��� ������ ��������� ��������� ������



//��������� ���� �����, ��� ���� ����� ������ �������� �� ����� ������ ����������
int Sravnenie(const BigChislo& num1, const BigChislo& num2) {
    if (num1.value.length() > num2.value.length())
        return 1; //������ ����� �������

    if (num1.value.length() < num2.value.length())
        return -1; //������ ����� �������

    //���������� ���������� �����
    for (size_t i = 0; i < num1.value.length(); i++) {
        if (num1.value[i] > num2.value[i])
            return 1; //���� 1 ����� ������

        if (num1.value[i] < num2.value[i])
            return -1; //���� 2 ����� ������
    }
    return 0; //����� �����
}

//�������� ���� ������,��� ���� ����� ���������� ������� �������� mid
BigChislo Summa(const BigChislo& num1, const BigChislo& num2) {
    string result;
    int perenos = 0; //���������� ��� �������� 
    int i = num1.value.length() - 1; //������ ���������� ������� ������� �����
    int j = num2.value.length() - 1; //������ ���������� ������� ������� �����

    //���� ���� ����� ��� �������� ��� �������
    while (i >= 0 || j >= 0 || perenos) {
        int chislo1 = 0;
        int chislo2 = 0;

        //���� ���� ����� � ������ �����, ����� �,����� ������ �� ������ ������
        if (i >= 0) {
            chislo1 = num1.value[i] - '0'; //����������� ������ � �����
            i--;
        }

        if (j >= 0) {
            chislo2 = num2.value[j] - '0';
            j--;
        }
        int sum = chislo1 + chislo2 + perenos;

        //������� ��� ���������� �������,��������� � ���������
        perenos = sum / 10;
        result = char((sum % 10) + '0') + result;
    }
    return createBigChislo(result);
}

//��������� ���� �����,��������� ������� ������
BigChislo Subtract(const BigChislo& num1, const BigChislo& num2) {
    string result;
    int borrow = 0;
    int i = num1.value.length() - 1; //������ ���������� ������� ������� �����
    int j = num2.value.length() - 1; //������ ���������� ������� ������� �����

    //���� ���� ����� ��� ���������
    while (i >= 0) {
        int chislo1 = num1.value[i--] - '0' - borrow; //����� ������� ����� � ������ �������������
        int chislo2 = (j >= 0) ? num2.value[j--] - '0' : 0; //����� ������� �����
        if (chislo1 < chislo2) { //���� ����� ����� �� ����������� �������
            chislo1 += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result = char((chislo1 - chislo2) + '0') + result;
    }

    //�������  ����
    size_t pos = 0;
    while (pos < result.length() && result[pos] == '0') {
        pos++;
    }
    if (pos == result.length()) {
        return createBigChislo("0"); //����  ����
    }
    return createBigChislo(result.substr(pos));
}

//��������� ���� ����� ��� ���� ����� ���������� ������� �����,�������� �� �����
BigChislo Multiply(const BigChislo& num1, const BigChislo& num2) {
    if (num1.value == "0" || num2.value == "0")
        return createBigChislo("0"); //���� ���� �� �����  ����

    int len1 = num1.value.length(); //����� ������� �����
    int len2 = num2.value.length(); //����� ������� �����
    string result(len1 + len2, '0'); //��������

    //�������� ������ ����� ������� ����� �� ������ ����� ������� �����
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1.value[i] - '0') * (num2.value[j] - '0') + (result[i + j + 1] - '0');
            result[i + j + 1] = (product % 10) + '0'; //���������� �������
            result[i + j] += product / 10; //��������� �������
        }
    }

    //������� ������� ����
    size_t pos = 0;
    while (pos < result.length() && result[pos] == '0') {
        pos++;
    }
    if (pos == result.length()) {
        return createBigChislo("0"); //���� ���������  ����
    }
    return createBigChislo(result.substr(pos));
}

//������� ����� �� 2
BigChislo Split(const BigChislo& num) {
    string result;
    int ostatok = 0; //�������

    //����� ������ ����� �� 2
    for (size_t i = 0; i < num.value.length(); i++) {
        int digit = num.value[i] - '0';
        int value = ostatok * 10 + digit;
        result += char((value / 2) + '0');
        ostatok = value % 2;
    }

    //������� ������� ����
    size_t pos = 0;
    while (pos < result.length() && result[pos] == '0') {
        pos++;
    }
    if (pos == result.length()) {
        return createBigChislo("0"); //���� ���������  ����
    }
    return createBigChislo(result.substr(pos)); //���������� ���������
}

//���������� ����������� �����
string Koren(const BigChislo& num) {
    BigChislo left = createBigChislo("0"); //����� �������
    BigChislo right = num; //������ �������
    string result;

    //������� ����� ����� ����������� �����
    while (Sravnenie(left, right) <= 0) {
        BigChislo mid = Split(Summa(left, right)); //������� ��������
        BigChislo midSqrt = Multiply(mid, mid); //�������� ������ � ������� 

        int cmp = Sravnenie(midSqrt, num); //���������� ������� � �������� ������ 
        if (cmp == 0) {
            result = mid.value;
            break;
        }
        else if (cmp < 0) {
            left = Summa(mid, createBigChislo("1")); //���� ������� ������ ����������� ����� �������
        }
        else {
            right = Subtract(mid, createBigChislo("1")); //���� ������� ������ ��������� ������ �������
        }
    }

    if (result.empty()) {
        result = Subtract(left, createBigChislo("1")).value;
    }

    //������ � ������� ������,��������� ������
    result += ".";

    //������� ������� ����� (2 ����� ����� �������)
    BigChislo ostatok = Subtract(num, Multiply(createBigChislo(result.substr(0, result.find('.'))), createBigChislo(result.substr(0, result.find('.')))));
    ostatok = Multiply(ostatok, createBigChislo("100")); //�������� ������� �� 100 

    BigChislo fraction = Split(ostatok); //��������������� �������� ������� ����� 
    string fractionStr = fraction.value;

    //��������� ������� ����� � ����������
    if (fractionStr.length() < 2) {
        fractionStr = string(2 - fractionStr.length(), '0') + fractionStr; //��������� ������
    }
    result += fractionStr.substr(0, 2); //����� ������ 2 ����� ����� �������

    return result;
}

//������� ��� �������� �����
void waitForEnter() {
    cout << "������� Enter ��� ������...";
    string input;
    getline(cin, input);
}
