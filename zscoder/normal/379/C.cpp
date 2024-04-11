#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl; //Debug


const ll INF = 1000000000;
const ll MOD = 1000000007;

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
	else
	{
		if(a.second > b.second)
		{
			return false;
		}
		return true;
	}
}
/*A
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int sum = 0;
	int burnt = 0;
	while(a > 0)
	{
		sum += a;
		burnt += a;
		a = burnt/b;
		burnt %= b;
	}
	cout << sum << endl;
	return 0;
}*/
/*B
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int arr[301];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++)
	{
		while(arr[i] > 0)
		{
			cout << "P";
			if(i == n - 1)
			{
				cout << "LR";
			}
			else
			{
				cout << "RL";
			}
			arr[i]--;
		}
		if(i < n-1)
		{
			cout << "R";
		}
	}
	return 0;
}*/
vii vec;
int ans[300001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(make_pair(x, i));
	}
	sort(vec.begin(), vec.end(), compare);
	int counter = 0;
	for(int i = 0; i < n; i++)
	{
		counter = max(counter + 1, vec.at(i).first);
		ans[vec.at(i).second] = counter;
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
/*D
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*E
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*F
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*G
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/