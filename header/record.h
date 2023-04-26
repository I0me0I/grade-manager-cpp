#include"common.h"

union Range{
    char substr[STR_LEN];
    struct {
        int min;
        int max;
    };
};

class Student{
    private:
        int number;
        char name[STR_LEN];
        bool sex;
        int age;

        enum{
            NUMBER = 1,
            NAME,
            SEX,
            AGE
        };
    
    public:
        bool setAll();
        bool compPrim(const Student &s) const;
        static void showCols();
        void showValues() const;
        bool setPrim();
        static int chooseCol();
        static bool specRange(int col, Range &range);
        bool match(int col, const Range &range) const;
        bool setValue(int col);
};

class Course{
    private:
        int number;
        char name[STR_LEN];
        int credit;

        enum{
            NUMBER = 1,
            NAME,
            CREDIT
        };
    
    public:
        bool setAll();
        bool compPrim(const Course &c) const;
        static void showCols();
        void showValues() const;
        bool setPrim();
        static int chooseCol();
        static bool specRange(int col, Range &range);
        bool match(int col, const Range &range) const;
        bool setValue(int col);
};

class Grade{
    private:
        int stunum;
        int counum;
        int score;

        enum{
            STUNUM = 1,
            COUNUM,
            SCORE
        };
    
    public:
        bool setAll();
        bool compPrim(const Grade &g) const;
        static void showCols();
        void showValues() const;
        bool setPrim();
        static int chooseCol();
        static bool specRange(int col, Range &range);
        bool match(int col, const Range &range) const;
        bool setValue(int col);
};
