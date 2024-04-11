#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(){
    cin>>n>>k;
    k=min(k, n-k+1);
    cout<<n+n+1+k-1+n-1;
}