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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a1,t1,p1,a2,t2,p2,f,T,t0;

const ll INF = ll(1e18);
ll mult(ll a, ll b)
{
	if(b==0) return 0;
	if(a>INF/b) return INF;
	return (a*b);
}

ll add(ll a, ll b)
{
	a+=b;
	if(a>=INF) a=INF;
	return a;
}

ll X;
ll Y;
ll T2;
ll T1;
bool check(ll x, ll y)
{
	ll totaltime = add(X,mult(y,T2));
	ll fileload1 = mult(a1,x);
	ll fileload2 = mult(a2,y);
	if(fileload1>=f)
	{
		totaltime=mult(f,t1);
		if(totaltime>T) return false;
		else return true;
	}
	else if(fileload1+fileload2>=f)
	{
		totaltime=mult(x,T1);
		fileload2 = f - fileload1;
		totaltime+=mult(fileload2,t2);
		if(totaltime>T) return false;
		else return true;
	}
	if(totaltime>T) return false;
	ll remtime = T - totaltime;
	ll extrafile = remtime/t0;
	ll totalfile = extrafile + mult(x,a1) + mult(y,a2);
	if(totalfile<f) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>f>>T>>t0>>a1>>t1>>p1>>a2>>t2>>p2;
	if(t1>t2)
	{
		swap(a1,a2); swap(t1,t2); swap(p1,p2);
	}
	ll y = 10000000;
	if(t1>=t0)
	{
	    if(mult(f,t0)<=T)
	    {
	        cout<<0<<'\n';
	    }
	    else
	    {
	        cout<<-1<<'\n';
	    }
	    return 0;
	}
	if(t2>=t0)
	{
		y = 0;
	}
	ll bestp = ll(5e18);
	T2 = mult(t2,a2);
	T1 = mult(t1,a1);
	for(ll x = 0; x <= 10000000; x++)
	{
	    X = mult(x,T1);
	    if(X>T) y=0;
	    ll pricex = mult(x,p1);
	    if(bestp<pricex) break;
	    while(y>0&&add(X,mult(y-1,T2))>T)
		{
			y--;
		}
		
		//cout<<x<<' '<<y<<'\n';
		while(y>0&&check(x,y-1))
		{
			y--;
			bestp=min(bestp,add(pricex,mult(y,p2)));
		}
		if(check(x,y))
		{
			bestp=min(bestp,add(pricex,mult(y,p2)));
		}
		if(X>T) break;
	}
	if(bestp>ll(1e17)) cout<<-1<<'\n';
	else cout<<bestp<<'\n';
}