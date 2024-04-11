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
/*A
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
}*/
int main()
{
	int n, k;
	cin >> n >> k;
	
	vi vec;
	
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	
	ll time = 0;
	sort(vec.begin(), vec.end());
	
	time += (2*ceil((double)n/(double)k) - 1)*(vec.at(0) - 1);
	//cout << time << endl;
	for(int i = 1; i < n; i++)
	{
		time += (2*(ceil((double)(n - i)/(double)k)) - 1)*(vec.at(i) - vec.at(i - 1));
		//cout << time << endl;
	}
	time += vec.at(vec.size() - 1) - 1;
	cout << time << endl;
	return 0;
}