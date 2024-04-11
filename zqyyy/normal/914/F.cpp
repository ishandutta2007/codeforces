#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline char getc(){
	char c;
	while(!isalpha(c=getchar()));
	return c;
}
const int N=1e5+7;
int n,Q;
char str[N],t[N];
bitset<N>c[27],b;
int main(){
	scanf("%s",str+1),n=strlen(str+1);
	for(int i=1;i<=n;i++)c[str[i]&31].set(i);
	Q=read();
	while(Q--){
		int opt=read();
		if(opt==1){
			int x=read();
			c[str[x]&31].reset(x);
			c[(str[x]=getc())&31].set(x);
		}else{
			int l=read(),r=read(),m;b.set();
			scanf("%s",t+1),m=strlen(t+1);
			for(int i=1;i<=m;i++)
				b<<=1,b&=c[t[i]&31];
			b<<=N-1-r,b>>=N-1-r+l+m-1;
			printf("%lu\n",b.count());
		}
	}
	return 0;
}