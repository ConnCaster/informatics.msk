#include <stdio.h>
#include <vector>
#include <cmath>


using namespace std;

int main ()
{
    int N, M, K, maxNumOfN = 200000;

    scanf ("%d %d %d", &N, &K, &M);
    vector < int >a (N, K); // количество оставшихся билетов
    int groupSize = ceil(sqrt(maxNumOfN/2)) ; //также определяем оптимальный размер группы
    vector < int >minNumInGroup (1 + (N - 1) / groupSize, K); //список минимумов в полученных группах
    vector < int >subtrahendInGroup (1 + (N - 1) / groupSize, 0); // на сколько надо уменьшить элементы данной группы после операции
    vector < int >result (0);

    for (int i = 0; i < M; i++)
    {
        bool isTicketsEnded = false; // остались ли билеты???
        int l, r;
        scanf ("%d %d", &l, &r);
        r--;
        int indexOfGroupWithL = l / groupSize; //индекс группы с первой станцией в маршруте
        int indexOfGroupWithR = r / groupSize; // --//-- с конечной станцией
        if (indexOfGroupWithL == indexOfGroupWithR) //проверка на принадлежность одной группе, потом ищем минимум
        {
            for (int j = l; j <= r; j++)
            {
                if (a[j] == subtrahendInGroup[indexOfGroupWithL]) // если значения совпадают, билеты кончились
                {
                    isTicketsEnded = true;
                }
            }
        }
        else // тут аналогично предыдущей задаче идем по группам до конца, вычисляем минимум, но только с корректировкой
        {
            int nextIndexOfGroupWithL = (indexOfGroupWithL + 1) * groupSize; //индекс
            for (int j = l; j < nextIndexOfGroupWithL; j++)
            {
                if (a[j] == subtrahendInGroup[indexOfGroupWithL])
                {
                    isTicketsEnded = true;
                }
            }
            for (int j = indexOfGroupWithL + 1; j < indexOfGroupWithR; j++)
            {
                if (minNumInGroup[j] == subtrahendInGroup[j])
                {
                    isTicketsEnded = true;
                }
            }
            for (int j = indexOfGroupWithR * groupSize; j <= r; j++)
            {
                if (a[j] == subtrahendInGroup[indexOfGroupWithR])
                {
                    isTicketsEnded = true;
                }
            }
        }
        if (isTicketsEnded)
        {
            result.push_back (0); //если билеты кончились,то все
        }
        else
        {
            result.push_back (1); // если нет, то уменьшаем количество билетов в группах. Выподняется запрос на покупку
            if (indexOfGroupWithL == indexOfGroupWithR)
            {
                for (int j = l; j <= r; j++)
                {
                    a[j]--;
                    minNumInGroup[indexOfGroupWithL] = min (minNumInGroup[indexOfGroupWithL], a[j]); // обновляем минимум в группе
                }
            }
            else
            {
                int nextIndexOfGroupWithL = (indexOfGroupWithL + 1) * groupSize;
                for (int j = l; j < nextIndexOfGroupWithL; j++)
                {
                    a[j]--;
                    minNumInGroup[indexOfGroupWithL] = min (minNumInGroup[indexOfGroupWithL], a[j]);
                }
                for (int j = indexOfGroupWithL + 1; j < indexOfGroupWithR; j++)
                {
                    subtrahendInGroup[j]++; // увеличиваем число, на которое надо уменьшить все элементы группы, так как билета нету на участке из станций внутри этой группы
                }
                for (int j = indexOfGroupWithR * groupSize; j <= r; j++)
                {
                    a[j]--;
                    minNumInGroup[indexOfGroupWithR] = min (minNumInGroup[indexOfGroupWithR], a[j]);
                }
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        printf ("%d\n", result[i]);
    }
    return 0;
}