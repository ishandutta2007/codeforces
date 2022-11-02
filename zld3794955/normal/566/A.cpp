#include <map>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define rint register int
#define uint unsigned int
#define ll long long
#define ull unsigned ll
using namespace std;

const int MaxN = 800010;
int Ch[MaxN][26], Total, Ans, Pair[MaxN], Father[MaxN], Deep[MaxN];
vector <int> P[MaxN];
char St[MaxN];
int N;

void Check(int Now) {
    int T = P[Now].size();
    if (T <= 1) return;
    if ((P[Now][T - 1] > N) ^ (P[Now][T - 2] > N)) {
        Pair[P[Now][T - 1]] = P[Now][T - 2];
        Pair[P[Now][T - 2]] = P[Now][T - 1];
        Ans += Deep[Now];
        P[Now].pop_back();
        P[Now].pop_back();
    }
}

void Insert(int Ind) {
    int Now = 0;
    for (int i = 1; St[i]; i++) {
        if (!Ch[Now][St[i] - 'a']) {
            Ch[Now][St[i] - 'a'] = ++Total;
            Deep[Total] = Deep[Now] + 1;
        }
        Now = Ch[Now][St[i] - 'a'];
    }
    P[Now].push_back(Ind);
    Check(Now);
}

void Bfs() {
    static int H[MaxN];
    int L = 0, R = 1;
    while (L++ != R) {
        int U = H[L];
        for (int i = 0; i < 26; i++)
            if (Ch[U][i]) {
                H[++R] = Ch[U][i];
                Father[H[R]] = U;
            }
    }
    for (int i = R; i; i--) {
        for (; P[H[i]].size(); P[H[i]].pop_back()) {
            P[Father[H[i]]].push_back(P[H[i]][P[H[i]].size() - 1]);
            Check(Father[H[i]]);
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N * 2; i++) {
        scanf("%s", St + 1);
        Insert(i);
    }
    Bfs();
    printf("%d\n", Ans);
    for (int i = 1; i <= N; i++) printf("%d %d\n", i, Pair[i] - N);
    return 0;
}