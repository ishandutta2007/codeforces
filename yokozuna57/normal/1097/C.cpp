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
	static int n;
	static string s[100010];
	scanf("%d",&n);
	rep(i,n)cin >> s[i];
	
	static int l[500010] = {};
	static int r[500010] = {};
	rep(i,n){
		int cnt = 0;
		rep(j,s[i].size()){
			if(s[i][j] == '(')cnt ++;
			else cnt --;
		}
		if(cnt >= 0){
			cnt = 0;
			bool b = true;
			rep(j,s[i].size()){
				if(s[i][j] == '(')cnt ++;
				else cnt --;
				b &= cnt >= 0;
			}
			if(b)l[cnt] ++;
		}
		else {
			cnt = 0;
			bool b = true;
			rrep(j,s[i].size()){
				if(s[i][j] == '(')cnt ++;
				else cnt --;
				b &= cnt <= 0;
			}
			if(b)r[-cnt] ++;
		}
	}
	
	int ret = l[0]/2;
	rep1(i,500000)ret += min( l[i] , r[i] );
	cout << ret << endl;
}