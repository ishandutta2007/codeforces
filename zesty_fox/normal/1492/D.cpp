#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int a,b,k;
int main(){
    a=rdi(),b=rdi(),k=rdi();
    swap(a,b);
    if(k==0){
        puts("Yes");
        cout<<string(a,'1')<<string(b,'0')<<endl<<string(a,'1')<<string(b,'0')<<endl;
        return 0;
    }
    for(int lowb=0;lowb<b;lowb++){
        int y=k-b+lowb;
        if(y<0) continue;
        for(int x=1;x<=min(a-y-1,b-lowb);x++){
            puts("Yes");
            cout<<string(a,'1')<<string(b,'0')<<endl;
            cout<<string(a-x-y,'1')<<string(x-1,'0')<<'0'<<string(y,'1')<<string(x-1,'1')<<string(b-lowb-x,'0')<<'1'<<string(lowb,'0')<<endl;
            return 0;
        }
    }
    puts("No");
    return 0;
}