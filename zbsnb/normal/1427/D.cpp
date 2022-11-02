#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x[100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i];
    vector<vector<int> > vec;
    for(int i=1;i<=n;i++){
        int flg=0;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(x[j]==x[k]+1){
                    
                    int pos=j+1;
                    while(x[pos]==x[pos-1]+1) pos++;
                    vector<int> tmp;
                    int a=j-1;
                    int b=pos-j;
                    int c=k-pos+1;
                    int d=n-k;
                    if(a!=0) tmp.push_back(a);
                    if(b!=0) tmp.push_back(b);
                    if(c!=0) tmp.push_back(c);
                    if(d!=0) tmp.push_back(d);
                    vec.push_back(tmp);

                    reverse(x+1,x+a+1);
                    reverse(x+a+1,x+a+b+1);
                    reverse(x+a+b+1,x+a+b+c+1);
                    reverse(x+a+b+c+1,x+a+b+c+d+1);
                    reverse(x+1,x+n+1);

                    flg=1;
                    break;
                }
            }
            if(flg) break;
        }
        // for(int i=1;i<=n;i++) cout<<x[i]<<" ";
        // cout<<endl;
    }
    cout<<vec.size()<<endl;
    for(auto &it:vec){
        cout<<it.size()<<" ";
        for(auto &it2:it) cout<<it2<<" ";
        cout<<endl;
    }
}