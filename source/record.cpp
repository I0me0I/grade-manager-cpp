#include"../header/record.h"

using namespace std;

bool Student::set()
{
    return SetInt("学号", number)
        && SetString("学生名", name, STR_LEN)
        && SetSex(sex)
        && SetInt("年龄", age, 0, 200);
}

bool Student::compPrim(const Student &s) const
{
    return number == s.number;
}

void Student::showCols()
{
    cout << "学号\t 学生名\t 性别\t 年龄" << endl;
}

void Student::show() const
{
    cout << number << "\t "
        << name << "\t "
        << (sex ? "男" : "女") << "\t "
        << age << endl;
}

bool Student::setPrim()
{
    return SetInt("学号", number);
}

int Student::chooseCol()
{
    cout << "1.学号" << endl
        << "2.学生名" << endl
        << "3.性别" << endl
        << "4.年龄" << endl
        << endl
        << "请选择：";
    
    int key;

    if(!(cin >> key)){
        cout << "输入错误，" << endl;
        clearInput();
        return 0;
    }

    switch(key){
        case NUMBER:
        case NAME:
        case SEX:
        case AGE:
            return key;
        
        default:
            cout << "输入的数字无效，" << endl;
            return 0;
    }
}

bool Student::setRange(int col, Range &range)
{
    switch(col){
        case NAME:
        case SEX:
            return SetString("包含的值", range.substr, STR_LEN);
        
        case NUMBER:
        case AGE:
            return SetInt("最小值", range.min, 0)
                && SetInt("最大值", range.max, range.min);
        
        default:
            return false;
    }
}

bool Student::match(int col, const Range &range) const
{
    switch(col){
        case NUMBER:
            return (number >= range.min) && (number <= range.max);

        case NAME:
            return string(name).find(range.substr) != string::npos;
        
        case SEX:
        {
            string str = range.substr;
            return sex ? (str == "男") : (str == "女");
        }   
        
        case AGE:
            return (age >= range.min) && (age <= range.max);
        
        default:
            return false;
    }
}