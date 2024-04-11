#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
inline ll query(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    return read();
}
int n;
inline void work(){
    n=read();
    ll sum=query(1,n);
    int l=1,r=n;
    while(l<=r){
	int mid=(l+r)>>1;
	if(!query(mid,n))r=mid-1;
	else l=mid+1;
    }
    ll a=query(1,l-1);
    a=l-(sum-a);
    ll y=query(1,a-1),b=a-1-(y-query(1,a-2));
    cout<<"! "<<b<<" "<<a<<" "<<l<<endl;
}
int main(){
//    freopen("1.in","r",stdin);
    //   freopen("1.out","w",stdout);
    int test=read();
    while(test--)work();
    return 0;
}