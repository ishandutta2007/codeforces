#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
/*A
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout << min(2*a+2*b, min(a+b+c, min(2*a+2*c, 2*b+2*c))) << endl;
	return 0;
}*/
/*B
int f[100010], b[100010], a[100010], inv[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i = 0; i < 100010; i++)
	{
		inv[i] = -1;
	}
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> f[i];
		if(inv[f[i]-1] == -1)
		{
			inv[f[i]-1] = i;
		}
		else
		{
			inv[f[i]-1] = -2;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	bool possible = true;
	bool ambiguity = false;
	for(int i = 0; i < m; i++)
	{
		if(inv[b[i]-1] == -2)
		{
			ambiguity = true;
		}
		else if(inv[b[i] - 1] == -1)
		{
			possible = false;
			break;
		}
		else
		{
			a[i] = inv[b[i]-1]+1;
		}
	}
	if(!possible)
	{
		cout << "Impossible" << endl;
	}
	else if(ambiguity)
	{
		cout << "Ambiguity" << endl;
	}
	else
	{
		cout << "Possible" << endl;
		for(int i = 0; i < m; i++)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}	*/
int arr[100001];
vii vec;

bool compare(ii a, ii b)
{
	if(a.first < b.first)
	{
		return true;
	}
	else if(a.first > b.first)
	{
		return false;
	}
	else if(a.second < b.second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		vec.push_back(make_pair(arr[i], i));
	}
	sort(vec.begin(), vec.end(), compare);
	//reverse(vec.begin(), vec.end());
	int counter = n - 1;
	int division = n - 1;
	int count = 1;
	while(counter >= 0)
	{
		if(counter < division)
		{
			count++;
			division = counter;
		}
		if(vec.at(counter).second < division)
		{
			division = vec.at(counter).second;
		}
		counter--;
	}
	cout << count << endl;
	return 0;
}