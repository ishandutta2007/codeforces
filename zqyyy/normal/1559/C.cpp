#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e4+7;
int n,a[N];
inline void work(){
	n=read();int pos=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(!pos && !a[i-1] && a[i]==1)pos=i;
	}
	if(!pos && !a[n])pos=n+1;
	if(!pos){puts("-1");return;}
	for(int i=1;i<pos;i++)printf("%d ",i);
	printf("%d ",n+1);
	for(int i=pos;i<=n;i++)printf("%d ",i);
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}