#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef long long ll;
ll a[8],s[maxn],ans,r,t,x,y,z;

ll p(ll u){
    return u*u-(u+1)*u/2;
}

ll q(ll u){
    return (u+2)*(u+1)*u/6+p(u)*u*3-u*u*u;
}

int main(){
    for (int i=1;i<maxn;i++)
        for (int j=1;j*i<maxn;j++)
            s[i*j]++;
    cin >> t;
    while (t--){
        scanf("%lld%lld%lld",&x,&y,&z);
        r=__gcd(__gcd(x,y),z); ans=0;
        a[1]=s[x]-s[__gcd(x,y)]-s[__gcd(x,z)]+s[r];
        a[2]=s[y]-s[__gcd(x,y)]-s[__gcd(y,z)]+s[r];
        a[4]=s[z]-s[__gcd(y,z)]-s[__gcd(x,z)]+s[r];
        a[3]=s[__gcd(x,y)]-s[r];
        a[5]=s[__gcd(x,z)]-s[r];
        a[6]=s[__gcd(y,z)]-s[r];
        a[7]=s[r];
        for (int i=1;i<8;i++) for (int j=i;j<8;j++) for (int k=j;k<8;k++){
            if ((i&1)&&(j&2)&&(k&4)
            ||  (i&1)&&(k&2)&&(j&4)
            ||  (j&1)&&(i&2)&&(k&4)
            ||  (j&1)&&(k&2)&&(i&4)
            ||  (k&1)&&(i&2)&&(j&4)
            ||  (k&1)&&(j&2)&&(i&4)){
                if (i==j&&j==k) ans+=(a[i]+2)*(a[i]+1)*a[i]/6;
                else if (i==j) ans+=(a[i]+1)*a[i]*a[k]/2;
                else if (j==k) ans+=a[i]*(a[k]+1)*a[k]/2;
                else ans+=a[i]*a[j]*a[k];
            }
        }
        cout << ans << endl;
    }
    return 0;
}