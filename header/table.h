#include"common.h"

class Table{
    private:

    protected:
        virtual void addRecord();

    public:
        void menu();
        void show();
        void add();
        void del();
};

class StudentTable : Table{
    private:
        struct Student{
            int number;
            char name[20];
            bool sex;
            int age;
        };
    
    public:
};