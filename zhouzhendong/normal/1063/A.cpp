#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int n;
int t[1000];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	memset(t,0,sizeof t);
	for (int i=1;i<=n;i++)
		t[s[i]]++;
	for (int i=0;i<1000;i++)
		while (t[i]--)
			putchar(i);
	return 0;
}