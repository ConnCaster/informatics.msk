#include <cstdio>
#include <vector>
#include <functional>

/*
4 5
2 1 1 2 1
0 3 0 1 0
3 0 0 3 1
0 2 0 2 0

    5 6
    1 1 1
    2 3 1
    3 3 1
    4 3 2
    2 5 1
 */

using namespace std;

int main () {
    int sizeI, sizeJ;  //координаты типа строка и столбец соответственно
    scanf ("%d %d", &sizeI, &sizeJ);

    // функция перехода к новому базису (от двумерной структуры к одномерной непересекающейся структуре множеств), по факту перезод в новую систему координат (такое даже в акадосе было!!!)
    function < int (int, int) > encode =[&](int i, int j)
    {
        return sizeJ * i + j;
    };
    vector < int >parent (1 + encode (sizeI, sizeJ), -1); // сама СНМ: >=0  родитель, < 0 - главная вершина компоненты

    //фукция получения корня по заданной вершине
    function < int (int) > getRoot =[&](int v)
    {
        if (parent[v] < 0)
        {
            return v; // сама себе родитель
        }
        else
        {
            int root = getRoot (parent[v]);
            parent[v] = root; //родитель вершины корень, сокращаем путь
            return root;
        }

    };


//ф-я объединения двух вершин, если тру - то объединини, фолс - они уже были объединенины
    function < bool (int,int) >join =[&](int a, int b)
    {
        a = getRoot (a);
        b = getRoot (b);
        if (a == b)
        {
            return false;
        }
        if (parent[a] < parent[b])
        {
            parent[a] += parent[b];
            parent[b] = a;
        }
        else
        {
            parent[b] += parent[a];
            parent[a] = b;
        }
        return true;
    };
//считываем
    for (int i = 1; i <= sizeI; i++)
    {
        for (int j = 1; j <= sizeJ; j++)
        {
            int code;
            scanf ("%d", &code);
            if ((code & 1) != 0)
            {
                join (encode (i, j), encode (i + 1, j));
            }
            if ((code & 2) != 0)
            {
                join (encode (i, j), encode (i, j + 1));
            }
        }
    }

    vector < int >ansI;
    vector < int >ansJ;
    vector < int >ansD;

    int ansCost = 0;
//пытаемся объединить по вертикали
    for (int i = 1; i < sizeI; i++)
    {
        for (int j = 1; j <= sizeJ; j++)
        {
            if (join (encode (i, j), encode (i + 1, j)))
            {
                ansI.push_back (i);
                ansJ.push_back (j);
                ansD.push_back (1);
                ansCost += 1;

            }
        }
    }

// пытаемся  по горизонтали
    for (int i = 1; i <= sizeI; i++)
    {
        for (int j = 1; j < sizeJ; j++)
        {
            if (join (encode (i, j), encode (i, j + 1)))
            {
                ansI.push_back (i);
                ansJ.push_back (j);
                ansD.push_back (2);
                ansCost += 2;
            }
        }
    }
    printf ("%d %d\n", (int) ansI.size (), ansCost);
    for (int i = 0; i < (int) ansI.size (); i++)
    {
        printf ("%d %d %d\n", ansI[i], ansJ[i], ansD[i]);
    }

    return 0;
}
