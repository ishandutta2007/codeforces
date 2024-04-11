#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n;

bool query(const vi &s){
    cout<<"? "<<s.size()<<' ';
    for(auto x:s) cout<<x<<' ';
    cout<<endl;
    string str;cin>>str;
    return str=="YES";
}

bool guess(int x){
    cout<<"! "<<x<<endl;
    string str;cin>>str;
    return str==":)";
}

void solve(const vi &s){
    if(s.size()==1){
        guess(s[0]);
        return;
    }
    if(s.size()==2){
        if(!guess(s[0])) guess(s[1]);
        return;
    }
    if(s.size()==3){
        int res=query({s[0],s[1]});
        if(!res){
            if(!guess(s[2]))
                guess(query({s[0]})?s[0]:s[1]);
        }
        else{
            int res1=query({s[0],s[1]});
            if(res1){
                if(!guess(s[0])) guess(s[1]);
            }
            else{
                if(!guess(s[2]))
                    guess(query({s[0]})?s[0]:s[1]);
            }
        }
        return;
    }
    vi tmp;
    for(int i=0;i<s.size();i++)
        if(i&1) tmp.pb(s[i]);
    int res1=query(tmp);
    tmp.clear();
    for(int i=0;i<s.size();i++)
        if(i&2) tmp.pb(s[i]);
    int res2=query(tmp)*2;
    tmp.clear();
    for(int i=0;i<s.size();i++)
        if((i&1)==res1||(i&2)==res2)
            tmp.pb(s[i]);
    return solve(tmp);
}

int main(){
    n=rdi();
    vi tmp(n);
    for(int i=0;i<n;i++) tmp[i]=i+1;
    solve(tmp);
    return 0;
}