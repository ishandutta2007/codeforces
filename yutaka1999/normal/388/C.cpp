#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector <int> vec;
int in[1005];

int main()
{
	int n;
	scanf("%d",&n);
	int l=0,r=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<a;j++) scanf("%d",&in[j]);
		for(int j=0;j<a/2;j++) l+=in[j];
		for(int j=(a+1)/2;j<a;j++) r+=in[j];
		if(a%2==1) vec.push_back(in[a/2]);
	}
	sort(vec.begin(),vec.end(),greater <int>());
	for(int i=0;i<vec.size();i++)
	{
		if(i%2==0) l+=vec[i];
		else r+=vec[i];
	}
	printf("%d %d\n",l,r);
	return 0;
}