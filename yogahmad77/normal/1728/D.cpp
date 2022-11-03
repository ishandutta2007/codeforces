#include<bits/stdc++.h>
using namespace std;

const int mx = 2003;

string ss;
int dp[mx][mx][3];
vector<tuple<int, int, int>> aa;

int f(int l, int r, int siapa){
    if(l > r) return siapa;
    int &ret = dp[l][r][siapa];
    if(ret != -1) return ret;
    aa.push_back(make_tuple(l, r, siapa));
    ret = 2;

    // pick l
    int jadi = 1;

    auto x = ss[l];
    auto y = ss[l + 1];
    int z = siapa;
    if(x > y) z = 1;
    if(y > x) z = 2;
    int has = f(l + 2, r, z);
    if(has == 2) jadi = 2;
    if(has == 0) jadi = 0;

    y = ss[r];
    z = siapa;
    if(x > y) z = 1;
    if(y > x) z = 2;
    has = f(l + 1, r - 1, z);

    if(has == 2) jadi = 2;
    if(jadi != 2 && has == 0) jadi = 0;

    if(jadi == 1) ret = 1;
    if(jadi == 0) ret = 0;

    // pick r
    jadi = 1;

    x = ss[r];
    y = ss[l];
    z = siapa;
    if(x > y) z = 1;
    if(y > x) z = 2;
    has = f(l + 1, r - 1, z);
    if(has == 2) jadi = 2;
    if(has == 0) jadi = 0;

    y = ss[r - 1];
    z = siapa;
    if(x > y) z = 1;
    if(y > x) z = 2;
    has = f(l, r - 2, z);

    if(has == 2) jadi = 2;
    if(jadi != 2 && has == 0) jadi = 0;

    if(jadi == 1) ret = 1;
    else if(ret != 1 && jadi == 0) ret = 0;
    return ret;
}

void empty(){
    for(auto xx : aa){
        int a, b, c;
        tie(a, b, c) = xx;
        dp[a][b][c] = -1;
    }
    aa.clear();
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    memset(dp, -1, sizeof dp);
    while(t--){
        cin >> ss;
        empty();
        int res = f(0, ss.size() - 1, 0);
        if(res == 1) cout << "Alice\n";
        else if(res == 2) cout << "Bob\n";
        else cout << "Draw\n";

    }
    
}