#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <cstdio>
#include <stack>
#include <complex>
#include <climits>
#include <bitset>
#include <deque>
#include <set>
#include <list>
#include <valarray>
#include <functional>
#include <new>
#include <iterator>
#include <stdexcept>
#include <cstddef>
#include <fstream>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <bool> vb;

#define _CRT_SECURE_NO_DEPRECATE
#define forloopp(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define forloopm(i, a, b) \
for(int i = int(a); i >= int(b); i--)
#define INF 2000000000 //2 billion

bool check_digits(int n, int k)
{
	vi digits;
	while(n > 0)
	{
		digits.push_back(n % 10);
		//cout << n % 10;
		n /= 10;
	}
	//cout << endl;
	sort(digits.begin(), digits.end());
	if(digits.at(0) != 0)
	{
		return false;
	}
	for(int i = 0; i < digits.size() - 1; i++)
	{
		//cout << digits.at(i);
		if(digits.at(i + 1) - digits.at(i) > 1 && digits.at(i) < k)
		{
			//cout << endl;
			return false;
		}
	}
	//cout << digits.at(digits.size() - 1) << endl;
	if(digits.at(digits.size() - 1) < k)
	{
		//cout << "Reached" << endl;
		return false;
		//cout << "Got Away!" << endl;
	}
	return true;
}

int main()
{
	//cout << (int)check_digits(1000000, 1);
	int n, k;
	cin >> n >> k;
	int array[n];
	int i;
	int count = 0;
	
	for(i = 0; i < n; i++)
	{
		cin >> array[i];
		if(check_digits(array[i], k))
		{
			count++;
		}
	}
	
	cout << count;
	
	return 0;
}

/* Copy and paste if you want to avoid typing.
	
	int i; //for loops
	int count = 0; //for answers
	int array[m][n];

	for(i = ; i  ; i  )
	{

	}

	if()
	{

	}
	else
	{

	}

	if()
	{

	}
	else if()
	{

	}
	else
	{
	
	}
*/

/*	Algorithms
	sort(vec.begin(), vec.end());
	string.at();
*/