#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
const int N=705;
int n,a[N];
bool ok[N][N],L[N][N],R[N][N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),L[i][i]=R[i][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(gcd(a[i],a[j])>1)ok[i][j]=1;
	for(int len=1;len<=n;len++)
		for(int l=1,r=len;r<=n;l++,r++)
			for(int k=l;k<=r;k++)
				if(L[l][k] && R[k][r]){
					if(l==1 && r==n)return puts("Yes"),0;
					if(ok[l-1][k])R[l-1][r]=1;
					if(ok[k][r+1])L[l][r+1]=1;
				}
	return puts("No"),0;
}