#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
map<string,int> mp;
multiset<char> s[110];
int main(){
    int n;cin>>n;
    if(n==1){
        cout<<"? 1 1"<<endl;
        string tmp;cin>>tmp;
        cout<<"! "<<tmp<<endl;
        return 0;
    }
    cout<<"? 2 "<<n<<endl;
    for(int i=1;i<=n*(n-1)/2;i++){
        string tmp;cin>>tmp;
        sort(tmp.begin(),tmp.end());
        mp[tmp]++;
    }
    cout<<"? 1 "<<n<<endl;
    for(int i=1;i<=n*(n+1)/2;i++){
        string tmp;cin>>tmp;
        sort(tmp.begin(),tmp.end());
        mp[tmp]--;
        if(mp[tmp]==-1){
            for(auto &it:tmp)
                s[tmp.size()].insert(it);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            s[j].erase(s[j].find(*s[i].begin()));
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<*s[i].begin();
    }
    cout<<endl;
}