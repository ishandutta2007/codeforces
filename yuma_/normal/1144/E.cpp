#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int N;cin>>N;
    string l,r;cin>>l>>r;
    vector<int>lv,rv;
    for(int i=0;i<N;++i){
        lv.push_back(l[i]-'a');
        rv.push_back(r[i]-'a');
    }
    vector<int>ansv(N);
    for(int i=0;i<N;++i){
        ansv[i]=lv[i]+rv[i];
    }
    for(int i=0;i<N;++i){
        if(ansv[i]%2){
            ansv[i+1]+=26;
        }
        ansv[i]/=2;
    }
    for(int i=N-1;i>=0;--i){
        if(ansv[i]>=26){
            ansv[i]-=26;
            ansv[i-1]++;
        }
    }
    string ansst;
    for(int i=0;i<N;++i){
        ansst.push_back('a'+ansv[i]);
    }
    cout<<ansst<<endl;
    return 0;   
}