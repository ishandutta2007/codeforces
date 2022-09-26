#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned int uint;

/// Set your CPU's L1 data cache size (in bytes) here
const uint L1D_CACHE_SIZE = 32768;

/// Generate primes using the segmented sieve of Eratosthenes.
/// This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
/// @param limit  Sieve primes <= limit.
///

uint vp(uint n, uint p)
{
	uint ans = 0; uint tmpn=n;
	while(n)
	{
		ans+=n%p; n/=p;
	}
	return (tmpn-ans)/(p-1);
}

uint A,B,C,D;

uint func(uint p)
{
	return (A*p*p*p+B*p*p+C*p+D);
}
uint N;
void segmented_sieve(uint limit)
{
  uint sqrt = (uint) std::sqrt(limit);
  uint segment_size = std::max(sqrt, L1D_CACHE_SIZE);
  uint count = 0;
	if(limit>=2)
	{
		count+=vp(N,2)*func(2);
	}
  // we sieve primes >= 3
  uint i = 3;
  uint n = 3;
  uint s = 3;

  std::vector<char> sieve(segment_size);
  std::vector<char> is_prime(sqrt + 1, true);
  std::vector<uint> primes;
  std::vector<uint> multiples;

  for (uint low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), true);

    // current segment = [low, high]
    uint high = low + segment_size - 1;
    high = std::min(high, limit);

    // generate sieving primes using simple sieve of Eratosthenes
    for (; i * i <= high; i += 2)
      if (is_prime[i])
        for (uint j = i * i; j <= sqrt; j += i)
          is_prime[j] = false;

    // initialize sieving primes for segmented sieve
    for (; s * s <= high; s += 2)
    {
      if (is_prime[s])
      {
           primes.push_back(s);
        multiples.push_back(s * s - low);
      }
    }

    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++)
    {
      uint j = multiples[i];
      for (uint k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = false;
      multiples[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]) // n is a prime
      {
        count+=vp(N,n)*func(n);
	}
  }
cout<<count<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>A>>B>>C>>D;
	if(N==1) {cout<<0<<'\n'; return 0;}
	segmented_sieve(N);
}