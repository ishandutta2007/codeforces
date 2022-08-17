#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100500;
char buf[N];

char ans[N];

int main() {
    int m;
    scanf("%d", &m);
    scanf("%s", buf);
    int n = strlen(buf);
    int c = -1;
    vector<int> pos;
    for (int q = 'a'; q <= 'z'; q++) {
        pos = {-1, n};
        for (int i = 0; i < n; i++) {
            if (buf[i] <= q)
                pos.push_back(i);
        }
        sort(pos.begin(), pos.end());
        bool bad = false;
        for (int i = 0; i < (int)pos.size() - 1; i++) {
            if (pos[i + 1] - pos[i] > m)
                bad = true;
        }
        if (!bad) {
            c = q;
            break;
        }
    }
    assert(c != -1);
    int prv = -1;
    vector<int> rpos;
    for (int _i = 1; _i < (int)pos.size() - 1; _i++) {
        int i = pos[_i];
        if (buf[i] > c) {
            continue;
        } else if (buf[i] < c) {
            rpos.push_back(i);
            prv = i;
        } else {
            int ni = pos[_i + 1];
            if (ni - prv > m) {
                rpos.push_back(i);
                prv = i;
            }
        }
    }
    int apt = 0;
    for (int i : rpos) {
        ans[apt++] = buf[i];
    }
    sort(ans, ans + apt);
    puts(ans);
}