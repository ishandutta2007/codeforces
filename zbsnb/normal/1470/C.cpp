#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    mt19937 rd(time(0));
    while(1){
        int now=rd()%n+1;
        cout<<"? "<<now<<endl;
        int tmp;cin>>tmp;
        if(tmp==k) continue;
        
        if(tmp<k){
            while(1){
                now=(now==n?1:now+1);
                cout<<"? "<<now<<endl;
                cin>>tmp;
                if(tmp==k){
                    cout<<"! "<<now<<endl;
                    return 0;
                }
            }
        }

        if(tmp>k){
            while(1){
                now=(now==1?n:now-1);
                cout<<"? "<<now<<endl;
                cin>>tmp;
                if(tmp==k){
                    cout<<"! "<<now<<endl;
                    return 0;
                }
            }
        }
    }
}