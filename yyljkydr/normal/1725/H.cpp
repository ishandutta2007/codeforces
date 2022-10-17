    #include<bits/stdc++.h>
    using namespace std;

    const int N=1e5+1e3+7;

    int n;

    int c[3],a[N];

    int main()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),c[a[i]%3]++;
        //check 0

        if(c[0]<=n/2)
        {
            puts("0");
            int cc=0;
            for(int i=1;i<=n;i++)
            {
                int x=a[i]%3;
                if(!x)
                    putchar('0');
                else if(cc<n/2)
                    putchar('1'),cc++;
                else
                    putchar('0');
            }
            puts("");
            return 0;
        }
        else
        {

            puts("2");
            int cc=0;
            for(int i=1;i<=n;i++)
            {
                int x=a[i]%3;
                if(x)
                    putchar('0');
                else if(cc<n/2)
                    putchar('1'),cc++;
                else
                    putchar('0');
            }
            puts("");
            return 0;
        }
    }