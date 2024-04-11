#include <cstdio>
#include <bitset>
#include <algorithm>
#include <unordered_map>
const int N=1e6+10;
int n,k,nk,nw,cnt,ext,ans1,ans2,p[N],a[N];
bool vis[N];
std::bitset<N> f;
std::unordered_map<int,int> map;
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline int min(int x,int y){return x<y?x:y;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar(' ');
	}
}using basic::min;using basic::read;using basic::write;
void dfs(int u){
	if(vis[u])return;
	vis[u]=true,++nw,dfs(p[u]);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		nw=0,dfs(i),a[++cnt]=nw,++map[nw];
	}
	f[0]=1;
	for(auto i:map){
		int v=i.first,c=i.second;
		for(int j=0;c;++j){
			if(c>(1<<j))c-=1<<j,f|=f<<((1<<j)*v);
			else f|=f<<(c*v),c=0;
		}
	}
	nk=k,std::sort(a+1,a+cnt+1);
	for(int h,i=1;i<=cnt;++i){
		ext+=a[i]&1,h=a[i]>>1;
		if(nk>=h)nk-=h,ans2+=h<<1;
		else ans2+=nk<<1,nk=0;
	}
	ans2+=min(nk,ext);
	write(k+(!f[k])),write(ans2);
	return 0;
}