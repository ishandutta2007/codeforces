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
	ll n,k;
	string s,t;
	cin >> n >> k;
	cin >> s >> t;
	
	static ll cnt[500010];
	if(s[0] == 'b' || t[0] == 'a')cnt[0] = 1;
	else cnt[0] = 2;
	for(int i = 1 ; i < n ; i ++){
		cnt[i] = cnt[i-1]*2;
		if(s[i] == 'b')cnt[i] --;
		if(t[i] == 'a')cnt[i] --;
		if(cnt[i] > k)break;
	}
	for(int i = n-1 ; i > 0 ; i --){
		cnt[i] -= cnt[i-1];
	}
	
	ll ret = 0;
	for(int i = 0 ; i < n ; i ++){
		cnt[i] = min( cnt[i] , k );
		ret += (n-i)*cnt[i];
		k -= cnt[i];
		if(k == 0)break;
	}
	cout << ret << endl;
}