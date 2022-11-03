#include<cstdio>
#include<iostream>
using namespace std;
int n;
long long s[300],d[300];
long long l[300],r[300],lt,rt;
bool cd(long long l1,long long r1,long long l2,long long r2)
{
    if(r1<l2)return 0;
    if(r2<l1)return 0;
    return 1;
}
bool flg,f;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>d[i];
        flg=1;
        for(int j=1;j<i;j++)if(cd(l[j],r[j],s[i],s[i]+d[i]-1)){flg=0;break;}
        if(flg)
        {
            l[i]=s[i];
            r[i]=s[i]+d[i]-1;
            continue;
        }
        else
        {
            for(int k=0;k<i;k++)
            {
                lt=r[k]+1;
                rt=lt+d[i]-1;
                flg=1;
                for(int j=1;j<i;j++)if(cd(l[j],r[j],lt,rt)){flg=0;break;}
                if(flg&&(l[i]==0||lt<l[i])){l[i]=lt;r[i]=rt;}
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;
}