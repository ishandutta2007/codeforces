#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

char s[10001000];
int n;

vector<int>sep;

void lindon(){
    for (int i=0;i<n;){
        sep.push_back(i);
        int p1=i, p2=i+1;
        while (p2<n&&s[p1]<=s[p2]){
            if (s[p1]==s[p2]) ++p1, ++p2;
            else p1=i, ++p2;
        }
        int len=p2-p1;
        while (i<=p1) i+=len;
    }
}

int z[10001000];
void exkmp(){
    int id, mx=-1;
    for (int i=1;i<=2*n;++i){
        int p=0;
        if (mx>i) p=max(p,min(mx-i,z[i-id]));
        while (p<=2*n&&s[p]==s[i+p]) ++p;
        z[i]=p; if (i+p>mx) id=i, mx=i+p;
    }
    z[0]=2*n+1;
}

string ans;

bool same(string s){
    string t=s; reverse(t.begin(),t.end());
    return s==t;
}

int T, m;
void rua3(){
    sep.push_back(n); m=sep.size()-2;
    while (T>=3&&m>=0){
        ans+=string(s+sep[m],sep[m+1]-sep[m]); --m;
        if (!(m>=0&&same(string(s+sep[m],sep[m+1]-sep[m]))&&same(string(s+sep[m+1],sep[m+2]-sep[m+1])))) --T;
    }
}

int rev(int x){
    return 2*n-x;
}

string fix(string s){
    string t=s; reverse(t.begin(),t.end());
    return min(s,t);
}

ll bas1, bas2, mod1, mod2, hasinit;
bool ispri(int x){
  for (int i=2;i*i<=x;++i) if (x%i==0) return 0;
  return 1;
}
int ranpri(int l,int r){
  for (;;){
    ll tmp= rand()%10000*(1e8) +rand()%10000*(1e4) +rand()%10000;
    tmp= tmp%(r-l+1)+l;
    if (ispri(tmp)) return tmp;
  }
}
struct HASH{
  static const int mxlen=1e7+10;
  int nn, h1[mxlen+233], h2[mxlen+233], p1[mxlen+233], p2[mxlen+233];
  
  void init(char *s,int n){  // s: [0,n)
    if (!hasinit){
      srand(time(0)); hasinit=1;
      bas1=ranpri(1e3,1e4); bas2=ranpri(1e3,1e4);
      mod1=ranpri(5e8,1e9); mod2=ranpri(5e8,1e9);
    }
    nn=n;
    h1[0]=h2[0]=0; p1[0]=p2[0]=1;
    for (int i=1;i<=n;++i){
      h1[i]= (h1[i-1]*bas1+s[i-1])%mod1;
      h2[i]= (h2[i-1]*bas2+s[i-1])%mod2;
      p1[i]= p1[i-1]*bas1%mod1;
      p2[i]= p2[i-1]*bas2%mod2;
    }
  }

  pii gay(int l,int r){  //   [l,r)
    if (r>nn) return (pii){rand(),rand()};
    int res1= (h1[r]-(ll)h1[l]*p1[r-l]%mod1+mod1)%mod1;
    int res2= (h2[r]-(ll)h2[l]*p2[r-l]%mod2+mod2)%mod2;
    return (pii){res1,res2};
  }
}hs;

int fuck(int pa,int pb,int lim){
    int lcp=0;
    for (int i=25;i>=0;--i)
        if (hs.gay(pa,pa+(1<<i))==hs.gay(pb,pb+(1<<i))){
            pa+=1<<i; pb+=1<<i;
            lcp+=1<<i;
        }
    if (lcp>=lim) return 0;
    return s[pa]<s[pb]? 1: -1;
}

vector<pii> hashmin(vector<pii>a,vector<pii>b){
    if (!a.size()||!b.size()) return max(a,b);
    if (a[0].se>b[0].se) swap(a,b);
    {
        int t=fuck(a[0].fi, b[0].fi, a[0].se);
        if (t) return t==1? a: b;
    }
    {
        int t=fuck(a[1].fi, b[0].fi+a[0].se, b[0].se-a[0].se);
        if (t) return t==1? a: b;
    }
    {
        int t=fuck(a[1].fi+b[0].se-a[0].se, b[1].fi, b[1].se);
        if (t) return t==1? a: b;
    }
    return a;
}

string gaolas(){
    int l=sep[m+1];
    string res=fix(string(s,l));
    if (T<=1||m<=0) return res;
    {
        int mn=0; char c1, c2;
        for (int i=1;i<l-1;++i){
            int lcp1=z[rev(i)];
            if (lcp1<i-mn){
                c1=s[i-lcp1];
                c2=s[lcp1];
            }else{
                int lcp2=z[i-mn];
                c1=s[lcp2];
                c2=s[i-mn+lcp2];
            }
            if (c1>c2) mn=i;
        }
        string t1(s,mn+1), t2(s+mn+1,l-mn-1);
        reverse(t2.begin(),t2.end());
        string t=t2+t1;
        res=min(res,t);
    }
    {
        vector<pii>best;
        for (int i=m;i>=0&&i>=m-25;--i){
            // string t1=fix(string(s,sep[i])), t2=string(s+sep[i],l-sep[i]);
            // string t=t2+t1;
            // res=min(res,t);
            {
                vector<pii>v;
                v.push_back({sep[i],l-sep[i]});
                v.push_back({0,sep[i]});
                best=hashmin(best,v);
            }
            {
                vector<pii>v;
                v.push_back({sep[i],l-sep[i]});
                v.push_back({rev(sep[i]-1),sep[i]});
                best=hashmin(best,v);
            }
        }
        string tmp=string(s+best[0].fi,best[0].se)+string(s+best[1].fi,best[1].se);
        res=min(res,tmp);
    }
    return res;
}

int main(){
    scanf("%s%d",s,&T); n=strlen(s);
    for (int i=0;i<n;++i) s[i+n+1]=s[i];
    reverse(s,s+n); s[n]='#'; s[n*2+1]='$';
    
    lindon();

    exkmp();

    hs.init(s,2*n+1);

    rua3();

    ans+=gaolas();

    printf("%s\n",ans.c_str());
}