#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
//#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

struct node{
    int size;
    int maxl, maxr, maxt;
    int lch, rch;
    int fath;
    int a, b;
};

int cn, sz;
vector<node> rmq;
vector<int> root;
vector<int> leave;

void init(int n)
{
    sz=1;
    while(sz<n) sz*=2;
    
    rmq.resize(2*sz);
    cn=2*sz;
    
    dforn(i, 2*sz)
    {
        if(i>=sz)
        {
            node nn;
            nn.size=1;
            nn.maxl=0;
            nn.maxr=0;
            nn.maxt=0;
            nn.lch=-1;
            nn.rch=-1;
            nn.fath=i/2;
            nn.a=i-sz;
            nn.b=i-sz+1;
            rmq[i]=nn;
        }
        else
        {
            node nn;
            nn.size=2*rmq[2*i].size;
            nn.maxl=0;
            nn.maxr=0;
            nn.maxt=0;
            nn.lch=2*i;
            nn.rch=2*i+1;
            nn.fath=i/2;
            nn.a=rmq[nn.lch].a;
            nn.b=rmq[nn.rch].b;
            rmq[i]=nn;
        }
    }
    //cout << "IUPI" << endl;
    
    leave.resize(n);
    forn(i, n) leave[i]=i+sz;
    
    root.push_back(0);
}

node get(int a, int b, node n)
{
    //cout << n.a << " " << n.b << " " << n.maxl << " " << n.maxr << " " << n.maxt << endl;
    if(n.a>=b || n.b<=a){ node res; res.maxl=0; res.maxr=0; res.maxt=0; return res; }
    
    if(n.a>=a && n.b<=b) return n;
    
    node hi=get(a, b, rmq[n.lch]), hd=get(a, b, rmq[n.rch]);
    
    node res;
    res.maxt=max(max(hi.maxt, hd.maxt), hi.maxr+hd.maxl);
    
    if(hd.size==hd.maxr) res.maxr=hd.maxr+hi.maxr; else res.maxr=hd.maxr;
    if(hi.size==hi.maxl) res.maxl=hd.maxl+hi.maxl; else res.maxl=hi.maxl;
    
    return res;
}

int get(int a, int b, int k)
{
    node start=rmq[root[k]];
    return get(a, b, start).maxt;
}

void upd(int a, int b)
{
    if(rmq[b].size>=sz){ root.push_back(b); return; }
    int f=rmq[a].fath;
    
    rmq.push_back(rmq[f]);
    rmq[b].fath=cn;
    
    //cout << a << " " << b << " " << f << " " << rmq[cn].lch << " " << rmq[cn].rch << endl;
    
    if(rmq[cn].lch==a){ 
        rmq[cn].lch=b; 
        rmq[rmq[cn].rch].fath=cn;
    }
    else {
        rmq[cn].rch=b; 
        rmq[rmq[cn].lch].fath=cn;
    }
    //cout << a << " " << b << " " << f << " " << rmq[cn].lch << " " << rmq[cn].rch << endl;
    
    node hd=rmq[rmq[cn].rch], hi=rmq[rmq[cn].lch];
    
    if(hd.size==hd.maxr) rmq[cn].maxr=hd.maxr+hi.maxr; else rmq[cn].maxr=hd.maxr;
    if(hi.size==hi.maxl) rmq[cn].maxl=hd.maxl+hi.maxl; else rmq[cn].maxl=hi.maxl;
    
    rmq[cn].maxt=max(max(hd.maxt, hi.maxt), hd.maxl+hi.maxr);
    
    //cout << rmq[cn].a << " " << rmq[cn].b << endl;
    //cout << a << " " << b << " " << f << " " << rmq[cn].maxr << " " << rmq[cn].maxl << " " << rmq[cn].maxt << endl;
    cn++;
    
    upd(f, cn-1); 
    
}

void set(int l)
{
    int start=leave[l];
    
    rmq.push_back(rmq[start]);
    leave[l]=cn;
    
    rmq[cn].maxl=1;
    rmq[cn].maxr=1;
    rmq[cn].maxt=1;
    cn++;
    
    upd(start, cn-1);
}

pair<int, int> fence[100010];

int main()
{
#ifdef ACMTUYO
    freopen("276E.in","r",stdin);
#endif
    int n, m;
    cin >> n;
    
    init(n);
    
    forn(i, n)
    {
        cin >> fence[i].first;
        fence[i].second=i;
    }
    
    sort(fence, fence+n);
    reverse(fence, fence+n);
    
    //forn(i, n) cout << leave[i] << endl;
    //cout << cn << endl;
    
    forn(i, n)
    {
        set(fence[i].second);
        //cout << "MANDO QUERIE " << fence[i].second << " " << n << " " << i+1 << endl;
        //cout << get(fence[i].second, fence[i].second+1, i+1) << endl;
    }
    
    //forn(i, n) cout << leave[i] << endl;
    
    cin >> m;
    forn(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        
        int top=n, bot=0;
        while(top-bot>1)
        {
            int mid=(top+bot)/2;
            //cout << "MANDO QUERIE " << a << " " << b << " " << mid << endl;
            
            int k=get(a,b,mid);
            //cout << k << endl;
            if(k<c)
            {
                bot=mid;
            }
            else
            {
                top=mid;
            }
        }
        cout << fence[bot].first << endl;
    }
    
    return 0;
}