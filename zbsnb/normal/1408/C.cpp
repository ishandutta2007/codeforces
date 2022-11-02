#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<setprecision(9)<<fixed;
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        double l=0,r=x,t=0;
        int posl=1,posr=n,vl=1,vr=1;
        while(posl<=posr){
            double t1=abs(a[posl]-l)/vl;
            double t2=abs(a[posr]-r)/vr;
            if(t1<t2){
                l+=t1*vl;
                r-=t1*vr;
                t+=t1;
                vl++;
                posl++;
            }
            else{
                l+=t2*vl;
                r-=t2*vr;
                t+=t2;
                vr++;
                posr--;
            }
            // cout<<posl<<" "<<posr<<" "<<vl<<" "<<vr<<endl;
            // cout<<t<<" "<<l<<" "<<r<<endl;
        }
        t+=(r-l)/(vl+vr);
        cout<<t<<endl;
    }
}