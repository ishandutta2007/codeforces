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
#include <ctime>
#include <cstdlib>

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

//Tip for reading input : scanf("%s%d", &s, &d);

//A
/*
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int array[n];
	//int t1 = 0, t2 = 0;
	int bowls = m, plates = k;
	int cleans = 0;
	forloopp(i, 0, n - 1)
	{
		cin >> array[i];
		if(array[i] == 1)
		{
			if(bowls > 0)
				bowls--;
			else
			{
				cleans++;
			}
		}
		else
		{
			if(plates > 0)
			{
				plates--;
			}
			else if(bowls > 0 && plates == 0)
			{
				bowls--;
			}
			else
			{
				cleans++;
			}
		}
	}
	cout << cleans << endl;
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}*/

//B
///*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	int n, k, l, r, sum, sumk;
	cin >> n >> k >> l >> r >> sum >> sumk; //6 4 1 9 11 8
	if(k < n)
	{
		int kav = sumk/k; //2
		//if(kav < l || kav > r)
	//	{
		//	cerr << "Error has occured" << endl;
		//}
		int lowerpart = sum - sumk; //3
		int lowav = lowerpart/(n - k); //1
		int overk, overo; 
		overk = sumk - (kav * k); //0
		overo = lowerpart - (lowav*(n-k)); //1
		//if(kav == lowav)
		//{
		//	
		//}
		
		//else
		{
			forloopp(i, 0, k - 1)
			{
				if(i < overk)
				{
					cout << kav + 1 << " ";
				}
				else
				{
					cout << kav << " ";
				}
			}
			forloopp(i, 0, n - k - 1)
			{
				if(i < overo)
				{
					cout << lowav + 1 << " ";
				}
				else
				{
					cout << lowav << " ";
				}
			}
		}
	}
	else
	{
		int kav = sumk/k;
		//if(kav < l || kav > r)
		//{
		//	cerr << "Error has occured";
		//}
		int overk = sumk - (kav * k);
		forloopp(i, 0, k - 1)
		{
			if(i < overk)
			{
				cout << kav + 1 << " ";
			}
			else
			{
				cout << kav << " ";
			}
		}
	}
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}

//C
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/

//D
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/

//E
/*
int main()
{
	//clock_t start = clock();
	//Program starts here.
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}
*/