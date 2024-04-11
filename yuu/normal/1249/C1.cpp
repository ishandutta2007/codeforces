#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        long long n;
        cin>>n;
        vector <int> temp;
        while(n>0){
            temp.push_back(n%3);
            n/=3;
        }
        for(int i=temp.size()-1; i>=0; i--) if(temp[i]==2){
            temp.push_back(0);
            for(int j=i; j<temp.size(); j++){
                if(temp[j]%3==2) temp[j]++;
                temp[j+1]+=temp[j]/3;
                temp[j]%=3;
            }
            for(int j=i-1; j>=0; j--) temp[j]=0;
            break;
        }
        reverse(temp.begin(), temp.end());
        long long ans=0;
        for(int x: temp) (ans*=3)+=x;
        cout<<ans<<'\n';
    }
}