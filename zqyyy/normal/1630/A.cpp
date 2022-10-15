#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
int n,K;
bool vis[114514];
inline void work(){
	n=read(),K=read();
	if(K==n-1 && n==4){puts("-1");return;}
	for(int i=0;i<n;i++)vis[i]=0;
	printf("%d %d\n",n-1,K-(K==n-1)),vis[n-1]=vis[K-(K==n-1)]=1;
	if(K==n-1){
		printf("1 3\n"),vis[1]=vis[3]=1;
		for(int i=0;i<n;i++)
			if(!vis[i]){
				printf("%d ",i);
				int x=(~i)&(n-1);
				if((!i))x=n-4;
				vis[i]=vis[x]=1;
				printf("%d\n",x);
			}
	}else{
		for(int i=0;i<n;i++)
			if(!vis[i]){
				printf("%d ",i);
				int x=(~i)&(n-1);
				if((!i))x=(~K)&(n-1);
				vis[i]=vis[x]=1;
				printf("%d\n",x);
			}
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
	return 0;
}