#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

struct point
{
	string str;
	int id;
	
	friend int operator < (point a, point b)
	{
		return b.str < a.str;
	}
}Now, New;

PQ <point> p;

string empty;
char str[100005];
int i, k, len;
long long x;

int main()
{
	gets(str + 1);
	scanf("%d", &k);
	for (i = 1; str[i] != 0; i++)
	{
		Now.str = empty + str[i];
		Now.id = i;
		p.push(Now);
	}
	
	len = i - 1;
	x = len;
	x *= (len + 1);
	x /= 2;
	if (x < k)
	{
		printf("No such line.\n");
		return 0;
	}
	
	while (k > 1)
	{
		k--;
		Now = p.top();
		p.pop();
		if (Now.id != len)
		{
			Now.str += str[Now.id + 1];
			Now.id++;
			p.push(Now);
		}
	}
	
	cout << p.top().str << endl;
	return 0;
}