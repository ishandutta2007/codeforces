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

const int N = 200005;
int a[N];
map < int , int > fa;
int n;

void init(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (!fa.count(a[i])){
            fa[a[i]] = i;
        }
    }
}

int cnt;
int hv[N];
void makeCount(){
    for (int i=1;i<=n;i++){
        hv[fa[a[i]]]++;
        hv[i]--;
    }
    for (int i=1;i<n;i++){
        hv[i] += hv[i - 1];
        if (hv[i] == 0){
            cnt++;
        }
    }
}

void solve(){
    long ans = 1;
    for (int i=1;i<=cnt;i++){
        (ans *= 2) %= 998244353;
    }
    cout << ans << endl;
}

int main(){
    init();
    makeCount();
    solve(); 
    return 0;
}