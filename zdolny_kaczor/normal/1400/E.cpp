# include <cstdio>
# include <set>
using namespace std;
// # define SIZE (1<<5)
# define SIZE (1<<13)
pair <int, int> tree[SIZE*2];
int a[5000];
# define INF (1<<30)
pair <int, int> minr(int l, int r, int wh=1, int lb=0, int rb=SIZE-1)
{
// 		printf("%d-%d from %d (%d-%d)\n", l, r, wh, lb, rb);
    if (l>rb || r<lb)
        return make_pair(INF, INF);
    if (l<=lb && r>=rb)
        return tree[wh];
    return min(minr(l, r, wh*2, lb, (lb+rb)/2), minr(l, r, wh*2+1, (lb+rb)/2+1, rb));
}
int res(int l, int r, int hei)
{
// 		printf("res %d-%d (%d)\n", l, r, hei);
    if (l>=r)
        return 0;
    else
    {
        pair <int, int> mini=minr(l, r-1);
// 				printf("min(%d-%d)=(%d,%d)\n", l, r-1, mini.first, mini.second);
        return min(r-l, mini.first-hei+res(l, mini.second, mini.first)+res(mini.second+1, r, mini.first));
    }
}
int main()
{
		if (SIZE!=(1<<13))
			printf("ZMIE SIZE\n");
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        scanf("%d", a+i);
        tree[i+SIZE]=make_pair(a[i], i);
    }
		for (int i=n; i<SIZE; ++i)
			tree[i+SIZE]=make_pair(INF, 10000000);
    for (int i=SIZE-1; i; --i)
        tree[i]=min(tree[2*i], tree[2*i+1]);
		printf("%d\n", res(0, n, 0));
		if (SIZE!=(1<<13))
			printf("ZMIE SIZE\n");
}