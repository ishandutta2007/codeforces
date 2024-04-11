#include <stdio.h>
#include <bits/stdc++.h>
#include <cassert>
#include <cstdint>
#include <ctime>
#include <functional>
#include <iterator>
#include <limits>
#include <map>
#include <random>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#ifdef ROOM_311
#	ifndef OLYMP_DEBUG
#		define OLYMP_DEBUG
#	endif
#else
#	define OLYMP_NDEBUG
#endif

//#include <olymp/geometry/point.h>
//#include <olymp/numeric/epsilonized.h>
//#include <olymp/numeric/modular.h>

#ifdef OLYMP_DEBUG
#ifndef OLYMP_PRINT_EXEC_TIME
#define OLYMP_PRINT_EXEC_TIME 1
#endif
#endif

namespace olymp::utils {

inline clock_t &get_exec_clock_storage()
{
	static clock_t exec_clock_storage;
	return exec_clock_storage;
}

inline clock_t &get_step_clock_storage()
{
	static clock_t step_clock_storage;
	return step_clock_storage;
}

inline void init_exec_time()
{
	auto &t0e = get_exec_clock_storage();
	auto &t0s = get_step_clock_storage();
	t0e = t0s = clock();
}

inline double get_exec_time_ms()
{
	const auto &t0 = get_exec_clock_storage();
	auto t1 = clock();
	return (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
}

inline double get_step_time_ms()
{
	auto &t0 = get_step_clock_storage();
	auto t1 = clock();
	double result = (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
	t0 = t1;
	return result;
}

inline void print_step_time([[maybe_unused]] std::string_view step_name = {})
{
#ifdef OLYMP_PRINT_EXEC_TIME
#if OLYMP_PRINT_EXEC_TIME
	if (step_name.empty()) {
		fprintf(stderr, "Step time = %0.0lf ms\n", get_step_time_ms());
	}
	else {
		fprintf(stderr, "Step '");
		fwrite(step_name.data(), 1, step_name.size(), stderr);
		fprintf(stderr, "' time = %0.0lf ms\n", get_step_time_ms());
	}
#endif
#endif
}

inline void print_exec_time()
{
#ifdef OLYMP_PRINT_EXEC_TIME
#if OLYMP_PRINT_EXEC_TIME
	fprintf(stderr, "Execution time = %0.0lf ms\n", get_exec_time_ms());
#endif
#endif
}

}  // namespace olymp::utils

namespace olymp::utils {

class rnd_t {
public:
	template<typename int_t = int>
	int_t get()
	{
		if constexpr (gen_.max() >= std::numeric_limits<int_t>::max()) {
			return gen_() & std::numeric_limits<int_t>::max();
		}
		else {
			std::uniform_int_distribution<int_t> d(0, std::numeric_limits<int_t>::max());
			return d(gen_);
		}
	}
	
	template<typename int_t = int>
	int_t operator () ()
	{
		return get<int_t>();
	}
	
	template<typename int_t>
	int_t operator () (int_t n)
	{
		std::uniform_int_distribution<int_t> d(0, n - 1);
		return d(gen_);
	}
	
	template<typename int_l_t, typename int_r_t>
	std::common_type_t<int_l_t, int_r_t> operator () (int_l_t l, int_r_t r)
	{
		std::uniform_int_distribution<std::common_type_t<int_l_t, int_r_t>> d(l, r);
		return d(gen_);
	}
	
	template<typename int_t>
	void seed(int_t &&value)
	{
		gen_.seed(std::forward<int_t>(value));
	}
	
	std::mt19937 &gen() { return gen_; }
	
	template<typename it_t>
	void shuffle(it_t b, it_t e)
	{
		std::shuffle(b, e, gen());
	}
	
	template<typename int_t>
	void discard(int_t n)
	{
		gen_.discard(n);
	}

private:
	std::mt19937 gen_{311311311};
};

#ifdef OLYMP_USE_MT
thread_local
#endif
static inline rnd_t rnd;

}  // namespace olymp::utils

namespace olymp::utils {

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uin(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(b, a) ? a = std::forward<b_t>(b), true : false;
}

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uax(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(a, b) ? a = std::forward<b_t>(b), true : false;
}

}  // namespace olymp::utils

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) std::begin(x), std::end(x)
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(std::make_signed_t<std::decay_t<decltype(en)>> i=(st); i<=static_cast<std::make_signed_t<std::decay_t<decltype(en)>>>(en); ++i)
#define Ford(i, st, en) for(std::make_signed_t<std::decay_t<decltype(st)>> i=(st); i>=static_cast<std::make_signed_t<std::decay_t<decltype(st)>>>(en); --i)
#define forn(i, n) for(std::make_signed_t<std::decay_t<decltype(n)>> i=0; i<static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n); ++i)
#define ford(i, n) for(auto i=static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n)-1; i>=0; --i)

using olymp::utils::print_step_time;
using olymp::utils::print_exec_time;
using olymp::utils::rnd;

template <class _T> inline _T sqr(const _T &x) { return x * x; }

namespace olymp {

__attribute__((constructor)) inline void init_main()
{
	utils::init_exec_time();
}

__attribute__((destructor)) inline void fini_main()
{
	utils::print_exec_time();
}

}  // namespace olymp

#ifdef OLYMP_NDEBUG
	#define OLYMP_ASSERT_LIB(x) (void)(x)
	#define OLYMP_ASSERT_USER(x) (void)(x)
#else
#ifdef OLYMP_DEBUG
	#define OLYMP_ASSERT_LIB(x) assert(x)
	#define OLYMP_ASSERT_USER(x) assert(x)
#else
	#define OLYMP_ASSERT_LIB(x) (void)(x)
	#define OLYMP_ASSERT_USER(x) assert(x)
#endif
#endif

namespace olymp::utils {
}  // namespace olymp::utils

namespace olymp::strings {

template<typename char_t, bool next_map_is_ordered = false, typename node_index_t = int>
class ahoc_tree_t {
public:
	using node_id_t = node_index_t;
	
