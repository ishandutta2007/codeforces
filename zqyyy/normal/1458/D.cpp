#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=5e5+7,B=5e5;
int n,sum,cnt[N<<1];
char s[N];
inline void work(){
	scanf("%s",s+1),n=strlen(s+1),sum=0;
	for(int i=1;i<=n;i++)
		if(s[i]&15)cnt[B+sum]++,sum++;
		else sum--,cnt[B+sum]++;
	sum=0;
	for(int i=1;i<=n;i++)
		if(cnt[sum+B-1] && (!cnt[sum+B] || cnt[sum+B-1]>1))sum--,cnt[sum+B]--,putchar('0');
		else cnt[sum+B]--,sum++,putchar('1');
	putchar('\n');
	for(int i=B-n;i<=B+n;i++)cnt[i]=0;
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}