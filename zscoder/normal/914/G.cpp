#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD = 1e9 + 7;

int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int F[211111];
int cnt[211111];
int cnt1[211111];

int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}

void xorfft(vi &data, bool inverse = 0) {
	int dim = (1<<17);
    for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];
                
                data[i + j] = add(a,b);
                data[i + j + len] = add(a, MOD - b);
            }   
        }
    }
    if(inverse)
    {
		int invP = modpow(dim, MOD - 2);
		for(int i=0;i<dim;i++)
		{
			data[i]=mult(data[i],invP);
		}
	}
}

void andfft(vi &data, bool inverse = 0)
{
	int dim = (1<<17);
	for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];
                
                if(!inverse)
                {
					data[i+j] = b;
					data[i+len+j] = add(a, b);
				}
				else
				{
					data[i + j] = add(MOD-a,b);
					data[i + j + len] = a;
				}
			}
        }
    }
}

vi xormult(vi &a, vi &b)
{
	vi c(1<<17,0);
	xorfft(a); xorfft(b);
	for(int i=0;i<(1<<17);i++)
	{
		c[i] = mult(a[i],b[i]);
	}
	xorfft(c,1);
	return c;
}

vi andmult(vi &a, vi &b)
{
	vi c(1<<17,0);
	andfft(a); andfft(b);
	for(int i=0;i<(1<<17);i++)
	{
		c[i] = mult(a[i],b[i]);
	}
	andfft(c,1);
	return c;
}

int main()
{
	F[0]=0;F[1]=1;
	for(int i=2;i<=200000;i++) F[i]=add(F[i-1],F[i-2]);
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x); cnt[x]++;
	}
	for(int superset=0;superset<(1<<17);superset++)
	{
		int i = superset;
		for(;;i=(i-1)&superset)
		{
			cnt1[superset] = add(cnt1[superset], mult(cnt[i], cnt[superset^i]));
			if(i==0) break;
		}
	}
	vi V1,V2;
	for(int i=0;i<(1<<17);i++) V1.pb(mult(F[i], cnt1[i]));
	for(int i=0;i<(1<<17);i++) V2.pb(mult(F[i], cnt[i]));
	vi LHS = andmult(V1, V2);
	vi V3,V4;
	for(int i=0;i<(1<<17);i++)
	{
		V3.pb(cnt[i]); V4.pb(cnt[i]);
	}
	vi RHS = xormult(V3, V4);
	for(int i=0;i<(1<<17);i++)
	{
		RHS[i] = mult(RHS[i], F[i]);
	}
	vi tmp = andmult(LHS, RHS);
	int ans = 0;
	for(int i=0;i<17;i++)
	{
		ans=add(ans,tmp[(1<<i)]);
	}
	cout<<ans<<'\n';
}