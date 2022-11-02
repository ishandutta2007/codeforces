#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
char c[200000];
int x[200000];
int ans[200000];

void input(){
    cin >> n;
    for(int i = 0; i < 2*n; i++){
        cin >> c[i];
        if(c[i] == '-') cin >> x[i];
    }
}

void solve(){
    set<int> rem;
    for(int i = 0; i < 2*n; i++) {
        rem.insert(i);
    }
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < 2*n; i++){
        if(c[i] == '-'){
            que.push(P(x[i], i));
        }
    }
    while(!que.empty()){
        P p = que.top(); que.pop();
        int idx = p.second;
        auto ptr = rem.find(idx);
        if(ptr == rem.begin()){
            cout << "NO" << endl;
            return;
        }
        ptr--;
        int j = *ptr;
        if(c[j] == '-'){
            cout << "NO" << endl;
            return;
        }
        rem.erase(j);
        ans[j] = x[idx];
        rem.erase(idx);
    }
    cout << "YES" << endl;
    for(int i = 0; i < 2*n; i++){
        if(c[i] == '+') cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}