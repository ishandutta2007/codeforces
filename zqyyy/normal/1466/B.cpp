#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+7;
int n,a[N],cnt[N];
inline void work(){
	n=read();int ans=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n+n+n;i++)cnt[i]=0;
	a[n+1]=1e9;
	for(int i=n;i;i--){
		if(a[i]<a[i+1]-1)a[i]++;
		cnt[a[i]]++;
	}
	for(int i=1;i<=n+n+n;i++)ans+=cnt[i]>0;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}