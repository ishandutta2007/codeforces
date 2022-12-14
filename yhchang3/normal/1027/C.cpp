#include<bits/stdc++.h>

using namespace std;
long long int T,n,m,la,lb,lla,llb;
int a[1000010];
int b[1000010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>a[j];
        sort(a,a+n);
        m=0;
        for(int j=0;j<n-1;j++){
            if(a[j]==a[j+1]){
                b[m++]=a[j];
                j++;
            }
        }
        la=b[0];
        lb=b[1];
        for(int j=1;j<m-1;j++){
            lla=b[j];
            llb=b[j+1];
            if(lb*lla>la*llb){
                la=lla;
                lb=llb;
            }
        }
        cout<<la<<' '<<la<<' '<<lb<<' '<<lb<<endl;
    }
}