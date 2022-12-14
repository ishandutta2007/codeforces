#include<bits/stdc++.h>

using namespace std;
int a[101];
int manu(int mid){
    int ans=0;
    for(int i=1;i<=100;i++)
        ans+=a[i]/mid;
    return ans;
}

int main(){
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        a[x]++;
    }
    int left=0,right=100,mid;
    while(left<right){
        mid=(left+right+1)/2;
        if(manu(mid)<n)
            right=mid-1;
        else    left=mid;
    }
    cout<<left<<endl;
}