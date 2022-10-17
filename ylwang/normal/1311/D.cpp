#include<cstdio>
#include<cmath>
using namespace std;
int Abs(int x)
{
    if(x<0)return -x;
    return x;
}
int Min(int x,int y)
{
    if(x<y)return x;
    return y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int aa,b,c;
        scanf("%d%d%d",&aa,&b,&c);
        int AAA,BBB,CCC;
        int sum=0x3f3f3f3f;
        for(int i=1;i<=15000;i++)
        {
            int ans=0;
            int Zuo,You;

            int tmp=0x3f3f3f3f;
            int qaq=sqrt(i);
            ans=Abs(b-i);
            for(int j=1;j<=qaq;j++)
            {
                if(i%j!=0)
                {
                    continue;
                }
                if(Abs(aa-j)<tmp)
                {
                    tmp=Abs(aa-j);
                    Zuo=j;
                }
                if(Abs(aa-(i/j))<tmp)
                {
                    tmp=Abs(aa-(i/j));
                    Zuo=i/j;
                }
            }
            ans+=tmp;
            tmp=0x3f3f3f3f;
            for(int j=i;j<=32000;j+=i)
            {
                if(Abs(c-j)<tmp)
                {
                    You=j;
                    tmp=Abs(c-j);
                }
            }
            ans+=tmp;
            if(ans<sum)
            {
                sum=ans;
                AAA=Zuo;
                BBB=i;
                CCC=You;
            }
        }
        printf("%d\n",sum);
        printf("%d %d %d\n",AAA,BBB,CCC);
    }
    return 0;
}