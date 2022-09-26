#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int bear = 0;
	vi candidates;
	int x;
	cin >> bear;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n - 1; i++)
	{
		cin >> x;
		candidates.push_back(x);
	}
	int candy = 0;
	sort(candidates.begin(), candidates.end());
	while(bear <= candidates.at(n - 2))
	{
		candidates.at(n - 2)--;
		candy++;
		bear++;
		sort(candidates.begin(), candidates.end());
	}
	
	cout << candy << endl;
	return 0;
}