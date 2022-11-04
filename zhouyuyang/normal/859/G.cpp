#include<bits/stdc++.h>
using namespace std;
char c[300005];
int a[1005],w,n;
int g,y,z;
bool isp(int p){
	for (int i=2;i*i<=p;i++)
		if (p%i==0) return 0;
	return 1;
}
int power(int x,int y,int p){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%p)
		if (y&1) s=1ll*s*x%p;
	return s;
}
int getg(int p){
	int g=2;
	for (;;++g){
		int fl=0;
		for (int i=1;i<=w;i++)
			if (power(g,a[i],p)==1){
				fl=1; break;
			}
		if (!fl) return g;
	}
}
int main(){
	scanf("%d%s",&n,c+1);
	for (int i=1;i<=n;i++) c[i]-=48;
	int u=clock();
	for (int p=1;clock()-u<800;){
		for (p+=n;!isp(p);p+=n);
		w=0;
		for (int i=2;i*i<=(p-1);i++)
			if ((p-1)%i==0) a[++w]=i,a[++w]=(p-1)/i;
		g=getg(p); y=0;
		z=power(g,(p-1)/n,p);
		for (int i=1,x=1;i<=n;i++,x=1ll*x*z%p)
			y=(y+1ll*c[i]*x)%p;
		if (y) return puts("NO"),0;
	} 
	puts("YES");
}