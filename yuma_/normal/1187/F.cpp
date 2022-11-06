#include <bits/stdc++.h>


const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}
using namespace std;
vector<int>ls,rs;

Mod memo[200010][3];
bool flag[200010][3];
Mod same_per(int x,int y){
    if(flag[x][y-x]){
        return memo[x][y-x];
    }else{
        flag[x][y-x]=true;
    }
    if(x==-1){
        return 0;
    }else{
        {
            vector<pair<int,int>>vs;
            Mod sum=1;
            for(int i=x;i<=y;++i){
                sum/=Mod(rs[i]-ls[i]);
                vs.push_back(make_pair(ls[i],1));
                vs.push_back(make_pair(rs[i],-1));
            }
            sort(vs.begin(),vs.end());
            bool flag=false;
            for(int t=0,j=0;j<vs.size();++j){
                t+=vs[j].second;
                if(t==y-x+1){
                    sum*=Mod(vs[j+1].first-vs[j].first);
                    flag=true;
                }
            }
            if(!flag){
                //cout<<-1<<endl;
                sum=Mod(0);
            }
            //cout<<x<<' '<<y<<' '<<sum<<endl;
            return memo[x][y-x]=sum;
        }
    }
}
int main() {
    int N;cin>>N;
    for(int i=0;i<2;++i){
        for(int j=0;j<N;++j){
            int a;scanf("%d",&a);
            if(i==0)ls.push_back(a);
            else rs.push_back(a+1);
        }
    }
    if(N==1){
        cout<<1<<endl;
    
    }else{
        Mod answer=0;
        Mod total_not=0;
        for(int i=-1;i<N-1;++i){
            total_not+=Mod(1)-same_per(i,i+1);
        }
        //cout<<total_not<<endl;
        total_not=total_not*total_not+total_not;
        Mod total_minus=0;
        
        {
            Mod minus_same=0;
            minus_same+=Mod(1)-same_per(-1,0);
            for(int i=-1;i<N-1;++i){
                if(i<N-2)minus_same+=Mod(1)-same_per(i+1,i+2);
                total_minus+=(Mod(1)-same_per(i,i+1))*minus_same;
                if(i>=0)minus_same-=Mod(1)-same_per(i-1,i);
            }
        }
        Mod total_plus=0;
        {
            for(int i=-1;i<N-2;++i){
                total_plus+=Mod(2)*(Mod(1)-same_per(i,i+1)-same_per(i+1,i+2)+same_per(i,i+2));
            }
        }
        
        answer=total_not-total_minus+total_plus;
        cout<<answer.num<<endl;


    }
    
    //cout<<total_not.num<<" "<<total_minus.num<<" "<<total_plus.num<<endl;
    return 0;
}