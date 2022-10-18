#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
const int MOD = 998244353;
const int P = 998244353;
 
int tem,a[1000005],top,t1[2000005],t2[2000005],w[2000005],R[2000005],lim;
 
typedef std::vector<int>poly;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){if(b&1)ans=mul(ans,a);a=mul(a,a);b>>=1;}
	return ans;
}
 
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])std::swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
poly operator*(poly a,poly b){
	int size=a.size()+b.size()-1;
	lim=1;while(lim<=size)lim<<=1;
	for(int i=1;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?lim>>1:0);
	memset(t1,0,(lim+1)<<2);
	memset(t2,0,(lim+1)<<2);
	for(int i=a.size()-1;~i;--i)t1[i]=a[i];
	for(int i=b.size()-1;~i;--i)t2[i]=b[i];
	NTT(t1);NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	NTT(t1);
	std::reverse(t1+1,t1+lim);
	a.resize(size);
	int inv=qsm(lim,P-2);
	for(int i=0;i<size;i++)a[i]=mul(t1[i],inv);
	return a;
}
 
int n, k, h[MAXN];
vector <int> A;
 
vector <int> solve(int m){
	if(m == 0)return vector <int> ({1});
	if(m % 2 == 1){
		return A * solve(m - 1);
	}
	
	vector <int> r = solve(m / 2);
	return r * r;
}
 
int main(){
	scanf("%d %d", &n, &k);
	
	for(int i=1,wn;i<((2 * n+1)<<2);i<<=1){
		wn=qsm(3,(P-1)/(i<<1)),w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	
	for(int i = 0; i < n; i++)
		scanf("%d", &h[i]);
		
	if(n == 1){
		printf("0\n");
		return 0;
	}
	
	long long res = 1, cnt = 0;
	for(int i = 0; i < n; i++){
		if(h[i] == h[(i + 1) % n]){
			res = res * k % MOD;
		}else{
			cnt++;
		}
	}
	
	A.push_back(1);
	A.push_back(k - 2);
	A.push_back(1);
	
	vector <int> ret = solve(cnt);
	
	long long sum = 0;
	for(int i = cnt + 1; i <= 2 * cnt; i++){
		sum = (sum + ret[i]) % MOD;
	}
	res = res * sum % MOD;
	
	printf("%lld\n", res);
	
	return 0;
}