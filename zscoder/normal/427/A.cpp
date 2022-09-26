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
int main()
{
	//clock_t start = clock();
	//Program starts here.
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int count = 0;
	int ans = 0;
	int arr[n];
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i] == -1 && count <= 0)
		{
			ans++;
		}
		else if(count > 0 && arr[i] == -1)
		{
			count--;
		}
		else
		{
			count += arr[i];
		}
	}
	
	
	cout << ans << endl;
	//clock_t end = clock();
	//printf("Run Time : %.5f\n", ((double)(end - start))/CLOCKS_PER_SEC);
	return 0;
}

//B
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