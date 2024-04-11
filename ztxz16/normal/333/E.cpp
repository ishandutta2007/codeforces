#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

struct point
{
	int x, y;
}p[3005], ListNow[3005], sta[3005];

int n, i, l, r, mid, top;

int cmp(point a, point b)
{
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

inline int dis(point a, point b);
inline int Cross(int x1, int y1, int x2, int y2);
inline int Cross(point a, point b, point c);
int check(int Ans);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, cmp);
	l = 1, r = 800000000;
	while (l < r)
	{
		mid = ((l + r + 1) >> 1);
		if (check(mid) == 1)
			l = mid;
		else
			r = mid - 1;
	}
	
	printf("%.10lf\n", sqrt((double)l) / 2.0);
	return 0;
}

inline int dis(point a, point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline int Cross(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}

inline int Cross(point a, point b, point c)
{
	return Cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}

int check(int Ans)
{
	int i, j, k, tot, Max, Now, Now1, Now2;
	for (i = 1; i <= n; i++)
	{
		tot = 0;
		for (j = 1; j <= n; j++)
			if (i != j && dis(p[i], p[j]) >= Ans)
				ListNow[++tot] = p[j];
		if (tot < 2)
			continue;
		top = 1;
		sta[1] = ListNow[1];
		for (j = 2; j <= tot; j++)
		{
			while (top > 1 && Cross(sta[top - 1], sta[top], ListNow[j]) <= 0)
				top--;
			sta[++top] = ListNow[j];
		}
		
		sta[++top] = ListNow[tot - 1];
		for (j = tot - 2; j >= 1; j--)
		{
			while (top > 1 && Cross(sta[top - 1], sta[top], ListNow[j]) <= 0)
				top--;
			sta[++top] = ListNow[j];
		}
		
		Max = 0;
		for (j = 1; j < top; j++)
		{
			Now1 = max(dis(sta[1], sta[j]), dis(sta[2], sta[j]));
			if (Now1 > Max)
				Max = Now1, Now = j;
		}
		
		for (j = 2; j < top; j++)
		{
			while (1)
			{
				Now1 = max(dis(sta[j], sta[Now]), dis(sta[j + 1], sta[Now]));
				Now2 = max(dis(sta[j], sta[Now % top + 1]), dis(sta[j + 1], sta[Now % top + 1]));
				if (Now2 > Now1)
					Now = Now % top + 1;
				else
					break;
			}
			
			Now1 = max(dis(sta[j], sta[Now]), dis(sta[j + 1], sta[Now]));
			if (Now1 > Max)
				Max = Now1;
		}
		
		if (Max >= Ans)
			return 1;
	}
	
	return 0;
}