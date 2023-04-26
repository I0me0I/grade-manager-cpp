#include"../header/manager.h"

int main()
{
    Manager man;
    man.menu();

    std::cout << "请按任意键继续. . ." << std::endl;
    std::cin.get();
}