#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;

#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	static int n;
	static int x[50010],y[50010],z[50010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	
	static vector<P2> vec;
	for(int i = 0 ; i < n ; i ++){
		vec.push_back(P2(P(x[i],y[i]),P(z[i],i+1)));
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	
	static vector<P> ret;
	while(vec.size() > 0){
		if(vec[vec.size()-1].fr.fr == vec[vec.size()-2].fr.fr){
			if(vec.size() > 2 && vec[vec.size()-2].fr == vec[vec.size()-3].fr){
				ret.push_back(P(vec[vec.size()-2].sc.sc,vec[vec.size()-3].sc.sc));
				P2 p = vec[vec.size()-1];
				vec.pop_back();
				vec.pop_back();
				vec.pop_back();
				vec.push_back(p);
			}
			else {
				ret.push_back(P(vec[vec.size()-1].sc.sc,vec[vec.size()-2].sc.sc));
				vec.pop_back();
				vec.pop_back();
			}
		}
		else if(vec.size() <= 2 || vec[vec.size()-2].fr.fr != vec[vec.size()-3].fr.fr){
			ret.push_back(P(vec[vec.size()-1].sc.sc,vec[vec.size()-2].sc.sc));
			vec.pop_back();
			vec.pop_back();
		}
		else if(vec.size() <= 3 || vec[vec.size()-3].fr.fr != vec[vec.size()-4].fr.fr
			|| vec[vec.size()-3].fr.sc != vec[vec.size()-4].fr.sc){
			ret.push_back(P(vec[vec.size()-2].sc.sc,vec[vec.size()-3].sc.sc));
			P2 p = vec[vec.size()-1];
			vec.pop_back();
			vec.pop_back();
			vec.pop_back();
			vec.push_back(p);
		}
		else {
			ret.push_back(P(vec[vec.size()-3].sc.sc,vec[vec.size()-4].sc.sc));
			P2 p = vec[vec.size()-1];
			P2 q = vec[vec.size()-2];
			vec.pop_back();
			vec.pop_back();
			vec.pop_back();
			vec.pop_back();
			vec.push_back(q);
			vec.push_back(p);
		}
	}
	for(int i = 0 ; i < ret.size() ; i ++){
		printf("%d %d\n",ret[i].fr,ret[i].sc);
	}
}