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
#define rep(i,x) for(ll i=0;i<x;i++)
#define rep1(i,x) for(ll i=1;i<=x;i++)
#define rrep(i,x) for(ll i=x-1;i>=0;i--)
#define rrep1(i,x) for(ll i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

const char a[4] = { 'A' , 'C' , 'G' , 'T' };
const ll M = 1000000009;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){ret *= x; ret %= M;}
	return ret;
}

int main(){
	static ll m;
	static int x[100010],y[100010];
	
	map<P,int> S;
	
	cin >> m;
	rep(i,m){
		scanf("%d%d",&x[i],&y[i]);
		S[P(x[i],y[i])] = i;
	}
	
	static int nex[100010][8];
	rep(i,m){
		rep(j,8){
			int nx = x[i] + dir_8[j][0];
			int ny = y[i] + dir_8[j][1];
			map<P,int>::iterator itr = S.find(P(nx,ny));
			if(itr != S.end()){
				nex[i][j] = itr->sc;
			}
			else nex[i][j] = -1;
		}
	}
	
	static bool used[100010];
	rep(i,100010)used[i] = false;
	
	rep(i,m){
		int cnt = 0;
		for(int j = 5 ; j <= 7 ; j ++){
			if(nex[i][j] != -1)cnt ++;
		}
		if(cnt == 1){
			for(int j = 5 ; j <= 7 ; j ++){
				if(nex[i][j] != -1){
					used[nex[i][j]] = true;
				}
			}
		}
	}
	
	set<ll> L;
	rep(i,m){
		if(!used[i])L.insert(i);
	}
	
	ll ret = 0;
	rrep(i,m){
		ll x_;
		if((m-i)%2 == 0){
			x_ = *L.begin();
			L.erase(L.begin());
		}
		else {
			x_ = *--L.end();
			L.erase(--L.end());
		}
		ret += x_ * modpow(m,i);
		ret %= M;
		
		ll cnt = 0;
		for(int j = 5 ; j <= 7 ; j ++){
			if(nex[x_][j] != -1){
				cnt ++;
			}
		}
		if(cnt == 1){
			for(int j = 5 ; j <= 7 ; j ++){
				if(nex[x_][j] != -1){
					int num = nex[x_][j];
					bool ttt = false;
					for(int k = 1 ; k <= 3 ; k ++){
						int num_ = nex[num][k];
						if(num_ == x_ || num_ == -1)continue;
						int cnt_ = 0;
						for(int l = 5 ; l <= 7 ; l ++){
							if(nex[num_][l] != -1){
								cnt_ ++;
							}
						}
						if(cnt_ == 1){
							ttt = true;
							break;
						}
					}
					if(!ttt)L.insert(nex[x_][j]);
				}
			}
		}
		
		for(int j = 1 ; j <= 3 ; j ++){
			int num = nex[x_][j];
			if(num == -1)continue;
			cnt = 0;
			for(int k = 5 ; k <= 7 ; k ++){
				if(nex[num][k] != -1){
					cnt ++;
				}
			}
			if(cnt == 2){
				for(int k = 5 ; k <= 7 ; k++){
					if(nex[num][k] != -1 && nex[num][k] != x_){
						L.erase(nex[num][k]);
					}
				}
			}
		}
		
		rep(j,8){
			nex[nex[x_][j]][(j+4)%8] = -1;
			nex[x_][j] = -1;
		}
	}
	
	cout << ret << endl;
}