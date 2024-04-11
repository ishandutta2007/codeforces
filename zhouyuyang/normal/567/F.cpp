#include<cstdio>
#include<cstring>
const int N=75;
int a[N][N];//0:no 1:< 2:<= 3:= 4:>= 5:>
int n,m,i,j,x,y;
long long f[N][N];
char s[5];
bool pdl(int p,int l,int r){
	if (p<1) return 0;
	for (int i=l;i<=r;i++)
		if (a[p][i]>2) return 0;
	return 1;
}
bool pdr(int p,int l,int r){
	if (p>n) return 0;
	for (int i=l;i<=r;i++)
		if (a[p][i]>2) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);n<<=1;
	for (i=1;i<=m;i++){
		scanf("%d%s%d",&x,s,&y);
		int l=strlen(s);
		if (s[0]=='<'&&l==1) a[x][y]=1;
		if (s[0]=='<'&&l==2) a[x][y]=2;
		if (s[0]=='=') a[x][y]=3;
		if (s[0]=='>'&&l==2) a[x][y]=4;
		if (s[0]=='>'&&l==1) a[x][y]=5;
		a[y][x]=6-a[x][y];
	}
	for (i=1;i<n;i++)
		if (a[i][i+1]!=1&&a[i][i+1]!=5)
			f[i][i+1]=1;
	for (int len=2;len<=n;len+=2){
		for (i=1;i<=n-len+1;i++){
			j=i+len-1;
			bool lf1=pdl(i-1,i,j);
			bool lf2=i-2>0&&a[i-2][i-1]!=1
				&&a[i-2][i-1]!=5&&pdl(i-2,i,j);
			bool rf1=pdr(j+1,i,j);
			bool rf2=j+2<=n&&a[j+1][j+2]!=1
				&&a[j+1][j+2]!=5&&pdr(j+2,i,j);
			if (lf1&&rf1&&a[i-1][j+1]!=1&&a[i-1][j+1]!=5)
				f[i-1][j+1]+=f[i][j];
			if (lf1&&lf2) f[i-2][j]+=f[i][j];
			if (rf1&&rf2) f[i][j+2]+=f[i][j];
		}
	}
	printf("%I64d",f[1][n]);
}