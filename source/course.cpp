#include"../header/record.h"

using namespace std;

bool Course::setAll()
{
    return SetInt("课号", number)
        && SetString("课程名", name, STR_LEN)
        && SetInt("学分", credit, 1, 100);
}

bool Course::compPrim(const Course &c) const
{
    return number == c.number;
}

void Course::showCols()
{
    cout << "课号\t 课程名\t 学分" << endl;
}

void Course::showValues() const
{
    cout << number << "\t "
        << name << "\t "
        << credit << endl;
}

bool Course::setPrim()
{
    return SetInt("课号", number);
}

int Course::chooseCol()
{
    cout << "1.课号" << endl
        << "2.课程名" << endl
        << "3.学分" << endl
        << endl
        << "请选择：";
    
    int key;

    if(!(cin >> key)){
        cout << "输入错误，";
        clearInput();
        return 0;
    }

    clearInput();

    switch(key){
        case NUMBER:
        case NAME:
        case CREDIT:
            return key;
        
        default:
            cout << "输入的数字无效，";
            return 0;
    }
}

bool Course::specRange(int col, Range &range)
{
    switch(col){
        case NAME:
            return SetString("包含的字符串", range.substr, STR_LEN);
        
        case NUMBER:
        case CREDIT:
            return SetInt("最小值", range.min, 0)
                && SetInt("最大值", range.max, range.min);
        
        default:
            return false;
    }
}

bool Course::match(int col, const Range &range) const
{
    switch(col){
        case NUMBER:
            return (number >= range.min) && (number <= range.max);

        case NAME:
            return string(name).find(range.substr) != string::npos;
        
        case CREDIT:
            return (credit >= range.min) && (credit <= range.max);
        
        default:
            return false;
    }
}

bool Course::setValue(int col)
{
    switch(col){
        case NUMBER:
            return SetInt("课号", number);

        case NAME:
            return SetString("课程名", name, STR_LEN);
        
        case CREDIT:
            return SetInt("学分", credit, 1, 100);
        
        default:
            return false;
    }
}