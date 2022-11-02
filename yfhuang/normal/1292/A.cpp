#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n, q;
const int maxn = 1e5 + 5;

int vis[3][maxn];

int main(){
    cin >> n >> q;
    long long cnt = 0;
    for(int i = 1;i <= q;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(vis[x][y] == false){
            for(int j = -1;j <= 1;j++){
                if(vis[3 - x][y + j]){
                    cnt++;
                }
            }
            vis[x][y] = true;
        }else{
            for(int j = -1;j <= 1;j++){
                if(vis[3 - x][y + j]){
                    cnt--;
                }
            }
            vis[x][y] = false;
        }
        if(cnt == 0){
            puts("Yes");
        }else{
            puts("No");
        }
    } 
    return 0;
}