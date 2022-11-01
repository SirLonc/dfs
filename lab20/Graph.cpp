#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#define SIZE 6
int i, j;
bool* visited = new bool[SIZE];


int** read_matrix()
{
    ifstream fin("matrix.txt");
    int** a = new int* [SIZE];
    for (int count = 0; count < SIZE; count++) {
        a[count] = new int[SIZE];
    }
    int k = 0;
    while (k++ < 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                fin >> a[i][j];
            }
        }
    }
    fin.close();
    return a;
}

int read_start() {
    ifstream fin("matrix.txt");
    int a;
    int k = SIZE * SIZE + 1;
    while (k != 0)
    {
        fin >> a;
        k--;
    }
    fin.close();
    return a;
}

void DFS(int st, int** graph)
{
    int r;
    cout << st + 1 << " ";
    visited[st] = true;
    for (r = 0; r <= SIZE; r++)
        if ((graph[st][r] != 0) && (!visited[r]))
            DFS(r, graph);
}
//главная функция
void main()
{
    int** matrix = new int* [SIZE];
    for (int count = 0; count < SIZE; count++) {
        matrix[count] = new int[SIZE];
    }
    matrix = read_matrix();

    int start = read_start();
    cout << "Graph Adjacency Matrix: " << endl;
    for (i = 0; i < SIZE; i++)
    {
        visited[i] = false;
        for (j = 0; j < SIZE; j++)
            cout << " " << matrix[i][j];
        cout << endl;
    }
    //массив посещенных вершин
    bool* vis = new bool[SIZE];
    cout << "Traversal order: ";
    DFS(start - 1, matrix);
    delete[]visited;
   
}
