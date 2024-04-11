#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,s,n,m,s1,s2;
char c[100005];
int main() {
	scanf("%s",c);
	n=strlen(c);
	for (i=0;i<n;i++) if (c[i]=='a') s++;
	else break;
	for (;i<n;i++) if (c[i]=='b') s1++;
	else break;
	for (i;i<n;i++) if (c[i]=='c') s2++;
	else break;
	if (!s||!s1||!s2||s+s1+s2<n) puts("NO");
	else if (s==s2||s1==s2) puts("YES");
	else puts("NO");
}