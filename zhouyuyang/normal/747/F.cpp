#include<bits/stdc++.h> 
using namespace std;
const char s[]="0123456789abcdef";
int fac[15],sz[20],f[20];
int k,t,w;
int C(int x,int y){
	return fac[x]/fac[y]/fac[x-y];
}
void calc(){
	memset(f,0,sizeof(f));
	f[0]=1;
	for (int i=0;i<=15;i++){
		for (int j=8;j>=0;j--){
			int x=0;
			for (int k=0;k<=sz[i]&&k<=j;k++)
				x+=f[j-k]*C(j,k);
			f[j]=x;
		}
	}
}
int main(){
	scanf("%d%d",&k,&t);
	for (int i=fac[0]=1;i<=10;i++)
		fac[i]=fac[i-1]*i;
	for (int i=0;i<=15;i++) sz[i]=t;
	sz[1]--; calc(); sz[1]++;
	for (int i=0;i<=8;i++)
		if (15ll*f[i]<k) k-=15*f[i];
		else{
			putchar(s[(k-1)/f[i]+1]);
			sz[(k-1)/f[i]+1]--;
			w=i; k-=(k-1)/f[i]*f[i];
			break;
		}
	while (w--){
		for (int i=0;i<=15;i++){
			sz[i]--; calc();
			if (f[w]<k) sz[i]++,k-=f[w];
			else{
				putchar(s[i]);
				break;
			}
		}
	}
}