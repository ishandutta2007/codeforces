#include<bits/stdc++.h>
#define maxh 20
#define maxn 300050
using namespace std;

int n,a[maxn];

int mx[maxn],preansp[maxn];
pair<int,char> prt[maxn];
pair<int,int> pre[maxn];

struct node {
    int tag;
    pair<int,int> info;
} T[maxn<<2];
#define val(k) T[k].info.first
#define pos(k) T[k].info.second
#define tag(k) T[k].tag
#define info(k) T[k].info

void renew(int k,int l,int r,int d) {
    if (val(k)&&val(k)<d)
        val(k)=d;
    tag(k)=max(tag(k),d);
}

void update(int k)  {
    info(k)=max(info(k<<1),info(k<<1|1));
}

void godown(int k,int l,int r)  {
    int mid=(l+r)>>1;
    renew(k<<1,l,mid,tag(k));
    renew(k<<1|1,mid+1,r,tag(k));
    tag(k)=0;
}

void change(int k,int l,int r,int a,int b,int d)    {
    if (a>b||a>r||l>b) return ;
    // cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    if (a<=l&&r<=b)
        renew(k,l,r,d);
    else    {
        godown(k,l,r);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,d);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,d);
        update(k);
    }
    // cout<<"after change:"<<k<<"("<<val(k)<<" "<<pos(k)<<") "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
}
void modify(int k,int l,int r,int p,int d)    {
    if (p<l||p>r) return ;
    if (l==r)   {
        pos(k)=l;
        if (val(k))
            val(k)=max(val(k),d);
        else
            val(k)=d;
    }   else    {
        godown(k,l,r);
        int mid=(l+r)>>1;
        if (p<=mid)
            modify(k<<1,l,mid,p,d);
        else
            modify(k<<1|1,mid+1,r,p,d);
        update(k);
    }
    // cout<<"after change:"<<k<<"("<<val(k)<<" "<<pos(k)<<") "<<l<<" "<<r<<" "<<a<<" "<<d<<endl;
}

pair<int,int> query(int k,int l,int r,int a,int b)    {
    if (a>r||l>b||a>b) return make_pair(0,0);
    // cout<<"query:"<<k<<"("<<val(k)<<" "<<pos(k)<<") "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    if (a<=l&&r<=b) return info(k);
    godown(k,l,r);
    int mid=(l+r)>>1;
    return max(query(k<<1,l,mid,a,b),query(k<<1|1,mid+1,r,a,b));
}

void build(int k,int l,int r)   {
    tag(k)=val(k)=pos(k)=0;
    if (l==r) return ;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

char res[maxn];

int Log2[maxn];
int ST[maxh][maxn];

int vis[maxn];

int main()  {
    Log2[0]=-1;
    for (int i=1;i<maxn;++i) Log2[i]=Log2[i>>1]+1;

    int cnt=0;
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        build(1,1,n);

        for (int i=1;i<=n;++i)
            scanf("%d",a+i),ST[0][i]=i+a[i];
        
        for (int j=1;j<=Log2[n];++j)
            for (int i=1;i+(1<<j)-1<=n;++i)
                ST[j][i]=max(ST[j-1][i],ST[j-1][i+(1<<j-1)]);
        auto RMQ=[&](int l,int r)   {
            if (l>r) return 0;
            int t=Log2[r-l+1];
            return max(ST[t][l],ST[t][r-(1<<t)+1]);
        };
        
        int ans=0,ansp=0;
        for (int i=1;i<=n;++i)  {
            mx[i]=ans,preansp[i]=ansp;

            //L
            pre[i]=query(1,1,n,i-a[i],i-1);
            if (pre[i].first<i-1&&a[i])
                pre[i].first=i-1;
            if (pre[i].second)  {
                modify(1,1,n,pre[i].first+1,pre[i].first);
                prt[i]=make_pair(pre[i].second,'L');
            }

            //R
            change(1,1,n,1,i-1,i+a[i]);
            if (ans==i-1)   
                modify(1,1,n,i,i+a[i]);
            if (ans>=i-1)   {
                if (pre[i].first<max(ans,i+a[i]))
                    prt[i]=make_pair(ansp,'R');
            }
            

            if (ans>=i)
                ans=max(ans,i+a[i]);
            if (pre[i].first>=i&&ans<pre[i].first)
                ans=pre[i].first,ansp=i;
            // cout<<i<<":"<<pre[i].first<<" "<<pre[i].second<<" | "<<prt[i].first<<" "<<prt[i].second<<" | "<<ans<<" "<<ansp<<endl;
            // cout<<"Tree:"; for (int i=1;i<=n;++i) cout<<query(1,1,n,i,i).first<<" "; cout<<endl;
            // cout<<endl;
        }

        // cout<<"ans:"<<ans<<endl;
        if (ans>=n) {
            puts("YES");
            for (int i=1;i<=n;++i) res[i]='R'; res[n+1]='\0';
            int k=ansp;
            function<void(int)> print=[&](int k)   {
                // cout<<"print:"<<k<<" "<<pre[k].second<<endl;
                res[k]='L';
                k=pre[k].second;
                // cout<<"???:"<<k<<endl;
                while (k>0) {
                    // cout<<"k:"<<k<<" "<<prt[k].second<<" "<<prt[k].first<<endl;
                    res[k]=prt[k].second;
                    if (res[k]=='L')
                        k=prt[k].first;
                    else    {
                        print(preansp[k]);
                        break;
                    }
                }
            };
            print(ansp);
            puts(res+1);

            for (int i=1;i<=n;++i) vis[i]=0;
            for (int i=1;i<=n;++i)  {
                int l=1,r=n;
                if (res[i]=='L')
                    r=i-1,l=max(l,i-a[i]);
                else
                    l=i+1,r=min(r,i+a[i]);
                ++vis[l],--vis[r+1];
            }
            for (int i=1;i<=n;++i) 
                if (!(vis[i]+=vis[i-1]))    {
                    cout<<n<<endl;
                    for (int i=1;i<=n;++i)
                        cout<<a[i]<<" ";
                    cout<<endl;
                    assert(0);
                }


        } else
            puts("NO");
    }
    // assert(0);
    return 0;
}