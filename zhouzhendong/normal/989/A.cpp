#include <bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int n;
bool solve(){
	bool f[3];
	n=strlen(s+1);
	memset(f,0,sizeof f);
	for (int i=2;i<n;i++){
		if (s[i-1]=='.'||s[i]=='.'|s[i+1]=='.')
			continue;
		memset(f,0,sizeof f);
		for (int j=i-1;j<=i+1;j++)
			f[s[j]-'A']=1;
		if (f[0]&&f[1]&&f[2])
			return 1;
	}
	return 0;
}
int main(){
	scanf("%s",s+1);
	puts(solve()?"Yes":"No");
	return 0;
}