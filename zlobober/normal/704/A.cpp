#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

const int N = 300500;

int color[N];

vector<int> E[N];
int pt[N];

vector<int> gen;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int read = 0;
    int last_all = 0;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int c;
            scanf("%d", &c);
            color[i] = c;
            E[c].push_back(i);
            gen.push_back(i);
        } else if (t == 2) {
            int c;
            scanf("%d", &c);
            read += E[c].size() - pt[c];
            pt[c] = E[c].size();
        } else {
            int x;
            scanf("%d", &x);
            assert(x <= gen.size());
            if (x > last_all) {
                for (int _i = last_all; _i < x; _i++) {
                    int i = gen[_i];
                    int c = color[i];
                    if (pt[c] != (int)E[c].size() && E[c][pt[c]] == i) {
                        pt[c]++;
                        read++;
                    }
                }
                last_all = x;
            }
        }
        printf("%d\n", (int)gen.size() - read);
    }

}