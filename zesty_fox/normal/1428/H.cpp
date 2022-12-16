#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define pb push_back
#define mp make_pair

const int N=1010;

int n,m,pos[N];
vi s;

int qry(int x,int fx){
    cout<<"? "<<x<<" "<<fx<<endl;
    return rdi();
}

void asw(int *a){
    cout<<"! ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<n;i++) s.pb(i);
    int cur=0,tot=n*m,i1=qry(0,-1),i2=qry(0,1),i3=qry(0,1);
    while(!s.empty()){
        if(i2-i1==1&&i3-i2!=1){
            int l=0,r=s.size()-1,mid=(l+r)>>1;
            for(int i=l;i<=mid;i++) qry(s[i],-1);
            int now=qry(0,-1);
            while(l<r){
                int nxt=qry(0,-1);
                if(nxt>=now){
                    r=mid;mid=(l+r)>>1;
                    for(int i=mid+1;i<=r;i++) qry(s[i],1);
                }
                else{
                    l=mid+1;mid=(l+r)>>1;
                    for(int i=l;i<=mid;i++) qry(s[i],-1);
                }
                now=qry(0,1);
            }
            int x=s[l];s.erase(s.begin()+l);
            for(int i=1;i<=m;i++) qry(x,-1);
            pos[x]=(cur-(m+1)+tot)%tot;
            
            i1=qry(0,-1),i2=qry(0,1),i3=qry(0,1);
        }
        else{
            cur=(cur+1)%tot;
            i1=i2;i2=i3;i3=qry(0,1);
        }
    }
    cur=(cur+1)%tot;
    for(int i=1;i<n;i++) pos[i]=(pos[i]+tot-cur)%tot;
    asw(pos+1);
    return 0;
}////