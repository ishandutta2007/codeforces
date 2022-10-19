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

int f(int n){
	int ret = 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			ret ++;
			n /= i;
			if(n%i == 0)return 0;
		}
	}
	if(n != 1)ret ++;
	if(ret%2 == 0)return -1;
	else return 1;
}

vector<int> divisors(int n){
	vector<int> vec;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			vec.pb(i);
			while(n%i==0)n /= i;
		}
	}
	if(n!=1)vec.pb(n);
	
	vector<int> ret;
	ret.pb(1);
	rep(i,vec.size()){
		int s = ret.size();
		rep(j,s){
			ret.pb(ret[j]*vec[i]);
		}
	}
	
	return ret;
}

int main(){
	static int n,q;
	static int a[200010];
	static int x[200010];
	scanf("%d%d",&n,&q);
	rep1(i,n){
		scanf("%d",&a[i]);
	}
	rep(i,q){
		scanf("%d",&x[i]);
	}
	
	static ll cnt[500010];
	static ll k[500010];
	static bool used[200010];
	static bool sqfree[500010];
	rep(i,200010)used[i] = false;
	for(int i = 2 ; i <= 500010 ; i ++){
		k[i] = f(i);
		cnt[i] = 0;
		sqfree[i] = true;
		/*int i_ = i;
		for(int j = 2 ; j*j <= i_ ; j ++){
			if(i_%j == 0){
				i_ /= j;
				if(i_%j == 0){
					sqfree[i] = false;
					break;
				}
			}
		}*/
	}
	ll ans = 0;
	ll now = 0;
	
	rep(i,q){
		if(used[x[i]]){
			used[x[i]] = false;
			now --;
			vector<int> vec = divisors(a[x[i]]);
			rep(j,vec.size()){
				int t = vec[j];
				ans -= k[t]*(cnt[t]-1);
				cnt[t] --;
			}
		}
		else {
			used[x[i]] = true;
			now ++;
			vector<int> vec = divisors(a[x[i]]);
			rep(j,vec.size()){
				int t = vec[j];
				ans += k[t]*cnt[t];
				cnt[t] ++;
			}
		}
		printf("%I64d\n",(now*(now-1))/2 - ans);
	}
}