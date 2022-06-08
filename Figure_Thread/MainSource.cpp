#include<iostream> 
#include<thread>  //Файл в котором определен класс thread  
#include "windows.h"
using namespace std;

void printStr(const char* str) {
    cout << str << '\n';
}

void printArray(int a[], const int len) {
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ' ';
    }
}

void Print_rect()
{
    int hei = 5;
    int widh = 10; 

    for (int y = 0; y <= hei; y++)
    {
        for (int x = 0; x <= widh; x++)
        {
            if (x == 0 || x == widh)  cout << "*";
            if (y == 0 || y == hei) cout << "**";
            else cout << "  ";
        }
        cout << endl;
    }
}

void Print_square()
{
    Sleep(1000);
    int hei = 5;
    int widh = 10; 

    for (int y = 0; y < hei; y++)
    {
        for (int x = 0; x < widh; x++)
        {
            if (y == 0 || y == hei - 1 || x == 0 || x == widh / 2)  cout << "*";
            else cout << "  ";
        }
        cout << endl;
    }
}

void Print_treang()
{
    Sleep(2000);
    int hei = 5;
    int widh = 10;
    int i = 1;

    for (int y = 0; y < hei; y++)
    {
        for (int x = 0; x < widh; x++)
        {
            if (y == hei - 1 || x == 0) cout << "*";
            else cout << "  ";
            if (y == i && x == i)
            {
                i++;
                cout << "*";
            }
        }
        cout << endl;
    }
}

void Print_rect_2()
{
    Sleep(3000);
    int hei = 5;
    int widh = 10;
    int i = 0;

    for (int y = 0; y < hei; y++)
    {
        for (int x = 0; x < widh; x++)
        {
            if (y == 0 || y == hei - 1 || x == 0 || x == widh / 2)  cout << "*";
            else cout << "  ";
            if (y == i && x == i)
            {
                i++;
                cout << "*";
            }
        }
        cout << endl;
    }
}

int main() 
{   
    

    thread func_Rect(Print_rect);
    thread func_Square(Print_square);
    thread func_Treang(Print_treang);
    thread func_Rect_2(Print_rect_2);

    if (func_Rect.joinable())  func_Rect.join(); 
    if (func_Square.joinable())  func_Square.join();
    if (func_Treang.joinable())  func_Treang.join();
    if (func_Rect_2.joinable())  func_Rect_2.join();

    int hei = 5;
    int widh = 10;
    int i = 1;

    for (int y = 0; y < hei; y++)
    {
        for (int x = 0; x < widh; x++)
        {
            if (y == 0 || x == widh - 1) cout << "*";
            else cout << " ";
            if (y == i && x == i)
            {
                i++;
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}