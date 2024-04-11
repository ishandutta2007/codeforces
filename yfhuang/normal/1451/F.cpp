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

int val[maxn * 2];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(val, 0, sizeof(val));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> a[i][j];
                val[i + j] ^= a[i][j];
            }
        }
        bool flag = false;
        for(int i = 0;i < n + m - 1;i++){
            if(val[i] != 0){
                flag = true;
            }
        }
        if(flag){
            cout << "Ashish" << endl;
        }else{
            cout << "Jeel" << endl;
        }
    }
    return 0;
}