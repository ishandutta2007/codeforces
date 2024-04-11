# include <cstdio>
# include <algorithm>
using namespace std;
const int MN=500010;
pair <int, int> pos[MN];
const int SIZE=1<<19;
int tree[2*SIZE];
const int INF=1<<27;
void ins(int pos, int val)
{
	pos+=SIZE;
	tree[pos]=min(tree[pos], val);
	pos/=2;
	while (pos)
	{
		tree[pos]=min(tree[pos*2], tree[pos*2+1]);
		pos/=2;
	}
}
int rr(int l, int r, int wh, int lb, int rb)
{
	if (lb>r || rb<l)
		return INF;
	if (lb>=l && rb<=r)
		return tree[wh];
	return min(rr(l, r, wh*2, lb, (lb+rb)/2), rr(l, r, wh*2+1, (lb+rb)/2+1, rb));
}
const bool add=true, read=false;
struct event_t
{
	int pos;
	bool type;
	int end;
	int nr;
}
events[2*MN];
bool cmp(event_t a, event_t b)
{
	if (a.pos!=b.pos)
		return a.pos<b.pos;
	return a.type<b.type;
}
int res[MN];
int main()
{
	for (int i=1; i<2*SIZE; ++i)
		tree[i]=INF;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d", &x);
		pos[i-1]=make_pair(x, i);
	}
	sort(pos, pos+n);
	int last=0;
	for (int i=0; i<n-1; ++i)
		if (pos[i].first==pos[i+1].first)
		{
			events[last].pos=pos[i].second;
			events[last].end=pos[i+1].second;
			events[last].type=add;
			last++;
		}
	for (int i=0; i<m; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		events[last].pos=l;
		events[last].end=r;
		events[last].nr=i;
		events[last].type=read;
		last++;
	}
	sort(events, events+last, cmp);
	for (int i=last-1; i>=0; --i)
	{
		if (events[i].type==add)
		{
// 			printf("add %d-%d\n", events[i].pos, events[i].end);
			ins(events[i].end, events[i].end-events[i].pos);
		}
		else
		{
// 			printf("read %d-%d\n", events[i].pos, events[i].end);
			res[events[i].nr]=rr(0, events[i].end, 1, 0, SIZE-1);
		}
	}
	for (int i=0; i<m; ++i)
		if (res[i]==INF)
			printf("-1\n");
		else
			printf("%d\n", res[i]);
}