#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

int n;

using namespace std;

pair<int, int> a[12345];
int b[12345];
int tim[12345];


int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i].first;
		a[i].second = i;
		b[i] = a[i].first;
	}
	sort(a, a+n);
	int l = -1;
	int c = -1;
	for(int i = 0; i < n; i++)
	{
		if(a[i].first != l)
				c++;
		b[a[i].second] = c;
		l = a[i].first;
	}
	// for(int i = 0; i < n; i++)
	// 	cout<<b[i]<<" ";
	// cout<<endl;
	int mi = 1e9;
	for(int i = 0; i < n; i++)
	{
		int ans = 0;
		int big = 0;
		for(int j = 0; j < n; j++)
			tim[j] = 0;
		for(int j = 0; j < n; j++)
			tim[b[j]]++;
		for(int j = 0; j < n; j++)
			if(tim[j] > 1)
				big++;
		for(int j = i; j < n; j++)
		{
			// cout<<big<<endl;
			if(!big)
			{
				break;
			}
			tim[b[j]]--;
			if(tim[b[j]] == 1)
				big--;
			ans++;
		}
		if(!big)
			mi = min(ans, mi);
	}
	cout<<mi<<endl;
	return 0;
}