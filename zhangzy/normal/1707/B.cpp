#include<bits/stdc++.h>
using namespace std;

int n, q, a[101000], T, ans[101000];

int main(){
    for (cin>>T;T--;){
        cin>>n;
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        for (int iter=n-1;iter>0;--iter){
            sort(a+1,a+n+1,greater<int>());
            for (int i=1;i<n;++i) a[i]-=a[i+1];
            while (n>1&&a[n]==0) --n;
            n = min(n,iter);
        }
        cout<<a[n]<<endl;
    }
}