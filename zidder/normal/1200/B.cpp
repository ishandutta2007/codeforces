#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    bool answer=true;
    int last_h, h;
    cin>>last_h;
    for (int i=1;i<n;i++){
        cin>>h;
        if (h <= last_h+k){
            int d = h - k;
            if (d < 0) d=0;
            m += last_h-d;
        }
        else{
            if (m < h-last_h-k)
                answer=false;
            m -= h - last_h - k;
        }
        last_h=h;
    }
    if (answer)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}