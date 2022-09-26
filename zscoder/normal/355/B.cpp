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
/*
int main()
{
	int k, d;
	cin >> k >> d;
	
	if(d == 0 && k > 1)
	{
		cout << "No solution";
	}
	else
	{
		cout << d;
		for(int i = 0; i < k - 1; i++)
		{
			cout << 0;
		}
	}
	return 0;
}*/

//B
///*
int main()
{
	/*
	int c1, c2, c3, c4, n, m;
	scanf("%d %d %d %d \n %d %d", &c1, &c2, &c3, &c4, &n, &m);
	int bus[n];
	int trolley[m];
	
	forloopp(i, 0, n - 1)
	{
		cin >> bus[i];
	}
	forloopp(i, 0, m - 1)
	{
		cin >> trolley[i];
	}
	int min = INF, min2 = INF; 
	int i, count = 0;
	//cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << n << " " << m << endl;
	if(c4 <= c3 && c4 <= c2 && c4 <= c1)
	{
		cout << c4;
	}//ok till here
	else
	{
		//int a = n * c1; 
		min = c3;
		for(i = 0; i < n; i++)
		{
			if(c2 > c1*bus[i])
			{
				count += c1*bus[i];
			}
			else
			{
				count += c2;
			}
		}
		if(min > count)
		{
			min = count;
		}
		//a = m * c1;
		/*if(c3 > a)
		{
			min2 = a;
		}
		else
		{
			min2 = c3;
		}*/
	/*
		min2 = c3;
		count = 0;
		for(i = 0; i < m; i++)
		{
			if(c2 > c1*trolley[i])
			{
				count += c1*trolley[i];
			}
			else
			{
				count += c2;
			}
		}
		if(min2 > count)
		{
			min2 = count;
		}
		cout << min + min2;
	}*/
	long long a[1111],b[1111],cost[11],n,m;
	for(int i=0; i<4; i++)
	{
		cin >> cost[i];
	}
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i]; 
	for(int i=0; i<m; i++) cin >> b[i];
	long long ans=min(cost[3],2*cost[2]);
	long long mi=0;
	for(int i=0; i<n; i++) 
	{
		long long cur =min(a[i]*cost[0],cost[1]);
		mi+=cur;
	} 
	mi=min(mi,cost[2]);
	long long mmi=0;
	for(int i=0; i<m; i++) 
	{
		long long cur=min(b[i]*cost[0],cost[1]);
		mmi+=cur;
	} 	
	mmi=min(mmi,cost[2]);
	mi+=mmi;
	ans=min(mi,ans);
	cout << ans << endl;	
	cin >> n;
	return 0;
}
//*/

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