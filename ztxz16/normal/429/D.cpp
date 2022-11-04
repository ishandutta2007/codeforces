/**
O(n*logn*logn)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const long double INF = 1e20;
const int N = 100005;

struct Point
{
    long double x;
    long double y;
}point[N];
int n;
int tmpt[N];

bool cmpxy(const Point& a, const Point& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(const int& a, const int& b)
{
    return point[a].y < point[b].y;
}

long double min(long double a, long double b)
{
    return a < b ? a : b;
}

long double dis(int i, int j)
{
    return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)
                + (point[i].y-point[j].y)*(point[i].y-point[j].y));
}

long double Closest_Pair(int left, int right)
{
    long double d = INF;
    if(left==right)
        return d;
    if(left + 1 == right)
        return dis(left, right);
    int mid = (left+right)>>1;
    long double d1 = Closest_Pair(left,mid);
    long double d2 = Closest_Pair(mid+1,right);
    d = min(d1,d2);
    int i,j,k=0;
    //d
    for(i = left; i <= right; i++)
    {
        if(fabs(point[mid].x-point[i].x) <= d)
            tmpt[k++] = i;
    }
    sort(tmpt,tmpt+k,cmpy);
    //
    for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k && point[tmpt[j]].y-point[tmpt[i]].y<d; j++)
        {
            long double d3 = dis(tmpt[i],tmpt[j]);
            if(d > d3)
                d = d3;
        }
    }
    return d;
}

int x, s[100005];

int main()
{
    while(true)
    {
        n = 0, scanf("%d",&n);
        if(n==0)
            break;
        for (int i = 1; i <= n; i++)
        	scanf("%d", &x), s[i] = s[i - 1] + x;
        for(int i = 0; i < n; i++)
            point[i].x = i + 1, point[i].y = s[i + 1];
        sort(point,point+n,cmpxy);
        long double ans = Closest_Pair(0, n - 1);
        printf("%d\n", (int)(ans * ans + 1e-9));
    }
    return 0;
}