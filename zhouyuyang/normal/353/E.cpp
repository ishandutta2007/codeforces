#include<bits/stdc++.h>
#define N 1000005
using namespace std;
char ch[N];
int t,ans,k,s[N];
int main(){
	scanf("%s",ch+1);
	int n=strlen(ch+1);
	for (int i=1;i<=n;i++)
		if (ch[i]^ch[i-1]) s[t++]=1;
		else s[t-1]++;
	if (ch[1]==ch[n]) s[0]+=s[--t];
	for (int i=0;i<t;i++)
		if (s[i]==1) k++;
		else ans+=k/2+1,k=0;
	printf("%d",ans+k/2);
}