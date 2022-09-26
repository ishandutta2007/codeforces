#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define INF 1000000000;
/*A
int main()
{
	int l;
	cin >> l;
	int p, q;
	cin >> p >> q;
	float ans = p * l;
	ans /= (p + q);
	cout << ans << endl;
	return 0;
}
*/
int main()
{
	int m, n;
	string name;
	cin >> n >> m;
	cin >> name;
	char x, y;
	string ori = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		for(int j = 0; j < 26; j++)
		{
			if(ori.at(j) == x)
			{
				ori.at(j) = y;
			}
			else if(ori.at(j) == y)
			{
				ori.at(j) = x;
			}
		}
	}
	//cout << ori << endl;
	for(int i = 0; i < n; i++)
	{
		name.at(i) = ori.at(name.at(i) - 97); 
	}
	cout << name << endl;
	return 0;
}