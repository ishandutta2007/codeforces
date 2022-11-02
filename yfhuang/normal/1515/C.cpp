#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, m, x;
const int maxn = 1e5 + 5;

int h[maxn];
int y[maxn];
set<pi> s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        s.clear();
        cin >> n >> m >> x;
        for(int i = 1;i <= m;i++){
            s.insert(mp(0, i));
        }
        for(int i = 1;i <= n;i++){
            cin >> h[i];
            auto it = s.begin();
            int sum = it->fi;
            y[i] = it->se;
            s.erase(s.begin());
            s.insert(mp(sum + h[i], y[i]));
        }
        cout << "YES" << endl;
        for(int i = 1;i <= n;i++){
            cout << y[i] << ((i == n) ? '\n' : ' ');
        }
    }
    return 0;
}