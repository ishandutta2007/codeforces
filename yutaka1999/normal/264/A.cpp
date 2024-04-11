#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int ret[1000005];

int main()
{
	string p;
	cin>>p;
	
	int s=0,t=p.size()-1;
	for(int i=0;i<p.size();i++)
	{
		if(p[i]=='l')
		{
			ret[t]=i+1;
			t--;
		}
		else
		{
			ret[s]=i+1;
			s++;
		}
	}
	for(int i=0;i<p.size();i++) printf("%d\n",ret[i]);
	return 0;
}