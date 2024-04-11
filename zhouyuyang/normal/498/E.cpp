#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int w[10];
struct mat{
	int a[128][128],n,m;
	friend mat operator *(mat a,mat b){
		mat c; c.n=a.n; c.m=b.m;
		memset(c.a,0,sizeof(c.a));
		for (int i=0;i<a.n;i++)
			for (int j=0;j<b.n;j++)
				for (int k=0;k<b.m;k++)
					c.a[i][k]=(c.a[i][k]+1ll*a.a[i][j]*b.a[j][k]%mo)%mo;
		return c;
	}
	friend mat operator ^(mat a,int b){
		mat c; c.n=c.m=a.n;
		memset(c.a,0,sizeof(c.a));
		for (int i=0;i<c.n;i++)
			c.a[i][i]=1;
		for (;b;b/=2,a=a*a)
			if (b&1) c=c*a;
		return c;
	}
}f,a;
int main(){
	for (int t=1;t<=7;t++)
		scanf("%d",&w[t]);
	f.n=1; f.a[0][1]=1;
	for (int t=1;t<=7;t++){
		a.n=a.m=(1<<t);
		memset(a.a,0,sizeof(a.a));
		for (int i=0;i<1<<t;i++)
			for (int j=0;j<1<<t;j++)
				for (int k=0;k<1<<(t-1);k++){
					int tmp=(k<<1)|1|(1<<t);
					if (!(tmp&(tmp>>1)&i&j))
						a.a[i][j]++;
				}
		f.m=(1<<t);
		f=f*(a^w[t]);
		if (t<7)
			for (int i=0;i<1<<t;i++){
				f.a[0][i|(1<<t)]=f.a[0][i];
				f.a[0][i]=0;
			}
	}
	printf("%d",f.a[0][127]);
}