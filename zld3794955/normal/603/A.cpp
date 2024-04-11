#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n;
char ch[N]={};
int main()
{
	scanf("%d\n%s",&n,ch+1);
	int ans1=1,ans2=0;
	for(int i=2;i<=n;++i)
		ch[i]==ch[i-1] ? ++ans2 : ++ans1;
	printf("%d\n",ans1+min(ans2,2));
	return 0;
}