	static constexpr node_id_t none = static_cast<node_id_t>(-1);
	
	class finals_t {
	public:
		finals_t(const ahoc_tree_t &a, node_id_t node) :
			a_(a),
			node_(node)
		{
			if (node_ != none && !a_.is_final(node_)) node_ = a_.final_pref(node_);
		}
		
		class iterator_t {
		public:
			using difference_type = std::make_signed_t<node_id_t>;
			using value_type = node_id_t;
			using pointer = value_type *;
			using reference = value_type &;
			using iterator_category = std::forward_iterator_tag;
			
			iterator_t(const ahoc_tree_t &a, node_id_t node) :
				a_(a),
				node_(node)
			{}
			
			node_id_t operator * () const
			{
				return node_;
			}
			
			iterator_t operator ++ ()
			{
				node_ = a_.final_pref(node_);
				return *this;
			}
			
			iterator_t operator ++ (int)
			{
				auto tmp = *this;
				node_ = a_.final_pref(node_);
				return tmp;
			}
			
			bool operator == (const iterator_t &r) const
			{
				OLYMP_ASSERT_USER(&a_ == &r.a_);
				return node_ == r.node_;
			}
			
			bool operator != (const iterator_t &r) const
			{
				return !(*this == r);
			}
			
		private:
			const ahoc_tree_t &a_;
			node_id_t node_;
		};
		
		iterator_t begin() const
		{
			return {a_, node_};
		}
		
		iterator_t end() const
		{
			return {a_, none};
		}
		
		bool empty() const
		{
			return node_ == none;
		}
		
		size_t size() const
		{
			return std::distance(begin(), end());
		}
		
		node_id_t front() const
		{
			OLYMP_ASSERT_USER(!empty());
			return node_;
		}
		
		using iterator = iterator_t;
		
	private:
		const ahoc_tree_t &a_;
		node_id_t node_;
	};
	
	explicit ahoc_tree_t(size_t max_size = 0)
	{
		reserve(max_size);
		new_node();
	}
	
	void reserve(size_t max_size)
	{
		nodes_.reserve(max_size + 1);
	}
	
	void clear()
	{
		nodes_.clear();
		q_.clear();
		builded_ = false;
		new_node();
	}
	
	size_t size() const
	{
		return nodes_.size();
	}
	
	node_id_t add(const std::vector<char_t> &s, node_id_t v0 = 0)
	{
		return add(std::begin(s), std::end(s), v0);
	}
	
	template<typename it_t>
	node_id_t add(it_t begin, it_t end, node_id_t v0 = 0)
	{
		node_id_t v = v0;
		while (begin != end) {
			const auto &c = *begin;
			auto [it, inserted] = nodes_[v].next.emplace(c, none);
			if (inserted) it->second = new_node();
			OLYMP_ASSERT_LIB(it->second != none);
			v = it->second;
			++begin;
		}
		nodes_[v].is_final = true;
		builded_ = false;
		return v;
	}
	
	template<bool enabled = std::is_same_v<char_t, char>>
	std::enable_if_t<enabled, node_id_t> add(std::string_view s, node_id_t v0 = 0)
	{
		return add(std::begin(s), std::end(s), v0);
	}
	
	__attribute__((noinline)) void build()
	{
		q_.resize(nodes_.size());
		node_id_t qb = 0, qe = 0;
		q_[qe++] = 0;
		while (qb != qe) {
			node_id_t v = q_[qb++];
			for (auto &[c, vn] : nodes_[v].next) {
				nodes_[vn].depth = nodes_[v].depth + 1;
				node_id_t z = nodes_[v].p;
				for (;;) {
					if (z == none) {
						z = 0;
						break;
					}
					auto it = nodes_[z].next.find(c);
					if (it != nodes_[z].next.end()) {
						z = it->second;
						break;
					}
					z = nodes_[z].p;
				}
				nodes_[vn].p = z;
				q_[qe++] = vn;
			}
		}
		
		OLYMP_ASSERT_LIB(nodes_.size() == q_.size());
		
		for (node_id_t idx = 0; idx < qe; idx++) {
			node_id_t v = q_[idx];
			node_id_t vp = nodes_[v].p;
			nodes_[v].final_p = (
				vp == none ? none : (
					nodes_[vp].is_final ? vp : nodes_[vp].final_p
				)
			);
		}
		
		builded_ = true;
	}
	
