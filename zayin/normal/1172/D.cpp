#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n;
int fr[maxn],tr[maxn];
int fc[maxn],tc[maxn];

void init() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  scanf("%d",tr+i),fr[tr[i]]=i;
    for (int i=1;i<=n;++i)  scanf("%d",tc+i),fc[tc[i]]=i;
}

struct node {
    int x,y;
    node(int _x=0,int _y=0) {
        x=_x,y=_y;
    }
};
vector<pair<node,node> > A;

void calc(int x)    {
    if (x==n)   return;
    if (tr[x]!=x||tc[x]!=x) {
        A.emplace_back(node(fr[x],x),node(x,fc[x]));
        tr[fr[x]]=tr[x],fr[tr[x]]=fr[x];
        tc[fc[x]]=tc[x],fc[tc[x]]=fc[x];
    }
    calc(x+1);
}

void solve()    {
    calc(1);
    printf("%d\n",A.size());
    for (auto p:A)
        printf("%d %d %d %d\n",p.first.x,p.first.y,p.second.x,p.second.y);
}

int main()  {
    init();
    if (n==1)
        puts("0");
    else
        solve();
    return 0;
}