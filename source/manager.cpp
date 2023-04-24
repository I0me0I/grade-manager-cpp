#include"../header/manager.h"

using namespace std;

void Manager::menu()
{
    while(1){
        cout << endl 
            << "--- 学生成绩管理系统 ---" << endl
            << endl
            << "1.从文件导入" << endl
            << "2.导出到文件" << endl
            << "3.操作学生信息表" << endl
            << "4.操作学生成绩表" << endl
            << "5.操作课程信息表" << endl
            << "0.退出" << endl
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
                //importFile();
                break;
            case 2:
                //exportFile();
                break;
            case 3:
                //studentTable.menu();
                break;
            case 4:
                //gradeTable.menu();
                break;
            case 5:
                //courseTable.menu();
                break;
            case 0:
                return;
            default:
                cout << "输入的数字无效，请重新输入！" << endl;
        }
    }
}