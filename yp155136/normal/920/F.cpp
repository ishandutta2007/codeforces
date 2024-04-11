#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int d[N];

int a[N];

struct Node
{
    Node *lc,*rc;
    long long sum;
    bool tag;
    Node():lc(NULL),rc(NULL),sum(0),tag(true){}
    void pull()
    {
        sum = lc->sum + rc->sum;
        tag = (lc->tag & rc->tag);
    }
    void update()
    {
        if (sum == 1 || sum == 2) tag = true;
        else tag = false;
    }
};

Node* Build(int L,int R)
{
    Node* node = new Node();
    if (L==R)
    {
        node->sum = a[L];
        if (a[L] == 1 || a[L] == 2) node->tag = true;
        else node->tag = false;
        return node;
    }
    int mid=(L+R)>>1;
    node->lc = Build(L,mid);
    node->rc = Build(mid+1,R);
    node->pull();
    return node;
}

void modify(Node* node,int L,int R,int l,int r)
{
    if (l > R || L > r || node->tag) return;
    else if (L == R)
    {
        node->sum = d[ node->sum ];
        node->update();
        return;
    }
    int mid=(L+R)>>1;
    modify(node->lc,L,mid,l,r);
    modify(node->rc,mid+1,R,l,r);
    node->pull();
    return;
}

long long query(Node* node,int L,int R,int l,int r)
{
    if (l>R || L>r) return 0;
    else if (l<=L && R<=r) return node->sum;
    int mid=(L+R)>>1;
    return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int main ()
{
    for (int i=1;N>i;i++)
    {
        for (int j=i;N>j;j+=i)
        {
            ++d[j];
        }
    }
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    Node* root = Build(1,n);
    for (int i=1;q>=i;i++)
    {
        int t,l,r;
        scanf("%d %d %d",&t,&l,&r);
        if (t == 1) modify(root,1,n,l,r);
        else printf("%lld\n",query(root,1,n,l,r));
    }
}