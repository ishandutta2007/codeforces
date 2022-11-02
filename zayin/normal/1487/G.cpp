#include<bits/stdc++.h>
#define maxn 405
#define modu 998244353
using namespace std;
typedef long long LL;

int n;
int cnt[maxn];

const int C=26;

LL f[2][maxn][maxn][3][3],g[2][maxn][2][2];
LL cf[]={C-2,1,1},cg[]={C-1,1};

void add(LL &x,LL y)    {
    x=(x+y)%modu;
}


int main()  {
    scanf("%d",&n);
    for (int i=0;i<C;++i) scanf("%d",cnt+i);

    int now=0;
    for (int a=0;a<=1;++a)
        g[now][a==1][0][a]=cg[a];
    for (int a=0;a<=2;++a)
        f[now][a==1][a==2][0][a]=cf[a];

    for (int i=2;i<=n;++i)    {
        // cout<<i<<":"<<endl;
        now^=1;
        memset(f[now],0,sizeof(f[now]));
        memset(g[now],0,sizeof(g[now]));
        for (int cnt=0;cnt<i;++cnt)
            for (int a=0;a<=1;++a)
                for (int b=0;b<=1;++b)
                    for (int c=0;c<=1;++c)
                        // cout<<"tran:"<<a<<" "<<c<<" -> "<<(cg[c]+(!c&&a))<<endl,
                        add(g[now][cnt+(c==1)][b][c],g[now^1][cnt][a][b]*(cg[c]-(a==c&&i>2)));
        
        for (int cnt1=0;cnt1<i;++cnt1)
            for (int cnt2=0;cnt1+cnt2<i;++cnt2)
                for (int a=0;a<=2;++a)
                    for (int b=0;b<=2;++b)
                        for (int c=0;c<=2;++c)
                            add(f[now][cnt1+(c==1)][cnt2+(c==2)][b][c],f[now^1][cnt1][cnt2][a][b]*(cf[c]-(a==c&&i>2)));
                                
        // for (int cnt1=0;cnt1<=i;++cnt1)
        //     for (int cnt2=0;cnt1+cnt2<=i;++cnt2)
        //         for (int a=0;a<=2;++a)
        //             for (int b=0;b<=2;++b)
        //                 if (f[now][cnt1][cnt2][a][b])
        //                     cout<<"f["<<i<<"]["<<cnt1<<"]["<<cnt2<<"]["<<a<<"]["<<b<<"]="<<f[now][cnt1][cnt2][a][b]<<endl;
        // for (int cnt=0;cnt<=i;++cnt)
        //     for (int a=0;a<=1;++a)
        //         for (int b=0;b<=1;++b)  
        //             if (g[now][cnt][a][b])
        //                 cout<<"g["<<i<<"]["<<cnt<<"]["<<a<<"]["<<b<<"]="<<g[now][cnt][a][b]<<endl;
    }

    // cout<<"???"<<endl;

    LL ans1=1,ans2=0,ans3=0;
    for (int i=0;i<n;++i) ans1=ans1*(C-1+(i<=1))%modu;

    for (int i=0;i<C;++i)   {
        LL sum=0;
        for (int c=n;c>cnt[i];--c)
            for (int a=0;a<=1;++a)
                for (int b=0;b<=1;++b)
                    if (g[now][c][a][b])
                        // cout<<"g["<<n<<"]["<<c<<"]["<<a<<"]["<<b<<"]="<<g[now][c][a][b]<<endl,
                        add(sum,g[now][c][a][b]);
        add(ans2,sum);
    }


    for (int i=0;i<C;++i)   
        for (int j=0;j<i;++j)   {
            LL sum=0;
            // cout<<i<<" "<<j<<":"<<cnt[i]<<" "<<cnt[j]<<endl;
            for (int ci=n;ci>cnt[i];--ci)
                for (int cj=n;cj>cnt[j];--cj)
                    for (int a=0;a<=2;++a)
                        for (int b=0;b<=2;++b)
                            if (f[now][ci][cj][a][b])
                                // cout<<"f["<<n<<"]["<<ci<<"]["<<cj<<"]["<<a<<"]["<<b<<"]="<<f[now][ci][cj][a][b]<<endl,
                                add(sum,f[now][ci][cj][a][b]);
            add(ans3,sum);
        }
    // cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

    LL ans=(ans1-ans2+ans3+modu)%modu;
    printf("%lld\n",ans);

    return 0;
}