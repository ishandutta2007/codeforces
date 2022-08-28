#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int ret=0;
	for(int i=0;i<n;i++)
	{
		string p;
		cin>>p;
		int sum=0;
		for(int i=0;i<p.size();i++) if(p[i]=='4'||p[i]=='7') sum++;
		if(sum<=k) ret++;
	}
	cout<<ret<<endl;
	return 0;
}