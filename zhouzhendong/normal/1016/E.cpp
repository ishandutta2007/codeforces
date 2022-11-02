#include <bits/stdc++.h>
#define y0 _zzd0001
#define y1 _zzd0002
#define rank _zzd0003
#define next _zzd0004
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=200005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n;
LL xL,xR,y,L[N],R[N],sum[N];
int main(){
	y=read(),xL=read(),xR=read();
	n=read();
	for (int i=1;i<=n;i++)
		L[i]=read(),R[i]=read(),sum[i]=sum[i-1]+R[i]-L[i];
	int q=read();
	while (q--){
		LL px=read(),py=read();
		LD lv=(LD)px-(LD)(px-xL)/(py-y)*py;
		LD rv=(LD)px-(LD)(px-xR)/(py-y)*py;
		int a=0,b=n+1;
		for (int i=20;i>=0;i--)
			if (a+(1<<i)<=n&&R[a+(1<<i)]<=lv)
				a+=1<<i;
		for (int i=20;i>=0;i--)
			if (b-(1<<i)>=1&&L[b-(1<<i)]>=rv)
				b-=1<<i;
		a++,b--;
		if (a==n+1||b==0){
			puts("0.0000000000");
			continue;
		}
		LD v=R[a]-max(lv,(LD)L[a])+min((LD)R[b],rv)-L[b]+sum[b-1]-sum[a+1-1];
		printf("%.10lf\n",(double)(v*(py-y)/py));
	}
	
	return 0;
}