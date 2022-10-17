#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,S=448;

int n,ct[N],a[N];

int pos[N*2],sa[N],sb[N];

vector<int>v;

int cnt[N],cxt[N],mx;

void ins(int x)
{
    --cxt[cnt[x]];
    ++cnt[x];
    ++cxt[cnt[x]];
    mx=max(mx,cnt[x]);
}

void del(int x)
{
    --cxt[cnt[x]];
    --cnt[x];
    ++cxt[cnt[x]];
    if(!cxt[mx])
        mx--;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),ct[a[i]]++;
    int ans=0;
    int x=max_element(ct+1,ct+n+1)-ct;
    for(int i=1;i<=n;i++)
        if(ct[i]>=S)
            v.push_back(i);
    for(auto y:v)
    {
        if(x==y)
            continue;
        for(int i=0;i<=n*2;i++)
            pos[i]=0;
        for(int i=1;i<=n;i++)
        {
            sa[i]=sa[i-1]+(a[i]==x);
            sb[i]=sb[i-1]+(a[i]==y);
            pos[sa[i]-sb[i]+n]=i;
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,pos[sa[i]-sb[i]+n]-i);
        }
    }
    for(int i=1;i<S;i++)
    {
        for(int j=1,k=0;j<=n;j++)
        {
            while(1)
            {
                k++;
                if(k>n)
                {
                    k--;
                    break;
                }
                ins(a[k]);
                // cout<<x<<" "<<cnt[x]<<endl;
                if(cnt[x]>i)
                {
                    del(a[k]);
                    k--;
                    break;
                }
            }
            if(cxt[mx]>=2&&cnt[x]==mx)
                ans=max(ans,k-j+1);
            del(a[j]);
        }
    }
    printf("%d\n",ans);
}