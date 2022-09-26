#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct pairs
{
	int a;
	int b;
};

bool compare(pairs x, pairs y)
{
	if(x.a < y.a)
	{
		return true;
	}
	else if(x.a > y.a)
	{
		return false;
	}
	else
	{
		if(x.b < y.b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	vector <pairs> vec;
	cin >> n;
	int x;
	pairs inp;
	
	int count_a = 0, count_b = 0, count_c = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		inp.a = x;
		if(x == 1)
		{
			count_a++;
		}
		else if(x == 2)
		{
			count_b++;
		}
		else
		{
			count_c++;
		}
		inp.b = i+1;
		vec.push_back(inp);
	}
	
	sort(vec.begin(), vec.end(), compare);
	
	int ans = min(count_a, min(count_b, count_c));
	
	cout << ans << endl;
	
	int ans_a[5001];
	int ans_b[5001];
	int ans_c[5001];
	if(ans > 0)
	{
		for(int i = 0; i < ans; i++)
		{
			ans_a[i] = vec.at(i).b;
		}
		for(int i = count_a; i < count_a + ans; i++)
		{
			ans_b[i - count_a] = vec.at(i).b;
		}
		for(int i = count_a + count_b; i < count_a + count_b + ans; i++)
		{
			ans_c[i - count_a - count_b] = vec.at(i).b;
		}
	}
	
	for(int i = 0; i < ans; i++)
	{
		cout << ans_a[i] << " " << ans_b[i] << " " << ans_c[i] << endl;
	}
	return 0;
}