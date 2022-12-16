#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
int n,a[107],cnt[107];
inline void work(){
	n=read();
	for(int i=1;i<=100;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++;
	for(int i=0;i<=100;i++)
		if(cnt[i])printf("%d ",i),cnt[i]--;
	for(int i=0;i<=100;i++)while(cnt[i])printf("%d ",i),cnt[i]--;
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}