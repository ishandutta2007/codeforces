#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n,x,y,xor_sum,ans1,ans2;

int _query(const vi &v){
    if(v.empty()) return 0;
    cout<<"? "<<v.size()<<" ";
    for(auto x:v) cout<<x<<" ";
    cout<<endl;return rdi();
}

bool query(const vi &v){
    int val=_query(v);
    if(v.size()&1) return val==y;
    else return val==(x^y);
}

int main(){
    n=rdi(),x=rdi(),y=rdi();
    for(int i=__lg(n);i>=0;i--){
        vi tmp;
        for(int j=1;j<=n;j++) if((j-1)>>i&1) tmp.pb(j);
        if(query(tmp)) xor_sum|=(1<<i);
    }

    for(int i=__lg(n);i>=0;i--){
        if(xor_sum>>i&1){
            vi tmp;
            for(int j=1;j<=n;j++) if((j-1)>>i&1) tmp.pb(j);
            int l=0,r=tmp.size()-1;
            while(l<r){
                int mid=(l+r)/2;
                if(query(vi(tmp.begin(),tmp.begin()+mid+1))) r=mid;
                else l=mid+1;
            }
            ans1=tmp[l];break;
        }
    }
    ans2=((ans1-1)^xor_sum)+1;
    if(ans1>ans2) swap(ans1,ans2);
    cout<<"! "<<ans1<<" "<<ans2<<endl;
    return 0;
}