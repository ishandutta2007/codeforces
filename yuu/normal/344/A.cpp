#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<(unique(a+1, a+n+1)-a-1)<<'\n';
}