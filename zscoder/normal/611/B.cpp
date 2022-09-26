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
		if(a.second > b.second)
		{
			return false;
		}
		return true;
	}
}*/

//freopen("input.txt", "r", stdin);
/*A
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	cin >> s;
	if(s.at(0) == 'm')
	{
		if(n <= 29)
		{
			cout << 12;
		}
		else if(n == 30)
		{
			cout << 11;
		}
		else
		{
			cout << 7;
		}
	}
	else
	{
		if(n <= 4)
		{
			cout << 52;
		}
		else if(n == 7)
		{
			cout << 52;
		}
		else
		{
			cout << 53;
		}
	}
	return 0;
}*/
vi binary(ll a)
{
	vi vec;
	while(a > 0)
	{
		vec.push_back(a%2);
		a /= 2;
	}
	reverse(vec.begin(), vec.end());
	return vec;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
	vi x, y;
	x = binary(a);
	y = binary(b);
	ll sum = 0;
	int counter = x.size();
	int counter2 = y.size();
	int count = 0;
	int count2 = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x.at(i) == 0)
		{
			if(count == 0)
			{
				counter = i;
			}
			count++;
		}
	}
	for(int i = 0; i < y.size(); i++)
	{
		if(y.at(i) == 0)
		{
			if(count2 == 0)
			{
				counter2 = i;
			}
			count2++;
		}
	}
	//cout << counter << " " << counter2 << endl;
	if(x.size() == y.size())
	{
		sum = counter2 - counter;
		if(count2 == 1)
		{
			sum++;
		}
	}
	else
	{
		sum += counter2 - 1;
		sum += x.size() - counter;
		for(int i = x.size() + 1; i < y.size(); i++)
		{
			sum += i-1;
		}
		if(count2 == 1)
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
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
/*H
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/