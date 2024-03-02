//2023111359 �ְ���
#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    ~Date() {}
    //����Լ��� �̿��� ++���۷����� �����ε�
    Date operator++() {
        ++day;
        if (day > 31) {
            day = 1;
            ++month;
            if (month > 12) {
                month = 1;
                ++year;
            }
        }
        return *this;
    }
    //����Լ��� �̿��� --���۷����� �����ε�
    Date operator--() {
        --day;
        if (day < 1) {
            day = 31;
            --month;
            if (month < 1) {
                month = 12;
                --year;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Date& d);
};
//�����Լ� <<���۷����� �����ε�
ostream& operator<<(ostream& os, const Date& d) {
    os << d.year << "�� " << d.month << "�� " << d.day << "��" << endl;
    return os;
}

int main() {
    Date d1(2023, 12, 31);
    cout << "    " << d1;
    cout << "++: ";
    cout << ++d1 << endl;

    Date d2(2023, 12, 31);
    cout << "    " << d2;
    cout << "--: ";
    cout << --d2 << endl;

    Date d3(2023, 1, 1);
    cout << "    " << d3;
    cout << "++: ";
    cout << ++d3 << endl;

    Date d4(2023, 1, 1);
    cout << "    " << d4;
    cout << "--: ";
    cout << --d4 << endl;
    return 0;
}