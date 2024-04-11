#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define MAXN
#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 1 << 30;
const int p = 1000000009;
int lowbit(int x){ return x & (-x);}
int fast_power(int a, int b){ int x; for(x = 1; b; b >>= 1){ if(b & 1) x = 1ll * x * a % p; a = 1ll * a * a % p;} return x % p;}

map<int, int> f;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int maxx = 0;
    rep(i, 1, k + 1){
        putchar('?');
        rep(j, 1, k + 1){
            if(i == j) continue;
            printf(" %d", j);
        }
        puts("");
        fflush(stdout);
        int x, y;
        scanf("%d%d", &x, &y);
        f[y]++;
        maxx = max(maxx, y);
    }
    printf("! %d\n", f[maxx]);
    return 0;
}