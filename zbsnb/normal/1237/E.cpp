#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> mp;
    int now=2,flg=-1;
    while(now<=1000010){
        mp[now]=mp[now+flg]=1;
        now=(now<<1)+flg+1,flg=-flg;
    }
    int n;cin>>n;
    cout<<mp[n]<<endl;
}