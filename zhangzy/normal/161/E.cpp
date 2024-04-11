#pragma GCC optimize(3)
#include<stdio.h>
using namespace std;
int T=100000,n,val[7],ten[7],np[101000],z,nex[101000],t,i,j,ans,a[7][7];
inline void dfs(int x){
	if (x>n){ans++;return;}
	val[x]=0;
	for (i=1;i<x;i++)
		val[x]+=a[i][x]*ten[n-i];
	int l=nex[val[x]],r=val[x]+ten[n-x+1];
	for (val[x]=l;val[x]<r;val[x]=nex[val[x]+1]){
		for (t=val[x],i=n;i>x;i--)
			a[x][i]=t%10,t/=10;
		dfs(x+1); 
	}
}

int main(){
	np[0]=np[1]=1;  
	for (i=2;i<=T;i++) if (!np[i])
		for (j=i+i;j<=T;j+=i)
			np[j]=1;
	nex[T+1]=T+1;
	for (i =T;i>=0;i--) nex[i]= np[i]? nex[i+1]: i;
	ten[0]=1;
	for (i=1;i<7;i++) ten[i]=ten[i-1]*10;
	for (scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&z);
		n=0; for (t=z;t;t/=10) n++;
		for (t=z,i=n;i>1;i--) a[1][i]=t%10,t/=10;
		ans=0; dfs(2);
	}
}