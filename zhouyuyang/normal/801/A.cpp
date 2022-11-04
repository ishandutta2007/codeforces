#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int n,ans;
int getans(){
	int ans=0;
	for (int i=1;i<n;i++)
		if (s[i]=='V'&&s[i+1]=='K') ans++;
	return ans;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=getans();
	for (int i=1;i<=n;i++){
		if (s[i]=='V') s[i]='K'; else s[i]='V';
		ans=max(ans,getans());
		if (s[i]=='V') s[i]='K'; else s[i]='V';
	} 
	printf("%d",ans);
}