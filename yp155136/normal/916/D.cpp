#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#define IOS ios:sync_with_stdio(0); cin.tie(0);
typedef long long LL;

const int N = 1e5 + 6;
int a[N];

struct Node
{
    Node *lc,*rc;
    bool have;
    int x;
    Node():lc(NULL),rc(NULL),have(0){}
    void pull()
    {
        have = 0;
        if (lc) have |= lc->have;
        if (rc) have |= rc->have;
        //have = lc->have | rc->have;
    }
};

Node* root[N];

Node* getNode(Node *old)
{
    Node* node = new Node();
    if (old == NULL) return node;
    node->lc = old->lc;
    node->rc = old->rc;
    node->have = old->have;
    return node;
}

int jizz;

void modify(Node* node,Node* old,int L,int R,int pos,int x)
{
    //cout<<"L = "<<L<<" , R = "<<R<<endl;
    if (L==R)
    {
        node->have ^= 1;
        node->x = x;
        return;
    }
    int mid=(L+R)>>1;
    if (pos <= mid)
    {
        if (old == NULL)
        {
            node->lc = new Node();
            modify(node->lc,old,L,mid,pos,x);
        }
        else
        {
            node->lc=getNode(old->lc);
            modify(node->lc,old->lc,L,mid,pos,x);
        }
    }
    else
    {
        if (old == NULL)
        {
            node->rc = new Node();
            modify(node->rc,old,mid+1,R,pos,x);
        }
        else
        {
            node->rc=getNode(old->rc);
            modify(node->rc,old->rc,mid+1,R,pos,x);
        }
    }
    node->pull();
    return;
}

bool query(Node* node,int L,int R,int pos)
{
    if (!node) return false;
    if (!node->have) return false;
    if (L==R)
    {
        jizz = node->x;
        return node->have;
    }
    int mid=(L+R)>>1;
    if (pos <= mid) return query(node->lc,L,mid,pos);
    else return query(node->rc,mid+1,R,pos);
}

struct Treap
{
    Treap *lc,*rc;
    int cnt;
    Treap():lc(NULL),rc(NULL),cnt(0){};
    void pull()
    {
        cnt = 0;
        if (lc) cnt += lc->cnt;
        if (rc) cnt += rc->cnt;
    }
};

Treap* getTreap(Treap* old)
{
    Treap* treap = new Treap();
    if (!old) return treap;
    treap->lc = old->lc;
    treap->rc = old->rc;
    treap->cnt = old->cnt;
    return treap;
}

void modifyy(Treap* node,Treap* old,int L,int R,int pos,int val)
{
    if (L==R)
    {
        node->cnt += val;
        return;
    }
    int mid=(L+R)>>1;
    if (pos <= mid)
    {
        if (old == NULL)
        {
            node->lc = new Treap();
            modifyy(node->lc,old,L,mid,pos,val);
        }
        else
        {
            node->lc=getTreap(old->lc);
            modifyy(node->lc,old->lc,L,mid,pos,val);
        }
    }
    else
    {
        if (old == NULL)
        {
            node->rc = new Treap();
            modifyy(node->rc,old,mid+1,R,pos,val);
        }
        else
        {
            node->rc=getTreap(old->rc);
            modifyy(node->rc,old->rc,mid+1,R,pos,val);
        }
    }
    node->pull();
    return;
}

int Cnt(Treap* t)
{
    return t?t->cnt:0;
}

int queryy(Treap* node,int L,int R,int pos)
{
    if (!node) return 0;
    if (!node->cnt) return 0;
    if (L==R)
    {
        return node->cnt;
    }
    int mid=(L+R)>>1;
    if (pos <= mid) return queryy(node->lc,L,mid,pos);
    else return Cnt(node->lc) + queryy(node->rc,mid+1,R,pos);
}

Treap* kirino[N];

const int NN = 1000000000;

int main ()
{
    int q;
    cin >> q;
    root[0] = new Node();
    kirino[0] = new Treap();
    map<string,int> mp;
    int idd=0;
    int n=q;
    for (int i=1;q>=i;i++)
    {
        string c;
        cin >> c;
        if (c=="set")
        {
            root[i] = getNode(root[i-1]);
            kirino[i] = getTreap(kirino[i-1]);
            string s;
            cin >> s;
            int id=mp[s];
            if (!id) id = mp[s] = ++idd;
            int x;
            cin >> x;
            //cout<<"hi"<<endl;
            if (query(root[i],1,n,id) == false)
            {
                //cout<<"inn"<<endl;
                modify(root[i],root[i-1],1,n,id,x);
                //cout<<"innn"<<endl;
                modifyy(kirino[i],kirino[i-1],1,NN,x,1);
                //cout<<"innnn"<<endl;
            }
            else
            {
                //cout<<"GG"<<endl;
                //cout<<"jizz = "<<jizz<<endl;
                modify(root[i],root[i-1],1,n,id,x);
                modify(root[i],root[i],1,n,id,x);
                modifyy(kirino[i],kirino[i-1],1,NN,jizz,-1);
                modifyy(kirino[i],kirino[i],1,NN,x,1);
            }
        }
        else if (c == "remove")
        {
            root[i] = getNode(root[i-1]);
            kirino[i] = getTreap(kirino[i-1]);
            string s;
            cin >> s;
            if (mp[s] == 0)
            {
                continue;
            }
            if(query(root[i],1,q,mp[s]) == false) continue;
            //query(root[i],1,q,mp[s]);
            modify(root[i],root[i-1],1,n,mp[s],0);
            modifyy(kirino[i],kirino[i-1],1,NN,jizz,-1);
        }
        else if (c == "query")
        {
            root[i] = getNode(root[i-1]);
            kirino[i] = getTreap(kirino[i-1]);
            string s;
            cin >> s;
            if (mp[s] == 0)
            {
                cout << -1 << endl;
            }
            else if (query(root[i],1,n,mp[s]) == false)
            {
                cout << -1 << endl;
            }
            else if (jizz == 1)
            {
                cout<<0<<endl;
            }
            else
            {
                //cout<<"jizz = "<<jizz<<endl;
                cout<<queryy(kirino[i],1,NN,jizz-1)<<endl;
            }
            cout<<flush;
        }
        else
        {
            int d;
            cin >> d;
            root[i] = getNode(root[i-1-d]);
            kirino[i] = getTreap(kirino[i-1-d]);
        }
    }
}