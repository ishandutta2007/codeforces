#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
char s[N];
void No(){
	puts("No");
	exit(0);
}
int main(){
	scanf("%d%s",&n,s+1);
	s[0]=s[n+1]='0';
	int tot=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='1'){
			if (s[i-1]=='1'||s[i+1]=='1')
				No();
		}
		else if (s[i-1]=='0'&&s[i+1]=='0')
			No();
	puts("Yes");
	return 0;
}