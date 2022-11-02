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
typedef pair<int, int> pi;

const int maxn = 5005;

typedef long long db;

int n;

struct P {//
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return P(x + p.x, y + p.y); }
	P operator-(P p) { return P(x - p.x, y - p.y); }
	P operator*(db d) { return P(x * d, y * d); }
	P operator/(db d) { return P(x / d, y / d); }
	db dot(P p) { return x * p.x + y * p.y; }//
	db det(P p) { return x * p.y - y * p.x; }//
	db distTo(P p) { return (*this-p).abs(); }//
	db alpha() { return atan2(y, x); }//
	void read() { cin>>x>>y; }
	db abs() { return sqrt(abs2());}//
	db abs2() { return x * x + y * y; }//
	P rot90() { return P(-y,x);}//90
	P unit() { return *this/abs(); }//
}p[maxn];

int id[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        p[i].read();
    }
    vector<int> ans;
    ans.push_back(1);
    vis[1] = true;
    for(int i = 2;i <= n;i++){
        vector<int> cand;
        for(int j = 1;j <= n;j++){
            if(!vis[j]){
                cand.push_back(j);
            }
        }
        int k = cand[0];
        for(int j = 1;j < cand.size();j++){
            if((p[cand[j]] - p[ans.back()]).abs2() > (p[k] - p[ans.back()]).abs2()){
                k = cand[j]; 
            }
        }
        ans.push_back(k);
        vis[k] = true;
    }
    for(int i = 0;i < n;i++){
        cout << ans[i] << ((i == n - 1) ? '\n' : ' ');
    }
    return 0;
}