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

/*bool compare(ii a, ii b)
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
		if(a.first > b.first)
		{
			return false;
		}
		return true;
	}
}*/

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
}
/*B
int main()
{
	ios_base::sync_with_stdio(false);

	
	return 0;
}*/
/*C
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
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