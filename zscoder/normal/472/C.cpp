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
#include <fstream>

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
/*B
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
}*/
struct name
{
	string a;
	int id;
};

struct input
{
	int x;
	int y;
};

bool myfunc(name x, name y)
{
	if(x.a < y.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool myfunc2(input a, input b)
{
	if(a.y < b.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int binarysearch(vector<name>& vec, unsigned start, unsigned end,  name x)
{
	if(start > end)
    {
        return -1;
    }
 
    unsigned middle = start + ((end - start) / 2);
 
    if(vec.at(middle).a == x.a)
    {
        return middle;
    }
    else if(!myfunc(vec.at(middle), x))
    {
        return binarysearch(vec, start, middle - 1, x);
    }
 
    return binarysearch(vec, middle + 1, end, x);
}

int main()
{
	//ofstream fout;
	//ifstream fin;
	//fout.open("Codeforces270C.out");
	//fin.open("Codeforces270C.in");
	int n;
	cin >> n;
	//fin >> n;
	
	vector<name> vec;
	vector <input> inp;
	string first[100001];
	string last[100001];
	string x, y;
	name x1, y1;
	int a;
	input a1;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		//fin >> x >> y;
		//cout << x << " " << y << endl;
		first[i] = x;
		last[i] = y;
		x1.a = x;
		x1.id = i + 1;
		y1.a = y;
		y1.id = i + 1;
		vec.push_back(x1);
		vec.push_back(y1);
	}
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		//fin >> a;
		//cout << a << " ";
		a1.x = a - 1;
		a1.y = i;
		inp.push_back(a1);
	}
	//cout << endl;
	sort(vec.begin(), vec.end(), myfunc);
	sort(inp.begin(), inp.end(), myfunc2);
	
	/*for(int i = 0; i < n; i++)
	{
		cout << inp.at(i).x << " " << inp.at(i).y << " " << endl;
	}*/
	int current_min = INT_MAX;
	int min = INT_MAX;
	name loop;
	bool possible = true;
	for(int i = 0; i < n; i++)
	{
		if(first[inp.at(i).x] < last[inp.at(i).x])
		{
			loop.a = first[inp.at(i).x];
			loop.id = inp.at(i).x + 1;
			min = binarysearch(vec, 0, vec.size() - 1, loop);
		}
		else
		{
			loop.a = last[inp.at(i).x];
			loop.id = inp.at(i).y + 1;
			min = binarysearch(vec, 0, vec.size() - 1, loop);
		}
		if(i == 0)
		{
			current_min = min;
		}
		else
		{
			if(min < current_min)
			{
				if(first[inp.at(i).x] > last[inp.at(i).x])
				{
					loop.a = first[inp.at(i).x];
					loop.id = inp.at(i).x + 1;
					min = binarysearch(vec, 0, vec.size() - 1, loop);
				}
				else
				{
					loop.a = last[inp.at(i).x];
					loop.id = inp.at(i).x + 1;
					min = binarysearch(vec, 0, vec.size() - 1, loop);
				}
				if(min < current_min)
				{
					//cout << "FOILED AT i = " << i << ", FIRST NAME : " << first[inp.at(i).x] << "  LAST NAME : " << last[inp.at(i).x] << endl;
					possible = false;
					break;
				}
				else
				{
					current_min = min;
				}
			}
			else
			{
				current_min = min;
			}
		}
	}
	if(possible)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	//fout.close();
	//fin.close();
}