#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<ll, ll> > vpll;


const int infi=1000000007;
struct Node;
Node *NIL;
Node *root=NULL;
struct Node
{
    int val;
    int pri;
    int m;
    Node *left, *right;
    Node(){};
    Node(int v)
    {
        val=v;
        pri=((rand()<<15)+rand())%infi;
        m=1;
        left=NIL;
        right=NIL;
    }
};
bool start=false;
void init()
{
    NIL=new Node();
    NIL->pri=infi;
    root=NIL;
    start=true;
}
int M(Node *p)
{
    if(p==NIL) return 0;
    return 1+p->left->m+p->right->m;
}
void update(Node *&p)
{
    p->m=M(p);
}
void rotleft(Node *&p)
{
    Node *q=p;
    p=p->right;
    q->right=p->left;
    p->left=q;
    update(q);
    update(p);
}
void rotright(Node *&p)
{
    Node *q=p;
    p=p->left;
    q->left=p->right;
    p->right=q;
    update(q);
    update(p);
}
void inserting(Node *&f, Node *&p)
{
    if(f==NIL)
    {
        f=p;
        return;
    }
    if(p->val<f->val)
    {
        inserting(f->left, p);
        if(f->left->pri<f->pri) rotright(f);
    }
    else
    {
        inserting(f->right, p);
        if(f->right->pri<f->pri) rotleft(f);
    }
    update(f);
}
int kth(Node *f, int k)
{
    if(M(f->left)>k) return kth(f->left, k);
    if(M(f->left)==k) return f->val;
    return kth(f->right, k-(M(f->left)+1));
}
int pos(Node *f, int x)
{
    if(x<f->val) return pos(f->left, x);
    if(x>f->val) return 1+M(f->left)+pos(f->right, x);
    return M(f->left);
}
void eraseing(Node *&p)
{
    if(p==NIL) return;
    if(p->left==NIL && p->right==NIL)
    {
        p=NIL;
        return;
    }
    if(p->left->pri<p->right->pri)
    {
        rotright(p);
        eraseing(p->right);
    }
    else
    {
        rotleft(p);
        eraseing(p->left);
    }
    if(p!=NIL) update(p);
}
void erasex(Node *&p, int x)
{
    if(p==NIL) return;
    if(x<p->val) erasex(p->left, x);
    else if(x>p->val) erasex(p->right, x);
    else eraseing(p);
    if(p!=NIL) update(p);
}
void erasekth(Node *&f, int k)
{
    if(M(f->left)>k) erasekth(f->left, k);
    else if(M(f->left)==k) eraseing(f);
    else erasekth(f->right, k-(M(f->left)+1));
    if(f!=NIL) update(f);
}
int Elemszam()
{
    if(!start) init();
    return M(root);
}
void Adat(int x)
{
    if(!start) init();
    //cout<<"Adat esz: "<<Elemszam()<<endl;
    Node *p=new Node(x);
    inserting(root, p);
}
int Hanyadik(int x)
{
    if(!start) init();
    return pos(root, x)+1;
}
int Kadik(int k)
{
    if(!start) init();
    //cout<<"kez"<<endl;
    return kth(root, k-1);
}
void Torol(int x)
{
    if(!start) init();
    erasex(root, x);
}
void KTorol(int k)
{
    if(!start) init();
    erasekth(root, k-1);
}


vpll v1;
ll n1, m1, q1;
vll darab1;
vpll query1;
int ans1[500009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    cin>>n1>>m1>>q1;
    for(int i=1; i<=m1; i++)
    {
        v1.push_back({0, i});
    }
    for(int i=1; i<=n1; i++)
    {
        ll idx;
        cin>>idx;
        v1[idx-1].F++;
    }
    sort(v1.begin(), v1.end());
    darab1.resize(m1);

    ll nagyok=0;
    for(ll i=m1-1; i>=0; i--)
    {
        darab1[i]=(i+1)*v1[i].F+nagyok;
        nagyok+=v1[i].F;
    }


    for(int tt=1; tt<=q1; tt++)
    {

        ll x;
        cin>>x;
        query1.push_back({x, tt});
    }


    sort(query1.begin(), query1.end());
    int treapcnt=0;
    for(int tt=0; tt<q1; tt++)
    {
        ll x=query1[tt].F;
        int elso=0;
        int utolso=m1-1;
        while(elso<=utolso)
        {
            int kozep=(elso+utolso)/2;
            if(darab1[kozep]<x) elso=kozep+1;
            else utolso=kozep-1;
        }
        elso--;
        while(treapcnt<=elso)
        {
            //cout<<"Be "<<v1[treapcnt].S<<endl;
            Adat((int)(v1[treapcnt].S));

            //cout<<Elemszam()<<endl;
            treapcnt++;
        }
        x-=darab1[elso];
        x=x%((ll)(elso+1));
        if(x>0)
        {
            ans1[query1[tt].S]=Kadik(x);
            //cout<<"Kadik "<<x<<" esz: "<<Elemszam()<<endl;
        }
        else
        {
            //cout<<"Kadik "<<elso+1<<" esz: "<<Elemszam()<<endl;
            ans1[query1[tt].S]=Kadik(elso+1);
        }
        //cout<<tt<<" ok"<<endl;
    }
    for(int i=1; i<=q1; i++)
    {
        cout<<ans1[i]<<endl;
    }


    return 0;
}