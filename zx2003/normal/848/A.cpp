#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100005;
int n,a[N],k,i,pre[N],f[N],l,j;
bool b[N],bb[N];
char c='a';
int main(){
	scanf("%d",&n);
	if(n==0)return puts("a"),0;
	for(i=1;i<=500 && f[i-1]<=n;++i)f[i]=i*(i-1)>>1;
	l=i-1;
	*b=1;
	for(i=1;i<=26;++i){
		memcpy(bb,b,sizeof b);
		for(j=1;j<=l;++j)
			for(k=n;k>=f[j];--k)
				if(!b[k] && bb[k-f[j]])pre[k]=j,b[k]=1;
		if(b[n]){
			for(j=k;j;j-=f[pre[j]],++c)
				for(k=1;k<=pre[j];++k)putchar(c);
			return 0;
		}
	}
	return 0;
}