#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
inline int read01(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	return ch-'0';
}
const int M=1010;
const int dx[]={0,1,0,-1},dy[]={-1,0,1,0};
int col[M][M];
#define pii pair<int,int>
vector<pii> v[M*M];
#define mp make_pair 
int n,m,a[M][M];
void dfs(int x,int y,int c){
	col[x][y]=c;
	v[c].pb(mp(x,y));
	F(i,0,3){
		int tx=x+dx[i],ty=y+dy[i];
		if (tx && ty && tx<=n && ty<=m && !col[tx][ty] && a[tx][ty]==a[x][y]){
			dfs(tx,ty,c);
		}
	}
}
int T,ct,q[M*M],tim[M*M]; 
int main(){
	n=read(); m=read(); T=read();
	F(i,1,n){
		F(j,1,m){
			a[i][j]=read01();
		}
	}
	int l=1,r=0;
	F(i,1,n){
		F(j,1,m){
			if (!col[i][j]){
				dfs(i,j,++ct);
				if (SZ(v[ct])+1>1){
					q[++r]=ct;
					tim[ct]=1;
				}
			}
		}
	}
	while (l<=r){
		int co=q[l++];
		F(i,0,SZ(v[co])){
			int x=v[co][i].first,y=v[co][i].second;
			F(j,0,3){
				int tx=x+dx[j],ty=y+dy[j];
				if (tx && ty && tx<=n && ty<=m && !tim[col[tx][ty]]){
					tim[col[tx][ty]]=tim[co]+1;
					q[++r]=col[tx][ty];
				}
			}
		}
	}
	F(i,1,T){
		int x=read(),y=read();
		LL t=read();
		int ti=tim[col[x][y]];
//		cout<<ti<<"  time access \n";
		if (t<ti || !ti){
			cout<<a[x][y]<<"\n";
		}
		else cout<<(a[x][y]^((t-ti+1)&1))<<"\n";
	}
	return 0;
}