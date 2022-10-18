#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;

int n, t[MAXN];

bool check(int i){
	if(i % 2 == 0){
		if(i + 1 < n && t[i] >= t[i + 1])return false;
		if(i > 0 && t[i - 1] <= t[i])return false;
	}else{
		if(i + 1 < n && t[i] <= t[i + 1])return false;
		if(i > 0 && t[i - 1] >= t[i])return false;
	}
	return true;
}
bool check(int i, int j){
	swap(t[i], t[j]);

	if(!check(i)){
		swap(t[i], t[j]);
		return false;
	}
	if(!check(j)){
		swap(t[i], t[j]);
		return false;
	}

	swap(t[i], t[j]);
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);

	vector <int> v;
	for(int i = 0; i < n - 1; i++){
		if(i % 2 == 0){
			if(t[i] >= t[i + 1])v.push_back(i);
		}else{
			if(t[i] <= t[i + 1])v.push_back(i);
		}
	}

	if(v.size() == 1){
		int r = 0;
		r += check(v[0], v[0] + 1);
		for(int k = 0; k < n; k++){
			if(k == v[0] || k == v[0] + 1)continue;

			r += check(k, v[0]);
			r += check(k, v[0] + 1);
		}
		printf("%d\n", r);
	}else if(v.size() == 2){
		if(v[0] + 1 == v[1]){
			int r = 0;
			r += check(v[0], v[0] + 1);
			r += check(v[0], v[0] + 2);
			r += check(v[0] + 1, v[0] + 2);

			for(int k = 0; k < n; k++){
				if(k == v[0] || k == v[0] + 1 || k == v[0] + 2)continue;
				r += check(k, v[0] + 1);
			}
			printf("%d\n", r);
		}else{
			int r = 0;
			r += check(v[0], v[1]);
			r += check(v[0] + 1, v[1]);
			r += check(v[0], v[1] + 1);
			r += check(v[0] + 1, v[1] + 1);
			printf("%d\n", r);
		}
	}else if(v.size() <= 4){
		int r = 0;
		for(int i = 0; i < n; i++){
			bool ok = false;
			for(int j = 0; j < v.size(); j++)
				if(v[j] == i || v[j] + 1 == i)ok = true;

			if(!ok)continue;

			for(int j = i + 1; j < n; j++){
				ok = false;
				for(int k = 0; k < v.size(); k++)
					if(v[k] == j || v[k] + 1 == j)ok = true;

				if(!ok)continue;

				ok = true;
				for(int k = 0; k < v.size(); k++){
					if(v[k] == i || v[k] == j)continue;
					if(v[k] + 1 == i || v[k] + 1 == j)continue;
					ok = false;
				}

				if(ok)r += check(i, j);
			}
		}
		printf("%d\n", r);
	}else printf("0\n");

	return 0;
}