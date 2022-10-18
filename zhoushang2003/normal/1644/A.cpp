#include<bits/stdc++.h>
using namespace std;
const int N=999;
int t,q[N],p[N];
string s;
int main()
{
	cin>>t,q['r']=1,q['R']=2,q['g']=3,q['G']=4,q['b']=5,q['B']=6;
	while(t--&&cin>>s)
	{
		for(int i=0;i<6;i++)
			p[q[s[i]]]=i;
		p[1]<p[2]&&p[3]<p[4]&&p[5]<p[6]?puts("YES"):puts("NO");
	}
}