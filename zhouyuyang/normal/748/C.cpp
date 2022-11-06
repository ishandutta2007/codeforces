#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[200005];
int n,ans,p,q;
int main(){
	scanf("%d %s",&n,&s);
	p=0;
	q=0;
	ans=0;
	for (int i=0;i<n;i++){
		if (s[i]=='L') p|=1;
		else if (s[i]=='R') p|=2;
		else if (s[i]=='U') q|=1;
		else if (s[i]=='D') q|=2;
		if (p==3||q==3){
			ans++;
			p=0;
			q=0;
			if (s[i]=='L') p=1;
			else if (s[i]=='R') p=2;
			else if (s[i]=='U') q=1;
			else if (s[i]=='D') q=2;
		}
	}
	ans++;
	printf("%d",ans);
	return 0;
}