#include<cstdio>
const int N=20005,A=N*300;
int i,j,x[N],y[N],n,s;
bool b[A];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",x+i),b[x[i]]=1;
	for(i=1;i<=n;++i)scanf("%d",y+i),b[y[i]]=1;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)s+=b[x[i]^y[j]];
	puts(s&1?"Koyomi":"Karen");
	return 0;
}