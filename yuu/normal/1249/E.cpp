#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[200001];
int b[200001];
int main(){
    cin>>n>>c;
    for(int i=2; i<=n; i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=2; i<=n; i++){
        cin>>b[i];
        b[i]+=b[i-1];
    }
    int mia=0;
    int mib=0;
    int f=0;
    cout<<f<<' ';
    for(int i=2; i<=n; i++){
        f=min(mia+a[i], mib+b[i]+c);
        mia=min(mia, f-a[i]);
        mib=min(mib, f-b[i]);
        cout<<f<<" \n"[i==n];
    }
}