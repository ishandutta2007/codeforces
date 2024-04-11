// https://codeforces.com/problemset/problem/1567/D

    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <map>
    #include <set>
     
    using namespace std;
     
    void solve(int test_ind){
    	string s;
    	int n;
    	cin >> s >> n;
    	int k = s[s.size()-1] - '0';
    	vector<int> v1;
    	vector<int> v(n);
    	vector<int> p(10, 1);
    	for (int i=1;i<p.size();++i)
    		p[i] = p[i-1]*10;
     
    	for (int i=0;i+1<s.size();++i){
    		for (int j=0;j<s[i]-'0';j++)
    			v1.push_back(s.size()-i-1);
    	}
    	while (v1.size() + k < n){
    		int q = v1.back();
    		v1.pop_back();
    		if (q == 1){
    			k += 10;
    		} else {
    			for (int i=0;i<10;++i)
    				v1.push_back(q-1);
    		}
    	}
    	for (int i=0;i<k;++i)
    		v[i%n] += 1;
    	for (int i=0;i<v1.size();++i){
    		v[(i + k)%n] += p[v1[i]];
    	}
     
    	for (auto i: v)
    		cout << i << " ";
    	cout << endl;
    }
     
    int main(){
    	int t=1;
    	cin >> t;
    	for(int i=0;i<t;i++){
    		solve(i);
    	}
    	return 0;
    }