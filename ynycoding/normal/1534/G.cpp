#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
using std::priority_queue;
const int N=16000005;
int n, x[N], y[N], id[N], al, ar;
ll val;
priority_queue<int> ql, qr;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d", x+i, y+i);
		id[i]=i;
	}
	std::sort(id+1, id+n+1, [] (int a, int b) { return x[a]+y[a]<x[b]+y[b]; });
	for(int i=1, pr=0; i<=n; ++i)
	{
		int adv=x[id[i]]+y[id[i]]-pr, x=::x[id[i]]-y[id[i]];
		al-=adv, ar+=adv;
		if(x<al) val+=al-x, x=al;
		if(x>ar) val+=x-ar, x=ar;
		if(ql.empty()||x<=ql.top()+al)
		{
			ql.push(x-al), ql.push(x-al);
			qr.push(ar-(ql.top()+al));
			val+=std::abs(x-(ar-qr.top()));
			ql.pop();
		}
		else
		{
			qr.push(ar-x), qr.push(ar-x);
			ql.push((ar-qr.top())-al);
			val+=std::abs(x-(ql.top()+al));
			qr.pop();
		}
		pr+=adv;
	}
	printf("%lld\n", val/2);
	return 0;
}