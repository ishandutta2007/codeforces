#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
vector<int> v[M];
int n,m,dis[M];
void work(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[y].pb(x);
	}
	vector<int> ans;
	F(x,1,n){
		dis[x]=0;
		for (int y:v[x]){
			dis[x]=max(dis[x],dis[y]+1);
		}
		if (dis[x]==2) ans.pb(x),dis[x]=-1;
		v[x].clear(); 
	}
	cout<<ans.size()<<"\n";
	for (int x:ans){
		 cout<<x<<" ";
	}
	cout<<"\n";
}
int main(){
	int T=read();
	while (T--) work();
    return 0;
}