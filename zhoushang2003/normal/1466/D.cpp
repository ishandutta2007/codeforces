#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int T;
int n;
int w[N];

int d[N];

vector <int> vec;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		vec.clear();
		for(int i = 1; i <= n; i++)
			d[i] = 0;
		cin >> n;
		ll sum = 0;
		for(int i = 1; i <= n; i++)
			cin >> w[i] , sum += w[i];
		for(int i = 1; i < n; i++)
		{
			int u , v;
			cin >> u >> v;
			if(d[u])
				vec.push_back(w[u]);
			if(d[v])
				vec.push_back(w[v]);
			d[u]++;
			d[v]++;
		}
		sort(vec.begin() , vec.end());
		cout << sum << " ";
		for(int i = vec.size() - 1; i >= 0; i--)
			sum += vec[i] , cout << sum << " ";
		cout << endl; 
	}
	return 0;
}