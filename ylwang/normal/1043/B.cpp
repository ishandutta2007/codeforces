#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(x, l, r) for(int x = (int)l; x <= (int)r; x++)
#define repd(x, r, l) for(int x = (int)r; x >= (int)l; x--)
#define clr(x,y) memset(x, y, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define INF 1 << 30
#define MAXN 1005
using namespace std;
typedef long long LL;
typedef pair<int,int> par;

int n;
int a[MAXN], b[MAXN], ansk[MAXN];

bool judge(int len){
    rep(i, len, n - 1)
        if(a[i] != a[i % len]) return 0;
    return 1;
}

int main(){
    scanf("%d", &n);
    rep(i, 1, n){
        scanf("%d", &b[i]);
        a[i - 1] = b[i] - b[i - 1];
    }
    int ans = 0;
    rep(i, 1, n)
        if(judge(i)) ansk[++ans] = i;
    printf("%d\n", ans);
    rep(i, 1, ans) printf("%d ", ansk[i]);
    puts("");
    return 0;
}