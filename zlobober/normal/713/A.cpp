#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef long long llong;

const int LEN = 19;
map<llong, int> cnt[LEN];

void add(const string& s, int add) {
    llong msk = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        msk |= ((llong)((s[i] - '0') & 1)) << ((int)s.size() - i - 1);
    }
    cnt[(int)s.size()][msk] += add;
    /*for (int j = (int)s.size(); j < LEN; j++) {
        cnt[j][msk] += add;
    }
    for (int j = (int)s.size() - 1; j >= 0; j--) {
        int pos = (int)s.size() - 1 - j;
        if ((s[pos] - '0') & 1)
            break;
        cnt[j][msk] += add;
    }*/
}

inline int get(const map<llong, int>& M, llong msk) {
    auto it = M.find(msk);
    if (it == M.end())
        return 0;
    else
        return it->second;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char c;
        char buf[30];
        scanf(" %c %s", &c, buf);

        if (c == '+' || c == '-') {
            string s = buf;
            add(s, (c == '+') ? 1 : -1);
        } else {
            string s = buf;
            llong msk = 0;
            for (int j = 0; j < (int)s.size(); j++) {
                if ((s[j] - '0') & 1)
                    msk |= (1ll << ((int)s.size() - j - 1));
            }
            int ans = 0;
            for (int l = (int)s.size(); l < LEN; l++) {
                ans += get(cnt[l], msk);
            }
            for (int l = (int)s.size() - 1; l >= 0; l--) {
                int pos = (int)s.size() - 1 - l;
                if (s[pos] == '1')
                    break;
                ans += get(cnt[l], msk);
            }
            printf("%d\n", ans);
        }
    }
}