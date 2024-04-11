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
}