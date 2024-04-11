#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n;
char s[maxn];

int main()
{
	scanf("%d%s",&n,s);
	
	bool flag=0;
	for (int i=1;!flag&&i<n;++i)
		if (s[i]!=s[i-1])
			printf("YES\n%c%c\n",s[i-1],s[i]),flag=1;
	if (!flag)
		cout<<"NO"<<endl;
	return 0;
}