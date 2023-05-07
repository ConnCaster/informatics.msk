#include <iostream>


// Объявим структуру Item вершины дерева с неявным ключом. Элементы входной последовательности хранятся в значениях Value.
// В переменной Summa хранится сумма всех элементов последовательности в поддереве с корнем в текущей вершине.
struct Item {
    int cnt, Value, Priority;
    long long Summa;
    Item *l, *r;

    Item() {}

    Item(int Value) :
            Priority((rand() << 16u) + unsigned(rand())), Value(Value), Summa(Value), l(nullptr), r(nullptr) {}
};
//Объявим указатель Pitem на вершину дерева. Объявим два декартовых дерева T1 и T2.
typedef Item *Pitem;
Pitem T1, T2;

//Функция GetSize возвращает количество вершин в поддереве с корнем t.
int GetSize(Pitem t) {
    return t ? t->cnt : 0;
}

//Функция GetSum возвращает сумму элементов последовательности, хранящуюся в вершинах поддерева с корнем t.
long long GetSum(Pitem t) {
    return t ? t->Summa : 0;
}

//Функция пересчета данных в вершине t. Следует обновить количество вершин t → GetSize в поддереве t и сумму t → Summa.
void upd(Pitem t) {
    if (t) {
        t->cnt = 1 + GetSize(t->l) + GetSize(t->r);
        t->Summa = t->Value + GetSum(t->l) + GetSum(t->r);
    }
}

//Слияние двух деревьев L и R в T.
void Merge(Pitem L, Pitem R, Pitem &T) {
    if (!L || !R)
        T = L ? L : R;
    else if (L->Priority > R->Priority){
        Merge(L->r, R, L->r);
        T = L;
    }
    else{
        Merge(L, R->l, R->l);
        T = R;
    }
    upd(T);
}

//Разбиваем дерево T по неявному ключу pos в L и R. В левое дерево заносится в точности pos вершин.
void Split(Pitem T, Pitem &L, Pitem &R, int pos) {
    if (!T) return void(L = R = nullptr);
    if (pos <= GetSize(T->l)) {
        Split(T->l, L, T->l, pos);
        R = T;
    }
    else{
        Split(T->r, T->r, R, pos - 1 - GetSize(T->l));
        L = T;
    }
    upd(T);
}

//Вычисляем суммы элементов последовательности aL + … + aR.
// Ищем соответствующие индексы суммируемых элементов в деревьях T1 и T2.
// Для T1 это будет интервал [L1, R1], а для T2 интервал [L2, R2].
// Вырежем поддеревья с ключами [L1, R1] и [L2, R2],
// вычислим суммы элементов последовательности в них в переменной res, после чего склеим деревья обратно.
long long Sum(int L, int R) {
    if (L > R) return 0;
    int L1 = (L + 1) / 2;
    int R1 = R / 2;
    int L2 = L / 2;
    int R2 = (R + 1) / 2 - 1;
    Pitem A1, B1, C1, A2, B2, C2;
    Split(T1, A1, B1, L1);
    Split(B1, B1, C1, R1 - L1 + 1); // T1 = (A1, B1, C1)
    Split(T2, A2, B2, L2);
    Split(B2, B2, C2, R2 - L2 + 1); // T2 = (A2, B2, C2)

    long long res = GetSum(B1) + GetSum(B2);

    Merge(A1, B1, B1);
    Merge(B1, C1, T1);

    Merge(A2, B2, B2);
    Merge(B2, C2, T2);
    return res;
}

//Реализация операции своппера на отрезке [L; R] четной длины. Вырезаем соответствующие интервалы [L1, R1] и [L2, R2] из деревьев T1 и T2 и меняем их местами.
void Swap(int L, int R) {
    int L1 = (L + 1) / 2, R1 = R / 2;
    int L2 = L / 2, R2 = (R + 1) / 2 - 1;
    Pitem A1, B1, C1, A2, B2, C2;
    Split(T1, A1, B1, L1);
    Split(B1, B1, C1, R1 - L1 + 1); // T1 = (A1, B1, C1)
    Split(T2, A2, B2, L2);
    Split(B2, B2, C2, R2 - L2 + 1); // T2 = (A2, B2, C2)

    Merge(A1, B2, B2);
    Merge(B2, C1, T1); // T1 = (A1, B2, C1)
    Merge(A2, B1, B1);
    Merge(B1, C2, T2); // T2 = (A2, B1, C2)
}


//Основная часть программы. Читаем входные данные. Строим декартовы деревья T1 и T2.
int main() {
    int n, m, a, b, cs = 1, val, cmd;
    while (std::cin >> n >> m, n + m) {
        T1 = T2 = nullptr;
        if (cs != 1) std::cout << std::endl;
        std::cout << "Swapper " << cs++ << ":" << std::endl;
        for (int i = 1; i <= n; i++) {
            std::cin >> val;
            if (i & 1) Merge(T1, new Item(val), T1);
            else Merge(T2, new Item(val), T2);
        }

//Последовательно обрабатываем запросы.
        for (int i = 0; i < m; i++) {
            std::cin >> cmd >> a >> b;
            a--;
            b--;
            if (cmd == 1)
                Swap(a, b);
            else
                std::cout << Sum(a, b) << std::endl;
        }
    }
    return 0;
}

