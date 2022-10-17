#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n;

int a[N],b[N];

int cnt=0;

int qry(int x,int y)
{
    ++cnt;
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int ans;
    // ans=b[x]|b[y];
    scanf("%d",&ans);
    return ans;
}

int bad[N];

int main()
{
    srand(time(NULL));
    scanf("%d",&n);
    // for(int i=1;i<=n;i++)
    //     b[i]=i-1;
    // random_shuffle(b+1,b+n+1);
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    int p=rand()%n+1;
    int ths=2047;
    while(1)
    {
        for(int i=1;i<=8;i++)
        {
            int x=rand()%n+1;
            while(x==p)
                x=rand()%n+1;
            ths&=qry(x,p);
        }
        int tt=1;
        vector<int>v;
        for(int i=1;i<=n;i++)
            if(i!=p&&!bad[i])
                v.push_back(i);
        random_shuffle(v.begin(),v.end());
        for(int i=1;i<=n;i++)
            if(i!=p&&bad[i])
                v.push_back(i);
        reverse(v.begin(),v.end());
        int nx=-1;
        while(v.size())
        {
            int k=v.back();
            int val=qry(p,k);
            a[k]=val;
            ths&=val;
            if(val==ths)
            {
                nx=k;
                break;
            }
            bad[k]=1;
            v.pop_back();
        }
        if(!v.size())
        {
            printf("!");
            for(int i=1;i<=n;i++)
                if(i==p)
                    printf(" 0");
                else
                    printf(" %d",a[i]);
            puts("");
            fflush(stdout);
            // cerr<<cnt<<endl;
            return 0;
        }
        p=nx;
        bad[p]=1;
    }
}