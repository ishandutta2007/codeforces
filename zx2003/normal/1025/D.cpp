#include<bits/stdc++.h>
using namespace std;
const int N=705;
bitset<705>tl[N],tr[N],z,b2[N],b3[N];
int n,a[N],i,j,k;
bool bb[N][N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j){
		if(gcd(a[i],a[j])==1)continue;
		bb[i][j]=bb[j][i]=1;		
		b2[i][j]=1;b3[j][i+1]=1;
	}
	for(i=1;i<=n;++i){
		tl[i][i]=tr[i][i]=1;
		for(j=i-1;j;--j)if(bb[j][i] && tr[j][i-1])tl[i]|=tl[j];
		z.reset();z=tl[i]&b3[i];
		for(j=i-1;j;--j)
			if(z[j+1])
				tr[j][i]=1,z|=tl[j]&b3[j];
	}
	for(i=1;i<=n;++i)if(tl[i][1] && tr[i][n])break;
	puts(i<=n?"Yes":"No");
	return 0;
}