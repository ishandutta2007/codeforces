// Minimizing Difference

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i=0;i<n;++i)
		cin >>a[i];
	map<long long, int> b;
	for(int i=0;i<n;++i)
		b[a[i]]++;
	while(k){
		if (b.size() == 1)
			break;
		long long first = b.begin()->first;
		int min_count = b.begin()->second;
		long long last = b.rbegin()->first;
		int max_count = b.rbegin()->second;
		if (min_count < max_count){
			if (k<min_count)
				break;
			long long second = (++b.begin())->first;
			int count = min(k, (second - first) * min_count) / min_count;
			k -= (long long)min_count * count;
			b[first+count] += min_count;
			b.erase(first);
		}else{
			if (k<max_count)
				break;
			long long prelast = (--(--(b.end())))->first;
			int count = min(k, (last - prelast) * max_count) / max_count;
			k -= (long long)max_count * count;
			b[last-count] += max_count;
			b.erase(last);
		}
	}
	cout << b.rbegin()->first - b.begin()->first<<endl;
	return 0;
}