#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
int pa[N];
int find(int x){
	return x^pa[x]?pa[x]=find(pa[x]):x;	
}
inline void unin(int x,int y){
	pa[find(x)]=find(y);	
}
int n,m1,m2;
int a[N],b[N];
int main(){
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=n+n;i++)pa[i]=i;
	for(int i=1;i<=m1;i++)unin(read(),read());
	for(int i=1;i<=m2;i++)unin(read()+n,read()+n);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(find(i)!=find(j) && find(i+n)!=find(j+n))
				ans++,unin(i,j),unin(i+n,j+n),a[ans]=i,b[ans]=j;
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)printf("%d %d\n",a[i],b[i]);
	return 0;
}