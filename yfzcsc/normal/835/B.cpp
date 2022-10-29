#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
char s[100100];
int main(){
	scanf("%d%s",&k,s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)s[i]-=48;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;++i)k-=s[i];
	for(int i=1;i<=n&&k>0;++i)
		k=k+s[i]-9,ans++;
	printf("%d",ans);
}