#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=44,M=2e6+7;
int n,m,a[N],b[N],num[M];
inline void clear(){
	for(int i=1;i<=n;i++)num[a[i]]=0;
}
inline void work(){
	n=read(),m=n>>1;
	for(int i=1;i<=n;i++)a[i]=read()+1e6,num[a[i]]++;
	for(int i=1;i<=n;i++)if(num[a[i]]>=m){puts("-1"),clear();return;}
	clear();
	for(int k=2e6;k>2;k--){
		bool ok=0;
		for(int i=1;i<=n;i++){
			num[b[i]=a[i]%k]++;
			if(num[b[i]]>=m)ok=1;
		}
		for(int i=1;i<=n;i++)num[b[i]]=0;
		if(ok){printf("%d\n",k);return;}
	}
	puts("2");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}