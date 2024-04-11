    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    using namespace std;
    const int maxn=105;
    int t;
    int n,x;
    int w[maxn];
    int main()
    {
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&n,&x);
            for(int i=1;i<=n;i++)scanf("%d",&w[i]);
            sort(w+1,w+n+1);
            int flag=1;
            for(int i=1;i<=n;i++)
            {
                if(w[i]<x){x-=w[i];continue;}
                if(w[i]>x)break;
                if(w[n]>x){swap(w[i],w[n]);break;}
                if(w[i]==x&&w[n]==x){flag=0;break;}
            }
            if(!flag)printf("NO\n");
            else 
            {
                printf("YES\n");
                for(int i=1;i<=n;i++)printf("%d ",w[i]);
                printf("\n");
            }
        }
        return 0;
    }