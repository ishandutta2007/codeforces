#include<bits/stdc++.h>
using namespace std;
int n,a[100];
char S[100100];
int main(){
	scanf("%d%s",&n,S+1);
	if(n==1)return puts("Yes"),0;
	for(int i=1;i<=n;++i)a[S[i]-'a']++;
	int mx=0;
	for(int i=0;i<26;++i)mx=max(mx,a[i]);
	if(mx>1)return puts("Yes"),0;
	else puts("No");
}