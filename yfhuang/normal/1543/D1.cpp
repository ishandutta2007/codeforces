#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;

int n, k;

const int maxn = 2e5 + 5;
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> k;
        int r = 0;
        int y = 0;
        int x = 0;
        int pre = 0;
        while(!r){
            y = pre ^ (x++);
            pre ^= y;
            cout << y << endl; 
            cout.flush();
            cin >> r;
        }
    }
    return 0;
}