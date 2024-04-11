#include <bits/stdc++.h>
using namespace std;
string s;
inline int ask(int x,int y){cout<<"? "<<x<<' '<<y<<endl;cin>>s;return s=="x";}
bool solve(){
    cin>>s;if(s=="end") return false;
    int L=0,R=1,l,r;while(!ask(L,R)) L=R,R<<=1;
    l=L+1,r=R;
    while(l<r){int mid=(l+r)>>1;if(!ask(L,mid)) l=mid+1;else r=mid;}
    cout<<"! "<<l<<endl;return true;
}
int main(){ios::sync_with_stdio(0);while(solve());return 0;}