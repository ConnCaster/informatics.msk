#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class vertex {
public:
    int x, y, label;
    struct vertex *parent, *left, *right;

    vertex() {}

    void set(int xi, int yi, int labeli) {
        x = xi;
        y = -yi;
        label = labeli;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};


typedef vertex *pvertex;


class decTree {
private:
    int treeSize{};
    vertex *vertexs;
    pvertex *ordered;
    pvertex root{};
    int vertexCount;

    void _sortIns(pvertex *pvertexs, int left, int right) {
        pvertex shift;

        for (int i = left + 1; i < right; i++) {
            int j = i - 1;
            shift = pvertexs[i];

            for (int k = i - 1; ((k >= left) && (pvertexs[j]->x > shift->x)); k--, j--) {
                pvertexs[k + 1] = pvertexs[k];
            }
            pvertexs[j + 1] = shift;
        }
    }

    void _sortQuick(pvertex *pvertexs, int left, int right) {
        srand(time(nullptr));
        int l = left;
        int r = right - 1;
        pvertex p;

        p = pvertexs[l + rand() % (right - left)];

        do {
            while (pvertexs[l]->x < p->x) {
                l++;
            }
            while (pvertexs[r]->x > p->x) {
                r--;
            }

            if (l <= r) {
                swap(pvertexs[l++], pvertexs[r--]);
            }
        } while (l <= r);

        if (r - left > 16) {
            _sortQuick(pvertexs, left, r + 1);
        } else if (r > left) {
            _sortIns(pvertexs, left, r + 1);
        }

        if (right - l > 16) {
            _sortQuick(pvertexs, l, right);
        } else if (l < right - 1) {
            _sortIns(pvertexs, l, right);
        }

    }

    void _makeTree() {
        pvertex last = nullptr;
        root = ordered[0];
        last = root;
        for (int i = 1; i < treeSize; i++) {
            while (last->parent != nullptr && ordered[i]->y > last->y) {
                last = last->parent;
            }
            if (ordered[i]->y <= last->y) {
                ordered[i]->left = last->right;
                ordered[i]->parent = last;
                if (last->right) {
                    last->right->parent = ordered[i];
                }
                last->right = ordered[i];

            } else {
                ordered[i]->left = last;
                last->parent = ordered[i];
                root = ordered[i];
            }
            last = ordered[i];
        }

    }


public:

    decTree() {
        int a, b;
        vertexCount = 0;

        std::cin >> treeSize;
        vertexs = new vertex[treeSize];
        ordered = new pvertex[treeSize];
        for (int i = 0; i < treeSize; i++) {
            std::cin >> a >> b;
            vertexs[vertexCount].set(a, b, vertexCount + 1);
            ordered[vertexCount] = vertexs + vertexCount;
            vertexCount++;
        }
        _sortQuick(ordered, 0, treeSize);
        _makeTree();
    }


    void resultsDisplay() {
        int parent, left, right;
        std::cout << "YES" << endl;
        for (int i = 0; i < treeSize; i++) {
            if (vertexs[i].parent) {
                parent = vertexs[i].parent->label;
            } else {
                parent = 0;
            }

            if (vertexs[i].left) {
                left = vertexs[i].left->label;
            } else {
                left = 0;
            }

            if (vertexs[i].right) {
                right = vertexs[i].right->label;
            } else {
                right = 0;
            }

            std::cout << parent << " " << left << " " << right << endl;
        }
    }
};


int main() {
    auto *mytree = new decTree();
    mytree->resultsDisplay();
    return 0;
}