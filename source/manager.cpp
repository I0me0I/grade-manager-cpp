#include"../header/manager.h"

using namespace std;

Manager::Manager()
: stuTab("学生信息表"), couTab("课程信息表"), gradTab("学生成绩表")
{

}

void Manager::menu()
{
    while(1){
        cout << endl 
            << "--- 学生成绩管理系统 ---" << endl
            << endl
            << "1.从文件导入" << endl
            << "2.导出到文件" << endl
            << "3.操作学生信息表" << endl
            << "4.操作课程信息表" << endl
            << "5.操作学生成绩表" << endl
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
                importData();
                break;
            case 2:
                exportData();
                break;
            case 3:
                stuTab.menu();
                break;
            case 4:
                couTab.menu();
                break;
            case 5:
                gradTab.menu();
                break;
            case 0:
                return;
            default:
                cout << "输入的数字无效，请重新输入！" << endl;
        }
    }
}

void Manager::importData()
{
    cout << endl
        << "--- 从文件导入 ---" << endl
        << endl
        << "请输入文件名：";

    string file;
    getline(cin, file);
    ifstream fin(file);

    if(!fin.is_open()){
        cout << "打开文件失败！" << endl;
        return;
    }

    stuTab.load(fin);
    couTab.load(fin);
    gradTab.load(fin);
    cout << "导入成功！" << endl;
}

void Manager::exportData() const
{
    cout << endl
        << "--- 导出到文件 ---" << endl
        << endl
        << "请输入文件名：";

    string file;
    getline(cin, file);
    ofstream fout(file);

    if(!fout.is_open()){
        cout << "打开文件失败！" << endl;
        return;
    }

    stuTab.save(fout);
    couTab.save(fout);
    gradTab.save(fout);
    cout << "导出成功！" << endl;
}