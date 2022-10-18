#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q;
long long x,y,A,c;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='?'&&cin>>x>>y)
			s[i]=')',c--,A+=y,q.push(make_pair(y-x,i));
		else if(s[i]=='(')
			c++;
		else
			c--;
		if(c<0)
		{
			if(q.empty())
			{
				cout<<-1;
				return 0;
			}
			A-=q.top().first,s[q.top().second]='(',c+=2,q.pop();
		}
	}
	if(c)
		cout<<-1;
	else
		cout<<A<<'\n'<<s;
	return 0;
}