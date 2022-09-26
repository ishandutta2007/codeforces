#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;

int main()
{
	/*A
	int n, k;
	cin >> n >> k;
	char word[n+1];
	cin >> word;
	bool direct;
	int dist = min(k - 1, n - k);
	if(n - k > k - 1)
	{
		direct = false;
	}
	else
	{
		direct = true;
	}
	
	for(int i = 0; i < dist ; i++)
	{
		if(direct)
		{
			cout << "RIGHT" << endl;
		}
		else
		{
			cout << "LEFT" << endl;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(direct)
		{
			cout << "PRINT " << word[n - 1 - i] << endl;
			
			if(i != n - 1)
				cout << "LEFT" << endl;
		}
		else
		{
			cout << "PRINT " << word[i] << endl;
			if(i != n - 1)
			{
				cout << "RIGHT" << endl;
			}
		}
	}
	*/
	/*
	int n, k;
	cin >> n >> k;
	int x;
	int sum = 0;
	vector<int> vec;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n; i++)
	{
		sum += vec.at(i);
	}
	cout << vec.at(n - k);
	*/
	//*/
	///*C
	
	int n;
	cin >> n;
	string s[100001];
	//char common[100001];
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	int length = s[0].size();
	int j;
	char detect = '?';
	bool detected = false;
	char ans[100001];
	
	for(int i = 0; i < length; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(!detected)
			{
				//cout << "OPERATION " << i << " " << j << " OPERATING!" << endl;
				if(s[j].at(i) != '?')
				{
					//cout << "OPERATION " << i << " " << j << " OPERATING! IN AREA UNDETECTED! " << endl;
					detected = true;
					detect = s[j].at(i);
				}
			}
			else
			{
				if(s[j].at(i) != detect && s[j].at(i) != '?')
				{
					ans[i] = '?';
					//cout << "OPERATION " << i << " " << j << " OPERATING!" << endl;
					//j--;
					break;
				}
			}
			//cout << detect << " " << j << endl;
		}
		//cout << "Run with i = " << i << " half complete." << endl;
		//cout << j << endl;
		if(j == n)
		{
			if(detect != '?')
			{
				ans[i] = detect;
				//cout << "OPERATION " << i << " " << j << " OPERATING!" << endl;
			}
			else
			{
				ans[i] = 'x';
				//cout << "OPERATION " << i << " " << j << " OPERATING!" << endl;
			}
		}
		detected = false;
		detect = '?';
		//cout << ans[i] << endl;
		//cout << "Search for i = " << i << " complete!" << endl;
	}
	ans[length] = '\0';
	for(int i = 0; i < length; i++)
	{
		cout << ans[i];
	}
	//*/
	/*D
	
	*/
	/*E
	
	*/return 0;
}