#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef complex<double> base;
const double PI = 3.14159265359;
void fft(vector<base>& a, bool inv)
{
	int n = int(a.size());
	if(n == 1) return ;
	vector<base> l(n/2), r(n/2);
	for(int i = 0, j = 0; i < n; i += 2, ++j)
	{
		l[j] = a[i];
		r[j] = a[i + 1];
	}
	//l contains the even polynomial, r contains the odd polynomial
	fft(l, inv); fft(r, inv);
	double ang = 2*PI/n;
	if(inv) ang*=-1;
	base w(1); 
	base rt(cos(ang), sin(ang));
	for(int i = 0; i < n/2; i++)
	{
		a[i] = l[i] + w*r[i];
		a[i+n/2] = l[i] - w*r[i];
		if(inv)
		{
			a[i] /= 2; a[i+n/2] /= 2;
		}
		w *= rt;
	}
}

void mult(vector<ll> &a, vector<ll> &b, vector<ll> &r)
{
	int n = 1;
	while(n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	vector<base> ffa; vector<base> ffb;
	base zero(0);
	ffa.assign(n, zero); ffb.assign(n, zero);
	/*
	for(int i = n - a.size(); i < n; i++)
	{
		ffa[i] = a[i-(n-a.size())];
	}
	for(int i = n - b.size(); i < n; i++)
	{
		ffb[i] = b[i-(n-b.size())];
	}
	reverse(ffa.begin(), ffa.end());
	reverse(ffb.begin(), ffb.end());
	*/
	for(int i=0;i<a.size();i++) ffa[i]=a[i];
	for(int i=0;i<b.size();i++) ffb[i]=b[i];
	/*
	for(int i=0;i<ffa.size();i++)
	{
		if(ffa[i]!=zero) cerr<<"A "<<i<<' '<<ffa[i]<<'\n';
	}
	for(int i=0;i<ffb.size();i++)
	{
		if(ffb[i]!=zero) cerr<<"B "<<i<<' '<<ffb[i]<<'\n';
	}
	*/
	fft(ffa, 0); fft(ffb, 0); //fft
	for(int i = 0; i < n; i++)
	{
		ffa[i] *= ffb[i]; //convolution
	}
	fft(ffa, 1); //inverse fft
	r.resize(n);
	for(int i = 0; i < n; i++)
	{
		r[i] = ll(ffa[i].real() + 0.5);
	}
	//reverse(r.begin(), r.end());
}

int a[222222];
int cnt[222222];
ll res[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x; cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<x) a[i]=1;
		else a[i]=0;
		if(i>0) a[i]+=a[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		cnt[a[i]]++;
	}
	const int N = 200101;
	vi a(N+10,0); vi b(N+10,0);
	for(int i=0;i<=n;i++)
	{
		a[i] = cnt[i];
		b[N-i] = cnt[i];
		//cerr<<i<<' '<<cnt[i]<<'\n';
	}
	vi v;
	//cerr<<a.size()<<' '<<b.size()<<'\n';
	mult(a,b,v);
	for(int i=0;i<=n;i++)
	{
		res[i] = v[i+N];
		if(i==0) 
		{
			res[i]-=n+1; res[i]>>=1;
		}
	}
	for(int i=0;i<=n;i++)
	{
		cout<<res[i];
		if(i+1<=n) cout<<' ';
	}
	cout<<'\n';
}