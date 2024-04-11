#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[18][605][605],A[18][605][605],bin[18],b[18][18];
int from[70005][18],f[70005][18],ans[30000][18];
int T,n,m,K;
int c[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
double sqr(double x){return x*x;}
int main(){
	bin[0]=1;
	for (int i=1;i<=16;i++) bin[i]=bin[i-1]*2;
	scanf("%d",&T);
	for (int p=1;p<=T;p++){
		scanf("%d%d%d",&n,&m,&K);
		int sz=n/K;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&a[(i-1)/sz+1][(i-1)%sz+1][j]);
		for (int i=1;i<=K;i++)
			for (int j=1;j<=sz;j++)
				for (int k=1;k<=m;k++) A[i][j][k]=a[i][j][k];
		for (int i=1;i<=K;i++)
			for (int j=1;j<=sz;j++)
				for (int k=1;k<=m;k++){
					double sum=0,s=0,sum1=0;
					for (int l=0;l<8;l++){
						int x=j+c[l][0];
						int y=k+c[l][1];
						if (x<1||y<1||x>sz||y>m) continue;
						sum+=abs(a[i][j][k]-a[i][x][y]);
						sum1+=a[i][x][y];
						s++;
					}
					sum/=s; sum1/=s;
					if (sum>25)
						A[i][j][k]=(int)(sum1*0.8+A[i][j][k]*0.2);
				}
		for (int i=1;i<=K;i++)
			for (int j=1;j<=sz;j++)
				for (int k=1;k<=m;k++) a[i][j][k]=A[i][j][k];
		for (int i=1;i<=K;i++)
			for (int j=1;j<=K;j++){
				b[i][j]=0;
				for (int k=1;k<=m;k++){
					int tmp=abs(a[i][sz][k]-a[j][1][k]);
					if (k!=1) tmp=min(tmp,abs(a[i][sz][k]-a[j][1][k-1]));
					if (k!=m) tmp=min(tmp,abs(a[i][sz][k]-a[j][1][k+1]));
					b[i][j]+=tmp*tmp;
				}
			}
		memset(f,120,sizeof(f));
		for (int i=1;i<=K;i++)
			f[bin[i-1]][i]=0;
		for (int i=1;i<bin[K];i++)
			for (int j=1;j<=K;j++)
				if (i&bin[j-1])
					for (int k=1;k<=K;k++)
						if (!(i&bin[k-1]))
							if (f[i|bin[k-1]][k]>f[i][j]+b[j][k]){
								f[i|bin[k-1]][k]=f[i][j]+b[j][k];
								from[i|bin[k-1]][k]=j;
							}
		int mn=1,x=bin[K]-1;
		for (int i=2;i<=K;i++)
			if (f[x][i]<f[x][mn]) mn=i;
		for (int i=K;i;i--){
			ans[p][mn]=i;
			int tmp=mn;
			mn=from[x][mn];
			x-=bin[tmp-1];
		}
		ans[p][0]=K;
	}
	for (int i=1;i<=T;i++){
		for (int j=1;j<=ans[i][0];j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}