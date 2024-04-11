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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD=1e9+7;

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

const int maxn = 1e6+ 1, sigma = 26;
int len[maxn], link[maxn], to[maxn][sigma];
int slink[maxn], diff[maxn], series_ans[maxn];
int sz, last, n;
char s[maxn];
 
void init()
{
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    sz = 2;
}
 
int get_link(int v)
{
    while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
    return v;
}
 
void add_letter(char c)
{
    s[n++] = c -= 'a';
    last = get_link(last);
    if(!to[last][c])
    {
        len[sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        diff[sz] = len[sz] - len[link[sz]];
        if(diff[sz] == diff[link[sz]])
            slink[sz] = slink[link[sz]];
        else
            slink[sz] = link[sz];
        to[last][c] = sz++;
    }
    last = to[last][c];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	string s2 = s;
	int n=s.length();
	string t;
	for(int i=0;i<n/2;i++)
	{
		t+=s[i];
		t+=s[n-1-i];
	}
	//build pal tre for t
	init();
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        add_letter(t[i - 1]);
        for(int v = last; len[v] > 0; v = slink[v])
        {
            series_ans[v] = ans[i - (len[slink[v]] + diff[v])];
            if(diff[v] == diff[link[v]])
                series_ans[v] = add(series_ans[v], series_ans[link[v]]);
            ans[i] = add(ans[i], series_ans[v]);
        }
        if(i&1) ans[i]=0;
    }
    cout<<ans[n]<<'\n';
}