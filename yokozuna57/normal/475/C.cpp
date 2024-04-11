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

char a[1010][1010];

bool dfs(int S1,int S2,int T1,int T2,int x,int y){
	if(S1+x==S2&&T1+y==T2)return true;
	char c0=a[S1+x][T1],c1=a[S1][T1+y];
	if(c0==c1)return false;
	if(c0=='X')return dfs(S1+1,S2,T1,T2,x,y);
	else return dfs(S1,S2,T1+1,T2,x,y);
}

int main(){
	int n,m;
	cin>>n>>m;
	
	rep(i,1010)rep(j,1010)a[i][j]='.';
	
	rep(i,n){
		scanf("\n");
		rep(j,m){
			scanf("%c",&a[i][j]);
		}
	}
	
	int s=0,g=0;
	int S1=-1,S2=n;
	rep(i,n){
		rep(j,s)if(a[i][j]=='X'){ cout<<-1<<endl; return 0; }
		while(s<m&&a[i][s]=='.')s++;
		if(s>=m&&S2==n){
			if(S1==-1)s=0;
			if(S1!=-1)S2=i;
		}
		int gg=s;
		while(gg<m&&a[i][gg]=='X')gg++;
		if(gg>0&&S1==-1)S1=i;
		if(g>gg){ cout<<-1<<endl; return 0; }
		g=gg;
		for(int j=g;j<m;j++)if(a[i][j]=='X'){ cout<<-1<<endl; return 0; }
	}
	
	s=0,g=0;
	int T1=-1,T2=m;
	rep(j,m){
		rep(i,s)if(a[i][j]=='X'){ cout<<-1<<endl; return 0; }
		while(s<n&&a[s][j]=='.')s++;
		if(s>=n&&T2==m){
			if(T1==-1)s=0;
			if(T1!=-1)T2=j;
		}
		int gg=s;
		while(gg<n&&a[gg][j]=='X')gg++;
		if(gg>0&&T1==-1)T1=j;
		if(g>gg){ cout<<-1<<endl; return 0; }
		g=gg;
		for(int i=g;i<n;i++)if(a[i][j]=='X'){ cout<<-1<<endl; return 0; }
	}
	
	int x=0,y=0;
	rep(j,m)if(a[S1][j]=='X')y++;
	rep(i,n)if(a[i][T1]=='X')x++;
	
	int ret=INF;
	rep1(i,x){
		if(dfs(S1,S2,T1,T2,i,y))ret=min(ret,i*y);
		//cout<<i<<" "<<y<<endl;
	}
	rep1(j,y){
		if(dfs(S1,S2,T1,T2,x,j))ret=min(ret,x*j);
		//cout<<x<<" "<<j<<endl;
	}
	
	if(ret==INF)cout<<-1<<endl;
	else cout<<ret<<endl;
	
	//printf("%d %d %d %d\n",S1,S2,T1,T2);
}