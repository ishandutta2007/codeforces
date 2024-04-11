#include<bits/stdc++.h>
#define maxn 500050
using namespace std;
typedef long long LL;

int m,k,n,s;

int a[maxn],b[maxn];

int M;
int cnt[maxn],con[maxn];

void init() {
    scanf("%d%d%d%d",&m,&k,&n,&s);
    for (int i=1;i<=m;++i)
        scanf("%d",a+i);
    for (int i=1;i<=s;++i)
        scanf("%d",b+i),++con[b[i]];
}

void insert(int x)  {
    if (cnt[x]++<con[x])
        --M;
}

void erase(int x)   {
    if (cnt[x]--<=con[x])
        ++M;
}

void print(int l,int r) {
    // cout<<l<<" "<<r<<endl;
    memset(cnt,0,sizeof(cnt));
    vector<int> pos;
    for (int i=1;i<l%k;++i) pos.push_back(i);
    for (int c=0,i=l;i<=r;++i)  {
        if (r-l+1==c+k) break;
        if (cnt[a[i]]==con[a[i]])
            pos.push_back(i),++c;
        else
            ++cnt[a[i]];
        // cout<<i<<" "<<r-l+1<<" "<<c<<" "<<k<<endl;
    }

    printf("%d\n",pos.size());
    for (int i:pos)
        printf("%d ",i);
}

void solve()    {
    M=s;
    for (int i=1,j=1;i<=m;++i)  {
        while (j<=m&&(M||j-i<k))
            insert(a[j++]);
        // cout<<i<<" "<<j<<" "<<M<<" "<<(i-1)/k+1+(m-j+1)/k<<endl;
        if (M||j-i<k) break;
        if ((i-1)/k+1+(m-j+1)/k>=n)   {
            print(i,j-1);
            return ;
        }
        erase(a[i]);
    }
    puts("-1");
}

int main()  {
    init();
    solve();
    return 0;
}