#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int maxn = 40005;
int a[maxn], b[maxn];
int f[maxn], g[maxn];
int main(){
        cin >> n >> m;
        for(int i = 1;i <= m;i++){
            scanf("%d%d", a + i, b + i);
            a[i]--;
            b[i]--;
            f[a[i]]++;
            int dis = b[i] - a[i];
            if(dis < 0) dis += n;
            if(f[a[i]] == 1 || dis < g[a[i]]) g[a[i]] = dis;
        } 
        for(int i = 0;i < n;i++){
            int tmp = 0;
            for(int j = 0;j < n;j++){
                int to = (i + j) % n;
                tmp = max(tmp, j + (f[to] - 1) * n + g[to]);
            }
            printf("%d ", tmp);
        }
        cout << endl;
    return 0;
}