#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <bitset>
#include <cmath>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <pair<int,int> > vii;

int main()
{
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << 4 << " " << n - 4 << endl;
	}
	else if(n % 3 == 0)
	{
		cout << 6 << " " << n - 6 << endl;
	}
	else if(n % 3 == 1)
	{
		cout << 4 << " " << n - 4 << endl;
	}
	else if(n % 3 == 2)
	{
		cout << 8 << " " << n - 8 << endl;
	}
	return 0;
}