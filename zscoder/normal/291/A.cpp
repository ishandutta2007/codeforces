#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k, ct = 0;
	cin >> n;
	
	vector <long long> vec;
	
	long long count = 0;
	bool faulty = true;
	
	long long i;
	for(i = 0; i < n; i++)
	{
		cin >> k;
		vec.push_back(k);
	}
	
	sort(vec.begin(), vec.end());
	
	int c = 0;
	
	if(n > 2)
	{
		while(vec.at(c) == 0)
		{
			c++;
			if(c == n - 1)
			{
				cout << 0;
				return 0;
			}
		}
		
		//cout << c << endl;
		
		k = vec.at(c);
		//cout << k << endl;
		for(i = c; i < n; i++)
		{
			if(vec.at(i) == k)
			{
				ct++;
				if(ct > 2)
				{
					faulty = false;
					break;
				}
			}
			else
			{
				//cout << "I entered here!" << endl;
				if(ct == 2)
				{
					count++;
				}
				else if(ct > 2)
				{
					faulty = false;
					break;
				}
				k = vec.at(i);
				ct = 1;
			}
		}
		if(ct == 2)
		{
			count++;
		}
	}
	else if(n == 2)
	{
		if(vec.at(0) == vec.at(1) && vec.at(0) != 0)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	else
	{
		cout << 0;
		return 0;
	}
	if(!faulty)
	{
		cout << -1;
	}
	else
	{
		cout << count;
	}
	return 0;
}