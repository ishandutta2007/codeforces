#include<bits/stdc++.h>
using namespace std;
int n,t,anses[310],fafa[310];
int z[310];
int T;
int ask(int l,int r){
	printf("? %d %d\n",l,r);
/*	if(rand()%2){
		for(int i=l;i<=n;++i)T-=z[i],z[i]^=1,T+=z[i];
		return T;
	} else {
		for(int i=1;i<=r;++i)T-=z[i],z[i]^=1,T+=z[i];
		return T;
	}
*/	fflush(stdout);
	int s;
	scanf("%d",&s);
	return s;
}
int main(){
//	n=9,t=0;for(int i=1;i<=n;++i)z[i]=rand()%2,t+=z[i];T=t;for(int i=1;i<=n;++i)printf("%d",z[i]);puts("");
	scanf("%d%d",&n,&t);
	if(n==1){
		anses[1]=t?1:0;
	} else if(n&1){
		int nw=t;
		for(;nw==t;nw=ask(1,n-1))
			ask(1,n-1);
		anses[n]=nw<t?1:0;
		fafa[n]=1;
		int tg=0;
		for(int i=n-1;i>=1;--i){
			for(t=nw;t==nw;nw=ask(i,i+1))
				ask(i,i+1);
			for(int j=1;j<=n;++j)
				fafa[j]^=j<i||j>i+1;
			anses[i]=(nw+t-n)/2+1-(anses[i+1]^fafa[i+1])^fafa[i];
		}
	} else {
	// A^B=n-all-(1-x)+x=n-all-1+2x
	// A=all-lef+_lef-x+(1-x)
	// B=n-all-_lef+lef
	// 0=all
		int tg=0;
		for(int i=n;i>=1;--i){
			int nw=t;
			for(;nw==t;nw=ask(i,i))ask(i,i);
			anses[i]=((nw+t-n+1)/2)^tg;
			tg^=1,t=nw;
		}
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d",anses[i]);puts("");
	fflush(stdout);
}