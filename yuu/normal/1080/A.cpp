#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long get(long long x){
    return (x-1)/k+1;
}
int main(){
    cin>>n>>k;
    cout<<get(n*2)+get(n*5)+get(n*8)<<'\n';
}