#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=300005;
int n,k;
char s[N];
int check(){
	for (int i=1;i<=k;i++)
		if (s[i]!=s[1])
			return 1;
	return 0;
}
int check1(){
	for (int i=1;i<=k;i++)
		if (s[i]!=s[i+k])
			return 0;
	return 1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	k=n/2;
	if (!check())
		return puts("Impossible"),0;
	while (1){
		if (n&1)
			return puts("2"),0;
		if (!check1())
			return puts("1"),0;
		n/=2,k/=2;
	}
	return 0;
}