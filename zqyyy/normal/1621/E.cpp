#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m,a[N],k[N],id[N];
ll sum[N];
vector<int>b[N],num[N];
multiset<int>s;
int ans[N];
inline void work(){
	n=read(),m=read(),s.clear();
	for(int i=1;i<=n;i++)s.insert(a[i]=read());
	int tot=0;
	for(int i=1;i<=m;i++){
		k[i]=read(),b[i].resize(k[i]),num[i].resize(k[i]),sum[i]=0,id[i]=i;
		for(int j=0;j<k[i];j++)b[i][j]=read(),sum[i]+=b[i][j],num[i][j]=++tot,ans[tot]=0;
	}
	sort(id+1,id+m+1,[](int x,int y){return 1.*sum[x]/k[x]>1.*sum[y]/k[y];});
	int pos=0;
	for(int x=1;x<=m;x++){
		int i=id[x];
		auto it=s.lower_bound((int)ceil(1.*sum[i]/k[i]));
		if(it==s.end()){
			if(pos){
				for(int i=1;i<=tot;i++)putchar('0');
				return;	
			}
			pos=x;
			continue;
		}
		if(!pos){
			int v=*s.rbegin();
			for(int j=0;j<k[i];j++)
				if(v>=1.*(sum[i]-b[i][j])/(k[i]-1))ans[num[i][j]]=1;	
		}
		s.erase(it);
	}
	if(pos){
		for(int i=1;i<=tot;i++)ans[i]=0;
		int v=*s.rbegin();
		for(int x=1;x<=pos;x++){
			int i=id[x];
			for(int j=0;j<k[i];j++)
				if(v>=1.*(sum[i]-b[i][j])/(k[i]-1))ans[num[i][j]]=1;
		}
	}
	for(int i=1;i<=tot;i++)printf("%d",ans[i]);puts("");
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
	return 0;
}