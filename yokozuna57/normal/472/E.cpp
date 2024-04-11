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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

vector<P> ans;
int s[32][32],g[32][32];

void ope(int x0,int y0,int x1,int y1){
	swap(s[x0][y0],s[x1][y1]);
	ans.pb(P(x1,y1));
	
}

void start(int x,int y){
	ans.pb(P(x,y));
	for(int i=y;i>1;i--)ope(x,i,x,i-1);
	for(int i=x;i>1;i--)ope(i,1,i-1,1);
}

void row(int x,int y,int z){//(x,y)->(x,z)
	if(y==z)return;
	if(x!=1){
		if(y<z){
			rep1(i,x-2)ope(i,1,i+1,1);
			rep1(i,y-1)ope(x-1,i,x-1,i+1);
			for(int i=y;i<z;i++){
				ope(x-1,i,x,i);
				ope(x,i,x,i+1);
				ope(x,i+1,x-1,i);
				ope(x-1,i,x-1,i+1);
			}
			for(int i=z;i>1;i--){
				ope(x-1,i,x-1,i-1);
			}
			for(int i=x-1;i>1;i--){
				ope(i,1,i-1,1);
			}
		}
		else {
			rep1(i,x-2)ope(i,1,i+1,1);
			rep1(i,y-1)ope(x-1,i,x-1,i+1);
			for(int i=y;i>z;i--){
				ope(x-1,i,x,i);
				ope(x,i,x,i-1);
				ope(x,i-1,x-1,i);
				ope(x-1,i,x-1,i-1);
			}
			for(int i=z;i>1;i--){
				ope(x-1,i,x-1,i-1);
			}
			for(int i=x-1;i>1;i--){
				ope(i,1,i-1,1);
			}
		}
	}
	else {
		if(y<z){
			ope(1,1,2,1);
			rep1(i,y-1)ope(2,i,2,i+1);
			for(int i=y;i<z;i++){
				ope(2,i,1,i);
				ope(1,i,1,i+1);
				ope(1,i+1,2,i);
				ope(2,i,2,i+1);
			}
			for(int i=z;i>1;i--){
				ope(2,i,2,i-1);
			}
			ope(2,1,1,1);
		}
		else {
			ope(1,1,2,1);
			rep1(i,y-1)ope(2,i,2,i+1);
			for(int i=y;i>z;i--){
				ope(2,i,1,i);
				ope(1,i,1,i-1);
				ope(1,i-1,2,i);
				ope(2,i,2,i-1);
			}
			for(int i=z;i>1;i--){
				ope(2,i,2,i-1);
			}
			ope(2,1,1,1);
		}
	}
}

void col(int x,int y,int z){//(x,z)->(y,z)
	if(x==y)return;
	if(z!=1){
		if(x<y){
			rep1(i,z-2)ope(1,i,1,i+1);
			rep1(i,x-1)ope(i,z-1,i+1,z-1);
			for(int i=x;i<y;i++){
				ope(i,z-1,i,z);
				ope(i,z,i+1,z);
				ope(i+1,z,i,z-1);
				ope(i,z-1,i+1,z-1);
			}
			for(int i=y;i>1;i--){
				ope(i,z-1,i-1,z-1);
			}
			for(int i=z-1;i>1;i--){
				ope(1,i,1,i-1);
			}
		}
		else {
			rep1(i,z-2)ope(1,i,1,i+1);
			rep1(i,x-1)ope(i,z-1,i+1,z-1);
			for(int i=x;i>y;i--){
				ope(i,z-1,i,z);
				ope(i,z,i-1,z);
				ope(i-1,z,i,z-1);
				ope(i,z-1,i-1,z-1);
			}
			for(int i=y;i>1;i--){
				ope(i,z-1,i-1,z-1);
			}
			for(int i=z-1;i>1;i--){
				ope(1,i,1,i-1);
			}
		}
	}
	else {
		if(x<y){
			ope(1,1,1,2);
			rep1(i,x-1)ope(i,2,i+1,2);
			for(int i=x;i<y;i++){
				ope(i,2,i,1);
				ope(i,1,i+1,1);
				ope(i+1,1,i,2);
				ope(i,2,i+1,2);
			}
			for(int i=y;i>1;i--){
				ope(i,2,i-1,2);
			}
			ope(1,2,1,1);
		}
		else {
			ope(1,1,1,2);
			rep1(i,x-1)ope(i,2,i+1,2);
			for(int i=x;i>y;i--){
				ope(i,2,i,1);
				ope(i,1,i-1,1);
				ope(i-1,1,i,2);
				ope(i,2,i-1,2);
			}
			for(int i=y;i>1;i--){
				ope(i,2,i-1,2);
			}
			ope(1,2,1,1);
		}
	}
}

