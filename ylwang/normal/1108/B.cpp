#include <map>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

LL n;
LL a[1005];
LL maxn = 0,maxn2 = 0;
char vis[100005] = {0}; // charbool char

int main(){
    ios::sync_with_stdio(false); // cinscanf
    cin >> n;
    for(register int i = 1;i <= n;i ++){
        cin >> a[i]; maxn = max(maxn,a[i]); // 
    }
    for(register int i = 1;i <= n;i ++){
        if(maxn % a[i] == 0 && (!vis[a[i]])){
            vis[a[i]] = 1;
            a[i] = 0; //   
        }
    }
    for(register int i = 1;i <= n;i ++){
        maxn2 = max(maxn2,a[i]); // 
    }
    cout << maxn2 << ' ' << maxn << endl; // 
    return 0;
}