#include"table.h"

class Manager{
    private:
        Table<Student> stuTab;
    public:
        Manager();
        void menu();
        void importData();
        void exportData() const;
};