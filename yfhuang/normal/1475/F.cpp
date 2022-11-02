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
int n;
const int maxn = 1005;
string a[maxn];
string b[maxn];

int c[maxn][maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        for(int i = 0;i < n;i++){
            cin >> b[i];
            for(int j = 0;j < n;j++){
                c[i][j] = (a[i][j] - '0') ^ (b[i][j] - '0');
            }
        }
        bool flag = true;
        for(int i = 1;i < n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                cnt += (c[i][j] ^ c[0][j]);
            }
            if(cnt != 0 and cnt != n){
                flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}