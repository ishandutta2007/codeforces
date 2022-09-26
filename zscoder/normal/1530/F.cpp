#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int max_n = 1 << 23, mod = 31607;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

inline void amul(int &x, int y) {
	x*=y; x%=mod;
    /*
    int z = 0;
    while(y)
    {
		if(y&1) inc(z,x);
		inc(x,x);
		y>>=1;
	}
	return z;
	*/
}

int add(int x, int y)
{
	 x += y;
    while (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y)
{
	 x -= y;
    while (x < 0) {
        x += mod;
    }
    return x;
}

inline int mul(int x, int y) {
	return (x*y)%mod;
    /*
    int z = 0;
    while(y)
    {
		if(y&1) inc(z,x);
		inc(x,x);
		y>>=1;
	}
	return z;
	*/
}

/*
void transform(int n, int P[], bool inverse) 
{
    for (int len = 1; 2 * len <= n; len <<= 1) 
    {
        for (int i = 0; i < n; i += 2 * len) 
        {
            for (int j = 0; j < len; j++) 
            {
			
                if (!inverse) {
                    //P[i + j] = v; //add(u,v);
                   // P[i + len + j] = add(u,v); 
                   swap(P[i+j],P[i+len+j]);
                  // P[i+j]^=P[i+len+j];
                  // P[i+len+j]^=P[i+j];
					// P[i+j]^=P[i+len+j];
					inc(P[i+j],P[i+len+j]);
                   //P[i+j]=add(u,v);
                   //P[i+len+j]=u;
                } else {
					swap(P[i+j],P[i+len+j]);
					dec(P[i+len+j],P[i+j]);
                    //P[i + j] = v;
                    //P[i + len + j] = sub(u,v);
                }
            }
        }
    }
}
*/

void transform(int n, int a[], bool inverse) 
{
	/*
    for (int len = 1; 2 * len <= n; len <<= 1) 
    {
        for (int i = 0; i < n; i += 2 * len) 
        {
            for (int j = 0; j < len; j++) 
            {
			
                if (!inverse) {
                    //P[i + j] = v; //add(u,v);
                   // P[i + len + j] = add(u,v); 
                   swap(P[i+j],P[i+len+j]);
                  // P[i+j]^=P[i+len+j];
                  // P[i+len+j]^=P[i+j];
					// P[i+j]^=P[i+len+j];
					inc(P[i+j],P[i+len+j]);
                   //P[i+j]=add(u,v);
                   //P[i+len+j]=u;
                } else {
					swap(P[i+j],P[i+len+j]);
					dec(P[i+len+j],P[i+j]);
                    //P[i + j] = v;
                    //P[i + len + j] = sub(u,v);
                }
            }
        }
    }
    */
    if(n==0) return ;
    for (int i = 0; i < n / 2; ++i) {
        if (inverse) {
            //dec(a[i], a[i + n / 2]);
            swap(a[i],a[i+n/2]);
            dec(a[i+n/2],a[i]);
        } else {
			swap(a[i],a[i+n/2]);
			inc(a[i],a[i+n/2]);
            //inc(a[i], a[i + n / 2]);
        }
    }
    transform(n / 2, a, inverse);
    transform(n / 2, a + n / 2, inverse);
}

int a[32][32];
int b[32][32];
//int cur[4][(1<<21)+1]; 
int cur[(1<<23)+1];
int bruh[(1<<21)+1];
//int pre[2][4][(1<<21)+1]; //is (i,i) filled?, is the other one filled
int pre[(1<<23)+1];
//int nw[2][2][(1<<21)+1];
//everything is in its transformed variant
int bruh2[(1<<21)+1];

int lowbit[(1<<21)+2];
int invv[111111];

int modpow(int x, int y)
{
	int r=1;
	while(y)
	{
		if(y&1) r=mul(r,x);
		x=mul(x,x);y>>=1;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int iv=-1;
	for(int i=1;i<mod;i++)
	{
		if(mul(i,10000)==1){iv=i; break;}
	}
	//cerr<<iv<<'\n';
	for(int i=1;i<mod;i++) invv[i]=modpow(i,mod-2);
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) 
			{
				lowbit[i]=j; break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			a[i][j]=mul(a[i][j],iv);
			b[i][j]=a[i][j];
			a[i][j]=add(1,mod-a[i][j]); //complement
			amul(a[i][j],invv[b[i][j]]);
		}
	}
	int N=(1<<n)*4;
	pre[0] = 1; //the rest 0
	transform(N,pre,false);
	//ok now we get to the main topic
	for(int r=0;r<n;r++)
	{
		//for every row, let's see what we can do
		memset(cur,0,sizeof(cur));
		bruh[0]=1; //bruh2[0]=1;
		for(int i=0;i<n;i++) amul(bruh[0],b[r][i]);
		for(int i=1;i<(1<<n);i++)
		{
			//cerr<<i<<' '<<(i^(1<<lowbit[i]))<<'\n';
			bruh[i] = mul(bruh[i^(1<<lowbit[i])],a[r][lowbit[i]]); //bruh[i] is product of a's in these pos
			//bruh2[i] = mul(bruh2[i^(1<<lowbit[i])],b[r][lowbit[i]]); //bruh[i] is product of a's in these pos
		}
		for(int i=1;i<(1<<n);i++)
		{
			//compute cur[0/1][0/1][i]
			int x=0;
			int y=0;
			//x=1 if r is triggered
			if(i&(1<<r)) x=(1<<(n+1));
			//y=1 if n-1-r is triggered
			if(i&(1<<(n-1-r))) y=(1<<(n));
			cur[x^y^i]=bruh[i]; //mul(bruh[i],bruh2[((1<<n)-1)^i]);
			//cerr<<(x^y^i)<<' '<<cur[x^y^i]<<'\n';
		}
		cur[0]=0; //cannot be 0 tho!
		transform(N,cur,false);
		for(int m=0;m<N;m++)
		{
			amul(pre[m],cur[m]);
		}
	}
	transform(N,pre,true);
	int ans = pre[N-1];
	ans=add(1,mod-ans);
	cout<<ans<<'\n';
	//remember to 1 - the answer
}