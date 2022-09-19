# include <cstdio>
# include <set>
# include <cstring>
# define SIZE (1<<18)
using namespace std;
struct vertex
{
	int amo;
	long long int sum[5];
	vertex()
	{
		amo=0;
		for (int i=0; i<5; ++i)
			sum[i]=0;
	}
	vertex(int a)
	{
		amo=1;
		sum[0]=a;
		for (int i=1; i<5; ++i)
			sum[i]=0;
	}
};
vertex operator* (vertex a, vertex b)
{
	vertex res;
	res.amo=a.amo+b.amo;
	for (int i=0; i<5; ++i)
		res.sum[i]=a.sum[i]+b.sum[(5+i-a.amo%5)%5];
	return res;
}
vertex tree[2*SIZE];
set <int> in;
enum
{
	DEL,
	ADD,
	SUM,
};
struct query_t
{
	char type;
	int x;
}
queries[100000];
int scale[100000];
int amo;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		char comm[6];
		scanf("%s", comm);
		if (strcmp(comm, "del")==0)
			queries[i].type=DEL;
		else if (strcmp(comm, "add")==0)
			queries[i].type=ADD;
		else
			queries[i].type=SUM;
		if (queries[i].type!=SUM)
		{
			int x;
			scanf("%d", &x);
			queries[i].x=x;
			in.insert(x);
		}
	}
// 	printf("done\n");
	for (set <int>::iterator it=in.begin(); it!=in.end(); ++it)
		scale[amo++]=*it;
// 	for (int i=0; i<amo; ++i)
// 		printf("s[i]=%d\n", scale[i]);
	for (int i=0; i<n; ++i)
	{
		if (queries[i].type==SUM)
			printf("%I64d\n", tree[1].sum[2]);
		else
		{
			int min=0, max=amo-1, med;
			int sea=queries[i].x;
// 			printf("sea=%d\n", sea);
			while (min<=max)
			{
				med=(min+max)/2;
				if (scale[med]==sea)
					break;
				else if (scale[med]>sea)
					max=med-1;
				else
					min=med+1;
			}
// 			printf("edit %d\n", med);
			if (queries[i].type==ADD)
				tree[med+SIZE]=vertex(sea);
			else
				tree[med+SIZE]=vertex();
			int wh=(med+SIZE)/2;
			while (wh)
			{
				tree[wh]=tree[wh*2]*tree[wh*2+1];
				wh/=2;
			}
		}
	}
}