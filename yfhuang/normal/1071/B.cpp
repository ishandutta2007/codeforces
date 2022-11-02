#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, k;
const int maxn = 2005;

char a[maxn][maxn];
int val[maxn][maxn];
bool vis[maxn][maxn];
char ans[maxn];
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%s", a[i] + 1);
        for(int j = 1;j <= n;j++){
            if(a[i][j] == 'a')
                val[i][j] = 0;
            else
                val[i][j] = 1;
        }
    } 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i > 1 and j > 1)
                val[i][j] += min(val[i - 1][j], val[i][j - 1]);
            else if(i == 1 and j > 1){
                val[i][j] += val[i][j - 1];
            }else if(i > 1 and j == 1){
                val[i][j] += val[i - 1][j];
            }
        }
    }
    int id = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(val[i][j] <= k){
                id = max(id, i + j);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i + j == id and val[i][j] <= k){
                vis[i][j] = true;
            }
        }
    }
    for(int sum = 2;sum <= id;sum++){
        putchar('a');
    }
    vis[1][0] = vis[0][1] = true;
    for(int sum = id + 1;sum <= 2 * n;sum++){
        char c = 'z';
        for(int i = max(sum - n, 1);i <= min(sum - 1, n);i++){
            int j = sum - i;
            if(vis[i - 1][j] or vis[i][j - 1]){
                c = min(c, a[i][j]);
            } 
        }
        for(int i = max(sum - n, 1);i <= min(sum - 1, n);i++){
            int j = sum - i;
            if(vis[i - 1][j] or vis[i][j - 1]){
                if(a[i][j] == c){
                    vis[i][j] = true;
                }
            } 
        }
        putchar(c);
    }
    return 0;
}