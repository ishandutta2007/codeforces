#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=3e5+1e3+7;

int n,b[N],h[N];

int f[N],g[N];

int c[N];

int lowbit(int x)
{
    return x&-x;
}

void add(int x,int v)
{
    x++;
    while(x)
    {
        c[x]=max(c[x],v);
        x-=lowbit(x);
    }
}

int query(int x)
{
    x++;
    int ret=-1e18;
    while(x<=n+1)
    {
        ret=max(ret,c[x]);
        x+=lowbit(x);
    }
    return ret;
}

multiset<int>s;

stack<int>st;

signed main()
{
    scanf("%lld",&n);
    fill(c+1,c+n+2,-1e18);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    add(0,f[0]);
    st.push(0);
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&h[i]<=h[st.top()])
        {
            s.erase(s.find(g[st.top()]));
            st.pop();
        }
        int y=st.top();
        st.push(i);
        s.insert(g[i]=query(y)+b[i]);
        int mx=*s.rbegin();
        f[i]=mx;
        add(i,f[i]);
        //[y+1,i] f[y]
    }
    printf("%lld\n",f[n]);
}