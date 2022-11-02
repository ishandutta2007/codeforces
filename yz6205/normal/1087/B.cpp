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

#define long long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)

int n,k;

void init(){
    cin >> n >> k;
}

int main(){
    init();
    int ans = 0x3f3f3f3f;
    for (int i=1;i * i<=n && i < k;i++){
        if (n % i == 0) ans = min(ans, i + k * (n / i));
        if ((n % i == 0) && ((n / i) < k)) ans = min(ans,n / i + i * k);
    }
    cout << ans << endl;
    return 0;
}