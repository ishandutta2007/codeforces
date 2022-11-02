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
#include <ctime>
using namespace std;

const int maxn = 105;

int n, k;
int a[maxn][maxn];
typedef pair<int, int> pii;
vector<pii> G[maxn];

int vis[maxn];
int col[maxn];

long long dis[20][maxn];

long long cal(){
    for(int i = 1;i <= n;i++){
        col[i] = rand() % 2;
    }
    for(int i = 0;i <= k;i++){
        for(int j = 1;j <= n;j++){
            dis[i][j] = 1e18;
        }
    }
    dis[0][1] = 0;
    for(int r = 1;r <= k;r++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(col[i] != col[j]){
                    dis[r][j] = min(dis[r - 1][i] + a[i][j], dis[r][j]);
                }
            }
        }
    }
    return dis[k][1];
}

int main(){
    srand(time(NULL));
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d", &a[i][j]);
            if(j != i){
                G[i].emplace_back(j, a[i][j]);
            }
        }
    }
    long long ans = 1e18;
    for(int i = 1;i <= 3000;i++){
        ans = min(ans, cal());
    }
    cout << ans << endl;
    return 0;
}