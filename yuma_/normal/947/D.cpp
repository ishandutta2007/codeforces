#include"bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ha;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	static const ll add0 = 1000010007, add1 = 1003333331;
	size_t len;
	//vector<ll> hash_, hash2_;
	vector<ha>hash_;
	//static vector<ll> pmo_, pmo2_;
	static vector<ha>pmo_;
	void init(const vector<ll>& s) {
		len = s.size();
		hash_.resize(len + 1);
		hash_[0] = make_pair(0, 0);

		if (pmo_.empty()) {
			pmo_.push_back(make_pair(1, 1));
		}
		while (pmo_.size() <= len) {
			pmo_.push_back(make_pair(pmo_.back().first*mul0, pmo_.back().second*mul1));
		}
		for (unsigned int i = 0; i < len; ++i) {
			hash_[i + 1] = make_pair((hash_[i].first * mul0 + s[i]), (hash_[i].second*mul1 + s[i]));
		}
		return;
	}
	void init(const string& s) {
		vector<ll>v;
		for (int i=0;i<s.size();++i) {
			auto c(s[i]);
			v.push_back(c);
		}
		init(v);
	}
	ha hash(const int l, const int r)const { // s[l..r]
		return make_pair(hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first,
			hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second);
	}
	ha  hash()const { // s[all]
		return hash(0, len - 1);
	}

	//hash
	static ha concat(const ha L, const ha R, const int RLength) { // hash(L+R) 
		return make_pair((R.first + L.first*pmo_[RLength].first), (R.second + L.second*pmo_[RLength].second));
	}

	//indexfromto
	ha get_changed_hash(const int index, const ll from, const ll to)const {
		const ha p(hash());
		return make_pair(
			p.first + (to - from) * pmo_[len - index - 1].first,
			p.second + (to - from) * pmo_[len - index - 1].second);
	}
};
vector<ha> RollingHash::pmo_;

int main() {
	string S,T;cin>>S>>T;

	RollingHash rh1,rh2;

	rh1.init(S);
	rh2.init(T);
	vector<vector<int>>s_sums(3,vector<int>(S.size()+1));
	vector<vector<int>>t_sums(3,vector<int>(T.size()+1));

	vector<int>s_ra_num(S.size()+1),t_ra_num(T.size()+1);

	for(int i=0;i<S.size();++i){
		if(S[i]=='A'){
			s_ra_num[i+1]=s_ra_num[i]+1;
		}else{
			s_ra_num[i+1]=0;
		}
	}
	for(int i=0;i<T.size();++i){
		if(T[i]=='A'){
			t_ra_num[1+i]=t_ra_num[i]+1;
		}else{
			t_ra_num[i+1]=0;
		}
	}

	for(int i=0;i<S.size();++i){
		int ch=S[i]-'A';
		for(int j=0;j<3;++j){
			s_sums[j][i+1]=s_sums[j][i];
		}
		s_sums[ch][i+1]++;
	}
	for(int i=0;i<T.size();++i){
		int ch=T[i]-'A';
		for(int j=0;j<3;++j){
			t_sums[j][i+1]=t_sums[j][i];
		}
		t_sums[ch][i+1]++;
	}

	int Q;cin>>Q;
	vector<int>anss;
	while(Q--){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--;
		c--;

		int s_a_num=s_sums[0][b]-s_sums[0][a];
		int s_b_num=s_sums[1][b]-s_sums[1][a];
		int s_c_num=s_sums[2][b]-s_sums[2][a];

		int t_a_num=t_sums[0][d]-t_sums[0][c];
		int t_b_num=t_sums[1][d]-t_sums[1][c];
		int t_c_num=t_sums[2][d]-t_sums[2][c];

		bool ok=true;
		{
			
			int s_bc_num=s_b_num+s_c_num;
			int t_bc_num=t_b_num+t_c_num;

			{
				int s_ra=s_ra_num[b];
				int t_ra=t_ra_num[d];

				if(s_ra>=b-a)s_ra=b-a;
				if(t_ra>=d-c)t_ra=d-c;

				if(s_ra<t_ra)ok=false;
				else{
					int pp=(s_ra-t_ra)%3;
					if(pp==2)pp=1;
					s_bc_num+=(2*pp);
				}
				if(s_ra==b-a&&s_ra==t_ra&&t_ra!=d-c)ok=false;
			}

			if(ok){

				if(s_bc_num>t_bc_num)ok=false;
				else {
					if((t_bc_num-s_bc_num)%2==1){
						ok=false;
					}
				}
			}
			
		}

		
		anss.push_back(ok);
	}
	for(int i=0;i<anss.size();++i){
		if(anss[i])cout<<1;
		else cout<<0;
	}
	cout<<endl;
	return 0;
}