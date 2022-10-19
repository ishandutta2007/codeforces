#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char x[50005];// 
char ansa[50005];// 
char ansb[50005];// 
bool flag1;//1 
int t,n; 
inline void read(int &x)// 
{
    int f;char c;
    for (f=1,c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for (x=0;c<='9'&&c>='0';c=getchar()) x=x*10+(c&15);x*=f;
}
inline int mn(int _x,int _y)
{
    return _x<_y?_x:_y;
}
inline int mx(int _x,int _y)
{
    return _x>_y?_x:_y;
}
inline int ab(int _x)
{
    if(_x<0) return -_x;
    else return _x;
}
int main()
{
    read(t);
    while(t--)
    {
        flag1=true;//1 
        read(n);
        scanf("%s",1+x);//1 
        for(int i=1;i<=n;i++)//  
        {
            if(x[i]=='0') // 
            {
                ansa[i]=ansb[i]='0';
            }
            if(x[i]=='1')
            {
                if(flag1)// 
                {
                    ansa[i]='1';// ansa[i]1 
                    ansb[i]='0';
                    flag1=false;// 
                }
                else// 
                {
                    ansa[i]='0';
                    ansb[i]='1';
                }
            }
            if(x[i]=='2')
            {
                if(!flag1)// 
                {
                    ansa[i]='0';
                    ansb[i]='2';
                } 
                else
                {
                    ansa[i]=ansb[i]='1';
                }
            }
        }
        for(int i=1;i<=n;i++) printf("%c",ansa[i]);// 
        puts("");
        for(int i=1;i<=n;i++) printf("%c",ansb[i]);
        puts("");   
    } 
    return 0;
}