#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define B(x) (1<<(x))
#define lowbit(x) ((x)&-(x))
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,m,S,p[18],a[18],b[18],cnt[B(17)];
ll Y,f[B(17)][18];
inline void solve(int x){
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=0;i<S;i++)
		for(int j=0;j<=n;j++){
			int y=cnt[i]+1;
			if(b[y]){
				if((a[b[y]]&i)!=a[b[y]])continue;
				if((B(b[y]-1)&i)==B(b[y]-1))continue;
				if(b[y]==x)f[i|B(b[y]-1)][y]+=f[i][j];
				else f[i|B(b[y]-1)][j]+=f[i][j];
			}else
				for(int k=1;k<=n;k++)
					if(!(i&B(k-1))){
						if((a[k]&i)^a[k])continue;
						if(k==x)f[i|B(k-1)][y]+=f[i][j];
						else f[i|B(k-1)][j]+=f[i][j];
					}
		}
}
int main(){
	n=read(),Y=read()-2000,m=read();S=B(n);
	for(int i=1;i<B(n);i++)cnt[i]=cnt[i-lowbit(i)]+1;
	for(int i=1;i<=m;i++){
		int x=read()-1,y=read();
		a[y]|=B(x);
	}
	for(int i=1;i<=n;i++){
		solve(i);ll sum=0;
		for(int j=1;j<=n;j++){
			if(!b[j] && sum+f[S-1][j]>=Y){
				b[j]=i,p[i]=j;
				Y-=sum;break;
			}
			sum+=f[S-1][j];
		}
		if(!p[i])puts("The times have changed"),exit(0);
	}
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	return 0;
}