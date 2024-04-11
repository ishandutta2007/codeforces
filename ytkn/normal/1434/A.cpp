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

int a[6];
int n;
int b[100000];

void input(){
    for(int i = 0; i < 6; i++){
        cin >> a[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> b[i];
}


void solve(){
    sort(a, a+6);
    multiset<P> st;
    for(int i = 0; i < n; i++){
        st.insert(P(b[i]-a[0], 5));
    }
    int ans = 2e9;
    while(true){
        P pl = *(st.begin());
        auto p = st.end(); p--;
        P pr = *p;
        ans = min(ans, pr.first-pl.first);
        if(pl.second == 0) break;
        st.erase(st.find(pl));
        int idx = pl.second;
        st.insert(P(pl.first+a[idx]-a[idx-1], idx-1));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}