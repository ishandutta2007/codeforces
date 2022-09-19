# include <cstdio>
# include <set>
# include <algorithm>
using namespace std;
set <int> bounds;
# define SIZE (1<<17)
long long sum[2*SIZE];
long long fall[2*SIZE];
void drop(int x, int len)
{
	fall[2*x]+=fall[x];
	fall[2*x+1]+=fall[x];
	sum[2*x+1]+=fall[x]*len/2;
	sum[2*x]+=fall[x]*len/2;
	fall[x]=0;
}
# define st_para 1, 0, SIZE-1
void add(int l, int r, long long int val, int wh, int lb, int rb)
{
// 	if (wh==1)
// 	{
// 		printf("add %d on %d-%d\n", val, l, r);
// 	}
	if (r<lb || l>rb)
		return;
	if (lb>=l && rb<=r)
	{
		sum[wh]+=val*(rb-lb+1);
		fall[wh]+=val;
	}
	else
	{
		add(l, r, val, wh*2, lb, (lb+rb)/2);
		add(l, r, val, wh*2+1, (lb+rb)/2+1, rb);
		sum[wh]+=val*(min(r, rb)-max(l, lb)+1);
	}
}
long long sum_ran(int l, int r, int wh, int lb, int rb)
{
	if (r<lb || l>rb)
		return 0;
	if (lb>=l && rb<=r)
		return sum[wh];
	else
	{
		drop(wh, (rb-lb+1));
		return sum_ran(l, r, wh*2, lb, (lb+rb)/2)+sum_ran(l, r, wh*2+1, (lb+rb)/2+1, rb);
	}
}
int color[100000];
int main()
{
	int len, amo;
	scanf("%d%d", &len, &amo);
	for (int i=1; i<=len+1; ++i)
		bounds.insert(i);
	for (int i=1; i<=len; ++i)
		color[i]=i;
	for (int i=0; i<amo; ++i)
	{
// 		printf("i=%d\n", i);
		int type;
		scanf("%d", &type);
		if (type==1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			set <int>::iterator it=bounds.upper_bound(l);
			it--;
			int pre=*it;
			it++;
// 			printf("before\n");
			add(l, min(r, *it-1), abs(x-color[pre]), st_para);
// 			printf("in while\n");
			while (*it<=r)
			{
				int curr=*it;
				it++;
				int next=*it;
				add(curr, min(r, next-1), abs(x-color[curr]), st_para);
			}
			it--;
			if (bounds.find(r+1)==bounds.end())
				color[r+1]=color[*it];
			color[l]=x;
			bounds.erase(bounds.upper_bound(l), bounds.upper_bound(r+1));
			bounds.insert(l);
			bounds.insert(r+1);
// 			for (set <int>::iterator it=bounds.begin(); it!=bounds.end(); ++it)
// 				printf("%d ", *it);
// 			putchar(10);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%I64d\n", sum_ran(l, r, st_para));
		}
	}
}