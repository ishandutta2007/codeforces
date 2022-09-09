#include<bits/stdc++.h>
using namespace std;
const int N=600005;
typedef long long ll;
inline void putl(ll x){
	if(x){
		static int buf[30],xb;
		for(xb=0;x;x/=10)buf[++xb]=x%10;
		for(;xb;)putchar(buf[xb--]|48);
	}else putchar('0');putchar('\n');
}
inline void read(int&x){
	char c=getchar();
	for(x=0;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-48;
}
vector<int>e[N],qq[N];
int a,b,i,j,n,m,ql[N],qr[N],q,r[N],be[N],st[N],w,lst[N],dep[N];
ll s1[N],s2[N],ans[N];
void dfs(int x,int fa){
	st[++w]=x;dep[x]=dep[fa]+1;
	for(int i=0;i<e[x].size();++i){
		int y=e[x][i];
		if(y!=fa){
			if(dep[y]){
				if(dep[y]<dep[x]){
					int i,u=min(x,y),v=max(x,y);
					for(i=w-1;st[i]!=y;--i)u=min(u,st[i]),v=max(v,st[i]);
					r[u]=v;
				}
			}else dfs(y,x);
		}
	}--w;
}
inline ll query(ll*a,int x){
	ll ans=0;
	for(;x;x-=x&-x)ans+=a[x];
	return ans;
}
inline void add(ll*a,int x,ll v){for(;x<=n;x+=x&-x)a[x]+=v;}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)read(a),read(b),e[a].push_back(b),e[b].push_back(a);
	for(i=1;i<=n;++i)if(!dep[i])dfs(i,0);
	for(i=n,j=n+1;i;--i)
		if(r[i]){
			if(r[i]<j)j=r[i],be[i]=i;
				else r[i]=0;
		}
	for(i=1;i<=n;++i)
		if(be[i]){for(j=i-1;j && !be[j];--j)be[j]=i;lst[i]=j;}
	read(q);
	for(i=1;i<=q;++i){
		read(ql[i]),read(qr[i]);
		qq[be[ql[i]]].push_back(i);
	}
	for(i=n;i;--i)if(be[i]==i){
		for(j=0;j<qq[i].size();++j){
			a=qq[i][j];
			if(qr[a]<r[i])continue;
			ans[a]=query(s1,qr[a])*(qr[a]+1)-query(s2,qr[a])+1ll*(i-ql[a]+1)*(qr[a]-r[i]+1);
		}
		if(i==be[1])break;
		add(s1,r[i],i-lst[i]);
		add(s2,r[i],1ll*(i-lst[i])*r[i]);
	}
	for(i=1;i<=q;++i){
		a=qr[i]-ql[i]+1;
		ans[i]=(1ll*a*(a+1)>>1)-ans[i];putl(ans[i]);
	}
	return 0;
}