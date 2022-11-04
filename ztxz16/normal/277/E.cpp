#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define eps 1e-9

using namespace std;

struct TP
{
	int x, y;
};

TP p[2005];
int n, i, j, en, tag, AA, hash[2005], map[2005][2005], pre[2005];
int e[4000005], succ[4000005], last[4000005], sum;
double v[2005][2005], DIS[2005], ans;

int cmp(TP a, TP b)
{
	if (a.y > b.y)
		return 1;
	return 0;
}

double dis(TP a, TP b);
void Add(int a, int b, int c, double val);
void dfs(int i);
void work();
void modi();
int bj(double a, double b);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, cmp);
	en = n + n + 1;
	for (i = 1; i <= n; i++)
	{
		Add(0, i, 1, 0);
		Add(n + i, en, 2, 0);
		for (j = i + 1; j <= n; j++)
		{
			if (p[j].y == p[i].y)
				continue;
			Add(j, n + i, 1, dis(p[i], p[j]));
		}
	}
	
	while (1) 
    { 
          tag++; 
          dfs(0); 
          if (hash[en]==tag) work(); 
          else modi(); 
    }
    
	return 0;
}

double dis(TP a, TP b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Add(int a,int b,int c,double val) 
{
     e[++sum]=b,succ[sum]=last[a],last[a]=sum; 
     e[++sum]=a,succ[sum]=last[b],last[b]=sum; 
     map[a][b]=c,v[a][b]=val,v[b][a]=0-val; 
     return; 
}

void dfs(int i) 
{ 
     int x,y; 
     hash[i]=tag; 
     for(x=last[i];x!=0;x=succ[x]) 
     { 
        y=e[x]; 
        if (bj(DIS[y], (DIS[i]+v[i][y])) == 0 
		&& hash[y]!=tag && map[i][y]>0) 
        pre[y]=i,dfs(y); 
     } 
     return; 
} 
  
void work() 
{ 
     int now;
	 int min; 
     min=1616161616; 
     for(now=en;now!=0;now=pre[now]) 
     {
        if (map[pre[now]][now]<min) min=map[pre[now]][now];
        //printf("%d ",now);
     }
     //printf("%d\n",min); 
     for(now=en;now!=0;now=pre[now]) 
     {
			ans+=(double)(min)*v[pre[now]][now];
			map[pre[now]][now]-=min,map[now][pre[now]]+=min;
	}
	AA += min;
     return; 
} 
  
void modi() 
{ 
     int i,x,y;
	 double min; 
     min=1e100; 
     for(i=0;i<=en;i++) 
     { 
        if (hash[i]==tag) 
        { 
           for(x=last[i];x!=0;x=succ[x]) 
           { 
              y=e[x]; 
              if (hash[y]==tag) continue; 
              if (DIS[i]+v[i][y]-DIS[y]<min && map[i][y]>0) 
              min=DIS[i]+v[i][y]-DIS[y]; 
           } 
        } 
     } 
     if (bj(min, 1e100) == 0) 
     {
			if (AA == n - 1)
				printf("%.10lf\n", ans);
			else
				printf("-1\n");
			exit(0);
     } 
     for(i=0;i<=en;i++) 
     if (hash[i]!=tag) DIS[i]+=min; 
     return; 
}

int bj(double a, double b)
{
	if (a - b > 0 - eps && a - b < eps)
		return 0;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
}