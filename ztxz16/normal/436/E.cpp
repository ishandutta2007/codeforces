#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

struct Node
{
	int a, b, tag;
	
	friend bool operator < (Node a, Node b)
	{
		return a.a < b.a;
	}
}a[300005];

long long ans, now;
int n, w, i, st, sel[300005];
set <pair <int, int> > s1, s2, s3, s4;
set <pair <int, int> > :: iterator it;

int main()
{
	scanf("%d %d", &n, &w);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &a[i].a, &a[i].b), a[i].tag = i;
	sort(a + 1, a + n + 1);
	if (w & 1)
	{
		for (i = 2; i <= n; i++)
			s2.insert(make_pair(a[i].b, -a[i].tag));
		s1.insert(make_pair(a[1].b - a[1].a, a[1].tag));
		now += a[1].a;
		for (i = 1; i < w; i += 2)
		{
			pair <int, int> x = *s2.begin();
			now += x.first;
			s2.erase(x), s4.insert(x);
		}
		
		st = 2;
	}
	
	else
	{
		for (i = 1; i <= n; i++)
			s2.insert(make_pair(a[i].b, -a[i].tag));
		for (i = 0; i < w; i += 2)
		{
			pair <int, int> x = *s2.begin();
			now += x.first;
			s2.erase(x), s4.insert(x);
		}
		
		st = 1;
	}
	
	ans = now;
	for (i = st; i <= n; i++)
	{
		if (i > w)
			break;
		pair <int, int> x = make_pair(a[i].b, -a[i].tag);
		if (s4.find(x) != s4.end())
		{
			s4.erase(x);
			now -= x.first;
			now += a[i].a;
			s1.insert(make_pair(a[i].b - a[i].a, a[i].tag));
			x = *s1.begin();
			now += x.first;
			s1.erase(x), s3.insert(x);
		}
		
		else
		{
			s2.erase(x);
			now += a[i].a;
			s1.insert(make_pair(a[i].b - a[i].a, a[i].tag));
			if (s3.size())
			{
				x = *s3.rbegin();
				now -= x.first;
				s3.erase(x), s1.insert(x);
			}
			
			else
			{
				x = *s4.rbegin();
				now -= x.first;
				s4.erase(x), s2.insert(x);
				x = *s1.begin();
				now += x.first;
				s1.erase(x), s3.insert(x);
			}
		}
		
		while (s1.size() > 1 && s4.size())
		{
			pair <int, int> x1, x2, x3;
			x1 = *s1.begin();
			x2 = *(++s1.begin());
			x3 = *s4.rbegin();
			if (x1.first + x2.first < x3.first)
			{
				now -= x3.first;
				now += x1.first + x2.first;
				s1.erase(x1), s1.erase(x2);
				s3.insert(x1), s3.insert(x2);
				s4.erase(x3), s2.insert(x3);
			}
			
			else
				break;
		}
		
		while (s3.size() > 1 && s2.size())
		{
			pair <int, int> x1, x2, x3;
			x1 = *(--s3.end());
			x2 = *(--(--s3.end()));
			x3 = *s2.begin();
			if (x1.first + x2.first > x3.first)
			{
				now += x3.first;
				now -= x1.first + x2.first;
				s3.erase(x1), s3.erase(x2);
				s1.insert(x1), s1.insert(x2);
				s2.erase(x3), s4.insert(x3);
			}
			
			else
				break;
		}
		
		ans = min(ans, now);
	}
	
	cout << ans << endl;
	
	now = 0;
	s1.clear(), s2.clear(), s3.clear(), s4.clear();
	if (w & 1)
	{
		for (i = 2; i <= n; i++)
			s2.insert(make_pair(a[i].b, -a[i].tag));
		s1.insert(make_pair(a[1].b - a[1].a, a[1].tag));
		now += a[1].a;
		for (i = 1; i < w; i += 2)
		{
			pair <int, int> x = *s2.begin();
			now += x.first;
			s2.erase(x), s4.insert(x);
		}
		
		st = 2;
	}
	
	else
	{
		for (i = 1; i <= n; i++)
			s2.insert(make_pair(a[i].b, -a[i].tag));
		for (i = 0; i < w; i += 2)
		{
			pair <int, int> x = *s2.begin();
			now += x.first;
			s2.erase(x), s4.insert(x);
		}
		
		st = 1;
	}

	if (ans == now)
	{
		for (it = s1.begin(); it != s1.end(); ++it)
			sel[it->second] = 1;
		for (it = s3.begin(); it != s3.end(); ++it)
			sel[it->second] = 2;
		for (it = s4.begin(); it != s4.end(); ++it)
			sel[-it->second] = 2;
		for (i = 1; i <= n; i++)
			printf("%d", sel[i]);
		printf("\n");
		return 0;
	}
	
	for (i = st; i <= n; i++)
	{
		if (i > w)
			break;
		pair <int, int> x = make_pair(a[i].b, -a[i].tag);
		if (s4.find(x) != s4.end())
		{
			s4.erase(x);
			now -= x.first;
			now += a[i].a;
			s1.insert(make_pair(a[i].b - a[i].a, a[i].tag));
			x = *s1.begin();
			now += x.first;
			s1.erase(x), s3.insert(x);
		}
		
		else
		{
			s2.erase(x);
			now += a[i].a;
			s1.insert(make_pair(a[i].b - a[i].a, a[i].tag));
			if (s3.size())
			{
				x = *s3.rbegin();
				now -= x.first;
				s3.erase(x), s1.insert(x);
			}
			
			else
			{
				x = *s4.rbegin();
				now -= x.first;
				s4.erase(x), s2.insert(x);
				x = *s1.begin();
				now += x.first;
				s1.erase(x), s3.insert(x);
			}
		}
		
		while (s1.size() > 1 && s4.size())
		{
			pair <int, int> x1, x2, x3;
			x1 = *s1.begin();
			x2 = *(++s1.begin());
			x3 = *s4.rbegin();
			if (x1.first + x2.first < x3.first)
			{
				now -= x3.first;
				now += x1.first + x2.first;
				s1.erase(x1), s1.erase(x2);
				s3.insert(x1), s3.insert(x2);
				s4.erase(x3), s2.insert(x3);
			}
			
			else
				break;
		}
		
		while (s3.size() > 1 && s2.size())
		{
			pair <int, int> x1, x2, x3;
			x1 = *(--s3.end());
			x2 = *(--(--s3.end()));
			x3 = *s2.begin();
			if (x1.first + x2.first > x3.first)
			{
				now += x3.first;
				now -= x1.first + x2.first;
				s3.erase(x1), s3.erase(x2);
				s1.insert(x1), s1.insert(x2);
				s2.erase(x3), s4.insert(x3);
			}
			
			else
				break;
		}
		
		if (ans == now)
		{
			for (it = s1.begin(); it != s1.end(); ++it)
				sel[it->second] = 1;
			for (it = s3.begin(); it != s3.end(); ++it)
				sel[it->second] = 2;
			for (it = s4.begin(); it != s4.end(); ++it)
				sel[-it->second] = 2;
			for (i = 1; i <= n; i++)
				printf("%d", sel[i]);
			printf("\n");
			return 0;
		}
	}
	
	return 0;
}