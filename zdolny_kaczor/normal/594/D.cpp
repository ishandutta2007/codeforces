# include <cstdio>
# include <algorithm>
# include <vector>
# define div costamcostam
using namespace std;
const int MOD=1e9+7;
long long ext(int a, int b, long long &x, long long &y)
{
	if (b==0)
	{
		x=y=1;
		return a;
	}
	long long dx, dy;
	long long ret = ext(b, a%b, dx, dy);
	x=dy;
	y=dx-dy*(a/b);
	return ret;
}
long long inv(int a)
{
	long long r, x;
	ext(a, MOD, r, x);
	r%=MOD;
	if (r<0)
		return MOD+r;
	else
		return r;
}
const int SIZE = 1<<18;
const int MV = 1000*1000+20;
long long premul[SIZE];
int a[SIZE];
int div[MV];
vector <int> poses[MV];
struct event
{
	bool mul;
	int time;
	int x, y;
	long long val;
	event(int b, int c, int d, long long e)
	{
		mul=true;
		time=b;
		x=c;
		y=d;
		val=e;
	}
	event(int b, int c, int d)
	{
		mul=false;
		time=b;
		x=c;
		y=d;
	}
};
vector <event> events;//najpierw mno a potem obliczam wyniki
void mulr(int l, int r, int val, int valinv)
{
// 	printf("mul %d-%d *=%lld=1/%lld\n", l, r, val, valinv);
	if (l<=r)
	{
		events.push_back(event(l, l, r, val));
		events.push_back(event(r+1, l, r, valinv));
	}
}
void addq(int nr, int x, int y)
{
	events.push_back(event(y, x, nr));
}
long long tree[2*SIZE];
void tinit()
{
	for (int i=1; i<2*SIZE; ++i)
		tree[i]=1;
}
void multiply(int l, int r, long long val, int wh=1, int lb=0, int rb=SIZE-1)
{
// 	if (wh==1)
// 		printf("mul %d-%d * %lld\n", l, r, val);
	if (l>rb || r<lb)
		return;
	if (l<=lb && r>=rb)
	{
		tree[wh]=tree[wh]*val%MOD;
		return;
	}
	multiply(l, r, val, wh*2, lb, (lb+rb)/2);
	multiply(l, r, val, wh*2+1, (lb+rb)/2+1, rb);
}
long long read(int pos)
{
// 	printf("read %d\n", pos);
	long long res=1;
	pos += SIZE;
	while (pos)
	{
		res=res*tree[pos]%MOD;
		pos/=2;
	}
	return res;
}
long long ans[SIZE];
void solve()
{
	tinit();
	sort(events.begin(), events.end(),
			 [](event a, event b)
			 {
				 return make_pair(a.time, !a.mul) < make_pair(b.time, !b.mul);
			 }
	);
	for (auto ev : events)
	{
// 		printf("time = %d\n", ev.time);
		if (ev.mul)
			multiply (ev.x, ev.y, ev.val);
		else
		{
// 			printf("q nr %d\n", ev.y);
			ans[ev.y] *= read (ev.x);
			ans[ev.y] %= MOD;
		}
	}
}
int main()
{
	int n, q;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", a+i);
	premul[0]=1;
	for (int i=1; i<=n; ++i)
		premul[i]=premul[i-1]*a[i]%MOD;
	for (int p=2; p<MV; ++p)
		if (div[p]==0)
			for (int k=p; k<MV; k+=p)
				div[k]=p;
	for (int i=1; i<=n; ++i)
	{
		int curr=a[i];
		while (curr>1)
		{
			int p = div[curr];
			while (curr % p == 0)
				curr/=p;
			poses[p].push_back(i);
		}
	}
	long long resmul=1;
	for (int p=2; p<MV; ++p)
		if (poses[p].size())
		{
// 			printf("found %d\n", p);
			long long recmul = inv (p-1) * p %MOD;
			long long allmul = inv (recmul);
			resmul = resmul*allmul%MOD;
			int pre = 1;
			for (int x : poses[p])
			{
				mulr (pre, x-1, recmul, allmul);
				pre = x+1;
			}
			mulr(poses[p].back()+1, n, recmul, allmul);
		}
	scanf("%d", &q);
	for (int i=0; i<q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		addq(i, a, b);
		ans[i]=resmul * premul[b] % MOD * inv(premul[a-1]) % MOD;
// 		printf("ans[%d](%d-%d)=%lld*%lld = %lld\n", i, a, b, resmul, premul[b]*inv(premul[a-1])%MOD, ans[i]);
	}
	solve();
	for (int i=0; i<q; ++i)
		printf("%I64d\n", ans[i]);
}