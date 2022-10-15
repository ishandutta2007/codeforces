#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

class Node{
public:
    int vol, l, r, tot;
    Node (int val) {
        tot = vol = val;
        l = r = 0;
    }
    Node () {
        tot = vol = 0;
        l = r = 0;
    }
};

int main() {
    int H, q;
    cin >> H >> q;
    vector<Node> tree(1);
    string s;
    int v,val;
    for (int query = 0; query < q; ++query) {
        cin >> s;
        if (s[0] == 'a') {
            cin >> v >> val;
            vi vbit;
            while (v) {
                vbit.push_back(v % 2);
                v /= 2;
            }
            int it = 0;
            for (int h = (int)vbit.size() - 2; h >= 0; --h) {
                if (!tree[it].r) {
                    tree[it].l = tree.size();
                    tree[it].r = tree.size() + 1;
                    tree.resize(tree.size() + 2);
                }
                tree[it].tot += val;
                int nextit = tree[it].l;
                if (vbit[h]) {
                    nextit = tree[it].r;
                }
                it = nextit;
            }
            tree[it].vol += val;
            tree[it].tot += val;
        } else {
            double res = 0.;
            int it = 0;
            int ma = 0;
            int h = H;
            for (; h > 0 && tree[it].r; --h) {
//                cerr << ma << " " << tree[it].vol << " " << tree[it].tot << " " << tree[tree[it].r].tot << " " << tree[tree[it].l].tot << endl;
                int nextit = tree[it].r;
                if (tree[it].vol + tree[tree[it].r].tot > tree[tree[it].l].tot) {
                    res += max(ma, tree[it].vol + tree[tree[it].r].tot) * (double)(1 << (h - 1));
                    ma = max(ma, tree[it].vol + tree[tree[it].l].tot);
                } else {
                    res += max(ma, tree[it].vol + tree[tree[it].l].tot) * (double)(1 << (h - 1));
                    ma = max(ma, tree[it].vol + tree[tree[it].r].tot);
                    nextit = tree[it].l;
                }
                it = nextit;
            }
            res += max(ma, tree[it].vol) * (double)(1 << h);
            printf("%lf\n", res / (1 << (H)));
        }
    }
    return 0;
}