//2023111359 최가윤
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
    //멤버함수를 이용한 ++오퍼레이터 오버로딩
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
    //멤버함수를 이용한 --오퍼레이터 오버로딩
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
//전역함수 <<오퍼레이터 오버로딩
ostream& operator<<(ostream& os, const Date& d) {
    os << d.year << "년 " << d.month << "월 " << d.day << "일" << endl;
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