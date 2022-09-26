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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int C = 100;
vector<pair<pair<int,int>,int> > queries;
int K[300001];
int a[300001];
int ans[300001];
int occ[300001];
const int BLOCK_SIZE = 400;
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

int rnd(int x)
{
	int z = (rand()<<15)^rand();
	z%=x;
	return z;
}

inline void add(int x)
{
    occ[x]++;
}

inline void del(int x)
{
    occ[x]--;
}


int main()
{
	srand(1419);
	int n,q; scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	queries.resize(q);
	for(int i=0;i<q;i++)
	{
		int l,r,k; scanf("%d %d %d",&l,&r,&k);
		l--; r--;
		K[i]=k;
		queries[i] = mp(mp(l,r),i);
	}
	
	memset(ans,-1,sizeof(ans));
	sort(queries.begin(),queries.end(),mo_cmp);
	
	int mo_left = 0, mo_right = -1;

    for(int i = 0; i < q; i++) 
    {
        int l = queries[i].fi.fi;
        int r = queries[i].fi.se;
        while(mo_right < r) {
            mo_right++;
            add(a[mo_right]);
        }
        while(mo_right > r) {
            del(a[mo_right]);
            mo_right--;
        }

        while(mo_left < l) {
            del(a[mo_left]);
            mo_left++;
        }
        while(mo_left > l) {
            mo_left--;
            add(a[mo_left]);
        }
		int tes = int(1e9);
		int k=K[queries[i].se];
        for(int j = 0; j < C; j++)
        {
			int f = rnd(r-l+1);
			f+=l;
			if(occ[a[f]]*k>r-l+1)
			{
				//cerr<<a[f]<<' '<<occ[a[f]]<<' '<<l<<' '<<r<<'\n';
				tes=min(tes,a[f]);
			}
		}
        if(tes>10000000) tes=-1;
        ans[queries[i].se] = tes;
    }
	for(int i=0;i<q;i++)
	{
		printf("%d\n",ans[i]);
	}
}