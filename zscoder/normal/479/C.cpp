#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
/*A
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int ans = -1;
	ans = max(a + b + c, max(a*b*c, max(a + b*c, max(a*b + c,max(a*(b + c), (a + b)*c)))));
	cout << ans << endl;
	return 0;
}*/
/*
struct pairs
{
	int a;
	int b;
};


bool myfunc(pairs x, pairs y)
{
	if(x.a <= y.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<pairs> vec;
	int x;
	pairs inp;
	
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		inp.a = x;
		inp.b = i+1;
		vec.push_back(inp);
	}
	vector<int> vec1;
	vector<int> vec2;
	for(int i = 0; i < k; i++)
	{
		sort(vec.begin(), vec.end(), myfunc);
		if(vec.at(0).a == vec.at(vec.size() -1).a)
		{
			break;
		}
		else if(vec.at(vec.size() - 1).a - vec.at(0).a == 1)
		{
			break;
		}
		vec.at(vec.size() - 1).a--;
		vec.at(0).a++;
		vec1.push_back(vec.at(vec.size() - 1).b);
		vec2.push_back(vec.at(0).b);
		count++;
	}
	sort(vec.begin(), vec.end(), myfunc);
	cout << vec.at(vec.size() - 1).a - vec.at(0).a << " ";
	cout << count << endl;
	for(int i = 0; i < vec1.size(); i++)
	{
		cout << vec1.at(i) << " " << vec2.at(i) << endl;
	}
	return 0;
}*/
struct pairs
{
	int a;
	int b;
	int c;
};


bool myfunc(pairs x, pairs y)
{
	if(x.a < y.a)
	{
		return true;
	}
	else if(x.a == y.a)
	{
		if(x.b < y.b)
		{
			return true;
		}
		else if(x.b == y.b)
		{
			if(x.c < y.c)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	int n;
	//vector<int> a;
	//vector<int> b;
	vector <pairs> vec;
	int x, y;
	pairs inp;
	cin >> n;
	//int answer = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		inp.a = x;
		inp.b = y;
		inp.c = i+1;
		vec.push_back(inp);
	}
	sort(vec.begin(), vec.end(), myfunc);
	/*for(int i = 0; i < n; i++)
	{
		cout << vec.at(i).a << " " << vec.at(i).b << " " << vec.at(i).c << endl;
	}*/
	int current_min = 0;
	for(int i = 0; i < n; i++)
	{
		if(current_min > vec.at(i).b)
		{
			current_min = vec.at(i).a;
			
		}
		else
		{
			current_min = vec.at(i).b;
		}
		
	}
	cout << current_min << endl;
	return 0;
}