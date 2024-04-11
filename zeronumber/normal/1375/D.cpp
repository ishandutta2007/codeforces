#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e5+3;
const int M=1000000007;
int _,n,a[1005];
int mex(){
    bool f[1005];
    for (int i=0;i<=n;i++) f[i]=0;
    for (int i=0;i<n;i++) f[a[i]]=1;
    int ret=0;
    while (f[ret]) ++ret;
    return ret;
}

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int m=n;
        vector <int> ans; ans.clear();
        while (m){
            while (mex()<m){
                int x=mex();
                ans.pb(x); a[x]=x;
            }
            assert(mex()==m);
            a[m-1]=mex(); ans.pb(m-1);
            m--;
        }
        //for (int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
        printf("%d\n",(int)ans.size());
        for (auto x:ans) printf("%d ",x+1); puts("");
    }
    return 0;
}