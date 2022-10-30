#include<bits/stdc++.h>
#define maxn 305
using namespace std;

int n,m;
char s[maxn][maxn],t[maxn][maxn];

int solve(int a,char sa,char ta,int b,char sb,char tb)  {
    int ans=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)  {
            t[i][j]=s[i][j];
            if ((i+j)%3==a&&t[i][j]==sa)    t[i][j]=ta,++ans;
            if ((i+j)%3==b&&t[i][j]==sb)    t[i][j]=tb,++ans;
        }
    return ans;
}

void print()    {
    for (int i=1;i<=n;++i)  {
        for (int j=1;j<=n;++j)
            putchar(t[i][j]);
        puts("");
    }
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n),m=0;
        for (int i=1;i<=n;++i)  {
            scanf("%s",s[i]+1);
            for (int j=1;j<=n;++j)
                m+=s[i][j]!='.';
        }
        if (solve(0,'X','O',1,'O','X')<=m/3)
            print();
        else
        if (solve(1,'X','O',2,'O','X')<=m/3)
            print();
        else
        if (solve(2,'X','O',0,'O','X')<=m/3)
            print();
        else
            assert(0);
    }
    return 0;
}