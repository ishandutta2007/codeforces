#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,k=25;
int x[N];
char s[N][N];
int main(){
	n=m=50;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			s[i][j]='A'+(i-1)/k*2+(j-1)/k;
	scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
	for (int t=0;t<4;t++){
		int xx=t/2*k,yy=t%2*k;
		int tt=(t+1)%4;
		for (int i=2;i<n/2;i+=2)
			for (int j=2;j<n/2;j+=2){
				if (x[tt]<=1)
					break;
				s[xx+i][yy+j]='A'+tt;
				x[tt]--;
				if (x[tt]<=1)
					break;
			}
	}
	puts("50 50");
	for (int i=1;i<=n;i++)
		puts(s[i]+1);
	return 0;
}