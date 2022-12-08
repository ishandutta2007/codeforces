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

int N, P;
ll A[MX], B[MX];

int main() {
    scanf("%d%d", &N, &P);
    for (int i = 1; i <= N; i++) scanf("%lld", A + i);
    for (int i = 1; i <= N; i++) B[i] = B[i-1] + A[i];
    ll mx = 0;
    for (int i = 1; i < N; i++) {
        mx = max(mx, B[i]%P + (B[N] - B[i]) % P);
    }
    printf("%lld\n", mx);
}