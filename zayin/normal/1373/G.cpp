#include<bits/stdc++.h>
#define maxn 750050
using namespace std;

int n,R,m;

const int N=700000;

struct node {
    int val,tag,cnt;
} T[maxn<<2];
#define val(k) T[k].val
#define tag(k) T[k].tag
#define cnt(k) T[k].cnt

void renew(int k,int d) {
    val(k)+=d;
    tag(k)+=d;
}

void godown(int k)  {
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void update(int k)  {
    val(k)=max(val(k<<1),val(k<<1|1));
}

void change(int k,int l,int r,int p,int d)    {
    if (l>p) return ;
    if (r<=p)
        renew(k,d);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        change(k<<1,l,mid,p,d);
        change(k<<1|1,mid+1,r,p,d);
        update(k);
    }
    // cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<p<<" ~ "<<val(k)<<" "<<cnt(k)<<endl;
}

void modify(int k,int l,int r,int p,int d)    {
    if (l==r)   {
        if (!cnt(k)) val(k)+=l-1;
        cnt(k)+=d;
        if (!cnt(k)) val(k)-=l-1;
    }  
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (p<=mid)
            modify(k<<1,l,mid,p,d);
        else
            modify(k<<1|1,mid+1,r,p,d);
        update(k);
    }
    // cout<<"modify:"<<k<<" "<<l<<" "<<r<<" "<<p<<" ~ "<<val(k)<<" "<<cnt(k)<<endl;
}

set<pair<int,int> > s;

int main()  {
    scanf("%d%d%d",&n,&R,&m);
    while (m--) {
        int x,y;
        scanf("%d%d",&x,&y);
        auto pr=make_pair(x,y);
        int pos=abs(x-R)+y;
        // cout<<"pos:"<<pos<<endl;
        if (s.count(pr))    {
            modify(1,1,N,pos,-1);
            change(1,1,N,pos,-1);
            s.erase(pr);
        } else  {
            s.insert(pr);
            modify(1,1,N,pos,1);
            change(1,1,N,pos,1);
        }
        printf("%d\n",max(val(1),n)-n);
    }
    return 0;
}