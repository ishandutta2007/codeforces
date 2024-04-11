#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

const ll M = 1000000007;

int par[200010],r[200010];
int cnt = 0;
void init(int n){
	rep(i,200010){
		par[i] = i;
		r[i] = 0;
	}
	cnt = n*2;
}
int find(int x){
	if(par[x] == x)return x;
	return par[x] = find(par[x]);
}
bool same(int x,int y){
	return find(x) == find(y);
}
void unit(int x,int y){
	if(same(x,y))return;
	x = find(x);
	y = find(y);
	if(r[x] < r[y]){
		par[x] = y;
	}
	else {
		par[y] = x;
		if(r[x] == r[y]){
			r[x] ++;
		}
	}
	cnt --;
}

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){ ret *= x; ret %= M; }
	return ret;
}

int main(){
	ll n,m;
	cin >> n >> m;
	
	init(n);
	rep(i,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a > b)swap(a,b);
		if(a == 1){
			unit(2,2*b+c);
			unit(3,2*b+(1-c));
		}
		else {
			if(c == 1){
				unit(2*a,2*b);
				unit(2*a+1,2*b+1);
			}
			else {
				unit(2*a+1,2*b);
				unit(2*a,2*b+1);
			}
		}
	}
	
	rep1(i,n){
		if(same(2*i,2*i+1)){
			cout << 0 << endl;
			return 0;
		}
	}
	rep1(i,n){
		unit(2*i,2*i+1);
	}
	cout << modpow(2,cnt-1) << endl;
}