int main(){
	int n,m;
	
	cin>>n>>m;
	rep1(i,n)rep1(j,m)scanf("%d",&s[i][j]);
	rep1(i,n)rep1(j,m)scanf("%d",&g[i][j]);
	
	if(n>=2&&m>=2){
		int x,y;
		rep1(i,n)rep1(j,m)if(s[i][j]==g[1][1]){ x=i; y=j; }
		start(x,y);
		
		rep1(x0,n)rep1(y0,m){
			if(x0+y0>2){
				x=-1; y=-1;
				int i=x0,j=y0;
				for(;i<=n;i++){
					for(;j<=m;j++){
						if(s[i][j]==g[x0][y0]){ x=i; y=j; }
					}
					j=1;
				}
				
				if(x==-1){
					cout<<-1<<endl; 
					//rep1(i,n){rep1(j,m)cout<<s[i][j]; cout<<endl;}
					return 0;
				}
				
				row(x,y,y0);
				col(x,x0,y0);
			}
		}
		
		printf("%d\n",ans.size()-1);
		rep(i,ans.size()){
			printf("%d %d\n",ans[i].fr,ans[i].sc);
		}
		
		return 0;
	}
	else if(n==1){
		rep1(i,m){
			rep1(j,m){
				if(i<j){
					ans.pb(P(1,i));
					for(int k=i;k<j;k++){
						ope(1,k,1,k+1);
					}
					bool t=true;
					rep1(k,m){
						if(s[1][k]!=g[1][k])t=false;
					}
					if(t){
						printf("%d\n",ans.size()-1);
						rep(i,ans.size()){
							printf("%d %d\n",ans[i].fr,ans[i].sc);
						}
						return 0;
					}
					
					for(int k=j;k>i;k--){
						ope(1,k,1,k-1);
					}
					ans.clear();
				}
				if(i>j){
					ans.pb(P(1,i));
					for(int k=i;k>j;k--){
						ope(1,k,1,k-1);
					}
					bool t=true;
					rep1(k,m){
						if(s[1][k]!=g[1][k])t=false;
					}
					if(t){
						printf("%d\n",ans.size()-1);
						rep(i,ans.size()){
							printf("%d %d\n",ans[i].fr,ans[i].sc);
						}
						return 0;
					}
					
					for(int k=j;k<i;k++){
						ope(1,k,1,k+1);
					}
					ans.clear();
				}
			}
		}
		cout<<-1<<endl;
	}
	else if(m==1){
		rep1(i,n){
			rep1(j,n){
				if(i<j){
					ans.pb(P(i,1));
					for(int k=i;k<j;k++){
						ope(k,1,k+1,1);
					}
					bool t=true;
					rep1(k,n){
						if(s[k][1]!=g[k][1])t=false;
					}
					if(t){
						printf("%d\n",ans.size()-1);
						rep(i,ans.size()){
							printf("%d %d\n",ans[i].fr,ans[i].sc);
						}
						return 0;
					}
					
					for(int k=j;k>i;k--){
						ope(k,1,k-1,1);
					}
					ans.clear();
				}
				else if(i>j){
					ans.pb(P(i,1));
					for(int k=i;k>j;k--){
						ope(k,1,k-1,1);
					}
					bool t=true;
					rep1(k,n){
						if(s[k][1]!=g[k][1])t=false;
					}
					if(t){
						printf("%d\n",ans.size()-1);
						rep(i,ans.size()){
							printf("%d %d\n",ans[i].fr,ans[i].sc);
						}
						return 0;
					}
					
					for(int k=j;k<i;k++){
						ope(k,1,k+1,1);
					}
					ans.clear();
				}
			}
		}
		cout<<-1<<endl;
	}
						
}