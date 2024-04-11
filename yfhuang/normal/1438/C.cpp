#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;
int n, m;

const int maxn = 105;
int a[maxn][maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if((a[i][j] & 1) != ((i + j) & 1)){
                    a[i][j]++;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cout << a[i][j] << ((j == m) ? '\n' : ' ');
            }
        }
    }
    return 0;
}