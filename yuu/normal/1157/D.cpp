#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main(){
    cin>>n>>k;
    if(k*(k+1)/2>n){
        puts("NO");
        return 0;
    }
    if((k==2&&n==4)||(k==3&&n==8)){
        puts("NO");
        return 0;
    }
    if(k==1){
        puts("YES");
        cout<<n;
        return 0;
    }
    ///kx+k*(k-1)/2
    long long low=k*(k-1)/2;
    ///max x that k*(2x+k-1)<=2n
    long long x=1;
    while(k*((x+1)*2+k-1)<=n*2) x++;
    long long more=n-k*x-k*(k-1)/2;
    if((x>1)||(more<k-1)){
        puts("YES");
        for(int i=0; i<k-more; i++) cout<<x+i<<" ";
        for(int i=k-more; i<k; i++) cout<<x+i+1<<" \n"[i+1==k];
    }
    else{
        puts("YES");
        for(int i=0; i<2; i++) cout<<x+i<<" ";
        for(int i=2; i<k-1; i++) cout<<x+i+1<<" ";
        cout<<x+k+1<<'\n';
    }
}