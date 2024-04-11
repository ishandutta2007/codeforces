#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=6e5+7;
int n,m,a[N],cnt[N],pos[N];
bool vis[N];
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=a[i+n]=read();
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=n+n;i++)
		if(i>=a[i])cnt[i-a[i]+1]++;
	vector<int>ans;
	for(int x=1;x<=n;x++)
		if(cnt[x]>=n/3){
			for(int i=1;i<=n;i++)vis[i]=0,pos[a[i+x-1]]=i;
			int res=0;
			for(int i=1;i<=n;i++)
				if(!vis[i]){
					int y=i;res++;
					while(!vis[y])vis[y]=1,y=pos[y];
				}
			if(n-res<=m)ans.push_back(x-1);
		}
	printf("%lu ",ans.size());
	for(int x:ans)printf("%d ",x);
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}