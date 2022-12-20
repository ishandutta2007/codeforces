#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=57;
int n,a[N];
map<int,bool>h;
inline void work(){
	n=read();int ans=0;
	for(int i=1;i<=n;i++)a[i]=read();
	h.clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!h[a[j]-a[i]])ans++,h[a[j]-a[i]]=1;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}