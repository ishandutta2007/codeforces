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

int main(){
	ll n,m,k,x,y;
	cin >> n >> m >> k >> x >> y;
	
	if(n == 2){
		n = 1;
		y += (x-1)*m;
		m *= 2;
	}
	if(n == 1){
		printf("%I64d ",(k+m-1)/m);
		printf("%I64d ",k/m);
		printf("%I64d\n",(k+m-y)/m);
		return 0;
	}
	
	ll t = k/((n-1)*m);
	k %= (n-1)*m;
	
	if(t == 0){
		printf("%I64d ",(ll)1);
	}
	else if(t == 1){
		if(k <= m)printf("%I64d ",(ll)1);
		else printf("%I64d ",(ll)2);
	}
	else {
		if(k <= m)printf("%I64d ",t);
		else printf("%I64d ",t+1);
	}
	
	ll b=0,c=0;
	b += t/2;
	if(t%2 == 1 && k >= m)b ++;
	if(x != n)c += (t+1)/2;
	if(x != 1)c += t/2;
	if(t%2 == 0){
		if(k >= (x-1)*m+y)c ++;
	}
	else{
		if(k >= (n-x)*m+y)c ++;
	}
	printf("%I64d %I64d\n",b,c);
}