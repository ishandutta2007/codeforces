#include <iostream>
using namespace std;
int f[1010000];
int a[1100],b[1100];
int main()
{
    int tt,n;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)f[abs(a[i]-a[j])]=1;
        f[0]=1;
        b[1]=1;
        int num=1;
       // cout<<"f1:"<<f[1]<<endl;
        for(int i=2;i<=n;i++)
        {
            while(1)
            {
                num++;
                if(num>1000000)break;
                int flg=1;
                for(int j=1;j<i;j++)if(f[num-b[j]]==1){flg=0;break;}
                if(flg)break;
            }
            b[i]=num;
        }
        if(num>1000000)cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<b[i]<<" ";
            cout<<endl;
        }
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)f[abs(a[i]-a[j])]=0;
    }
    return 0;
}