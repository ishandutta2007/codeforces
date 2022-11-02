#include <bits/stdc++.h>
using namespace std;
const int N=104;
char s[N];
int a=0,b=0,n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='-')
			a++;
		else
			b++;
	if (a==0||b==0)
		puts("Yes");
	else if (a%b==0)
		puts("yes");
	else
		puts("no");
	return 0;
}