#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n,m;
int x[maxn],y[maxn];

int main()  {
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=n;++i)
            cin>>x[i]>>y[i];
        
        bool ans=0;
        for (int i=1;i<=n;++i)  {
            bool flag=1;
            for (int j=1;j<=n;++j)
                flag&=abs(x[i]-x[j])+abs(y[i]-y[j])<=m;
            ans|=flag;
        }
        cout<<(ans?1:-1)<<endl;
    }
    return 0;
}