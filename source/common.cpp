#include"../header/common.h"

using namespace std;

bool SetString(const char *name, char *str, int n)
{
    cout << name << "：";

    string s;
    cin >> s;
    clearInput();

    auto len = s.size();
    if(len >= n){
        cout << "输入的字符串过长，";
        return false;
    }

    s.copy(str, len);
    str[len] = '\0';
    return true; 
}

bool SetInt(const char *name, int &val, int min, int max)
{
    cout << name << "：";

    if(!(cin >> val)){
        cout << "应输入数字，";
        clearInput();
        return false;
    }

    clearInput();

    if(val < min){
        cout << "输入的值不能小于" << min << "，";
        return false;
    }
    else if(val > max){
        cout << "输入的值不能大于" << max << "，";
        return false;
    }

    return true;
}

bool SetSex(bool &sex)
{
    cout << "性别：";

    string str;
    cin >> str;
    clearInput();

    if(str == "男"){
        sex = true;
    }
    else if(str == "女"){
        sex = false;
    }
    else{
        cout << "性别只能是‘男’或‘女’，";
        return false;
    }

    return true;
}