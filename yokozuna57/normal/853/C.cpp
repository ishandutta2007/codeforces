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
typedef pair<P,P> P2;

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
#define mp2(a,b,c,d) P2(P(a,b),P(c,d))

const ll INF=1000000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

struct BIT{
	int a[1<<18];
	int siz;
	void init(){
		siz = 1<<18;
		rep(i,(1<<18))a[i] = 0;
	}
	void add(int k){
		while(k <= siz){
			a[k] ++;
			k += k&-k;
		}
	}
	int sum(int k){
		int ret = 0;
		while(k > 0){
			ret += a[k];
			k -= k&-k;
		}
		return ret;
	}
	int query(int l,int r){
		if(l == 1)return sum(r);
		return sum(r)-sum(l-1);
	}
}bit;

int main(){
	static int n,q;
	static int a[200010];
	static int l[2000010],d[2000010],r[2000010],u[2000010];
	static ll cnt[2000010] = {};
	scanf("%d%d",&n,&q);
	rep1(i,n)scanf("%d",&a[i]);
	rep(i,q){
		scanf("%d%d%d%d",&l[i],&d[i],&r[i],&u[i]);
		l[1*q+i] = 1; r[1*q+i] = l[i]-1; d[1*q+i] = u[i]+1; u[1*q+i] = n;
		l[2*q+i] = l[i]; r[2*q+i] = r[i]; d[2*q+i] = u[i]+1; u[2*q+i] = n;
		l[3*q+i] = r[i]+1; r[3*q+i] = n; d[3*q+i] = u[i]+1; u[3*q+i] = n;
		l[4*q+i] = 1; r[4*q+i] = l[i]-1; d[4*q+i] = d[i]; u[4*q+i] = u[i];
		l[5*q+i] = r[i]+1; r[5*q+i] = n; d[5*q+i] = d[i]; u[5*q+i] = u[i];
		l[6*q+i] = 1; r[6*q+i] = l[i]-1; d[6*q+i] = 1; u[6*q+i] = d[i]-1;
		l[7*q+i] = l[i]; r[7*q+i] = r[i]; d[7*q+i] = 1; u[7*q+i] = d[i]-1;
		l[8*q+i] = r[i]+1; r[8*q+i] = n; d[8*q+i] = 1; u[8*q+i] = d[i]-1;
	}
	
	static vector<P2> Q[200010];
	rep(i,9*q){
		Q[l[i]].pb(mp2(i,0,d[i],u[i]));
		Q[r[i]+1].pb(mp2(i,1,d[i],u[i]));
	}
	bit.init();
	for(int i = 1 ; i <= n+1 ; i ++){
		for(int j = 0 ; j < Q[i].size() ; j ++){
			P2 p = Q[i][j];
			if(p.fr.sc == 0){
				cnt[p.fr.fr] -= bit.query(p.sc.fr,p.sc.sc);
			}
			else {
				cnt[p.fr.fr] += bit.query(p.sc.fr,p.sc.sc);
			}
		}
		if(i == 0 || i == n+1)continue;
		bit.add(a[i]);
	}
	
	for(int i = 0 ; i < q ; i ++){
		ll ret = cnt[i]*(n-1);
		ret -= cnt[i]*(cnt[i]-1)/2;
		ret += cnt[1*q+i]*cnt[5*q+i];
		ret += cnt[1*q+i]*cnt[7*q+i];
		ret += cnt[1*q+i]*cnt[8*q+i];
		ret += cnt[2*q+i]*cnt[4*q+i];
		ret += cnt[2*q+i]*cnt[5*q+i];
		ret += cnt[2*q+i]*cnt[6*q+i];
		ret += cnt[2*q+i]*cnt[7*q+i];
		ret += cnt[2*q+i]*cnt[8*q+i];
		ret += cnt[3*q+i]*cnt[4*q+i];
		ret += cnt[3*q+i]*cnt[6*q+i];
		ret += cnt[3*q+i]*cnt[7*q+i];
		ret += cnt[4*q+i]*cnt[5*q+i];
		ret += cnt[4*q+i]*cnt[7*q+i];
		ret += cnt[4*q+i]*cnt[8*q+i];
		ret += cnt[5*q+i]*cnt[6*q+i];
		ret += cnt[5*q+i]*cnt[7*q+i];
		cout << ret << endl;
	}
}