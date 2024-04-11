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

#define int long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)

const int N = 100005;
int a[N];
int n,x;

void init(){
    cin >> n >> x;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }   
}

void err(int idx){
    int rrr = idx;
    int add = 0;
    idx ++;
    while (idx != x){
        if (idx > n){
            idx -= n;
        }
        a[idx]--;
        add++;
        idx++;
    }
    a[x] --;
    add++;
    a[rrr] = add;
    for (int i=1;i<=n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

void solve(){
    for (int i=x;i>=1;i--){
        if (a[i] == 0){
            err(i);
            return ;
        }
    }
    int r = x;
    for (int i=1;i<=x;i++){
        a[i] --;
    }
    int mn = a[1],mnw = 1;
    for (int i=2;i<=n;i++){
        //mn =  min(mn,a[i]);
        if (a[i] <= mn){
            mn = a[i];
            mnw = i;
        }
    }
    r += n * mn;
    r += n - mnw;
    a[mnw] += r;
    for (int i=1;i<=n;i++){
        cout << a[i] - mn  - (i > mnw)<< ' ';
    }
    cout << endl;
}

#undef int
int main(){
#define int long long
    init();
    solve();
    return 0;
}