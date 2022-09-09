#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f[N][2],i,j,n;
char a[N],b[N];
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	for(j=0;j<2;++j)f[1][j]=j!=a[1]-'0';
	for(i=2;i<=n;++i){
		f[i][0]=f[i][1]=N;
		if(a[i]==b[i-1])for(j=0;j<2;++j)f[i][j]=min(f[i][j],f[i-1][j]+1);
		for(j=0;j<2;++j)f[i][j]=min(f[i][j],f[i-1][b[i-1]-'0']+(j!=a[i]-'0'));
	}
	printf("%d\n",f[n][b[n]-'0']);
	return 0;
}