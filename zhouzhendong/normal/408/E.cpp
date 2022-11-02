#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=200005,mod=1e9+7;
int n,m;
int a[105][N],C[N][105];
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int add(int x,int y){
	Add(x,y);
	return x;
}
int fu(int x){
	return x?mod-x:0;
}
int main(){
	memset(C,0,sizeof C);
	for (int i=0;i<N;i++)
		C[i][0]=1;
	for (int i=1;i<N;i++)
		for (int j=1;j<105;j++)
			C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	    a[0][i]=read();
	for (int i=1;i<=m;i++){
		int L=read(),R=read(),k=read();
		Add(a[k+1][L],1);
		for (int j=k+1;j>=1;j--)
			Add(a[k+1-j+1][R+1],fu(C[R-L+j-1][j-1]));
	}
	for (int i=101;i>=0;i--){
		for (int j=1;j<=n;j++)
			Add(a[i+1][j],a[i+1][j-1]);
		for (int j=1;j<=n;j++)
			Add(a[i][j],a[i+1][j]);
	}
	for (int i=1;i<=n;i++)
		printf("%d\n",a[0][i]);
	return 0;
}

/*
i=  0 1 2 3 4 
k=0 1 0 0 0 0 0
k=1 1 1 1 1 1 1
k=2 1 2 3 4 5 6 
k=3 1 3 6 10 
v[i][j] = C(i+k-1,k-1)
C(i+k,k) = v[i][k+1]
*/