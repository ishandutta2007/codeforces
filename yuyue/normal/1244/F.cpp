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
const int M=3e5+10;
int f[M],ct[M];
int fd(int k){
	if (f[k]==k) return k;
	return f[k]=fd(f[k]);
}
vector<int> v[M];
int dis[M],home[M],q[M];
char ch[M],ans[M];
int n,k;
bool vis[M];
int main(){
	n=read(); k=read();
	scanf("%s",ch+1);
	F(i,1,n) f[i]=i;
	F(i,2,n){
		if (ch[i]==ch[i-1]) f[fd(i)]=fd(i-1);
	}
	if (ch[n]==ch[1]) f[fd(n)]=fd(1);
	F(i,1,n) f[i]=fd(i),ct[f[i]]++;
	
	F(i,2,n){
		if (f[i]!=f[i-1]) v[f[i]].pb(f[i-1]),v[f[i-1]].pb(f[i]);
	}
	if (f[1]!=f[n]) v[f[1]].pb(f[n]),v[f[n]].pb(f[1]);
	
	int l,r;
	l=1; r=0; 
	bool flag=0;
	F(i,1,n) {
		if (ct[i]>1){
			home[i]=i;
			q[++r]=i;
			flag=1;
			vis[i]=1;
		}
	}
	if (!flag){
		F(i,1,n){
			bool o=(ch[i]=='B');
			if (k&1) o^=1;
			if (o) cout<<'B';
			else cout<<'W';
		}
		//?
		return 0;
	}
	while (l<=r){
		int x=q[l++]; 
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			if (vis[y]) continue;
			dis[y]=dis[x]+1; home[y]=home[x];
			q[++r]=y; vis[y]=1;
		}
	}
	F(i,1,n){
		int bl=f[i];
//		cout<<i<<" "<<dis[bl]<<" "<<bl<<"  gg\n";
		if (ct[bl]>2){
			ans[i]=ch[i];
		}
		else {
			if (dis[bl]<=k) ans[i]=ch[home[bl]];
			else {
				bool o=(ch[i]=='B');
				if (k&1) o^=1;
				if (o) ans[i]='B';
				else ans[i]='W';
			}
		}
	}
	cout<<(ans+1)<<"\n";
	return 0;
}