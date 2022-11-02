#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=105;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n;
char s[N];
int tot[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		tot[s[i]-'0']++;
	int t1=tot[8];
	int t2=n-t1;
	int ans=0;
	for (int i=1;i<=t1;i++){
		ans=max(ans,min(i,(n-i)/10));
	}
	printf("%d",ans);
	return 0;
}