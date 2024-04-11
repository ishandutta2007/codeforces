#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;

int a[maxn];
bool vis[maxn];

int main(){
    int n;
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        memset(vis, false, sizeof(vis));
        int tot = 0;
        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                tot++;
                for(int j = 1;j <= n;j++){
                    if(a[j] % a[i] == 0){
                        vis[j] = true;
                    }
                }
            }
        }
        cout << tot << endl;
    }
    return 0;
}