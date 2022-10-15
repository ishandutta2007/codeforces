#include <cstdio>
#include <set>
const int inf=1e9,PW=30,N=1e5+10;
int n,k,mx,cnt,a[N],f[N],ans[N],rec[N],bkt[N],dbl[PW][N];
bool vis[N];
std::set<int> set;
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline int max(int x,int y){return x>y?x:y;}
	inline void cmin(int &x,int y){if(x>y)x=y;}
	inline void cmax(int &x,int y){if(x<y)x=y;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x){
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar(' ');
	}
}using basic::max;using basic::cmin;using basic::cmax;using basic::read;using basic::write;
int main(){
	n=read();
	for(int i=1;i<=n;++i)++bkt[dbl[0][i]=read()];
	for(int i=1;i<=n;++i)cmax(mx,a[i]=read());
	for(int i=1;i<=n;++i)f[i]=i,k+=max(0,bkt[i]-1),rec[i]=inf;
	k=(mx-n)/k;
	for(int i=1;i<PW;++i)for(int j=1;j<=n;++j)dbl[i][j]=dbl[i-1][dbl[i-1][j]];
	for(int i=PW-1;~i;--i){
		if(k<(1<<i))continue;
		k-=1<<i;
		for(int j=1;j<=n;++j)f[j]=dbl[i][f[j]];
	}
	cnt=1;
	for(int i=1;i<=n;++i)cmin(rec[f[i]],i);
	for(int i=1;i<=n;++i)if(a[i]<=n)vis[a[i]]=true,ans[rec[i]]=a[i];
	for(int i=1;i<=n;++i)if(!vis[i])set.insert(i);
	for(int i=1;i<=n;++i){
		if(!ans[i]){
			if(a[f[i]]<=n){
				auto it=set.lower_bound(a[f[i]]);
				ans[i]=*it,set.erase(it);
			}
			else ans[i]=*set.begin(),set.erase(set.begin());
		}
		write(ans[i]);
	}
	return 0;
}