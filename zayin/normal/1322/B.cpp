#include<bits/stdc++.h>
#define maxn 400050
using namespace std;
typedef long long LL;

int n;
int a[maxn],c[maxn],pos[maxn];

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    for (int i=1;i<=n;++i) pos[i]=i;

    int ans=0;
    for (int b=0;b<25;++b)  {
        vector<int> L,R;
        for (int i=1;i<=n;++i)
            if (~a[pos[i]]>>b&1)
                L.push_back(pos[i]);
            else
                R.push_back(pos[i]);
        int m=0;
        for (int j:L) pos[++m]=j;
        for (int j:R) pos[++m]=j;
        int all=(1<<(b+1))-1;
        for (int i=1;i<=n;++i) c[i]=a[pos[i]]&all;

        // cout<<"pos:"; for (int i=1;i<=n;++i) cout<<pos[i]<<" "; cout<<endl;
        // cout<<"c:"; for (int i=1;i<=n;++i) cout<<c[i]<<" "; cout<<endl;

        LL cnt=0;

        int down1=1<<b;
        for (int i=1,j=n;i<=n;++i)  {
            j=max(j,i);
            while (j>i&&c[i]+c[j]>=down1) --j;
            cnt-=j;;

            // cout<<"down:"<<i<<" "<<j<<endl;
        }

        int up1=1<<(b+1);
        for (int i=1,j=n;i<=n;++i)  {
            j=max(j,i);
            while (j>i&&c[i]+c[j]>=up1) --j;
            cnt+=j;
        }

        int down2=(1<<b)+(1<<(b+1));
        for (int i=1,j=n;i<=n;++i)  {
            j=max(j,i);
            while (j>i&&c[i]+c[j]>=down2) --j;
            cnt-=j;;

            // cout<<"down:"<<i<<" "<<j<<endl;
        }

        int up2=1<<(b+2);
        for (int i=1,j=n;i<=n;++i)  {
            j=max(j,i);
            while (j>i&&c[i]+c[j]>=up2) --j;
            cnt+=j;
        }

        if (cnt&1)
            ans|=1<<b;

        // cout<<b<<":"<<cnt<<endl;
    }

    printf("%d\n",ans);
    return 0;
}