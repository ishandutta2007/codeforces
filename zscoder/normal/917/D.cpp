#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd || g==-1){
			if(is_neg){
				x= -x;
			}
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}
long long mod=1000000007;
long long pw(long long b,long long k){
	long long p2=b;
	long long ret=1;
	while(k){
		if(k%2){
			ret *= p2;
			ret %= mod;
		}
		p2 *= p2;
		p2 %= mod;
		k/=2;
	}
	return ret;
}
long long innv(long long a){
	return pw(a,mod-2);
}
long long mat[110][110];
int n;
void swap_rows(int ii,int jj){
	int n=::n-1;
	for(int i=0;i<n;i++){
		swap(mat[ii][i],mat[jj][i]);
	}
}
long long determinant(){
	int n=::n-1;
	bool is_neg=false;
	for(int i=0;i<n;i++){
		int rr=-1;
		for(int j=i;j<n;j++){
			if(mat[j][i] != 0){
				rr=j;
				break;
			}
		}
		if(rr==-1)return 0;
		if(rr!=i){
			is_neg = ! is_neg;
			swap_rows(rr,i);
		}
		long long the_inv= innv(mat[i][i]);
		for(int j=i+1;j<n;j++){
			long long fact= (the_inv * mat[j][i])%mod;
			for(int k=i;k<n;k++){
				mat[j][k] -= fact * mat[i][k];
				mat[j][k] %= mod;
				mat[j][k] += mod;
				mat[j][k] %= mod;
			}
		}
	}
	long long ans =1;
	if(is_neg){
		//ans = mod-1;
	}
	for(int i=0;i<n;i++){
		ans *= mat[i][i];
		ans %= mod;
	}
	return ans;
}
long long white[111][111];
long long black[111][111];
long long points[111];
long long poly_res[1111];
long long poly_cur[1111];
long long temp[1111];
void mood(long long &a){
	a %= mod;
	a += mod;
	a %= mod;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j) black[i][j] = 1;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		white[u][v]++; white[v][u]++; black[u][v]--; black[v][u]--;
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				mat[j][k]=0;
			}
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				mat[j][k] = -(black[j][k] * i + white[j][k]);
				mat[j][k] %= mod;
				mat[j][k] += mod;
				mat[j][k] %= mod;
				mat[k][j] = mat[j][k];
				mat[j][j] += mod-mat[j][k];
				mat[j][j] %= mod;
				mat[k][k] += mod-mat[j][k];
				mat[k][k] %= mod;
			}
		}
		points[i]=determinant();
		//cout<<points[i]<< " ";
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			poly_cur[j]=0;
		}
		poly_cur[0]=1;
		long long dom=1;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			for(int k=0;k<n;k++){
				temp[k]=0;
			}
			for(int k=0;k<n;k++){
				temp[k+1] = poly_cur[k]; 
			}
			for(int k=0;k<n;k++){
				temp[k] -= j * poly_cur[k]; 
				mood(temp[k]);
			}
			for(int k=0;k<n;k++){
				poly_cur[k]=temp[k];
			}
			dom *= i - j;
			mood(dom);
		}
		dom =innv(dom) * points[i];
		mood(dom);
		for(int j=0;j<n;j++){
			poly_res[j] += poly_cur[j]*dom;
			mood(poly_res[j]);
		}
	}
	for(int i=0;i<n;i++){
		if(i==n-1){
			cout<<poly_res[n-1-i]<<'\n';
		} else {
			cout<<poly_res[n-1-i]<<" ";
		}
	}
}