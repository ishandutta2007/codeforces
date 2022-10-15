#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long double INF = 1000000000000000000ll;

void solve(int test_ind){
	// d/dx f(topic) = -csum / C^2
	// f1(topic) = csum / C
	// f(topic) = 2 * f1(topic)

	// c1 / C1^2 = c2 / C2^2
	// c1 / (C1 + x) ^ 2 ? c2 / (C2 + x) ^ 2

	int n, q;
	cin >> n >> q;
	vector<long double> C(n);
	vector<vector<int> > c(n);
	vector<vector<long double> > p(n);
	vector<vector<long double> > Cpoints(n); // C' = c_ij / p_ij
	set<pair<long double, int> > derivatives;
	long double initc = 0;
	long double initp = 0;
	for (int i=0;i<n;++i){
		int n1;
		scanf("%d", &n1);
		vector<int> tmpp(n1);
		c[i].resize(n1);
		for (int j=0;j<n1;++j){
			scanf("%d", &c[i][j]);
			C[i] += c[i][j];
		}
		int tmpsum = 0;
		for (int j=0;j<n1;++j){
			scanf("%d", &tmpp[j]);
			tmpsum += tmpp[j];
		}
		long double one = 1;
		int csum = 0;
		for (int j=0;j<n1;++j){
			p[i].push_back(tmpp[j] * one / tmpsum);
			// c[i][j] / C[i] < tmpp[j] / tmpsum : continue
			Cpoints[i].push_back(-1);
			if (c[i][j] * 1ll * tmpsum <= tmpp[j] * 1ll * C[i]) continue;
			Cpoints[i].pop_back();
			Cpoints[i].push_back(c[i][j] / p[i][j]);
			csum += c[i][j];
			initc += c[i][j] / C[i];
			initp += tmpp[j] * one / tmpsum;
		}
		derivatives.emplace(csum / C[i] / C[i], i);
	}

	vector<long double> ans(q);
	set<pair<long long, int> > qs;
	for (int i=0;i<q;++i) {
		pair<long long, int> pr;
		scanf("%lld", &pr.first);
		pr.second = i;
		qs.insert(pr);
	}

	long double moneySpend = 0;
	long double Csum = 0; // currently active topics
	long double curc = 0;
	long double coef;
	vector<bool> taken(n, false);
	set<pair<long double, pair<int, int> > > Cp; // (coef, ind)
	long double der; // start derivative

	auto get_last_derivative = [&](){
		coef = 1;
		auto it = derivatives.rbegin();
		// cerr << it->second << " last deriv" << endl;
		// cerr << initc << " " << initp << endl;
		// cerr << C[it->second] << endl;
		der = it->first;
		taken[it->second] = true;
		Csum = C[it->second];
		curc = 0;
		for (int k=0;k<Cpoints[it->second].size();++k) {
			if (Cpoints[it->second][k] == -1) continue;
			// cerr << "insert " << Cpoints[it->second][k] / C[it->second] << endl;
			Cp.emplace(Cpoints[it->second][k] / C[it->second], make_pair(it->second, k)); // turning point
			curc += c[it->second][k] / C[it->second];
		}
		derivatives.erase(*it);
	};

	auto change_coef = [&](long double coef2) {
		initc -= curc;
		curc *= coef / coef2;
		initc += curc;
		moneySpend += (coef2 / coef - 1) * Csum;
		Csum *= coef2 / coef;
		coef = coef2;
	};


	while (!qs.empty()) {
		if (Cp.empty()) {
			if (derivatives.empty()) {
				// no active point
				break;
			}
			get_last_derivative();
			continue;
		}

		long double coef1 = Cp.begin()->first;
		long double coef2 = ((qs.begin()->first - moneySpend) / Csum + 1) * coef;
		if (!derivatives.empty()) {
			long double coef3 = sqrtl(der / derivatives.rbegin()->first); // new point
			if (coef3 < coef1 && coef3 < coef2) {
				int j = derivatives.rbegin() -> second;
				// cerr << "another deriv " << j << endl;
				// new point
				taken[j] = true;

				change_coef(coef3);
				Csum += C[j];
				C[j] /= coef;
				for (int k=0;k<Cpoints[j].size();++k) {
					if (Cpoints[j][k] == -1) continue;
					// cerr << "insert" << endl;
					Cp.emplace(Cpoints[j][k] / C[j], make_pair(j, k)); // turning point
					curc += c[j][k] / C[j] / coef;
				}
				derivatives.erase(*derivatives.rbegin());
				continue;
			}
		}

		if (coef1 < coef2) {
			auto pr = *Cp.begin();
			// cerr << "remove " << pr.second.first << " " << pr.second.second << endl;
			// cerr << C[0] * coef1 << " " << C[1] * coef1 << endl;
			for (int j=0;j<c[pr.second.first].size();++j){
				if (Cpoints[pr.second.first][j] == -1) continue;
				Cp.erase(make_pair(Cpoints[pr.second.first][j] / C[pr.second.first], make_pair(pr.second.first, j)));
			}
			change_coef(coef1);
			taken[pr.second.first] = false;
			C[pr.second.first] *= coef;
			Csum -= C[pr.second.first];
			initc -= c[pr.second.first][pr.second.second] / C[pr.second.first];
			initp -= p[pr.second.first][pr.second.second];
			// cerr << "delta: " << c[pr.second.first][pr.second.second] / C[pr.second.first] << " " << p[pr.second.first][pr.second.second] << endl;
			Cpoints[pr.second.first][pr.second.second] = -1;
			curc -= c[pr.second.first][pr.second.second] / C[pr.second.first];
			int csum = 0;
			for (int j=0;j<c[pr.second.first].size();++j){
				if (Cpoints[pr.second.first][j] == -1) continue;
				csum += c[pr.second.first][j];
				curc -= c[pr.second.first][j] / C[pr.second.first];
			}
			if (csum) {
				// cerr << "deriv back: " << csum / C[pr.second.first] / C[pr.second.first] << endl;
				derivatives.emplace(csum / C[pr.second.first] / C[pr.second.first], pr.second.first);
			}
			// cerr << "money " << moneySpend << endl;
			// cerr << Csum << " " << curc << " " << coef << endl;
			// cerr << initc << " " << initp << endl;
			// turning point
		} else {
			// query
			change_coef(coef2);
			// cerr << "query " << qs.begin()->first << " " << qs.begin()->second << " " << coef << endl;
			ans[qs.begin()->second] = initc - initp;
			qs.erase(qs.begin());
			// cerr << "Qend" << endl;
		}
	}

	// add percentage of total C, until new topic appears, new query comes or some element from a topic gets removed
	// (c / C^2) / (c / (C * coef) ^ 2) = coef^2, i.e. multiplying C by coef gets derivative divided by coef^2
	// pick largest derivatives	

	for (int i=0;i<q;++i){
		printf("%.13Lf\n", 2 * ans[i]);
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}