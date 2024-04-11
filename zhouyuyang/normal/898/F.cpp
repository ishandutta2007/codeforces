#include<bits/stdc++.h>
#define N 1000005
using namespace std;
const int mo[3]={19260817,40049213,23333};
char s[N];
int P[3][N],V[3][N];
int n;
void check(int x,int z){
	if (z<=x||n<=z) return;
	if (s[1]=='0'&&x>1) return;
	if (s[x+1]=='0'&&z>x+1) return;
	if (s[z+1]=='0'&&n>z+1) return;
	for (int i=0;i<3;i++){
		int xx=V[i][x];
		int yy=V[i][z]-1ll*V[i][x]*P[i][z-x]%mo[i];
		int zz=V[i][n]-1ll*V[i][z]*P[i][n-z]%mo[i];
		if ((xx+yy-zz)%mo[i]) return;
	}
	for (int i=1;i<=n;i++){
		putchar(s[i]);
		if (i==x) putchar('+');
		if (i==z) putchar('=');
	}
	exit(0);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int j=0;j<3;j++){
		P[j][0]=1;
		for (int i=1;i<=n;i++){
			V[j][i]=(V[j][i-1]*10+s[i]-'0')%mo[j];
			P[j][i]=P[j][i-1]*10%mo[j];
		}
	}
	for (int i=1;i<n-1;i++){
		check(i,n-i);
		check(i,n-i-1);
		check(i,n-(n-i)/2);
		check(i,n-(n-i)/2-1);
	}
}