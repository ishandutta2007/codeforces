#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
char s[N];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0,p=n+1;
	for (int i=n;i>=1;i--)
		if (s[i]=='1')
			cnt++;
		else if (s[i]=='2')
			p=i;
	for (int i=1;i<p;i++)
		if (s[i]=='0')
			putchar('0');
	while (cnt--)
		putchar('1');
	for (int i=p;i<=n;i++)
		if (s[i]!='1')
			putchar(s[i]);
	return 0;
}