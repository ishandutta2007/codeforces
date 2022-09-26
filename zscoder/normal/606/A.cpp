#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int diff_a, diff_b, diff_c;
	int positive = 0; 
	int negative = 0;
	diff_a = a-d;
	diff_b = b-e;
	diff_c = c-f;
	if(diff_a > 0)
	{
		positive += diff_a/2;
	}
	else
	{
		negative -= diff_a;
	}
	if(diff_b > 0)
	{
		positive += diff_b/2;
	}
	else
	{
		negative -= diff_b;
	}
	if(diff_c > 0)
	{
		positive += diff_c/2;
	}
	else
	{
		negative -= diff_c;
	}
	if(positive >= negative)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}