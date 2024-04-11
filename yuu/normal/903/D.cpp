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
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
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
int n;
map <int, int> M;
ll a, s=0;
class num: public vector <ll>{
public:
    const ll base=1000000LL;
    bool negative;
    num(ll x){
        clear();
        negative=0;
        if(x<0){
            negative=1;
            x=-x;
        }
        while(x>0){
            pb(x%base);
            x/=base;
        }
        if(empty()) pb(0);
    }
    num operator -(){
        num res=(*this);
        res.negative=1-negative;
        if((res.size()==1)&&(res[0]==0)) negative=0;
        return res;
    }
    num(){
        clear();
        pb(0);
        negative=0;
    }
    void operator =(num x){
        clear();
        negative=x.negative;
        for(ll a: x) pb(a);
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
        if(size()==1&&back()==0) negative=0;
    }
    num operator +(num x){
        if(negative){
            if(x.negative){
                return -((-(*this))+(-x));
            }
            else return x-(-(*this));
        }
        else{
            if(x.negative) return (*this)-(-x);
            else{
                num res=(*this);
                while(res.size()<x.size()) res.pb(0);
                while(res.size()>x.size()) x.pb(0);
                FFOR(i, 0, x.size()) res[i]+=x[i];
                res.fix();
                return res;
            }
        }
    }
    void operator+=(num x){
        (*this)=x+(*this);
    }
    bool operator >=(num x){
        if(size()!=x.size()) return size()>x.size();
        DFOR(i, size()-1, 0) if((*this)[i]!=x[i]) return ((*this)[i])>x[i];
        return 1;
    }
    num operator -(num x){
        if(x.negative) return (*this)+(-x);
        else{
            if(negative) return -((-(*this))+x);
            else{
                if((*this)>=x){
                    num res=(*this);
                    FFOR(i, 0, x.size()) res[i]-=x[i];
                    res.fix();
                    return res;
                }
                else{
                    return -(x-(*this));
                }
            }
        }
    }
    void display(){
        if(negative) cout<<"-";
        cout<<back();
        DFOR(i, (int(size()))-2, 0) cout<<setw(6)<<setfill('0')<<(*this)[i];
        cout<<'\n';
    }
};
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    num ans=0;
    FOR(i, 1, n){
        read(a);
        s+=a;
        M[a]++;
        ll temp=0;
        temp+=a*i;
        temp-=s;
        temp+=(a-1)*M[a-1];
        temp+=(a+1)*M[a+1];
        temp-=a*(M[a-1]+M[a+1]);
        ans+=temp;
    }
    ans.display();
}