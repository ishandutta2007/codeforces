#include<bits/stdc++.h>
using namespace std;
const int L=1000100;
char ch[L]={};
int n;
int main()
{
	gets(ch+1);
	n=strlen(ch+1);
	long long ans=0;
	for(int i=n-4,t=0;i>=1;--i)
	{
		if(ch[i]=='h' && ch[i+1]=='e' && ch[i+2]=='a' && ch[i+3]=='v' && ch[i+4]=='y')
			ans+=t;
		if(ch[i]=='m' && ch[i+1]=='e' && ch[i+2]=='t' && ch[i+3]=='a' && ch[i+4]=='l')
			++t;
	}
	cout<<ans<<endl;
}