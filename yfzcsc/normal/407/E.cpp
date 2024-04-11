#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const int inf = 1e9;

struct Node
{
	int lz,minm;
}tr[N*4];


void up(int o)
{
	if (o)
	{
		tr[o].minm = min( tr[o<<1].minm , tr[o<<1|1].minm );
	}
}

void pushdown(int o)
{
	if (o && tr[o].lz)
	{
		tr[o<<1].minm += tr[o].lz;
		tr[o<<1|1].minm += tr[o].lz;
		tr[o<<1].lz += tr[o].lz;
		tr[o<<1|1].lz += tr[o].lz;
		tr[o].lz = 0;
	}
}
void modify(int o,int l,int r,int ql,int qr,int val)
{
	if (ql <= l && r <= qr)
	{
		tr[o].minm += val;
		tr[o].lz+=val;
		return ;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (ql <= mid)modify(o<<1  ,l    ,mid,ql,qr,val);
	if (mid < qr )modify(o<<1|1,mid+1,r  ,ql,qr,val);
	up(o);
}


int query(int o,int l,int r,int ql,int qr,int val)
{
	if (ql > qr) return -1;
	if (tr[o].minm > val) return -1;
	if ( l == r ){ return l;}

	pushdown(o);
	int mid = l + r >> 1;
	if (qr <= mid){ return query(o<<1,l,mid,ql,qr,val);}
	else if (mid < ql) { return query(o<<1|1,mid+1,r,ql,qr,val);}
	else
	{
		int tmp = query(o<<1,l,mid,ql,qr,val);
		if (tmp==-1) tmp = query(o<<1|1,mid+1,r,ql,qr,val);
		return tmp;
	}
}


int len,ans;

void update(int l,int r)
{
	int Len = r - l + 1;
	if (Len > len ) {len = Len;ans =l; }
	if (Len == len ){ if (ans > l) ans = l;}
}


int Min[N] , Max[N] ,  p1  ,  p2;
map <int,int> last;

int n,d,k;
int a[N];
void solve(int L,int R)
{
	p1 = p2 = 0;last.clear();Min[p1] = Max[p2] = L - 1;  int tmp = (a[L] % d + d) % d;
	for (int i = L; i <= R; i++)
{
if (a[i] > 0) {
			a[i] /= d;
		} else if (a[i] < 0) {
			a[i] = -(-a[i] - 1) / d - 1;
		}

}
//	puts("nan");
	int toleft=L;
	for (int i=L;i<=R;i++)
	{

		while ( p1 && a [ Min[p1] ] > a[ i ])
		{
			modify(1,1,n,Min[p1-1]+1,Min[p1],-a[i] + a[Min[p1]]);
			p1--;
		}
		Min[++p1] = i;


		while ( p2 && a [ Max[p2] ] < a[ i ])
		{
			modify(1,1,n,Max[p2-1]+1,Max[p2],a[i] - a[Max[p2]]  );
			p2--;
		}
		Max[++p2] = i;

		modify(1,1,n,i,i,i);
		if (last [ a[i] ] ) toleft = max(toleft , last[ a[i] ] +1); last[ a[i] ] = i;
		int pos = query(1,1,n,toleft,i,k+i);
		if (~pos) update(pos,i);
		//printf("gay %d %d now len %d val %d\n",i,toleft,pos,tr[2].minm);

	}

}

int read() {
	int w = 1, q = 0, ch = ' ';
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
	return q * w;
}
int toaddmin=inf;
int main()
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&k,&d);
	for (int i=1;i<=n;i++) a[i]=read(),toaddmin = min(a[i],toaddmin);
    for (int i=1;i<=n;i++)a[i]-=toaddmin;
	  if (n == 1) {
    puts("1 1");
    return 0;
  }
	if (d == 0)
	{
		int L = 0, R = 0;
		while (L <= n)
		{
			L++;
			R = L;
			while (R < n && a[R + 1] == a[L]) R++;
			update(L, R);
			L = R;
		}
		printf("%d %d\n", ans, ans+len-1);
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		int r = i;
		while ( r <= n && a[i]%d==a[r]%d) r++;
		solve(i,r-1);
//		printf("%d %d\n",i,r);
		i = r-1;
	}
	printf("%d %d",ans,ans+len-1);
	return 0;
}