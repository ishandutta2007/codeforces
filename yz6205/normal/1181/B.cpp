#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

struct bint {
//data
    static const int L = 100500;
    int a[L];//from 0 to L-1
//insideUse_use fumction
    bint(string s) {
        *this = s;
    }
    bint(long long num = 0){
        stringstream s;
        s<<num;
        string str;
        s>>str;
        *this = str;
    }
    void print(){
        int top = L - 1;
        while(a[top] == 0) top--;
        for (int i = top; i >= 0; i--)
            cout<<a[i];
    }
    int length() const{
        int top = L - 1;
        while(top > 0 && a[top] == 0) top--;
        return top+1;
    }
    void clear(int top = -1){
        if (top == -1){
            top = length()-1;
        }
        for (int i=0;i<=top;i++){
            if (a[i] >= 0){
                a[i + 1] += a[i] / 10;
                a[i] %= 10;
            }else{
                a[i] = -a[i];
                a[i+1] -= ((a[i]-1) / 10 + 1);
                a[i] %= 10;
                if (a[i] == 0){
                    continue;
                }
                a[i] = (-a[i] + 10);
            }
        }
    }
    void left(int k=1){ //eq (*this /= 10^k);
        int s = this->length();
        for (int i=0;i<=s-k;i++){
            a[i] = a[i + k];
        }
        for (int i=s-k+1;i<=s;i++){
            a[i] = 0;
        }
    }
    void right(int k=1){//eq (*this *= 10^k);
        int s = this->length();
        for (int i=s-1;i>=0;i--){
            a[i+k] = a[i];
        }
        for (int i=0;i<k;i++){
            a[i] = 0;
        }
    }
    bool less(bint A,bint B){
        int sa = A.length()-1;
        int sb = B.length()-1;
        if (sa < sb){
            return 1;
        }else if (sa > sb){
            return 0;
        }else{
            for (int i=sa;i>=0;i--){
                if (A.a[i] < B.a[i]){
                    return 1;
                }else if (A.a[i] > B.a[i]){
                    return 0;
                }
            }
        }
        return 0;
    }
    void div_mod(bint A,bint B,bint& d,bint& m){
        d = "0";
        int sa = A.length()-1;
        int sb = B.length()-1;
        int ts = sa - sb + 1;
        B.right(ts-1);
        for (int i=ts;i>=1;i--){
            /*
            puts("###");
            cout<<"fts "<<i<<' ';
            B.print();
            puts("");
            */
            /*int j;
            for (j=1;j<=10;j++){
                if ((st * j * B) > A){
                    break;
                }
            }
            j--;
            A -= st * j * B;
            d += st * j;*/
            while(A >= B){
                A -= B;
                d.a[i-1]++;
            }
            B.left();
        }
        m = A;
    }
//operator
    bool operator < (const bint B){
        return less(*this,B);
    }
    bool operator > (const bint B){
        return less(B,*this);
    }
    bool operator <= (const bint B){
        return !less(B,*this);
    }
    bool operator >= (const bint B){
        return !less(*this,B);
    }
    bint operator = (const string str){
        memset(a,0,sizeof(a));
        int len = (int)str.size();
        for (int  i = 0; i < len; i++) {
            a[i] = str[len - 1 - i] - '0';
        }
        return *this;
    }
    bint operator + (const bint B){
        const bint& A = *this;
        bint C;
        for (int i = 0; i < L; i++){
            C.a[i] = A.a[i] + B.a[i];
        }
        C.clear();
        return C;
    }
    bint operator += (const bint B){
        *this = *this + B;
        return *this;
    }
    bint operator - (const bint B) {
        const bint& A = *this;
        bint C;
        for (int i = 0; i < L; i++){
            C.a[i] = A.a[i] - B.a[i];
        }
        C.clear();
        return C;
    }
    bint operator -= (const bint B){
        *this = *this - B;
        return *this;
    }
    bint operator * (const bint B){
        bint C;
        int topA = length()-1;
        int topB = B.length()-1;
        for (int i=0;i<=topA;i++){
            for (int j=0;j<=topB;j++){
                int num = a[i] * B.a[j];
                C.a[i+j] += num % 10;
                C.a[i+j+1] += num / 10;
            }
        }
        C.clear();
        return C;
    }
    bint operator *= (bint B){
        *this = *this * B;
        return *this;
    }
    bint operator / (bint B){
        bint A = *this;
        bint x,y;
        div_mod(A,B,x,y);
        return x;
    }
     
    bint operator % (bint B){
        bint A = *this;
        bint x,y;
        div_mod(A,B,x,y);
        return y;
    }
//outsideUse_function
    bint pow(int x){
        if (x == 0){
            return 1;
        }
        if (x == 1){
            return *this;
        }
        bint k = pow(x / 2);
        if (x % 2 == 0){
            return k * k;
        }else{
            return k * k * *this;
        }
    }
};
//outStruct_function&operator
ostream& operator << (ostream& out,bint x){
    int top = x.length();
    for (int i = top-1; i >= 0; i--){
        out<<x.a[i];
    }
    return out;
}
 
istream& operator >> (istream& in,bint& x){
    string s;
    if (!(in >> s)){
        return in;
    }
    x = s;
    return in;
}

int main(){
    int l ;
    string s;
    cin >> l >> s;
    int bg = max(l / 2 - 2 , 1);
    int ed = min(l / 2 + 2 , l - 1);

    int bb = l / 2;
    int ee = l / 2;
    while (s[bb] == '0') bb--;
    while (s[ee] == '0' && ee + 1 < l) ee++;

    bint ans("0");
    for (int i=min(bg,bb);i<=max(ed,ee);i++){
        if (s[i] == '0') continue;
        bint a(s.substr(0,i));
        bint b(s.substr(i));
        bint c = a + b;
        if ( !(ans > bint("0")) ) ans = c;
        else if (c < ans) ans = c;
    }
    cout << ans << endl;
    return 0;
}