	auto begin() const
	{
		OLYMP_ASSERT_USER(builded_);
		return q_.begin();
	}
	
	auto end() const
	{
		OLYMP_ASSERT_USER(builded_);
		return q_.end();
	}
	
	auto rbegin() const
	{
		OLYMP_ASSERT_USER(builded_);
		return q_.rbegin();
	}
	
	auto rend() const
	{
		OLYMP_ASSERT_USER(builded_);
		return q_.rend();
	}
	
	finals_t finals(node_id_t node) const
	{
		return finals_t{*this, node};
	}
	
	node_id_t pref(node_id_t node) const
	{
		OLYMP_ASSERT_USER(builded_);
		OLYMP_ASSERT_USER(static_cast<size_t>(node) < nodes_.size());
		return nodes_[node].p;
	}
	
	node_id_t final_pref(node_id_t node) const
	{
		OLYMP_ASSERT_USER(builded_);
		OLYMP_ASSERT_USER(static_cast<size_t>(node) < nodes_.size());
		return nodes_[node].final_p;
	}
	
	bool is_final(node_id_t node) const
	{
		OLYMP_ASSERT_USER(builded_);
		OLYMP_ASSERT_USER(static_cast<size_t>(node) < nodes_.size());
		return nodes_[node].is_final;
	}
	
	[[nodiscard]] node_id_t next(node_id_t node, const char_t &chr) const
	{
		OLYMP_ASSERT_USER(builded_);
		OLYMP_ASSERT_USER(static_cast<size_t>(node) < nodes_.size());
		
		for (;;) {
			if (node == none) return 0;
			auto it = nodes_[node].next.find(chr);
			if (it != nodes_[node].next.end()) return it->second;
			node = nodes_[node].p;
		}
	}
	
	[[nodiscard]] node_id_t next(node_id_t node, const std::vector<char_t> &chrs) const
	{
		for (const char_t &chr : chrs) {
			node = next(node, chr);
		}
		return node;
	}
	
	node_id_t depth(node_id_t node) const
	{
		OLYMP_ASSERT_USER(builded_);
		OLYMP_ASSERT_USER(static_cast<size_t>(node) < nodes_.size());
		return nodes_[node].depth;
	}
	
private:
	using next_container_t = std::conditional_t<
		next_map_is_ordered,
		std::map<char_t, node_id_t>,
		std::unordered_map<char_t, node_id_t>
	>;

	struct tnode
	{
		next_container_t next;
		node_id_t p{none};
		node_id_t final_p{none};
		node_id_t depth{0};
		bool is_final{false};
	};
	
	int new_node()
	{
		nodes_.emplace_back();
		return nodes_.size() - 1;
	}
	
	std::vector<tnode> nodes_;
	std::vector<node_id_t> q_;
	bool builded_ = false;
};

}  // namespace olymp::strings

using namespace olymp;
using namespace std;
using utils::uax;
using utils::uin;

// Types
using ld = long double;
//using ed = numeric::epsilonized<ld, 9>;
using i64 = long long;
using u64 = unsigned long long;
//using tp = geometry::point<int>;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

//const int MOD = 1000000007;
//const int MOD = 998244353;
//using mint = numeric::modular<MOD>;

using act_t = strings::ahoc_tree_t<char, true>;

char s[1024000];
string a[102400];
int b[102400];
int h[2224000];
bool u[2224000];
act_t t;

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%s", s);
	int v0 = t.add(s);
	int m;
	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%s", s);
		a[i] = s;
		b[i] = t.add(a[i], v0);
	}
	
	clr(u);
	t.build();
	forn(i, v0 + 1)
	{
		h[i] = i;
		u[i] = true;
	}
	forn(i, m)
	{
		int v = v0;
		forn(j, a[i].size())
		{
			int vn = t.next(v, a[i][j]);
			h[vn] = h[v] + 1;
			v = vn;
		}
	}
	
	forn(i, m)
	{
		int v = v0;
		forn(j, a[i].size())
		{
			v = t.next(v, a[i][j]);
			assert(v > v0);
			u[v] = true;
			int x = t.pref(v);
			assert(x >= 0);
			while (!u[x])
			{
				x = t.pref(x);
				assert(x >= 0);
			}
			
			printf("%d%c", h[x], " \n"[j == int(a[i].size() - 1)]);
		}
		v = v0;
		forn(j, a[i].size())
		{
			v = t.next(v, a[i][j]);
			assert(v > v0);
			u[v] = false;
		}
	}
	
	return 0;
}