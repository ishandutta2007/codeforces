#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(x, l, r) for(int x = (int)l; x <= (int)r; x++)
#define repd(x, r, l) for(int x = (int)r; x >= (int)l; x--)
#define clr(x,y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define INF 1 << 30
#define MAXN 15
#define MAXM 100005
using namespace std;
typedef long long LL;
typedef pair<int,int> par;

struct node{
    int nxt;
    LL cnt;
}s[MAXM];
int a[MAXN][MAXM];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 1, m)
        rep(j, 1, n) scanf("%d", &a[i][j]);
    rep(i, 1, n - 1){
        s[a[1][i]].nxt = a[1][i + 1];
        s[a[1][i]].cnt = 1;
    }
    rep(i, 2, m)
        rep(j, 1, n - 1)
            if(s[a[i][j]].nxt == a[i][j + 1]) s[a[i][j]].cnt++;
    LL sum = 1, ans = 0;
    rep(i, 1, n - 1) {
        if(s[a[1][i]].cnt != m) ans += sum * (sum + 1) / 2, sum = 1;
        else sum++;
    }
    if(sum > 0) ans += sum * (sum + 1) / 2;
    cout << ans << endl;
    return 0;
}