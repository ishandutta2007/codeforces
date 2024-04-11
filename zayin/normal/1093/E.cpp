#include<bits/stdc++.h>
#define op(i)   Q[i].op
#define la(i)   Q[i].la
#define ra(i)   Q[i].ra
#define lb(i)   Q[i].lb
#define rb(i)   Q[i].rb
#define ALL(A)  A.begin(),A.end()
#define maxn 200050
using namespace std;

struct node
{
    int op,la,ra,lb,rb;
}   Q[maxn];

int n,m;

int tb[maxn];
int a[maxn],b[maxn];
int pa[maxn],pb[maxn];

vector<int> pos[maxn],T[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void insert(int x,int y)
{
    for (int tx=x;tx<=n;tx+=lowbit(tx))
        pos[tx].push_back(y);
}

void init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),pa[a[i]]=i;
    for (int i=1;i<=n;++i)
        scanf("%d",b+i),pb[b[i]]=i;
    
    for (int i=1;i<=n;++i)
        insert(pa[i],pb[i]);
    memcpy(tb,b,sizeof(b));
    for (int k=1;k<=m;++k)
    {
        scanf("%d",&op(k));
        if (op(k)==1)
        {
            scanf("%d%d%d%d",&la(k),&ra(k),&lb(k),&rb(k));
            // pos[ra(k)].push_back(rb(k));
            // pos[ra(k)].push_back(lb(k)-1);
            // pos[la(k)-1].push_back(rb(k));
            // pos[la(k)-1].push_back(lb(k)-1);
        }   else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            la(k)=x,lb(k)=y;
            swap(tb[x],tb[y]);
            swap(pb[tb[x]],pb[tb[y]]);
            insert(pa[tb[x]],x);
            insert(pa[tb[y]],y);
            // pos[pa[tb[x]]].push_back(x);
            // pos[pa[tb[y]]].push_back(y);
        }
    }
    for (int i=1;i<=n;++i)
    {
        pos[i].push_back(0);
        sort(pos[i].begin(),pos[i].end());
        pos[i].resize(unique(pos[i].begin(),pos[i].end())-pos[i].begin());
        T[i].resize(pos[i].size(),0);

        // cout<<i<<"("<<pos[i].size()<<","<<T[i].size()<<"):";
        // for (int j:pos[i])
        //     cout<<j<<" ";
        // cout<<endl;
    }
}

void change(int x,int y,int d)
{
    // cout<<"change:"<<x<<" "<<y<<" "<<d<<endl;
    for (int tx=x;tx<=n;tx+=lowbit(tx))
    {
        // cout<<"in_c:"<<tx<<" "<<lower_bound(ALL(pos[tx]),y)-pos[tx].begin()<<endl;
        for (int ty=lower_bound(ALL(pos[tx]),y)-pos[tx].begin();ty<pos[tx].size();ty+=lowbit(ty))
            // cout<<"ch:"<<tx<<" "<<ty<<" "<<d<<endl,
            T[tx][ty]+=d;
    }
}

int query(int x,int y)
{
    if (!x||!y) return 0;
    // cout<<"query:"<<x<<" "<<y<<endl;
    int ans=0;
    for (int tx=x;tx;tx-=lowbit(tx))
    {
        // cout<<tx<<" "<<upper_bound(ALL(pos[tx]),y)-pos[tx].begin()-1<<endl;
        for (int ty=upper_bound(ALL(pos[tx]),y)-pos[tx].begin()-1;ty>0;ty-=lowbit(ty))
            // cout<<"query:"<<tx<<" "<<ty<<" "<<T[tx][ty]<<endl,
            ans+=T[tx][ty];
    }
    // cout<<endl;
    return ans;
}

int Query(int lx,int rx,int ly,int ry)
{
    return query(rx,ry)-query(rx,ly-1)-query(lx-1,ry)+query(lx-1,ly-1);
}

void solve()
{
    for (int i=1;i<=n;++i)
        change(pa[b[i]],i,1);
    for (int k=1;k<=m;++k)
    {
        // cout<<"opt:"<<k<<endl;
        if (op(k)==1)
            printf("%d\n",Query(la(k),ra(k),lb(k),rb(k)));
        else
        {
            int x=la(k),y=lb(k);
            change(pa[b[x]],x,-1);
            change(pa[b[y]],y,-1);

            swap(b[x],b[y]);

            change(pa[b[x]],x,1);
            change(pa[b[y]],y,1);
        }
    }
}

int main()
{
    init();
    solve();
    return 0;
}