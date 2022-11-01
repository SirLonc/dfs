#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;
#define SIZE 7


int** read()
{
    ifstream fin("matrix.txt");
    int** a = new int* [SIZE];
    for (int count = 0; count < SIZE; count++) {
        a[count] = new int[SIZE];
    }
    int k = 0;
    while (k++ < 1)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                fin >> a[i][j];
            }
        }
    }
    fin.close();
    return a;
}

