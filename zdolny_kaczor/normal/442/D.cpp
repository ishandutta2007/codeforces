# include <cstdio>
# include <vector>
using namespace std;
# define MN 1000001
vector <int> down[MN];
int res[MN];
int check(int a)
{
// 	printf("try %d\n", a);
	for (int where=a; where>=0; --where)
	{
// 		printf("in %d\n", where);
		int maxx=-1, amo=2;
		for (int i=0; i<down[where].size() && down[where][i]<=a; ++i)
		{
// 			printf("down_res=%d\n", res[down[where][i]]);
			if (res[down[where][i]]==maxx)
				amo++;
			else if (res[down[where][i]]>maxx)
			{
				maxx=res[down[where][i]];
				amo=1;
			}
		}
// 		printf("m=%d a=%d\n", maxx, amo);
		if (maxx==-1)
		{
			if (where==0)
				res[where]=0;
			else
				res[where]=1;
		}
		else if (amo>1 && where>0)
			res[where]=maxx+1;
		else
			res[where]=maxx;
// 		printf("res[wh]=%d\n", res[where]);
	}
	return res[0];
}
void print(int left, int right, int lb, int ub)
{
// 	printf("%d-%d from %d-%d\n", left, right, lb, ub);
	if (right<=left)
		return;
	if (lb==ub)
	{
		for (int i=left; i<right; ++i)
			printf("%d ", lb);
		return;
	}
	int med=(left+right)/2;
	int medres=check(med);
	print(left, med, lb, medres);
	printf("%d ", medres);
	print(med+1, right, medres, ub);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d", &x);
		x--;
		down[x].push_back(i);
	}
	print(1, n+1, 0, 100);
	printf("\n");
}