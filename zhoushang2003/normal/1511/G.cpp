#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,m,x,y,a[N],f[N][21],A;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x,a[x]++;
	for(int i=1;i<=m;i++)
		a[i]+=a[i-1];
	for(int i=1;i<21;i++)
		for(int j=1;j<=m;j++)
			f[j][i]=f[j][i-1]^f[j+(1<<(i-1))][i-1]^(((a[j+(1<<i)-1]-a[j+(1<<(i-1))-1])&1)<<(i-1));
	cin>>m;
	while(m--&&cin>>x>>y){
		A=0;
		for(int i=20;~i;i--)
			if(x+(1<<i)-1<=y)
				A^=f[x][i],x+=(1<<i),A^=((a[y]-a[x-1])&1)<<i;
		cout<<(A?"A":"B");
	}
}