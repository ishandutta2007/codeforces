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
	int n,m;
	char c[52][52];
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("\n");
		rep(j,m){
			scanf("%c",&c[i][j]);
		}
	}
	
	int ret = 0;
	rep(i,n-1){
		rep(j,m-1){
			vector<char> vec;
			vec.pb(c[i][j]);
			vec.pb(c[i][j+1]);
			vec.pb(c[i+1][j]);
			vec.pb(c[i+1][j+1]);
			sor(vec);
			if(vec[0] != 'a')continue;
			if(vec[1] != 'c')continue;
			if(vec[2] != 'e')continue;
			if(vec[3] != 'f')continue;
			ret ++;
		}
	}
	
	cout << ret << endl;
}