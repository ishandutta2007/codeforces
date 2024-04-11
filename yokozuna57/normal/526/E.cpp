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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;

int main(){
	static ll n,q;
	static ll a[1000010],s[1000010] = {};
	scanf("%I64d%I64d",&n,&q);
	rep1(i,n){
		scanf("%I64d",&a[i]);
		s[i] = s[i-1] + a[i];
	}
	
	static ll dp[1000010][2];
	rep(ppp,q){
		ll b;
		scanf("%I64d",&b);
		
		ll nex = n;
		rrep(i,n){
			while(s[nex]-s[i] > b)nex--;
			if(nex == n){
				dp[i][0] = 0;
				dp[i][1] = i;
			}
			else {
				dp[i][0] = dp[nex][0] + 1;
				dp[i][1] = dp[nex][1];
			}
		}
		
		ll ret = n;
		for(int i = 0 ; s[i] < b && i < n ; i ++){
			ret = min ( ret , dp[i][0] + (s[n]-s[dp[i][1]]+s[i]-1)/b + 1 );
		}
		printf("%I64d\n",ret);
	}
}