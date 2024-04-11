#include<stdio.h>
#include<set>
using namespace std;
struct lgs
{
    long long id,x;
}yy;
struct syf
{
    bool operator()(const lgs &a,const lgs &b) 
    {
        if (a.x<b.x) return true;
        if (a.x==b.x&&a.id<b.id) return true;
        return false;
    }
};
set<long long>gt[3];
set<long long>::iterator gtw;
set<lgs,syf>s[3];
set<lgs,syf>::iterator ss;
long long i,j,k,l,m,n,p,q,tot;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&p);
    gt[1].insert(0);gt[1].insert(n);
    gt[2].insert(0);gt[2].insert(m);
    yy.x=n;yy.id=1;s[1].insert(yy);
    yy.x=m;yy.id=2;s[2].insert(yy);
    tot=2;
    for (i=1;i<=p;i++)
    {
        char c=getchar();
        while (c!='H'&&c!='V')
        c=getchar();
        if (i==3)
        i=3;
        if (c=='V')
        {
            scanf("%I64d",&q);
            gtw=gt[1].lower_bound(q);
            long long xx=*gtw;
            gtw--;
            long long xxx=*gtw;
            yy.x=xx-xxx;
            yy.id=0;
            gt[1].insert(q);
            ss=s[1].lower_bound(yy);
            s[1].erase(ss);
            yy.x=q-xxx;
            yy.id=++tot;
            s[1].insert(yy);
            yy.x=xx-q;
            yy.id=++tot;
            s[1].insert(yy);
        }
        else
        {
            scanf("%I64d",&q);
            gtw=gt[2].lower_bound(q);
            long long xx=*gtw;
            gtw--;
            long long xxx=*gtw;
            yy.x=xx-xxx;
            gt[2].insert(q);
            yy.id=0;
            ss=s[2].lower_bound(yy);
            s[2].erase(ss);
            yy.x=q-xxx;
            yy.id=++tot;
            s[2].insert(yy);
            yy.x=xx-q;
            yy.id=++tot;
            s[2].insert(yy);
        }
        ss=s[1].end();ss--;
        long long pp=(*ss).x;
        ss=s[2].end();ss--;
        printf("%I64d\n",1ll*pp*(*ss).x);
    }
}