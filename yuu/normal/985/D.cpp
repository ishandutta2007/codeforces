#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
//    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
//    if(c=='-'){
//        nega=1;
//        c=getchar();
//    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
//    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
class number: public vector <ll>{
public:
    const ll base=10;
    number (ll x){
        clear();
        while(x>0){
            pb(x%base);
            x/=base;
        }
        if(empty()) pb(0);
    }
    number(){
        clear();
    }
    operator = (number x){
        clear();
        for(auto a: x) pb(a);
    }
    void fix(){
        FFOR(i, 0, size()) if(((*this)[i]>=base)||((*this)[i]<0)){
            if(i+1==size()) pb(0);
            (*this)[i+1]+=(*this)[i]/base;
            (*this)[i]%=base;
            while((*this)[i]<0){
                (*this)[i]+=base;
                (*this)[i+1]--;
            }
        }
        while((size()>1)&&(back()==0)) pop_back();
    }
    void operator +=(number s){
        while(size()<s.size()) pb(0);
        while(s.size()<size()) s.pb(0);
        FFOR(i, 0, s.size()) (*this)[i]+=s[i];
        fix();
    }
    number operator +(number x){
        x+=*this;
        return x;
    }
    number operator *(number x){
        number res;
        while(res.size()<size()+x.size()) res.pb(0);
        FFOR(i, 0, size()) FFOR(j, 0, x.size()) res[i+j]+=(*this)[i]*x[j];
        res.fix();
        return res;
    }
    void operator *=(number x){
        x*=(*this);
        clear();
        for(int a: x) pb(a);
    }
    void operator -=(number x){
        FFOR(i, 0, x.size()) (*this)[i]-=x[i];
        fix();
    }
    number operator -(number x){
        number res=(*this);
        res-=x;
        return res;
    }
    void operator /=(int x){///x=2 only :)
        DFOR(i, size()-1, 0){
            if(i&&((*this)[i]%2)) (*this)[i-1]+=base;
            (*this)[i]/=2;
        }
        fix();
    }
    number operator /(int x){
        number res=(*this);
        res/=x;
        return res;
    }
    bool operator ==(number x){
        if(size()!=x.size()) return 0;
        FFOR(i, 0, size()) if(x[i]!=(*this)[i]) return 0;
        return 1;
    }
    bool operator >(number x){
        if(size()!=x.size()) return size()>x.size();
        DFOR(i, size()-1, 0) if(x[i]!=(*this)[i]) return (*this)[i]>x[i];
        return 0;
    }
    bool operator >=(number x){
        if(size()!=x.size()) return size()>x.size();
        DFOR(i, size()-1, 0) if(x[i]!=(*this)[i]) return (*this)[i]>x[i];
        return 1;
    }
    bool operator <=(number x){
        return (x>=(*this));
    }
    void display(){
        cout<<back();
        DFOR(i, (int(size()))-2, 0) cout<<setw(1)<<setfill('0')<<(*this)[i];
        cout<<'\n';
    }
};
number n, h;
number one(1);
number two(2);
number sum(number a){
    if(a[0]%2){
        return ((a/2)+1)*((a/2)+1);
    }
    else{
        return ((a/2))*((a/2)+1);
    }
}
bool check(number x){
    if(x<=h){
        number res=(x*(x+one))/2;
        return res>=n;
    }
    else{
//        return sum(x)>=n;
        number res=((x*(x+1))/2)-(((x-h)*(x-h+1))/2);
        return (res+sum(x-h-1))>=n;
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(h);
    number ans=n;
    number l=1, r=n-1, m;
    while(l<=r){
        m=(l+r)/2;
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    ans.display();
}