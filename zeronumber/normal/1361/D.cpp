#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int maxn=1e6+10;
map<pi,vi> f;
vector <db> ans;
vi rb;
db rl=0;
int n,m,id,mx;
db sqr(int x){return (db)x*x;}
mt19937_64 gen(time(0));
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        int x,y; scanf("%d%d",&x,&y);
        //x=-gen()%1000000000;
        //y=gen()%1000000000;
        if (x==0&&y==0) continue;
        int d=abs(__gcd(x,y));
        f[(pi){x/d,y/d}].pb(d);
    }
    id=1;

    for (auto tmp:f){
        db len=sqrt(sqr(tmp.F.F)+sqr(tmp.F.S));
        vi a=tmp.S; sort(a.begin(),a.end());
        mx=max(mx,(int)a.size());
        if (a.size()*2>n) rb=a,rl=len;
        reverse(a.begin(),a.end());
        for (int j=0;j<a.size();j++) {
            int xi=m-(2*j+1);
            if (xi>0) ans.pb(len*a[j]*(m-(2*j+1)));
        }
    }

    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    db A=0;
    if (ans.size()<m){
        for (auto x:ans) A+=x;
        int last=0;
        for (int j=0;j<rb.size();j++){
            int tot=n-mx+j;
            if (tot<m/2) {
                A-=rl*(rb[j]-last)*(m/2)*(m-m/2);
                A+=rl*(rb[j]-last)*tot*(m-tot);
            }
            last=rb[j];
        }
    } else {
        for (int i=0;i<m;i++) A+=ans[i];
    }
    printf("%.10f\n",A);
    return 0;
}