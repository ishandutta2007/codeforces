#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2050;
int n,k,i,j,a[N],b[N],p;
long long f[N][N];
inline int max(int x,int y){
	return x>y?x:y;
}
inline int abs(int x){
	return x>=0?x:-x;
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=k;++i)scanf("%d",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	for(i=1;i<=n;++i){
		f[i][i]=max(f[i-1][i-1],abs(a[i]-b[i])+abs(p-b[i]));
		for(j=i+1;j<=k;++j)
			if(max(f[i-1][j-1],abs(a[i]-b[j])+abs(p-b[j]))<f[i][j-1])
				f[i][j]=max(f[i-1][j-1],abs(a[i]-b[j])+abs(p-b[j]));
					else f[i][j]=f[i][j-1];
	}
	cout<<f[n][k]<<endl;
	return 0;
}