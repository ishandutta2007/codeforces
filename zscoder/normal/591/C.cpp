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
/*B
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
}*/
int arr[5000010];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i + 1];
	}
	arr[0] = arr[1];
	arr[n + 1] = arr[n];
	int ans = 0;
	bool strange = false;
	int start = -1;
	int left = -1;
	int end = -1;
	int right = -1;
	int mid = -1;
	int length = end - start + 1;
	for(int i = 1; i <= n; i++)
	{
		if(arr[i - 1] != arr[i] && arr[i + 1] != arr[i])
		{
			if(!strange)
			{
				strange = true;
				start = i;
				left = arr[i - 1];
			}
		}
		else
		{
			if(strange)
			{
				end = i - 1;
				right = arr[i];
				length = end - start + 1;
				ans = max(ans, ((length + 1)/2));
				mid = length/2 + start - 1;
				for(int j = start; j <= mid; j++)
				{
					arr[j] = left;
				}
				for(int j = mid + 1; j <= end; j++)
				{
					arr[j] = right;
				}
				strange = false;
			}
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= n - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[n] << endl;
	return 0;
}