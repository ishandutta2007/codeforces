#include<bits/stdc++.h>
#define ll long long
#define inf (1e16)
using namespace std;

ll n,m,q,num,a[301000]={0},b[301000]={0},c[301000]={0},tot=0,p;

void in(ll &x){
    scanf("%I64d",&x);
}
void out(ll x){
    printf("%I64d\n",x);
}

void doit(){
    p=lower_bound(c+1,c+num+2,tot)-c;
    out( min(tot-c[p-1],c[p]-tot) );
}

int main(){
    in(n);in(m);in(q);num=m-n+1;
    for (int i=1;i<=n;i++){
        in(a[i]);
        tot+=(i&1)?a[i]:-a[i];
    } 
    for (int i=1;i<=m;i++) in(b[i]);
    for (int i=m;i>0;i--){
    	c[i]=b[i]-c[i+1]+((n&1)?b[i+n]:-b[i+n]);
	}
    sort(c+1,c+num+1);
    c[0]=-inf;c[num+1]=inf;
    doit();
    for (ll l,r,x;q--;){
        in(l);in(r);in(x);
        if (l&1) tot+=x;
        if ((r+1)&1) tot-=x;
        doit();
    }
}