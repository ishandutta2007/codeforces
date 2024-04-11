#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=1;i<=n;i++)
#define reps(i,n) for (int i=0;i<n;i++)

const int N = 100005;
int sum[N];

int main(){
    int n,s;
    cin >> n >> s;
    int tmp;
    rep(i,n * 2 - 2) {
        cin >> tmp; 
        sum[tmp]++;
    }
    int ans = 0;
    rep(i,n) ans += (sum[i] == 1);
    //cout << (long double)1 * s / ans * 2 << endl;
    printf("%lf",(double)1 * s / ans * 2);
    return 0;
}