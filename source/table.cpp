#include"../header/table.h"

using namespace std;

void Table::menu()
{
    while(1){
        cout << endl 
            << "--- " << "name" << " ---" << endl
            << endl
            << "1.显示记录" << endl
            << "2.添加记录" << endl
            << "3.删除记录" << endl
            << "4.修改记录" << endl
            << "5.查询记录" << endl
            << "0.返回" << endl
            << endl
            << "选择你要执行的操作:";

        int key;
        
        if(!(cin >> key)){
            cout << "输入错误，请重试！" << endl;
            clearInput();
            continue;
        }

        clearInput();

        switch(key){
            case 1:
                //show();
                break;
            case 2:
                //add();
                break;
            case 3:
                //del();
                break;
            case 4:
                //modify();
                break;
            case 5:
                //query();
                break;
            case 0:
                return;
            default:
                cout << "输入的数字无效，请重新输入！" << endl;
        }
    }    
}