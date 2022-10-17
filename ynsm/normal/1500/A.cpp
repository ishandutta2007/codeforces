#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 5e6 + 100;

int n, a[N];
vector< pii > v[N];
void check(int x){
    for(auto a : v[x])
        for(auto b : v[x]){
            if(a.f == b.f)
                continue;
            if(a.f == b.s)
                continue;
            if(a.s == b.f)
                continue;
            if(a.s == b.s)
                continue;
            puts("YES");
            printf("%d %d %d %d", a.f, a.s, b.f, b.s);
            exit(0);
        }
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        for(int j = 1; j < i; j++){
            int x = a[i] + a[j];
            v[x].pb({i, j});
            check(x);
        }
    }
    puts("NO");
}