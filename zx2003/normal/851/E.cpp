#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int n,i,j,x,y,ans,a[105];
map<int,int> m;
map<int,int>::iterator it;
struct hash{
	static const int mo=1000003,N=11000000;
	int h[mo],a[N],nxt[N],xb,k,sg[N];
	inline void ins(int x,int y){
		register int z=x%mo;
		a[++xb]=x;
		sg[xb]=y;
		nxt[xb]=h[z];
		h[z]=xb;
	}
	inline int find(int x){
		register int i=h[x%mo];
		for(;i;i=nxt[i])if(a[i]==x)return sg[i];
		return -1;
	}
}h;
int dp(int x){
	int t=h.find(x);
	if(t!=-1)return t;
	bool v[33];
	memset(v,0,sizeof v);
	register int i=1;
	for(;x>>i;++i)v[dp(x>>i|(x&((1<<i)-1)))]=1;
	for(i=0;v[i];++i);
	h.ins(x,i);
	return i;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		a[i]=x;
		for(j=2;j*j<=x;++j)
			if(x%j==0){
				for(y=0;x%j==0;++y)x/=j;
				m[j]|=1<<y;
			}
		if(x>1)m[x]|=2;
	}
	for(it=m.begin();it!=m.end();++it){
		for(j=1;j<=n;++j)if(a[i]%it->first!=0)break;
		if(j<=n)it->second|=1;
		ans^=dp(it->second);
	}
	puts(ans?"Mojtaba":"Arpa");
	return 0;
}