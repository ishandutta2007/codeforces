#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int n;
vector<int> v[M];
bool uesd[M];
int fr[M],to[M];
LL ans;
bool used[M];
void dfs(int x,int fa){
	int num=0;
	int lst=0,hh=0;
	bool gg=0;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue; 
		dfs(y,x);
		num+=(!used[y]);
		if (!used[y]){
			if (lst){
				fr[y]=to[y]=lst;
				to[lst]=fr[lst]=y;
				lst=0;
				used[y]=used[lst]=1;
				ans+=4;
			}
			else lst=y;
			hh=y; gg=1;
		}
		if (!gg) hh=y;
	}
	
	if (!used[x] && gg){
		used[x]=1;
		to[fr[hh]]=x;
		fr[x]=fr[hh];
		to[x]=hh;
		fr[hh]=x;
	}
	if (lst){
		used[lst]=used[x]=1;
		fr[x]=to[x]=lst;
		to[lst]=fr[lst]=x;
		ans+=2;
	}
	if (!used[x] && x==1){
		used[x]=1;
		to[fr[hh]]=x;
		fr[x]=fr[hh];
		to[x]=hh;
		fr[hh]=x;
		ans+=2;
	}
}
int main(){
	n=read();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(1,0); 
	cout<<ans<<"\n";
	F(i,1,n){
		cout<<to[i]<<" ";
	}
	cout<<"\n";
	return 0; 
}