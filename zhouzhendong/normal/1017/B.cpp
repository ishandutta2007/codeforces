#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n;
char s1[N],s2[N];
int cnt[4];
int main(){
	n=read();
	memset(cnt,0,sizeof cnt);
	scanf("%s%s",s1+1,s2+1);
	for (int i=1;i<=n;i++)
		cnt[2*(s1[i]-'0')+s2[i]-'0']++;
	printf("%I64d",1LL*cnt[2+0]*(cnt[0]+cnt[1])+1LL*cnt[2+1]*cnt[0]);
	return 0;
}