#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[26][26];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll now=1;
    for(int i=24;i>=2;i-=2,now<<=2){
        ll k=now;
        for(int j=25;j>=1;j--,k<<=1){
            a[i][j]=k;
        }
    }
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        ll sum;cin>>sum;
        int x=1,y=1;
        while(x<=n&&y<=n){
            cout<<x<<" "<<y<<endl;
            sum-=a[x][y];
            if(x%2){
                if(x<n&&a[x+1][y]<=sum) x++;
                else y++;
            }
            else{
                if(y<n&&a[x][y+1]<=sum) y++;
                else x++;
            }
        }
    }
}