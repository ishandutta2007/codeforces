#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <memory.h>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 100500;

char buf[N];
typedef long long llong;

const int P1 = 42424243;
const int P2 = 1000000007;

struct hsh
{
    int x1, x2;
    hsh(int _x1, int _x2) 
    {
        x1 = _x1, x2 = _x2;
    }
    hsh(int x)
    {
        x1 = x % P1;
        x2 = x % P2;
    }
    hsh& operator -=(hsh other){
        x1 -= other.x1;
        x2 -= other.x2;
        if (x1 < 0)
            x1 += P1;
        if (x2 < 0)
            x2 += P2;
        return *this;
    }
    hsh& operator +=(hsh other){
        x1 += other.x1;
        x2 += other.x2;
        if (x1 >= P1)
            x1 -= P1;
        if (x2 >= P2)
            x2 -= P2;
        return *this;
    }
    llong to_llong()
    {
        return (((llong)x1) << 32) | x2;
    }
    friend bool operator ==(hsh a, hsh b) {
        return a.x1 == b.x1 && a.x2 == b.x2;
    }
    friend hsh operator *(hsh a, hsh b) {
        return hsh ((llong)a.x1 * b.x1 % P1, (llong)a.x2 * b.x2 % P2);
    }
    hsh(){};
};

const int HT = 1 << 19;

hsh H[HT];
int idx[HT];

int get(hsh h) {
    int x = (h.x1 ^ h.x2) & (HT - 1);
    while (idx[x] != -1 && !(H[x] == h))
        x = (x + 1) & (HT - 1);
    return idx[x];
}

void add(hsh h, int id) {
    int x = (h.x1 ^ h.x2) & (HT - 1);
    while (idx[x] != -1 && !(H[x] == h))
        x = (x + 1) & (HT - 1);
    if (idx[x] != -1)
        return;
    H[x] = h;
    idx[x] = id;
}

string W[N];
char word[N];

hsh SH[N];
hsh AA[N];

hsh get_hash(int l, int r) {
    hsh res = SH[r];
    res -= SH[l] * AA[r - l];
    return res;
}

int prv[N];
int prvid[N];

int main() {
    int n;
    scanf("%d ", &n);
    gets(buf);
    int m;
    scanf("%d ", &m);
    srand(n ^ m);
    hsh A(rand() % P1, rand() % P2);
    memset(idx, -1, sizeof(idx));
    for (int i = 0; i < m; i++) {
        gets(word);
        W[i] = word;
        hsh h(0, 0);
        for (int j = 0; j < W[i].size(); j++) {
            char c = W[i][(int)W[i].size() - j - 1];
            if (c >= 'A' && c <= 'Z')
                c += 'a' - 'A';
            h = h * A;
            h += hsh(c);
        }
        add(h, i);
    }
    AA[0] = hsh(1, 1);
    for (int i = 1; i <= n; i++)
        AA[i] = AA[i - 1] * A;
    for (int i = 0; i < n; i++) {
        SH[i + 1] = SH[i] * A;
        SH[i + 1] += buf[i];
    }
    memset(prv, -1, sizeof(prv));
    prv[0] = -42;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= min(1000, i); l++) {
            hsh h = get_hash(i - l, i);
            int id = get(h);
            if (id != -1 && prv[i - l] != -1)
                prv[i] = i - l, prvid[i] = id;
        }
    }
    assert(prv[n] != -1);
    vector<string> res;
    for (int x = n; x != 0; x = prv[x]) {
        res.push_back(W[prvid[x]]);
    }
    reverse(res.begin(), res.end());
    for (string s : res) {
        printf("%s ", s.data());
    }
    puts("");
}