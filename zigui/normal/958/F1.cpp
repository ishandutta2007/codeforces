#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int A[110], B[110];
    for(int i=1;i<=n;i++) scanf("%d", A+i);
    for(int i=1;i<=m;i++) scanf("%d", B+i);
    int s = 0;
    for(int i=1;i<=m;i++) s += B[i];
    for(int i=1;i+s-1<=n;i++) {
        int cnt[110] = {};
        for(int j=i;j<i+s;j++) {
            cnt[A[j]]++;
        }
        int f = 1;
        for(int i=1;i<=m;i++) if(cnt[i] != B[i]) f = 0;
        if(f) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}