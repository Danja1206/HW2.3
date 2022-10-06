#include <iostream>
#include <list>
#include <optional>
#include "Task1.h";
#include "Task2.h";
#include "Task3.h";
using namespace std;

void L1()
{
    list<float> List{ 1.1f,2.2f,3.3f,4.4f };
    average_push_back(List);
    for (auto& i : List)
        cout << i << " ";
}

void L2()
{
    Matrix M(cin);
    cout << endl;
    M.printMatrix();
    M.printAnswer();
}

void L3()
{
    for (const auto& i : Range<int>(0, 20))
        cout << i << " ";
    cout << endl;
    for (const auto& i : Range<float>(2, 10, 0.5f))
        cout << i << " ";
    cout << endl;
}
int main()
{
	setlocale(0, "rus");
    L1();
    L2();
    L3();
    return 0;
}

