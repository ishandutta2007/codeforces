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

typedef long long LL;
typedef long double LD;
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
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main(){
	int n,m;
	string s,t;
	cin>>n>>m;
	cin>>s>>t;
	
	static int d[500][500]; rep(i,500)rep(j,500){if(i==j)continue; d[i][j]=INF;}
	rep(i,n){
		if(s[i]=='>'){
			rep(j,m-1){
				d[m*i+j][m*i+j+1]=0;
			}
		}
		else {
			rep(j,m-1){
				d[m*i+j+1][m*i+j]=0;
			}
		}
	}
	rep(j,m){
		if(t[j]=='v'){
			rep(i,n-1){
				d[m*i+j][m*(i+1)+j]=0;
			}
		}
		else {
			rep(i,n-1){
				d[m*(i+1)+j][m*i+j]=0;
			}
		}
	}
	
	rep(k,n*m){
		rep(i,n*m){
			rep(j,n*m){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	
	rep(i,n*m){
		rep(j,n*m){
			if(d[i][j]==INF){ cout<<"NO\n"; return 0; }
		}
	}
	
	cout<<"YES\n";
}