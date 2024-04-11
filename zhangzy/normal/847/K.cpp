#include<bits/stdc++.h>
using namespace std;

int n,a,b,k,f,ans=0;
string s[333][2];
vector<int>v;
bool cmp(int x,int y){
    return x>y;
}
map<string,int>mp;
map<string,int>::iterator it;

void add(int x,string s1,string s2){
    if (s1>s2) swap(s1,s2);
    s1+=s2;
    mp[s1]+=x;
    ans+=x;
}

int main(){
    cin>>n>>a>>b>>k>>f;
    for (int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        if (i==1||s[i][0]!=s[i-1][1]){
            add(a,s[i][0],s[i][1]);
        }else{
            add(b,s[i][0],s[i][1]);
        }
    }
    int x;
    for (it=mp.begin();it!=mp.end();it++){
        x=it->second;
        if (x>f) v.push_back(x-f);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<min(k,(int)v.size());i++){
        ans-=v[i];
    }
    cout<<ans;
}