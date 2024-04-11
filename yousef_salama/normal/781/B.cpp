#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n;
string a, b, r[MAXN];

int main(){
	cin >> n;

	vector < pair < pair <string, string>, int> > v;
	for(int i = 0; i < n; i++){
		cin >> a >> b;

		string s1 = a.substr(0, 3);

		string s2 = a.substr(0, 2);
		s2 += b[0];

		v.push_back({{s1, s2}, i});

		r[i] = "";
	}

	sort(v.begin(), v.end());

	set <string> S;
	for(int i = 0; i < v.size(); ){
		int j = i;
		while(j < v.size() && v[j].first.first == v[i].first.first)j++;

		if(j - i > 1){
			for(int k = i; k < j; k++){
				if(S.count(v[k].first.second)){
					cout << "NO" << endl;
					return 0;
				}
				r[v[k].second] = v[k].first.second;
				S.insert(v[k].first.second);
			}
		}
		i = j;
	}

	while(true){
		bool found = false;
		for(int i = 0; i < v.size(); i++){
			if(r[v[i].second] != "")continue;

			if(S.count(v[i].first.first)){
				if(S.count(v[i].first.second)){
					cout << "NO" << endl;
					return 0;
				}
				r[v[i].second] = v[i].first.second;
				S.insert(v[i].first.second);

				found = true;
			}else if(S.count(v[i].first.second)){
				r[v[i].second] = v[i].first.first;
				S.insert(v[i].first.first);

				found = true;
			}
		}

		if(!found)break;
	}

	for(int i = 0; i < v.size(); i++){
		if(r[v[i].second] != "")continue;
		r[v[i].second] = v[i].first.first;
	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << r[i] << endl;

	return 0;
}