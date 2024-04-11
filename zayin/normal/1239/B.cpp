#include<bits/stdc++.h>
#define maxn 700050
using namespace std;

int n;
char s[maxn];
int a[maxn];

int cnt[maxn];
int match[maxn];
int dep[maxn];

int stk[maxn],tp;

int main()  {
    scanf("%d%s",&n,s+1);
    for (int i=1;i<=n;++i)
        s[i+n]=s[i];
    
    for (int i=1;i<=n+n;++i)    {
        a[i]=a[i-1];
        if (s[i]=='(')
            ++a[i];
        else
            --a[i];
    }

    int st=1;
    for (int i=1;i<=n;++i)
        if (a[i-1]<a[st-1])
            st=i;
    

    // cout<<"st:"<<st<<endl;

    int flag=1;
    for (int i=st;i<st+n;++i)   {
        if (s[i]=='(')  {
            ++cnt[stk[tp]];
            stk[++tp]=i;
            dep[i]=tp;
        } else  {
            if (!tp)    {
                flag=0;
                break;
            } else  {
                match[stk[tp--]]=i;
            }
        }
    }

    if (tp)
        flag=0;
    // cout<<"flag:"<<flag<<endl;

    if (!flag)  {
        puts("0");
        puts("1 1");
    } else  {
        int ans,sum=0,l=1,r=1;
        for (int i=st;i<st+n;++i)
            if (dep[i]==1)
                ++sum;
        ans=sum;
        for (int i=st;i<st+n;++i)   {
            if (s[i]==')') continue;
            // cout<<i<<" "<<match[i]<<endl;
            if (dep[i]==1)  {
                if (ans<cnt[i]+1)
                    ans=cnt[i]+1,l=i,r=match[i];
            }
            if (dep[i]==2)  {
                if (ans<sum+cnt[i]+1)
                    ans=sum+cnt[i]+1,l=i,r=match[i];
            }
        }
        printf("%d\n%d %d\n",ans,(l-1)%n+1,(r-1)%n+1);
    }
    return 0;
}