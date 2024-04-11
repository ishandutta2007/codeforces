#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=6e5+10;
int nxt[M],head[M],to[M],cnt;
int n,all;
bool tp[M];
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
}
int dfs(int x,int fa,int lim){
	if (to[head[x]]==fa) {
		all++;
		return 1;
	}
	int ct;
	if (tp[x]) ct=INT_MAX;
	else ct=0;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue;
		if (tp[x]) ct=min(ct,dfs(y,x,lim));
		else ct+=dfs(y,x,lim);
	}
	return ct;
}
bool check(int k){
	all=0;
	int tot=dfs(1,0,k);
	if (k+tot-1<=all) return 1;
	return 0;
}
int main(){
	n=read(); 
	for (int i=1;i<=n;i++) tp[i]=read();
	for (int i=2;i<=n;i++){
		int fa=read();
		add(fa,i); add(i,fa);
	}
	int l=1,r=n,ans=1;
	while (l<=r){
		int mid=(l+r>>1);
		if (check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<"\n";
    return 0;
}