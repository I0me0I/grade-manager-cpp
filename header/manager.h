#include"table.h"

class Manager{
    private:
        Table<Student> stuTab;
        Table<Course> couTab;
        Table<Grade> gradTab;

    public:
        Manager();
        void menu();
        void importData();
        void exportData() const;
};