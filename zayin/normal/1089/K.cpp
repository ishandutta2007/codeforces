#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

const LL inf=1LL<<40;

struct node {
    LL val,sum;
    node(LL _val=0,LL _sum=0)   {
        val=_val,sum=_sum;
    }
    node operator + (const node& N) const   {
        node ans;
        ans.val=max(val+N.sum,N.val);
        ans.sum=sum+N.sum;
        return ans;
    }
} T[maxn<<2];
#define val(k) T[k].val
#define sum(k) T[k].sum

int q;
struct qry  {
    int tp,x,y;
} Q[maxn];

vector<int> TIME;

void build(int k,int l,int r)   {
    val(k)=-inf,sum(k)=0;
    if (l==r) return ;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void change(int k,int l,int r,int p,int v)  {
    if (l==r)   {
        if (!v)
            val(k)=-inf,sum(k)=0;
        else
            val(k)=TIME[l-1]+v,sum(k)=v;
    } else  {
        int mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p,v);
        else
            change(k<<1|1,mid+1,r,p,v);
        T[k]=T[k<<1]+T[k<<1|1];
    }
    // cout<<"change:"<<k<<"("<<val(k)<<","<<sum(k)<<") "<<TIME[l-1]<<" "<<TIME[r-1]<<" "<<p<<" "<<v<<endl;
}

node query(int k,int l,int r,int p) {
    if (l>p) return node(-inf,0);
    if (r<=p) return T[k];
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,p)+query(k<<1|1,mid+1,r,p);
}

int main()  {
    scanf("%d",&q);
    for (int i=1;i<=q;++i) {
        char op[10];
        scanf("%s",op);
        if (*op=='+')   {
            Q[i].tp=0;
            scanf("%d%d",&Q[i].x,&Q[i].y);
            TIME.push_back(Q[i].x);
        } else
        if (*op=='-')   {
            Q[i].tp=1;
            scanf("%d",&Q[i].x);
        } else  {
            Q[i].tp=2;
            scanf("%d",&Q[i].x);
            TIME.push_back(Q[i].x);
        }
    }

    sort(TIME.begin(),TIME.end());
    TIME.resize(unique(TIME.begin(),TIME.end())-TIME.begin());
    
    auto id=[&](const int& i)   {
        return lower_bound(TIME.begin(),TIME.end(),i)-TIME.begin()+1;
    };

    build(1,1,TIME.size());

    for (int i=1;i<=q;++i)  {
        if (Q[i].tp==0) {
            change(1,1,TIME.size(),id(Q[i].x),Q[i].y);
        } else
        if (Q[i].tp==1) {
            change(1,1,TIME.size(),id(Q[Q[i].x].x),0);
        } else  {
            node res=query(1,1,TIME.size(),id(Q[i].x));
            // cout<<res.val<<" "<<res.sum<<endl;
            printf("%lld\n",max(res.val,(LL)Q[i].x)-Q[i].x);
        }
    }
    return 0;
}