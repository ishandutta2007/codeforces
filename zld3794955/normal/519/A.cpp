#include<bits/stdc++.h>
using namespace std;
const int L=20;
map<char,int> m;
int main()
{	
	m['q']=9;
	m['r']=5;
	m['b']=3;
	m['n']=3;
	m['p']=1;
	m['k']=0;
	m['Q']=-9;
	m['R']=-5;
	m['B']=-3;
	m['N']=-3;
	m['P']=-1;
	m['K']=0;
	char ch[L]={};
	int v=0;
	for(int i=1;i<=8;++i)
	{
		gets(ch+1);
		for(int j=1;j<=8;++j)
			v+=m[ch[j]];
	}
	puts(v==0 ? "Draw" : v<0 ? "White" : "Black");
	return 0;
}