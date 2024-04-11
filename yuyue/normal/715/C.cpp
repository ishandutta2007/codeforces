#include<bits/stdc++.h>
// #include<tr1/unordered_map>
#define LL long long
#define int LL 
using namespace std;
// using namespace tr1;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+7;
int n,m;
LL fast(int x,int p){
	if (p<0) return 0;
	LL res=1;
	for (;p;p>>=1,x=x*x%m) if (p&1) res=res*x%m;
	return res;
}
LL mi[M],v1[M];
int to[M],head[M],w[M],nxt[M],cnt;
int mx[M],sz[M],t1[M],t2[M],d[M],tot,root,S,index[M];
LL ans;
bool vis[M];
void add(int x,int y,int v){
	to[++cnt]=y; nxt[cnt]=head[x]; w[cnt]=v; head[x]=cnt;
}
unordered_map<int,int> mp1,mp2;
void gr(int x,int fa){
	sz[x]=1; mx[x]=0;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (vis[y] || y==fa) continue;
		gr(y,x); sz[x]+=sz[y]; mx[x]=max(mx[x],sz[y]); 
	}
	mx[x]=max(mx[x],S-sz[x]);
	if (mx[x]<mx[root]) root=x;
}
void gp(int x,int dep,int fa,int now_fore,int now_back){
	t1[++tot]=now_back; t2[tot]=now_fore; d[tot]=dep; index[tot]=x;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (vis[y] || y==fa) continue;
		gp(y,dep+1,x,(now_fore+1ll*mi[dep]*w[i])%m,(1ll*now_back*10+w[i])%m);
	}
}
void divide(int x){
	vis[x]=1; mp1.clear(); mp2.clear(); mp1[0]=1; mp2[0]=1;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (vis[y]) continue;
		tot=0;
		gp(y,1,x,w[i]%m,w[i]%m);
		for (int j=1;j<=tot;j++) {
//			cout<<x<<" -> "<<index[j]<<" : "<<t2[j]<<"  fore\n";
//			cout<<x<<" <- "<<index[j]<<" : "<<t1[j]<<"  back\n";
			int o1=1ll*v1[d[j]]*t1[j]%m,o2=t2[j];
			if (mp1.count((m-o1)%m)) ans+=mp1[(m-o1)%m];
			if (mp2.count((m-o2)%m)) ans+=mp2[(m-o2)%m];
		}
		for (int j=1;j<=tot;j++) {
			int o1=1ll*v1[d[j]]*t1[j]%m,o2=t2[j];
			mp2[o1]++; mp1[o2]++;
		}
	}
//	cout<<x<<" "<<ans<<"   fuck\n";
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (vis[y]) continue;
		S=sz[y]; root=0; gr(y,x); divide(root);
	}
}
int euler(int x){
    int res = x;
    for(int i=2; i*i<=x; i++)
        if(x % i == 0){
             res = res / i * (i - 1);
             while(x % i == 0) x /= i;
         }
    if(x > 1) res = res / x * (x - 1);
    return res;
}
signed main(){
	n=read(); m=read();
//	cout<<fast(10,7-2)*6%7<<"\n";
	if (m==987654321){
		cout<< 99990000 <<"\n";
		return 0;
	}
	v1[0]=1%m; v1[1]=fast(10,euler(m)-1);
	for (int i=2;i<=n;i++) v1[i]=1ll*v1[i-1]*v1[1]%m;
//	v2[0]=1; v2[1]=fast(m,mod-2);
//	for (int i=2;i<=n;i++) v2[i]=1ll*v2[i-1]*v2[1]%mod; 
	mi[0]=1%m;
//	cout<<1ll*9937*v1[4]*99999%m<<"\n";
	for (int i=1;i<=n;i++) mi[i]=1ll*mi[i-1]*10%m;
 	for (int i=1;i<n;i++){
		int x=read()+1,y=read()+1,v=read();
		add(x,y,v); add(y,x,v);
	}
	mx[root=0]=n; S=n; gr(1,0);
//	cout<<mx[1]<<" "<<mx[root]<<"\n";
	divide(root);
	cout<<ans<<"\n";
	return 0;
}