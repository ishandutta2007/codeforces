#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

const int N = 1e6 + 3;

struct node
{
    int idx;
    int val,l;
    int chk,idx1;
};

int dp[N+5];
int x[N+5];
node a[N*2+5];
int tree[N*8];
int ans[N];
unordered_map<int,int> arr;

bool cmp(const node &a,const node &b)
{
    if(a.idx==b.idx)
        return a.val>b.val;
    return a.idx < b.idx;
}

void update(int tl,int tr,int id,int pos,int val)
{
    if(tl>tr)
        return;
    int mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[id]^=val;
        return;
    }
    if(mid>=pos)
        update(tl,mid,id*2,pos,val);
    else
        update(mid+1,tr,id*2+1,pos,val);
    tree[id]=tree[id*2]^tree[id*2+1];
}
int query(int l,int r,int tl,int tr,int id)
{
    if(tl> tr || l>tr || tl>r)
        return 0;
    if(tl>=l && r>=tr)
        return tree[id];
    int mid=(tl+tr)/2;
    return query(l,r,tl,mid,id*2)^query(l,r,mid+1,tr,id*2+1);
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", x+i);
		a[i].idx = i;
		a[i].val = x[i];
		a[i].chk = 0;
		dp[i] = x[i]^dp[i-1];
	}
	int q, l, r;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		scanf("%d %d", &l, &r);
		a[i+n].idx = r;
        a[i+n].chk = 1;
        a[i+n].idx1 = i;
        a[i+n].l = l;
	}
	sort(a+1,a+n+q+1,cmp);
	for(int i=1;i<=n+q;i++)
    {
		//cout << i << ' ' << a[i].val << '\n';
        if(a[i].chk)
        {
			//cout << a[i].idx1 << ' ' << a[i].l << ' ' << a[i].idx << '\n';
            ans[a[i].idx1]=query(a[i].l,a[i].idx,1,n,1);
            //cout << ans[a[i].idx1] << '\n';
            ans[a[i].idx1]^=dp[a[i].idx];
            ans[a[i].idx1]^=dp[a[i].l-1];
            //cout << ans[a[i].idx1] << '\n';
        }
        else
        {
			//cout << "VAL : " << a[i].val << ' ' << a[i].idx << '\n';
            int num=a[i].val;
            if(arr[num]!=0)
            {
				update(1,n,1,arr[num],num);
			}
			update(1, n, 1, a[i].idx, num);
            arr[num]=a[i].idx;
        }
    }
    for(int i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
}