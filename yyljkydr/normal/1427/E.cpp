#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

vector<int>v;

set<int>s;

int x;

int rd(int x)
{
	return (1ll*rand()*rand()+rand())%x;
}

vector<string>ans;

int lb[N];

int l=60;

map<int,int>cho[N];

int ins(int x)
{
	int c=0;
	int ox=x;
	for(int i=l;i>=0;i--)
	{
		if(!((x>>i)&1))
			continue;
		if(!lb[i])
		{
			lb[i]=x;
			// c^=1<<i;
			cho[i][ox]=1;
			for(int j=0;j<=l;j++)
				if(c&(1ll<<j))
					for(auto [x,y]:cho[j])
					{
						cho[i][x]^=1;
						if(!cho[i][x])
							cho[i].erase(x);
					}
			return 1;
		}
		else
			x^=lb[i],c^=1ll<<i;
	}
	return 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	srand(time(NULL));
	cin.tie(0);
	cin>>x;
	v.push_back(x);
	s.insert(x);
	while(1)
	{
		int va=v[rd(v.size())],vb=v[rd(v.size())];
		int c=rand()%2;
		int nv;
		nv=va+vb;
		if(nv>(1ll<<l)||!ins(nv))
			continue;
		// if(!c)
		ans.push_back(to_string(va)+" + "+to_string(vb));
		// else
		// 	ans.push_back(to_string(va)+" ^ "+to_string(vb));
		v.push_back(nv);
		if(lb[0])
		{
			//found
			int last=cho[0].begin()->first;
			cho[0].erase(cho[0].begin());
			while(cho[0].size())
			{
				ans.push_back(to_string(last)+" ^ "+to_string(cho[0].begin()->first));
				last^=cho[0].begin()->first;
				cho[0].erase(cho[0].begin());
			}
			assert(last==1);
			break;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto s:ans)
		cout<<s<<"\n";
}