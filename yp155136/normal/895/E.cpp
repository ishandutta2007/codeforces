#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

typedef long double ld;
const int N = 1e5 + 6;

struct Node
{
    Node *lc,*rc;
    ld sum;
    ld tag1,tag2;
    bool have_tag;
    Node():lc(NULL),rc(NULL),sum(0),tag1(1),tag2(0),have_tag(0){}
    void pull()
    {
        sum = lc->sum + rc->sum;
    }
};

int a[N];

Node* Build(int L,int R)
{
    Node* node = new Node();
    if (L==R)
    {
        node->sum = a[L];
        return node;
    }
    int mid=(L+R)>>1;
    node->lc = Build(L,mid);
    node->rc = Build(mid+1,R);
    node->pull();
    return node;
}

void push(Node* node,int L,int R)
{
    if (L==R) node->have_tag = 0;
    if (!node->have_tag) return;
    int mid=(L+R)>>1;
    //push(node->lc,L,mid);
    //push(node->rc,mid+1,R);
    node->have_tag = 0;
    node->lc->sum *= node->tag1;
    node->rc->sum *= node->tag1;
    node->lc->sum += node->tag2 * (mid-L+1);
    node->rc->sum += node->tag2 * (R-mid);
    node->lc->tag2 *= node->tag1;
    node->lc->tag1 *= node->tag1;
    node->lc->tag2 += node->tag2;
    node->rc->tag2 *= node->tag1;
    node->rc->tag1 *= node->tag1;
    node->rc->tag2 += node->tag2;
    node->lc->have_tag = 1;
    node->rc->have_tag = 1;
    node->tag1 = 1;
    node->tag2 = 0;
    return;
}

void modify(Node* node,int L,int R,int l,int r,ld val1,ld val2)
{
    if(l>R || L>r) return;
    else if(l<=L && R<=r)
    {
        push(node,L,R);
        node->sum *= val1;
        node->sum += (R-L+1)*val2;
        node->tag1 = val1;
        node->tag2 = val2;
        node->have_tag = true;
        //cout << "val1 = "<<val1<<" , val2 = "<<val2<<endl;
        return;
    }
    push(node,L,R);
    int mid=(L+R)>>1;
    modify(node->lc,L,mid,l,r,val1,val2);
    modify(node->rc,mid+1,R,l,r,val1,val2);
    node->pull();
    return;
}

ld query(Node* node,int L,int R,int l,int r)
{
    if (l>R || L>r) return 0;
    else if (l<=L && R<=r) return node->sum;
    push(node,L,R);
    int mid=(L+R)>>1;
    return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=1;n>=i;i++)
    {
        cin >> a[i];
    }
    Node* root=Build(1,n);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int l,r;
            cin >> l >> r;
            cout << fixed << setprecision(12) << query(root,1,n,l,r) << endl;
        }
        else
        {
            int l1,r1,l2,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            ld sum1 = query(root,1,n,l1,r1),sum2 = query(root,1,n,l2,r2);
            sum1 /= (r1-l1+1),sum2/=(r2-l2+1);
            //cout << "sum1 = "<<sum1<<" , sum2 = "<<sum2<<endl;
            modify(root,1,n,l1,r1,(r1-l1*1.0)*1.0/(r1-l1+1),sum2/(r1-l1+1));
            modify(root,1,n,l2,r2,(r2-l2*1.0)*1.0/(r2-l2+1),sum1/(r2-l2+1));
        }
    }
}