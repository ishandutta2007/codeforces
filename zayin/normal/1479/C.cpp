#include<bits/stdc++.h>
using namespace std;

int n;
struct edge {
    int u,v,w;
};

int id[30];

vector<edge> E;
vector<pair<int,int> > G[30];

int vs=1,vmid=22,vt=23;

//vs=1,vt=22,mid=2~21

void join(int u,int v,int w)    {
    E.push_back(edge{u,v,w});
    G[u].emplace_back(v,w);
}

void build()    {
    join(vmid,vt,1);
    for (int i=21;i>=2;--i) {
        join(i,vt,1);
        for (int j=22;j>i;--j)
            join(i,j,1<<(22-j));
    }
}

vector<pair<int,int> > split(int l,int r)   {
    vector<pair<int,int> > res;
    function<void(int,int)> travel=[&](int a,int b)  {
        if (a>r||b<l) return ;
        // cout<<"travel:"<<a<<" "<<b<<endl;
        if (l<=a&&b<=r)
            res.emplace_back(a,b);
        else    {
            int mid=(a+b)>>1;
            travel(a,mid);
            travel(mid+1,b);
        }
    };
    travel(0,(1<<20)-1);
    return res;
}

int cnt[1<<24];

void dfs(int i,int offset)   {
    // cout<<i<<"("<<G[i].size()<<") "<<offset<<endl;
    if (i==vt)  {
        cout<<"dfs:"<<offset<<endl;
        ++cnt[offset];
    }
    else    {
        for (auto p:G[i])
            dfs(p.first,p.second+offset);
    }
}

void test(int l,int r) {
    dfs(vs,0);
    for (int i=0;i<(1<<22);++i)  {
        if (l<=i&&i<=r) {
            // cout<<i<<":"<<cnt[i]<<endl;
            assert(cnt[i]==1);
        }
        else
            assert(cnt[i]==0);
    }
}

int main()  {
    int L,R;
    cin>>L>>R;
    build();

    // auto I=split(L-1,R-1);
    if (L==1) join(vs,vt,1),++L;

    if (L<=R)   {
        int offset=L-1;
        for (int d=R-L+1,i=19;i>=0;--i)
            if (d>>i&1) {
                join(vs,22-i,offset);
                offset+=1<<i;
            }
    }

    // test(L,R);

    cout<<"YES"<<endl;
    cout<<23<<" "<<E.size()<<endl;
    for (edge e:E)
        cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;

    // dfs(21-0,0);
    // dfs(21-1,0);
    // dfs(21-2,0);
    return 0;
}