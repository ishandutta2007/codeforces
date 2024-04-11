    #include<iostream>
    #include<cstdio>
    #include<cmath>
    using namespace std;
    int t;
    int n;
    int main()
    {
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n);
            if(n%2==1){printf("NO\n");continue;}
            n/=2;
            int a=sqrt(n);
            if(a*a==n){printf("YES\n");continue;}
            if(n%2==1){printf("NO\n");continue;}
            n/=2;
            a=sqrt(n);
            if(a*a==n){printf("YES\n");continue;}
            else printf("NO\n");
        }
        return 0;
    }