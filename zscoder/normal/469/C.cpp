#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
/*A
int main()
{
	int n;
	cin >> n;
	
	int a, b;
	vector<int> arr;
	vector<int> arr2;
	int x;
	
	cin >> a;
	for(int i = 0; i < a; i++)
	{
		cin >> x;
		arr.push_back(x);
	}
	
	cin >> b;
	for(int i = 0; i < b; i++)
	{
		cin >> x;
		arr2.push_back(x);
	}
	
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	sort(arr2.begin(), arr2.end());
	reverse(arr2.begin(), arr2.end());
	
	bool pass = true;
	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		if(arr.back() == i)
		{
			arr.pop_back();
			count++;
		}
		if(arr2.back() == i)
		{
			arr2.pop_back();
			count++;
		}
		if(count == 0)
		{
			pass = false;
			break;
		}
		count = 0;
	}
	
	if(pass)
	{
		cout << "I become the guy." << endl;
	}
	else
	{
		cout << "Oh, my keyboard!" << endl;
	}

	return 0;
}*/
/*B
int main()
{
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	
	int arr[51][2];
	int arr2[51][2];
	
	for(int i = 0; i < p; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	for(int i = 0; i < q; i++)
	{
		cin >> arr2[i][0] >> arr2[i][1];
	}
	
	int count = 0;
	bool found = false;
bool break2 = false;
	for(int i = l; i <= r; i++)
	{
		for(int j = 0; j < p; j++)
		{
			for(int k = 0; k < q; k++)
			{
				if(arr[j][1] < (arr2[k][0] + i) || (arr2[k][1] + i) < arr[j][0])
				{}
				else
				{
					found = true;
					//cout << i << " " << arr[j][0] << " " << arr[j][1] << " " << arr2[k][0] + i << " " << arr2[k][1] + i << endl;
					break2 = true;
					break;
				}
			}
			if(break2)
			{break;}

		}
		if(found)
		{
			//cout << i << endl;
			count++;
		}
		found = false;
		break2 = false;
	}
	
	cout << count;
	
	return 0;
}*/

int main()
{
	int n;
	cin >> n;
	
	if(n <= 3)
	{
		cout << "NO";
	}
	else if(n == 4)
	{
		cout << "YES" << endl;
		cout << "4 * 3 = 12" << endl;
		cout << "12 * 2 = 24" << endl;
		cout << "24 * 1 = 24" << endl;
	}
	else if(n > 4 && n % 2 == 0)
	{
		cout << "YES" << endl;
		for(int i = n; i >= 6; i -= 2)
		{
			cout << i << " - " << i - 1 << " = 1" << endl;
		}
		for(int i = 0; i < n/2 - 2; i++)
		{
			cout << "1 * 1 = 1" << endl;
		}
		cout << "4 * 3 = 12" << endl;
		cout << "12 * 2 = 24" << endl;
		cout << "24 * 1 = 24" << endl;
	}
	else if(n >= 9 && n % 2 == 1)
	{
		cout << "YES" << endl;
		cout << "3 + 1 = 4" << endl;
		cout << "4 + 4 = 8" << endl;
		cout << "9 - 8 = 1" << endl;
		cout << "1 * 2 = 2" << endl;
		cout << "8 * 7 = 56" << endl;
		cout << "6 * 5 = 30" << endl;
		cout << "56 - 30 = 26" << endl;
		cout << "26 - 2 = 24" << endl;
		for(int i = n; i >= 11; i -= 2)
		{
			cout << i << " - " << i - 1 << " = 1" << endl;
		}
		for(int i = 0; i < (n - 1)/2 - 5; i++)
		{
			cout << "1 * 1 = 1" << endl;
		}
		cout << "24 * 1 = 24" << endl;
	}
	else if(n == 7)
	{
		cout << "YES" << endl;
		cout << "4 * 5 = 20" << endl;
		cout << "20 + 2 = 22" << endl;
		cout << "22 + 3 = 25" << endl;
		cout << "25 - 1 = 24" << endl;
		cout << "7 - 6 = 1" << endl;
		cout << "24 * 1 = 24" << endl;
	}
	else
	{
		cout << "YES" << endl;
		cout << "4 * 5 = 20" << endl;
		cout << "20 + 2 = 22" << endl;
		cout << "22 + 3 = 25" << endl;
		cout << "25 - 1 = 24" << endl;
	}
	return 0;
}