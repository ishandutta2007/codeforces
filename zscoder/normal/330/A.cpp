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

#define forloopp(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define forloopm(i, a, b) \
for(int i = int(a); i >= int(b); i--)
#define INF INT_MAX

//Tip for reading input : scanf("%s%d", &s, &d);!

//A
int main()
{
	int r, c;
	cin >> r >> c;
	char array[r][c];
	//int count = 0;
	
	forloopp(i, 0, r - 1)
	{
		forloopp(j, 0, c - 1)
		{
			//cout << " here";
			cin >> array[i][j];
		}
	}
	bool encountered = false;
	
	int ro = 0, co = 0;
	
	forloopp(i, 0, r - 1)
	{
		forloopp(j, 0, c - 1)
		{
			if(array[i][j] == 'S')
			{
				encountered = true;
				break;
			}
		}
		if(!encountered)
		{
			ro++;
		}
		encountered = false;
	}
	
	forloopp(j, 0, c - 1)
	{
		forloopp(i, 0, r - 1)
		{
			if(array[i][j] == 'S')
			{
				encountered = true;
				break;
			}
		}
		if(!encountered)
		{
			co++;
		}
		encountered = false;
	}
	//cout << co << " " << ro << endl;
	//cout <<  "(" << r << "-" << ro << ")*" << co << "+(" << c << "*" << ro << ") = "
	cout << ((r-ro)*co) + (c*ro);
	
	return 0;
}

//B
/*
int main()
{
	return 0;
}
*/

//C
/*
int main()
{
	return 0;
}
*/

//D
/*
int main()
{
	return 0;
}
*/

//E
/*
int main()
{
	return 0;
}
*/