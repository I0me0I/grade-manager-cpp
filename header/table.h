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
        void modify();
        void query();
        void save(ofstream &fout) const;
        void load(ifstream &fin);
};


using namespace std;

template<typename Record>
void Table<Record>::menu()
{
    while(1){
        cout << endl 
            << "--- 正在操作<" << tabName << "> ---" << endl
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
                show();
                break;
            case 2:
                add();
                break;
            case 3:
                del();
                break;
            case 4:
                modify();
                break;
            case 5:
                query();
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
        << "--- 向<" << tabName << ">添加记录 ---" << endl
        << endl
        << "请输入以下信息" << endl;

        Record rec;

        if(rec.setAll()){
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

template<typename Record>
void Table<Record>::show() const
{
    int page = 1;

    while(1){
        cout << endl
            << "--- " << tabName << " ---" << endl
            << endl;
        Record::showCols();
        
        for(
            int i = (page - 1) * REC_PER_PAGE;
            (i < page * REC_PER_PAGE) && (i < records.size());
            i++
        ){
            records[i].showValues();
        }

        cout << endl
            << "正在显示 第" << page << "页" << endl
            << "1.上一页" << endl
            << "2.下一页" << endl
            << "0.返回" << endl
            << endl
            << "选择你要执行的操作:";
        
        int key;

        if(!(cin >> key)){
            cout << "输入错误，请重试！" << endl << endl;
            clearInput();
            continue;            
        }

        clearInput();

        switch(key){
            case 1:
                if(page == 1){
                    cout << "已经是第一页!" << endl;
                }
                else{
                    page--;
                }
                break;
            case 2:
                if(page * REC_PER_PAGE >= records.size()){
                    cout << "已经是最后一页!" << endl;
                }
                else{
                    page++;
                }
                break;
            case 0:
                return;
            default:
                cout << "输入的数字无效，请重新输入！" << endl << endl;
        }
    }
}

template<typename Record>
void Table<Record>::del()
{
    cout << endl
        << "--- 删除<" << tabName << ">中的记录 ---" << endl
        << endl
        << "请输入以下信息" << endl;
    
    Record rec;

    if(rec.setPrim()){
        int pos = findRec(rec);

        if(pos != NOT_FOUND){
            records.erase(records.begin() + pos);
            cout << "删除成功！" << endl;
            return;
        }
        else{
            cout << "未找到记录，";
        }
    }

    cout << "删除失败！" << endl;
}

template<typename Record>
void Table<Record>::modify()
{
    cout << endl
        << "--- 修改<" << tabName << ">中的记录 ---" << endl
        << endl
        << "请输入以下信息" << endl;
    
    Record rec;

    do{
        if(!rec.setPrim()){
            break;
        }

        int pos = findRec(rec);
        if(pos == NOT_FOUND){
            cout << "未找到记录，";
            break;
        }

        cout << "选择你要修改的属性" << endl;

        int col = Record::chooseCol();
        if(col == 0){
            break;
        }

        cout << "输入修改后的值" << endl;

        if(records[pos].setValue(col)){
            cout << "修改成功！" << endl;
            return;
        }
    }while(false);
    cout << "修改失败！" << endl;
}

template<typename Record>
void Table<Record>::query()
{
    cout << endl
        << "--- 查询<" << tabName << ">中的记录 ---" << endl
        << endl
        << "请指定属性和值范围" << endl;

    do{
        int col = Record::chooseCol();
        if(col == 0){
            break;
        }

        Range range;
        if(!Record::specRange(col, range)){
            break;
        }

        Table<Record> tmp("查询结果集");

        for(auto rec : records){
            if(rec.match(col, range)){
                tmp.records.push_back(rec);
            }
        }

        if(tmp.records.size() > 0){
            tmp.show();
            return;
        }
        else{
            cout << "未找到匹配记录，";
        }
    }while(false);

    cout << "查询失败！" << endl;
}

template<typename Record>
void Table<Record>::save(ofstream &fout) const
{
    auto n = records.size();
    fout.write((char *)&n, sizeof(n));

    for( auto rec : records){
        fout.write((char *)&rec, sizeof(rec));
    }
}

template<typename Record>
void Table<Record>::load(ifstream &fin)
{
    auto n = records.size();
    fin.read((char *)&n, sizeof(n));

    Record rec;
    for(int i = 0; i < n; i++){
        fin.read((char *)&rec, sizeof(rec));
        records.push_back(rec);
    }
}