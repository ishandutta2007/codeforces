#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int n;
string cur;
vector <string> v;
map < vector <string>, bool> dp;
bool calc(vector <string> x){
    if(sz(x) == 1)return true;
    if(dp.count(x))
        return dp[x];

    int ind = sz(x) - 1;
    if(x[ind][0] == x[ind - 1][0] || x[ind][1] == x[ind - 1][1]){
        vector <string> y = x;

        y[ind - 1] = y[ind];
        y.pop_back();

        if(calc(y))return dp[x] = true;
    }
    if(ind - 3 >= 0 && (x[ind][0] == x[ind - 3][0] || x[ind][1] == x[ind - 3][1])){
        vector <string> y = x;

        y[ind - 3] = y[ind];
        y.pop_back();

        if(calc(y))return dp[x] = true;
    }
    return dp[x] = false;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cur;
        v.pb(cur);
    }

    if(calc(v))cout << "YES" << endl;
    else cout << "NO" << endl;
}