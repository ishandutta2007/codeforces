#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 150000 + 5;

int n;
int L[maxn], R[maxn], fa[maxn];

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        L[i] = i;
        R[i] = i;
    }
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        int fx = Find(u);
        int fy = Find(v);
        fa[fy] = fx;
        L[R[fx]] = fy;
        R[fx] = R[fy];
    } 
    int st = 0;
    for(int i = 1;i <= n;i++){
        int fx = Find(i);
        if(fx == i)
            st = i;
    }
    for(int i = 1;i <= n;i++){
        printf("%d ", st);
        st = L[st];
    }
    return 0;
}