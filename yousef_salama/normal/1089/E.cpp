#include <bits/stdc++.h>

using namespace std;

string arr[64]={"a1","b1","c1","d1","d2","c2","b2","a2","e2","f2","g2","h2","h1","g1","f1","e1","e3","e4","f4","g4","g3","f3","d3","d4","c4","c3","b3","b4","a4","a3","h3","h4"};

int main()
{
	int n;
	cin >> n;
	int cur=4*8;
	for(int i=4;i<8;i++)
	{
		int st=0,en=7,d=1;
		if(i%2==0)
		{
			swap(st,en); d*=-1;
		}
		for(int j=st;j!=d+en;j+=d)
		{
			arr[cur++]=string(1,j+'a')+string(1,i+'1');
		}
	}
	/*for(int i=0;i<64;i++)
		cout << arr[i] << " ";
	cout << endl;*/
	vector<string> v;
	for(int i=0;i<n;i++)
		v.push_back(arr[i]);
	/*for(int i=0;i<v.size();i++)
		cout << v[i] << " \n"[i+1==v.size()];*/
	if(v.back()[1]!='8')
	{
		v.pop_back();
		if(v.back()[0]=='h')
		{
			if(v.back()!="h7")
			{
				v.push_back("h7");
			}
			else
			{
				v.pop_back(); v.pop_back(); // currently in g6 needs 3 moves
				v.push_back("g7"); v.push_back("g8"); v.push_back("f8");
				
			}
		}
		else
		{
			v.push_back(v.back());
			v.back()[1]='8';
		}
	}
	v.push_back("h8");
	//assert(v[0]=="a1") assert(v.back()=="h8");
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			assert(v[i]!=v[j]);
		}
	}
	for(int i=1;i<v.size();i++)
	{
		assert(v[i][0]==v[i-1][0]||v[i][1]==v[i-1][1]);
	}
	assert(v.size()==n+1);
	for(int i=0;i<v.size();i++)
		cout << v[i] << " \n"[i+1==v.size()];
}