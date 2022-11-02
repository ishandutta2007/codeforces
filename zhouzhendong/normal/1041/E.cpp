#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005;
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
int n,v[N];
int X[N],Y[N],vis[N],tot=0;
void OutNO(){
	puts("NO");
	exit(0);
}
int main(){
	n=read();
	memset(v,0,sizeof v);
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		if (a>b)
			swap(a,b);
		if (a==b||b!=n)
			OutNO();
		v[a]++;
	}
	int t=1;
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n;i++){
		if (!v[i])
			continue;
		vis[i]=1;
		int pre=n;
		for (int j=1;j<v[i];j++){
			while (t<=i&&vis[t])
				t++;
			if (t>i)
				OutNO();
			vis[t]=1;
			tot++;
			X[tot]=pre,Y[tot]=t;
			pre=t;
		}
		tot++;
		X[tot]=pre,Y[tot]=i;
	}
	puts("YES");
	for (int i=1;i<=tot;i++)
		printf("%d %d\n",X[i],Y[i]);
	return 0;
}