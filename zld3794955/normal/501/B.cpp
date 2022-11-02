#include<bits/stdc++.h>
using namespace std;
map<string,string> old;
set<string> used;
int n;
string s1,s2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		if(used.count(s1))
		{
			auto it=old.find(s1);
			auto p=*it;
			old.erase(it);
			old[s2]=p.second;
		}
		else
		{
			old[s2]=s1;
			used.insert(s1);
		}
		used.insert(s2);
	}
	cout<<old.size()<<endl;
	for(auto p:old)
		cout<<p.second<<' '<<p.first<<endl;
}