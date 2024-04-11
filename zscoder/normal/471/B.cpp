#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
/*A
int main()
{
	vi vec;
	int x;
	for(int i = 0; i < 6; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	int answer = 0;
	if(vec.at(0) == vec.at(1) && vec.at(1) == vec.at(2) && vec.at(2) == vec.at(3))
	{
		if(vec.at(4) == vec.at(5))
		{
			answer = 2;
		}
		else
		{
			answer = 1;
		}
	}
	else if(vec.at(1) == vec.at(2) && vec.at(2) == vec.at(3) && vec.at(3) == vec.at(4))
	{
		if(vec.at(0) == vec.at(5))
		{
			answer = 2;
		}
		else
		{
			answer = 1;
		}
	}
	else if(vec.at(2) == vec.at(3) && vec.at(3) == vec.at(4) && vec.at(4) == vec.at(5))
	{
		if(vec.at(0) == vec.at(1))
		{
			answer = 2;
		}
		else
		{
			answer = 1;
		}
	}
	else
	{
		answer = -1;
	}
	if(answer == -1)
	{
		cout << "Alien" << endl;
	}
	else if(answer == 1)
	{
		cout << "Bear" << endl;
	}
	else
	{
		cout << "Elephant" << endl;
	}
	return 0;
}*/

struct input
{
	int a;
	int b;
};

int myfunc(input x, input y)
{
	if(x.a > y.a)
	{
		return false;
	}
	else if(x.a < y.a)
	{
		return true;
	}
	else
	{
		if(x.b > y.b)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector <input> vec;
	input x;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x.a;
		x.b = i + 1;
		vec.push_back(x);
	}
	
	sort(vec.begin(), vec.end(), myfunc);
	
	int times = 0;
	unsigned long long ways = 1;
	int last = vec.at(0).a;
	bool right = false;
	//int number = 1;
	
	//int arr[2001];
	/*for(int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}*/
	
	int pairs = 0;
	
	vi ans1;
	vi ans2;
	vi ans3;
	
	int i;
	
	for(i = 0; i < n; i++)
	{
		if(last == vec.at(i).a)
		{
			times++;
		}
		else
		{
			ways *= times;
			if(times == 1)
			{
				ans1.push_back(vec.at(i - 1).b);
				ans2.push_back(vec.at(i - 1).b);
				ans3.push_back(vec.at(i - 1).b);
			}
			else if(times == 2)
			{
				pairs++;
				if(pairs >= 2)
				{
					ans1.push_back(vec.at(i - 2).b);
					ans1.push_back(vec.at(i - 1).b);
					//ans1.push_back(vec.at(i).b);
					ans2.push_back(vec.at(i - 1).b);
					ans2.push_back(vec.at(i - 2).b);
					//ans2.push_back(vec.at(i).b);
					ans3.push_back(vec.at(i - 2).b);
					ans3.push_back(vec.at(i - 1).b);
					//ans3.push_back(vec.at(i).b);
				}
				else
				{
					ans1.push_back(vec.at(i - 2).b);
					ans1.push_back(vec.at(i - 1).b);
					//ans1.push_back(vec.at(i).b);
					ans2.push_back(vec.at(i - 2).b);
					//ans2.push_back(vec.at(i).b);
					ans2.push_back(vec.at(i - 1).b);
					ans3.push_back(vec.at(i - 1).b);
					ans3.push_back(vec.at(i - 2).b);
					//ans3.push_back(vec.at(i).b);
				}
			}
			else if(times >= 3)
			{
				for(int j = i - 4; j >= i - times; j--)
				{
					ans1.push_back(vec.at(j).b);
					ans2.push_back(vec.at(j).b);
					ans3.push_back(vec.at(j).b);
				}
				ans1.push_back(vec.at(i - 3).b);
				ans1.push_back(vec.at(i - 2).b);
				ans1.push_back(vec.at(i - 1).b);
				//ans1.push_back(vec.at(i).b);
				ans2.push_back(vec.at(i - 2).b);
				ans2.push_back(vec.at(i - 3).b);
				ans2.push_back(vec.at(i - 1).b);
				//ans2.push_back(vec.at(i).b);
				ans3.push_back(vec.at(i - 3).b);
				ans3.push_back(vec.at(i - 1).b);
				ans3.push_back(vec.at(i - 2).b);
				//ans3.push_back(vec.at(i).b);
			}
			times = 1;
			last = vec.at(i).a;
			//number++;
		}
		if(i == n - 1)
		{
			ways *= times;
			if(times == 1)
			{
				ans1.push_back(vec.at(i).b);
				ans2.push_back(vec.at(i).b);
				ans3.push_back(vec.at(i).b);
			}
			else if(times == 2)
			{
				pairs++;
				if(pairs >= 2)
				{
					//cout << "I'm here!" << endl;
					//ans1.push_back(vec.at(i - 2).b);
					ans1.push_back(vec.at(i - 1).b);
					ans1.push_back(vec.at(i).b);
					ans2.push_back(vec.at(i).b);
					//ans2.push_back(vec.at(i - 2).b);
					ans2.push_back(vec.at(i - 1).b);
					//ans3.push_back(vec.at(i - 2).b);
					ans3.push_back(vec.at(i - 1).b);
					ans3.push_back(vec.at(i).b);
				}
				else
				{
					//ans1.push_back(vec.at(i - 2).b);
					ans1.push_back(vec.at(i - 1).b);
					ans1.push_back(vec.at(i).b);
					//ans2.push_back(vec.at(i - 2).b);
					ans2.push_back(vec.at(i - 1).b);
					ans2.push_back(vec.at(i).b);
					ans3.push_back(vec.at(i).b);
					//ans3.push_back(vec.at(i - 2).b);
					ans3.push_back(vec.at(i - 1).b);
				}
			}
			else if(times >= 3)
			{
				for(int j = i - 3; j > i - times; j--)
				{
					ans1.push_back(vec.at(j).b);
					ans2.push_back(vec.at(j).b);
					ans3.push_back(vec.at(j).b);
				}
				//ans1.push_back(vec.at(i - 3).b);
				ans1.push_back(vec.at(i - 2).b);
				ans1.push_back(vec.at(i - 1).b);
				ans1.push_back(vec.at(i).b);
				ans2.push_back(vec.at(i - 2).b);
				//ans2.push_back(vec.at(i - 3).b);
				ans2.push_back(vec.at(i).b);
				ans2.push_back(vec.at(i - 1).b);
				//ans3.push_back(vec.at(i - 3).b);
				ans3.push_back(vec.at(i - 1).b);
				ans3.push_back(vec.at(i - 2).b);
				ans3.push_back(vec.at(i).b);
			}
		}
		if(ways >= 3)
		{
			right = true;
		}
	}
	/*i++;
	
	for(int j = i; j < n; j++)
	{
		ans1.push_back(vec.at(j).b);
		ans2.push_back(vec.at(j).b);
		ans3.push_back(vec.at(j).b);
	}*/
	
	if(!right)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		for(int j = 0; j < n; j++)
		{
			cout << ans1.at(j) << " ";
		}
		cout << endl;
		for(int j = 0; j < n; j++)
		{
			cout << ans2.at(j) << " ";
		}
		cout << endl;
		for(int j = 0; j < n; j++)
		{
			cout << ans3.at(j) << " ";
		}
		cout << endl;
		
	}
	
	//cout << ans1.size();
	//cout << "Pairs : " << pairs << endl;
	return 0;
}