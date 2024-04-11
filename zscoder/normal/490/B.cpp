#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <new>

using namespace std;

struct pairs
{
	int a;
	int b;
};

bool compare(pairs x, pairs y)
{
	if(x.a < y.a)
	{
		return true;
	}
	else if(x.a > y.a)
	{
		return false;
	}
	else
	{
		if(x.b < y.b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool compare2(pairs x, pairs y)
{
	if(x.b < y.b)
	{
		return true;
	}
	else if(x.b > y.b)
	{
		return false;
	}
	else
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
}
int search(vector<pairs>&vec, int first, int last, int key)
{
	int index;
	
	int mid = (first + last)/2;
 
	if (key == vec.at(mid).a)
	{
		index = mid;
	}
	else
	{
		if (key < vec.at(mid).a)
		{
			index = search(vec, first, mid-1, key);
		}
		else
		{
			index = search(vec, mid+1, last, key);
		 
		}
	}
	return index;
}

int search2(vector<pairs>&vec, int first, int last, int key)
{
	int index;
	
	int mid = (first + last)/2;
 
	if (key == vec.at(mid).b)
	{
		index = mid;
	}
	else
	{
		if (key < vec.at(mid).b)
		{
			index = search2(vec,first, mid-1, key);
		}
		else
		{
			index = search2(vec, mid+1, last, key);
		}
	}
	return index;
}

/*
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	vector <pairs> vec;
	cin >> n;
	int x;
	pairs inp;
	
	int count_a = 0, count_b = 0, count_c = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		inp.a = x;
		if(x == 1)
		{
			count_a++;
		}
		else if(x == 2)
		{
			count_b++;
		}
		else
		{
			count_c++;
		}
		inp.b = i+1;
		vec.push_back(inp);
	}
	
	sort(vec.begin(), vec.end(), compare);
	
	int ans = min(count_a, min(count_b, count_c));
	
	cout << ans << endl;
	
	int ans_a[5001];
	int ans_b[5001];
	int ans_c[5001];
	if(ans > 0)
	{
		for(int i = 0; i < ans; i++)
		{
			ans_a[i] = vec.at(i).b;
		}
		for(int i = count_a; i < count_a + ans; i++)
		{
			ans_b[i - count_a] = vec.at(i).b;
		}
		for(int i = count_a + count_b; i < count_a + count_b + ans; i++)
		{
			ans_c[i - count_a - count_b] = vec.at(i).b;
		}
	}
	
	for(int i = 0; i < ans; i++)
	{
		cout << ans_a[i] << " " << ans_b[i] << " " << ans_c[i] << endl;
	}
	return 0;
}*/

int main()
{
	vector<pairs> vec;
	vector<pairs> vec2;
	int n;
	cin >> n;
	
	int x, y;
	pairs inp;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		inp.a = x;
		inp.b = y;
		vec.push_back(inp);
		vec2.push_back(inp);
	}
	
	sort(vec.begin(), vec.end(), compare);
	sort(vec2.begin(), vec2.end(), compare2);

	int* arr;
	int* ar;
	int* ar2;
	//bool* arrr;
	arr = new int[200010];
	ar = new int[1000001];
	ar2 = new int[1000001];
	//arrr = new bool[200010] ;
	
	//memset (arrr,true,200010);
	memset (ar,0,1000001);
	memset (ar2,0,1000001);
	arr[0] = 0;
	arr[n + 1] = 0;
	
	for(int i = 2; i <= n; i += 2)
	{
		int x = search(vec, 0, vec.size() - 1, arr[i - 2]);
		//arrr[x] = false;
		arr[i] = vec.at(x).b;
	}
	
	int begin;
	if(n % 2 == 1)
	{
		for(int i = 0; i < n; i++)
		{
			//if(arrr[i] == true)
			//{
				int x, y;
				x = vec.at(i).a;
				y = vec.at(i).b;
				ar[x]++;
				ar2[y]++;
			//}
		}
		for(int i = 0; i < 1000001; i++)
		{
			if(ar[i] + ar2[i] == 1)
			{
				if(ar[i] == 1)
				{
					begin = i;
					break;
				}
			}
		}
		arr[1] = begin;
		for(int i = 3; i <= n; i += 2)
		{
			int x = search(vec, 0, vec.size() - 1, arr[i - 2]);
			arr[i] = vec.at(x).b;
		//cout << "FINE " <<endl;
		}
	}
	else
	{
		for(int i = n - 1; i >= 1; i -= 2)
		{
			//cout << "FINE " <<endl;
			int x = search2(vec2, 0, vec2.size() - 1, arr[i + 2]);
			arr[i] = vec2.at(x).a;
			//cout << "FINE " <<endl;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
/*C
int main()
{
	string x;
	cin >> x;
	int a, b;
	cin >> a >> b;
	
	vector<int> possible_a;
	
	int remain_a = 0, remain_b = 0;
	for(int i = 0; i < x.length() - 1; i++)
	{
		remain_a = ((remain_a*10)%a + x.at(i) - 48)%a;
		
		if(remain_a == 0)
		{
			possible_a.push_back(i);
		}
	}
	if(possible_a.size() == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	int ans;
	bool fail = false;
	bool found = false;
	for(int i = 0; i < possible_a.size(); i++)
	{
		for(int j = possible_a.at(i) + 1; j < x.length(); j++)
		{
			if(x.at(possible_a.at(i) + 1) == '0')
			{fail = true;break;}
			else
			{
				remain_b = ((remain_b*10)%b + x.at(j) - 48)%b;
				//cout << remain_b << endl;
			}
		}
		if(!fail && remain_b == 0)
		{
			ans = possible_a.at(i);
			found = true;
			break;
		}
		fail = false;
	}
	
	if(!found)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		for(int i = 0; i <= ans; i++)
		{
			cout << x.at(i);
		}
		cout << endl;
		for(int i = ans + 1; i <= x.length() - 1; i++)
		{
			cout << x.at(i);
		}
	}
	
	return 0;
}*/