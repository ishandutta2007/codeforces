#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int f[200001][2];
///f[i][0] i is in the increasing, f[i][0] is max of dec
bool trace[200001][2];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) f[i][0]=-1e9;
    for(int i=1; i<=n; i++) f[i][1]=1e9;
    f[1][0]=1e9;
    f[1][1]=-1e9;
    for(int i=1; i<n; i++){
        if(a[i]>a[i+1]){
            if(f[i+1][1]>f[i][1]){
                f[i+1][1]=f[i][1];
                trace[i+1][1]=1;
            }
        }
        else if(a[i]<a[i+1]){
            if(f[i+1][0]<f[i][0]){
                f[i+1][0]=f[i][0];
                trace[i+1][0]=0;
            }
        }
        if(f[i][0]>a[i+1]){
            if(f[i+1][1]>a[i]){
                f[i+1][1]=a[i];
                trace[i+1][1]=0;
            }
        }
        if(f[i][1]<a[i+1]){
            if(f[i+1][0]<a[i]){
                f[i+1][0]=a[i];
                trace[i+1][0]=1;
            }
        }
    }
    int b;
    if(f[n][0]!=-1e9) b=0;
    else if(f[n][1]!=1e9) b=1;
    else{
        puts("NO");
        return 0;
    }
    puts("YES");
    vector <int> temp;
    for(int i=n; i>0; i--){
        temp.push_back(b);
        b=trace[i][b];
    }
    reverse(temp.begin(), temp.end());
    for(int x: temp) cout<<x<<' ';
}