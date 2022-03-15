// Lesson5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string_view>
using namespace std;

template <template <typename, typename> class T, typename N, typename Tit>
void insert_sorted(T<N, Tit>& container, const N& i)
{
    //typename T<N>
    const auto bound = lower_bound(begin(container), end(container), i);
    container.insert(bound, i);
}

template<template<typename, typename> class T, typename N, typename Tit>
void Print(const T<N, Tit>& container)
{
    copy(container.begin(), container.end(), ostream_iterator<N>{cout, " "});
    cout << endl;
    cout << endl;
}

template <typename AnyIt>
void PrintUniqueWords(AnyIt beginIt, AnyIt endIt)
{
    unordered_set<string> us(beginIt, endIt);
    copy(us.begin(), us.end(), ostream_iterator<string>(cout, " "));
}
void Zadanie1()
{
    /*--------------------------------------------------
    Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
    и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз).
    Продемонстрировать работу функции, передав итераторы различных типов.
    ----------------------------------------------------*/
    vector<string> v{"kolya","vasya","lesya","kolya","mama","petya","misha","agata","misha","misha","kolya","asdadad","vasya"};
    Print(v);

    PrintUniqueWords(v.begin(), v.end());
    
   

};


int Zadanie2()
{
    /*--------------------------------------------------
    Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные пользователем
    из стандартного потока ввода и разбивать их на предложения. Далее программа должна вывести пользователю все предложения,
    отсортировав их по длине.
    ----------------------------------------------------*/
    cout << endl;
    string s, s_out;
    istringstream istr;

    multimap<int,string> sentences;


    while (getline(cin, s))
    {
        if (!s.empty())
        {
            s_out += s;
        }
    }
    istringstream input(s_out);
    for (string tempStr; getline(input,tempStr, '.'); )
    {
        sentences.insert({ tempStr.length(),tempStr });
    }

    for_each(sentences.begin(), sentences.end(), [](pair<int, string> item) {cout << item.second << endl;});
    system("pause");
    return 1;
        
};




void Zadanie3()
{
    /*--------------------------------------------------

    ----------------------------------------------------*/



};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер задания цифрой" << std::endl;
    unsigned short nomerZadania;

    std::cin >> nomerZadania;

    switch (nomerZadania)
    {
    case 1:Zadanie1(); break;

    case 2:Zadanie2(); break;

    case 3:Zadanie3(); break;

    default: break;
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
