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
typedef pair<ll,P> P1;

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

bool prim[1200010];
void run_prime(){
	rep(i,1200010)prim[i]=true;
	prim[0]=false; prim[1]=false;
	for(int i=2;i*i<=1200000;i++){
		if(prim[i]){
			for(int j=i*i;j<=1200000;j+=i){
				prim[j]=false;
			}
		}
	}
}

bool pal[1200010];
void run_pal(){
	pal[0] = false;
	int d = 1 , t = 10;
	int a[10] = {};
	rep1(i,1200000){
		a[0] ++;
		int j = 0;
		while(a[j] >= 10){
			a[j] -= 10;
			a[j+1] ++;
			j ++;
		}
		if(t == i){
			d ++;
			t *= 10;
		}
		pal[i] = true;
		for(int j = 0 ; pal[i] && j < d-1-j ; j ++){
			pal[i] &= (a[j] == a[d-1-j]);
		}
	}
}

int main(){
	run_prime();
	run_pal();
	static ll s[1200010] = {};
	static ll t[1200010] = {};
	rep(i,1200010){
		s[i] = s[i-1]; if(prim[i])s[i] ++;
		t[i] = t[i-1]; if(pal[i])t[i] ++;
	}
	ll p,q;
	cin >> p >> q;
	int ret = 0;
	rrep1(i,1200000){
		if(q*s[i] <= p*t[i]){
			cout << i << endl;
			return 0;
		}
	}
}