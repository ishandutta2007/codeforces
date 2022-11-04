#include<bits/stdc++.h>
#define ll long long
using namespace std;
int le[55][55];
int dn[55][55];
int main(){
	long long v; scanf("%lld",&v);
	int n=0,tot=0;
	for (;v;n++,v/=3){
		int val=v%3;
		if (n){
			le[n+3][n]=dn[n][n+3]=1,tot+=2;
			if (v>=3)
				dn[n+4][n]=le[n][n+4]=1,tot+=2;
		}
		if (val<2)
			le[n+1][n+3]=1,tot++;
		if (val<1)
			dn[n+3][n+1]=1,tot++;
	}
	tot+=4;
	le[n+1][n+2]=le[n+2][n+2]=1;
	dn[n+2][n+1]=dn[n+2][n+2]=1;
	printf("%d %d %d\n",n+3,n+3,tot);
	for (int i=1;i<n+3;i++)
		for (int j=1;j<n+3;j++){
			if (le[i][j]) printf("%d %d %d %d\n",i,j,i,j+1);
			if (dn[i][j]) printf("%d %d %d %d\n",i,j,i+1,j);
		}
}