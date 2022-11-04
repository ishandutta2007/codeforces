#include<bits/stdc++.h>
#define uint unsigned
using namespace std;
const int N=17330;
bitset<100000005> chk; 
int fl[N],n;
void init(){
	for (int i=2;i<N;i++)
		for (int j=i*2;j<N;j+=i) fl[j]=1;
}
int main(){
	init();
	uint A,B,C,D,ans=0;
	scanf("%d%u%u%u%u",&n,&A,&B,&C,&D);
	for (int i=2;i<N&&i<=n;i++) if (!fl[i]){
		uint rest=n,val=((A*i+B)*i+C)*i+D;
		for (;rest/=i;) ans+=val*rest;
	}
	for (int i=4;i<N&&i<=n;i++) if (!fl[i]){
		int del=i*2,lim=n/3;
		for (int j=5*i/3;j<=lim;j+=del) chk[j]=1;
		for (int j=7*i/3;j<=lim;j+=del) chk[j]=1;
	}
	for (int i=17333;i<=n;i+=6) if (!chk[i/3])
		ans+=n/i*(((A*i+B)*i+C)*i+D);
	for (int i=17335;i<=n;i+=6) if (!chk[i/3])
		ans+=n/i*(((A*i+B)*i+C)*i+D);
	printf("%u",ans);
}