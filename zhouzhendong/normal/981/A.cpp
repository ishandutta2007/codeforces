#include <bits/stdc++.h>
using namespace std;
const int N=55;
char s[N];
int n;
bool check(int L,int R){
	for (int i=L;i<=R;i++)
		if (s[i]!=s[R-(i-L)])
			return 0;
	return 1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (!check(i,j))
				ans=max(ans,j-i+1);
	printf("%d",ans);
	return 0;
}