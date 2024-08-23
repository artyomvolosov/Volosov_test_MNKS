﻿// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
struct item {
    int x;
    int y;
};
std::vector <item> myFunc(std::vector <item> data, int a);


int main()
{
    //Тестовый набор данных
    std::vector<item> data = {
        {1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10}
    };

    //Прореживание с шагом 3
    std::vector<item> three = myFunc(data, 3);

    //Прореживание с шагом 4
    std::vector<item> four = myFunc(data, 4);

    std::cout << "При n = 3 " << std::endl;
    for (int i = 0; i < three.size(); i++) {
        std::cout << "( " << three[i].x << ", " << three[i].y << " )" << std::endl;
    }
    std::cout << "При n = 4 " << std::endl;
    for (int i = 0; i < four.size(); i++) {
        std::cout << "( " << four[i].x << ", " << four[i].y << " )" << std::endl;
    }

    return 0;
}

//ПРОВЕРОЧНОЕ ЗАДАНИЕ
//ДЛЯ СОИСКАТЕЛЯ ВАКАНСИИ «ИНЖЕНЕР - ПРОГРАММИСТ»

//Дана последовательность отсчетов, представляющих собой пары(int Х : int Y).
//Отсчеты упорядочены по значениям Х. В этой последовательности могут встречаться непрерывные подпоследовательности,состоящие из идентичных отсчетов.
//Идентичные отсчеты имеют одинаковые значения Y.

//Реализовать функцию, прореживающую исходную последовательность следующим образом :
//В каждой подпоследовательности идентичных отсчетов оставить только первый и последний отсчеты, а так же каждый n - ный отсчет(n & gt; 2). 
//Вывести на экран последовательность до и после применения функции прореживания.

//Язык программирования : C++. Тип приложения : консольное. Входные данные задаются непосредственно в тексте программы (жесткое кодирование).

//Пример.
//Исходная :            (1, 10) (2, 11), (3, 11), (4, 11), (5, 11) (6, 10) (7, 11) (8, 11) (9, 11) (10, 11) (11, 10)
//Результат при n = 3 : (1, 10) (2, 11), (4, 11), (5, 11) (6, 10) (7, 11) (9, 11) (10, 11) (11, 10)
//Результат при n = 4 : (1, 10) (2, 11), (5, 11) (6, 10) (7, 11) (10, 11) (11, 10)

std::vector <item> myFunc(std::vector <item> data, int a) {
    std::vector <item> result;
    result.push_back(data[0]);
    int end = 0;
    for (int i = 1; i < data.size(); i++) {
        if (data[i].y != data[end].y) {
            result.push_back(data[i]);
            end = i;
        }
        else if ((i - end) % a == 0) {
            result.push_back(data[i]);
            end = i;
        }
    }
    return result;
}