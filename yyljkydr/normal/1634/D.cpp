#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],b[N];

set<int>s;

int query(int i,int j,int k)
{
    printf("? %d %d %d\n",i,j,k);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        s.clear();
        for(int i=3;i<=n;i++)
            a[i]=query(1,2,i),s.insert(a[i]);
        if(s.size()==1)
        {
            int x=*s.begin();
            s.clear();
            for(int i=2;i<=n;i++)
                if(i!=3)
                    b[i]=query(1,3,i),s.insert(b[i]);
                else
                    b[i]=-1;
            if(*max_element(b+2,b+n+1)==x)
                printf("! %d %d\n",1,2);
            else
                printf("! %d %d\n",3,max_element(b+2,b+n+1)-b);
            fflush(stdout);
            continue;
        }
        int p=max_element(a+3,a+n+1)-a;
        s.clear();
        for(int i=2;i<=n;i++)
            if(i!=p)
                b[i]=query(1,p,i),s.insert(b[i]);
            else
                b[i]=-1;
        int q=-1;
        if(s.size()==1)
            q=1;
        else
            q=max_element(b+2,b+n+1)-b;
        printf("! %d %d\n",p,q);
        fflush(stdout);
    }
}