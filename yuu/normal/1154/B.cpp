#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int minv=*min_element(a, a+n);
    int maxv=*max_element(a, a+n);
    if(minv==maxv){
        cout<<0;
        return 0;
    }
    if((maxv-minv)%2){
        for(int i=0; i<n; i++) if((a[i]!=minv)&&(a[i]!=maxv)){
            cout<<-1;
            return 0;
        }
        cout<<maxv-minv;
    }
    else{
        int d=(maxv-minv)/2;
        for(int i=0; i<n; i++) if((a[i]!=minv)&&(a[i]!=maxv)&&(a[i]!=minv+d)){
            cout<<-1;
            return 0;
        }
        cout<<d;
    }
}