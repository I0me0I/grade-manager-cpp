#include"../header/record.h"

using namespace std;

bool Student::set()
{
    return SetInt("学号", number)
        && SetString("学生名", name, NAME_LEN)
        && SetSex(sex)
        && SetInt("年龄", age, 0, 200);
}

bool Student::compPrim(const Student &s) const
{
    return number == s.number;
}

void Student::showColumns()
{
    cout << "学号\t 学生名\t 性别\t 年龄" << endl;
}

void Student::show() const
{
    cout << number << "\t "
        << name << "\t "
        << (sex?"男":"女") << "\t "
        << age << endl;
}

bool Student::setPrim()
{
    return SetInt("学号", number);
}