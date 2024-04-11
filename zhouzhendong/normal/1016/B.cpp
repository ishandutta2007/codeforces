#include <bits/stdc++.h>
#define y0 _zzd0001
#define y1 _zzd0002
#define rank _zzd0003
#define next _zzd0004
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=3005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
char s[N],t[N];
int n,m,q,f[N];
bool check(char *s,char *t){
	for (int i=1;i<=m;i++)
		if (s[i]!=t[i])
			return 0;
	return 1;
}
int main(){
	n=read(),m=read(),q=read();
	scanf("%s%s",s+1,t+1);
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		if (i<=n-m+1)
			f[i]+=check(s+i-1,t);
	}
	while (q--){
		int L=read(),R=read();
		printf("%d\n",max(f[max(R-m+1,0)]-f[L-1],0));
	}
	return 0;
}