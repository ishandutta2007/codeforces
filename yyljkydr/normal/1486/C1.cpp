#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int query(int l,int r)
{
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

void solve(int l,int r)
{
    if(r==l+2)
    {
        int s=query(l,r);
        if(s==(l+r)/2)
        {
            if(query(l,s)==s)
                printf("! %d",l);
            else
                printf("! %d",r);
            fflush(stdout);
            return;
        }
        else
        {
            if(s==l)
                solve(l+1,r);
            else
                solve(l,r-1);
            return;
        }
    }
    if(r==l+1)
    {
        int s=query(l,r);
        printf("! %d\n",l+r-s);
        fflush(stdout);
        return;
    }
    if(l==r)
    {
        printf("! %d\n",l);
        fflush(stdout);
        return;
    }
    int mid=(l+r)>>1;
    int p=query(l,r);
    int q=p<=mid?query(l,mid):query(mid+1,r);
    if(p!=q)
        p<=mid?solve(mid+1,r):solve(l,mid);
    else
        p<=mid?solve(l,mid):solve(mid+1,r);
}

int main()
{
    scanf("%d",&n);
    if(n<=100)
        solve(1,n);
    else
    {
        int mid=(1+n)>>1;
        int p=query(1,n);
        int q=p==1?n+1:query(1,p);
        if(p==q)
        {
            int l=1,r=p-1;
            while(r-l>3)
            {
                int mid=(l+r)>>1;
                if(query(mid,n)!=p)
                    r=mid-1;
                else
                    l=mid;
            }
            solve(l,r);
        }
        else
        {
            int l=p+1,r=n;
            while(r-l>3)
            {
                int mid=(l+r)>>1;
                if(query(1,mid)!=p)
                    l=mid+1;
                else
                    r=mid;
            }
            solve(l,r);
        }
    }
}