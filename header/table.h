#include"record.h"

template<typename Record>
class Table{
    private:
        string tabName;
        vector<Record> records;

        enum {
            NOT_FOUND = -1,
            REC_PER_PAGE = 10
        };

        int findRec(const Record &r) const;

    public:
        Table(const string &n) : tabName(n) {}
        void menu();
        void show() const;
        void add();
        void del();
};


using namespace std;

template<typename Record>
void Table<Record>::menu()
{
    while(1){
        cout << endl 
            << "--- " << tabName << " ---" << endl
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
                add();
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

template<typename Record>
int Table<Record>::findRec(const Record &r) const
{
    int i = 0;

    for(auto rec : records){
        if(rec.compPrim(r)){
            return i;
        }

        i++;
    }

    return NOT_FOUND;
}


template<typename Record>
void Table<Record>::add()
{
    cout << endl
        << "--- 添加记录 ---" << endl
        << endl
        << "请输入以下信息" << endl;

        Record rec;

        if(rec.set()){
            if(findRec(rec) == NOT_FOUND){
                records.push_back(rec);
                cout << "录入成功！" << endl;
                return;
            }
            else{
                cout << "记录重复，";
            }
        }

        cout << "录入失败！" << endl;
}

