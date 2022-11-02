#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned uint;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
uint n,A,B,C,D,ans=0;
uint fff[3333533];
// 6 -   1  5
uint F(uint v){
	return A*v*v*v+B*v*v+C*v+D;
}
void update(uint p){
	uint m=n,d=m/p,dd,i=0;
	while (p<=d){
		i++;
		dd=d/p;
		ans+=i*(d-dd)*F(p);
		d=dd;
	}
	ans+=(i+1)*d*F(p);
}
int main(){
	memset(fff,0,sizeof fff);
	n=read(),A=read(),B=read(),C=read(),D=read();
	for (uint i=2,f=0,k=0;i<=n;){
		uint id=k<<1;
		if (f==5)
			id--;
		if (i>5&&((fff[id>>5]>>(id&31))&1))
			;
		else {
//			printf("%d\n",i);
			update(i);
			if (i>=5){
				uint ii=i,ff=f,kk=k,iid,v1=4,v2=2;
				if (f==5)
					swap(v1,v2);
				while (1){
					if (ff==1)
						ii+=v1*i,ff=5;
					else
						ii+=v2*i,ff=1;
					if (ii>n)
						break;
//					printf("%u %u %u\n",ii,ff,kk);
					kk=(ii+1)/6;
					iid=kk<<1;
					if (ii%6==5)
						iid--;
					fff[iid>>5]|=1<<(iid&31);
				}
			}
		}
		if (i<5){
			if (i==2)
				i=3;
			else
				i=5,f=5,k=1;
		}
		else if (f==1)
			i+=4,f=5,k++;
		else
			i+=2,f=1;
	}
	printf("%u",ans);
	return 0;
}
/*
100 0 0 0 1
*/