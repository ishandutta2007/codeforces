#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int maxn = 200000 + 5;
int a[maxn];
int b[maxn];
int n;
set<int> s;
int vis[maxn];
bool p[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        if(vis[a[i]] > 1){
            p[i] = 1;
        }
        if(vis[i] == 0) s.insert(i);
    }
    for(int i = 1;i <= n;i++){
        if(p[i]){
            if(vis[a[i]] == 1){
                b[i] = a[i]; vis[a[i]] = 1e9;
            }else{
                if(*s.begin() < a[i] || vis[a[i]] > 1e8){
                    b[i] = *s.begin();
                    s.erase(*s.begin());
                    vis[a[i]]--;
                }else{
                    b[i] = a[i];
                    vis[a[i]] = 1e9;
                }
            }
        }else b[i] = a[i];
    }
    int m = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] != b[i]) m++;
    }
    cout << m << endl;
    for(int i = 1;i <= n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}