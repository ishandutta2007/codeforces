#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int L=100010;
char ch[L]={};
int n,b[L]={};
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	for(int i=1;i<n;++i)
		b[i]=(ch[i]=='A' && ch[i+1]=='B');
	int s1=accumulate(b+1,b+n,0);
	for(int i=1;i<n;++i)
		if(ch[i]=='B' && ch[i+1]=='A' && s1-b[i-1]-b[i]-b[i+1])
		{
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}