#include<bits/stdc++.h>
using namespace std;
int n,la[80][3],pos[3][80],f[80][80][80][2];
char s[80];
int move(int i,int j,int k,int p){
	return max(0,la[p][0]-i)+max(0,la[p][1]-j)+max(0,la[p][2]-k)-1;
}
void mn(int &x,int y){
	x>y?x=y:0;
}
int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<3;j++)
			la[i][j]=la[i-1][j];
		if (s[i]=='V')
			pos[0][la[i][0]++]=i;
		else if (s[i]=='K')
			pos[1][la[i][1]++]=i;
		else pos[2][la[i][2]++]=i;
	}
	memset(f,100,sizeof(f));
	f[0][0][0][0]=0;
	for (int i=0;i<=la[n][0];i++)
		for (int j=0;j<=la[n][1];j++)
			for (int k=0;k<=la[n][2];k++)
				for (int fl=0;fl<2;fl++){
					if (i<la[n][0]) mn(f[i+1][j][k][1],f[i][j][k][fl]+move(i,j,k,pos[0][i]));
					if (j<la[n][1]&&!fl) mn(f[i][j+1][k][0],f[i][j][k][fl]+move(i,j,k,pos[1][j]));
					if (k<la[n][2]) mn(f[i][j][k+1][0],f[i][j][k][fl]+move(i,j,k,pos[2][k]));
				}
	printf("%d",min(f[la[n][0]][la[n][1]][la[n][2]][0],
					f[la[n][0]][la[n][1]][la[n][2]][1]));
}