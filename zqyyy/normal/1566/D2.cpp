#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,m,a[N],id[N];
inline int num(int i,int j){
	return (i-1)*m+j;
}
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read(),id[i]=i;
	sort(id+1,id+n*m+1,[](int x,int y){return a[x]^a[y]?a[x]<a[y]:x<y;});
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=j+1;k<=m;k++)
				if(a[id[num(i,j)]]!=a[id[num(i,k)]] && id[num(i,j)]<id[num(i,k)])ans++;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}