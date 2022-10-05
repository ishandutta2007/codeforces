#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, ty[101000];

int calc(int i){
    if (i<1||i>n) return 1e9;
    cout<<"? "<<i<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    return x;
}

void chk(int i){
    int l=calc(i-1), m=calc(i), r=calc(i+1);
    if (m<l&&m<r){
        cout<<"! "<<i<<endl;
        exit(0);
    }
    ty[i]= l>r? -1: 1;
}

int main(){
    cin>>n;
    chk(1);
    chk(n);
    int l=2, r=n-1;
    while (1){
        int mid=l+r>>1;
        chk(mid);
        if (ty[mid]==1){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
}