#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)


int main(){
	static int n;
	static int p[300010];
	static int p_[300010];
	static int q[300010];
	static int q_[300010];
	scanf("%d",&n);
	rep1(i,n){
		scanf("%d",&p[i]);
		p_[p[i]] = i;
	}
	vector<P> ans;
	
	vector<int> vec;
	for(int i = 1 ; i <= n/2 ; i ++){
		vec.push_back(p[i]);
	}
	sort(vec.begin(),vec.end());
	for(int i = 1 ; i <= n/2 ; i ++){
		q[i] = lower_bound(vec.begin(),vec.end(),p[i])-vec.begin();
		q[i] = n/2-q[i];
		q_[q[i]] = i;
	}
	for(int i = 1 ; i <= n/2 ; i ++){
		if(q_[i] != i){
			ans.push_back(P(i,n));
			ans.push_back(P(q_[i],n));
			ans.push_back(P(i,n));
			swap(p[i],p[q_[i]]);
			swap(q[i],q[q_[i]]);
			swap(p_[p[i]],p_[p[q_[i]]]);
			swap(q_[q[i]],q_[q[q_[i]]]);
		}
	}
	
	/*for(int i = 1 ; i <= n ; i ++){
		cout << p[i] << " " ;
	}
	cout << endl;
	for(int i = 1 ; i <= n ; i ++){
		cout << p_[i] << " ";
	}cout << endl;*/
	
	vector<int> A,B;
	for(int i = 1 ; 2*i <= n ; i ++){
		if(p[i]*2 > n)A.push_back(i);
		if(p[i+n/2]*2 <= n)B.push_back(i+n/2);
	}
	for(int i = 0 ; i < A.size() ; i ++){
		ans.push_back(P(A[i],B[i]));
		swap(p[A[i]],p[B[i]]);
		swap(p_[p[A[i]]],p_[p[B[i]]]);
	}
	
	/*for(int i = 1 ; i <= n ; i ++){
		cout << p[i] << " " ;
	}
	cout << endl;
	for(int i = 1 ; i <= n ; i ++){
		cout << p_[i] << " ";
	}cout << endl;*/
	
	for(int i = 1 ; i <= n/2 ; i ++){
		if(p_[i] != i){
			ans.push_back(P(i,n));
			ans.push_back(P(p_[i],n));
			ans.push_back(P(i,n));
			swap(p[i],p[p_[i]]);
			swap(p_[p[i]],p_[p[p_[i]]]);
		}
	}
	for(int i = n/2+1 ; i <= n ; i ++){
		if(p_[i] != i){
			ans.push_back(P(i,1));
			ans.push_back(P(p_[i],1));
			ans.push_back(P(i,1));
			swap(p[i],p[p_[i]]);
			swap(p_[p[i]],p_[p[p_[i]]]);
		}
	}
	printf("%d\n",ans.size());
	for(int i = 0 ; i < ans.size() ; i ++){
		P p = ans[i];
		printf("%d %d\n",p.first,p.second);
	}
}