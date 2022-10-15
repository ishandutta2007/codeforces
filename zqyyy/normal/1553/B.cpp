#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,m;
char s[N],t[N];
inline void work(){
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	bool flg=0;
	for(int i=1;i<=n && !flg;i++)
		for(int j=i;j<=n && !flg && j-i+1<=m;j++){
			int k=1;
			while(s[i+k-1]==t[k] && i+k-1<j)k++;
			if(i+k-1!=j)continue;
			int l=1;
			while(s[j-l+1]==t[k] && j-l+1>0 && k<=m)l++,k++;
			if(k==m+1)flg=1;
		}
	puts(flg?"yes":"no");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}