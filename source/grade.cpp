#include"../header/record.h"

using namespace std;

bool Grade::setAll()
{
    return SetInt("学号", stunum)
        && SetInt("课程号", counum)
        && SetInt("分数", score, 0, 100);
}

bool Grade::compPrim(const Grade &g) const
{
    return (stunum == g.stunum)
        && (counum == g.counum);
}

void Grade::showCols()
{
    cout << "学号\t 课程号\t 分数" << endl;
}

void Grade::showValues() const
{
    cout << stunum << "\t "
        << counum << "\t "
        << score << endl;
}

bool Grade::setPrim()
{
    return SetInt("学号", stunum)
        && SetInt("课程号", counum);
}

int Grade::chooseCol()
{
    cout << "1.学号" << endl
        << "2.课程号" << endl
        << "3.分数" << endl
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
        case STUNUM:
        case COUNUM:
        case SCORE:
            return key;
        
        default:
            cout << "输入的数字无效，";
            return 0;
    }
}

bool Grade::specRange(int col, Range &range)
{
    switch(col){
        case STUNUM:
        case COUNUM:
        case SCORE:
            return SetInt("最小值", range.min, 0)
                && SetInt("最大值", range.max, range.min);
        
        default:
            return false;
    }
}

bool Grade::match(int col, const Range &range) const
{
    switch(col){
        case STUNUM:
            return (stunum >= range.min) && (stunum <= range.max);

        case COUNUM:
            return (counum >= range.min) && (counum <= range.max);
        
        case SCORE:
            return (score >= range.min) && (score <= range.max);
        
        default:
            return false;
    }
}

bool Grade::setValue(int col)
{
    switch(col){
        case STUNUM:
            return SetInt("学号", stunum);

        case COUNUM:
            return SetInt("课程号", counum);
        
        case SCORE:
            return SetInt("分数", score, 0, 100);
        
        default:
            return false;
    }
}