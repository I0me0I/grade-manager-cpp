#include"../header/record.h"

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