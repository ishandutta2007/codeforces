#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;cin>>m>>n>>k;
    if(k>4*n*m-2*n-2*m){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl; 

    if(n==1){
        if(k<=m-1){
            cout<<1<<endl;
            cout<<k<<" D"<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<m-1<<" D"<<endl;
            cout<<k-(m-1)<<" U"<<endl;
        }
        return 0;
    }

    if(m==1){
        if(k<=n-1){
            cout<<1<<endl;
            cout<<k<<" R"<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<n-1<<" R"<<endl;
            cout<<k-(n-1)<<" L"<<endl;
        }
        return 0;
    }

    int tmp=k/(4*(n-1)+1);
    vector<pair<int,string> > ans;

    int rest=k%(4*(n-1)+1);
    if(tmp>=m){
        rest+=(tmp-(m-1))*(4*(n-1)+1);
        tmp=m-1;
    }

    for(int i=1;i<=tmp;i++){
        ans.push_back({n-1,string("RDU")});
        ans.push_back({n-1,string("L")});
        ans.push_back({1,string("D")});
    }
    if(tmp==m-1){
        if(rest<=n-1){
            ans.push_back({rest,string("R")});
        }
        else{
            ans.push_back({n-1,string("R")});
            rest-=n-1;
            if(rest<=n-1){
                ans.push_back({rest,string("L")});
            }
            else{
                ans.push_back({n-1,string("L")});
                rest-=n-1;
                ans.push_back({rest,string("U")});
            }
        }
    }
    else{
        if(rest<=3*(n-1)){
            int rrest=rest%3;
            int cnt=rest/3;
            ans.push_back({cnt,string("RDU")});
            if(rrest>=1)ans.push_back({1,"R"});
            if(rrest>=2)ans.push_back({1,"D"});
        }
        else{
            ans.push_back({n-1,"RDU"});
            rest-=3*(n-1);
            ans.push_back({rest,"L"});
        }
    }

    int tot=ans.size();
    for(auto &it:ans){
        if(it.first==0)tot--;
    }

    cout<<tot<<endl;
    for(auto &it:ans){
        if(it.first!=0)cout<<it.first<<" "<<it.second<<endl;
    }

    // string ans;
    // for(int i=1;i<n;i++){
    //     ans+="RDU";
    // }
    // for(int i=1;i<n;i++){
    //     ans+="L";
    // }
    // ans+="D";
    // string anss;
    // for(int i=1;i<=m;i++){
    //     if(i!=m)anss+=ans;
    //     else{
    //         for(int i=1;i<n;i++)anss+="R";
    //         for(int i=1;i<n;i++)anss+="L";
    //         for(int i=1;i<m;i++)anss+="U";
    //     }
    // }
    // cout<<"1\n1 ";
    // for(int i=0;i<k;i++){
    //     cout<<anss[i];
    // }
    // cout<<endl;
}