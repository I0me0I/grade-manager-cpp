#include"common.h"

class Student{
    private:
        int number;
        char name[NAME_LEN];
        bool sex;
        int age;
    
    public:
        bool set();
        bool compPrim(const Student &s) const;
};

