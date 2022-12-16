#include<stdio.h>
#include<algorithm>
#define lowbit(o) o&-o
using namespace std;
int ff[100005],bb,i,j,k,l,s,m,n,f[100005],x,y,orzgtw,st,en;
inline void add(int o,int p)
{
    for (;o<=n;o+=lowbit(o))
    f[o]+=p;
}
inline int ask(int o)
{
    int s=0;
    for (;o;o-=lowbit(o))
    s+=f[o];
    return s;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        add(i,1);
        ff[i]=1;
    }
    int now=n;
    st=1;
    en=n;
    for (i=1;i<=m;i++)
    {
        if (i==4)
        i=4;
        now=en-st+1;
        int stt,end;
        scanf("%d",&orzgtw);
        if (orzgtw==1)
        {
            scanf("%d",&x);
            if (x>now/2)
            {
                x=now-x;
                bb^=1;
                if (bb)
                {
                    stt=en-x;
                    end=en;
                }
                else
                stt=st,end=st+x;
                int pp=1;
                if (bb)
                {
                    for (j=stt+1;j<=end;j++)
                    {
                        add(j-2*pp+1,ff[j]);
                        ff[j-2*pp+1]+=ff[j];
                        pp++;
                    }
                    en=stt;
                }
                else
                {
                    int pp=end-stt;
                    for (j=stt;j<end;j++)
                    {
                        add(j+2*pp-1,ff[j]);
                        ff[j+2*pp-1]+=ff[j];
                        pp--;
                    }
                    st=end;
                }
            
            }
            else
            {
                if (bb)
                {
                    stt=en-x;
                    end=en;
                }
                else
                stt=st,end=st+x;
                int pp=1;
                if (bb)
                {
                    for (j=stt+1;j<=end;j++)
                    {
                        add(j-2*pp+1,ff[j]);
                        ff[j-2*pp+1]+=ff[j];
                        pp++;
                    }
                    en=stt;
                }
                else
                {
                    int pp=end-stt;
                    for (j=stt;j<end;j++)
                    {
                        add(j+2*pp-1,ff[j]);
                        ff[j+2*pp-1]+=ff[j];
                        pp--;
                    }
                    st=end;
                }
            }           
        }
        else
        {
            scanf("%d%d",&x,&y);
            if (bb)
            {
                x=en-x,y=en-y;
            }
            else
            {
                x=st+x-1,y=st+y-1;
            }
            if (x>y)
            swap(x,y);
            printf("%d\n",ask(y)-ask(x));
        }
    }
}