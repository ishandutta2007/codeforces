#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
    LL x,y,z;
    node(LL _x=0,LL _y=0,LL _z=0)   {
        x=_x,y=_y,z=_z;
    }
    node operator + (const node& N) {
        return node(x+N.x,y+N.y,z+N.z);
    }
};

LL step(LL x)   {   return 1LL<<(x*2);  }
LL sum(LL x)    {   return !x?1:sum(x-1)+step(x);  }

void belong(LL n,LL &x,LL &y) {
    LL sum=0;
    for (int t=0;t<30;++t)  {
        // cout<<t<<":"<<sum<<" "<<step(t)<<" "<<n<<endl;
        if (sum+step(t)<=n)
            sum+=step(t);
        else    {
            x=t,y=(n-sum);
            return ;
        }
    }
    assert(0);
}

const LL a[]={0,2,3,1},b[]={0,3,1,2};

node find(LL x,LL y)   {
    if (!x) return node(0,0,0);
    LL t=step(x-1);
    // cout<<"find:"<<x<<" "<<y<<" ~ "<<t<<" "<<t*(y/t)<<" "<<t*a[y/t]<<" "<<t*b[y/t]<<endl;
    return find(x-1,y%t)+node(t*(y/t),t*a[y/t],t*b[y/t]);
}

LL calc(LL n)   {
    LL x,y;
    belong(n/3,x,y);
    // cout<<"x y:"<<x<<" "<<y<<endl;
    node now=find(x,y);
    // cout<<"now:"<<now.x<<" "<<now.y<<" "<<now.z<<endl;
    switch (n%3)    {
        case 0: return now.x+step(x);
        case 1: return now.y+step(x)*2;
        case 2: return now.z+step(x)*3;
    }
    assert(0);
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        LL n;
        scanf("%lld",&n);
        printf("%lld\n",calc(n-1));
    }
    return 0;
}