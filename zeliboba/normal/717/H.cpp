#pragma comment(linker, "/STACK:66777216")
#pragma warning(disable : 4996)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#pragma hdrstop

#include <cstdint>

#ifdef _MSC_VER
#include <intrin.h>

#else
#define popcount(a) __builtin_popcount(a)
#define clz(a) __builtin_clz(a)
#define ctz(a) __builtin_ctz(a)
#endif

template<typename T>
inline bool umax(T& a, const T& b) {
	return (a < b ? a = b, true : false);
}

#ifdef _MSC_VER

#endif

template<typename T, size_t N>
struct MakeVector {
	
};

template<typename T>
struct MakeVector<T, 1> {
	/// caide keep
	template<typename R = std::vector<T>>
	static R make_vector(std::size_t size, const T& value) {
		return R(size, value);
	}
};

#define all(a) a.begin(), a.end()

#ifdef _MSC_VER

#else
#define LLD "%lld"
#define LLU "%llu"
#endif

#include <iterator>

template<typename T>
class IntegerIterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	using value_type = T;

	constexpr explicit IntegerIterator(const value_type value) : value_(value) {}

	IntegerIterator& operator++() {
		++value_;
		return *this;
	}

	constexpr value_type operator*() const {
		return value_;
	}

	constexpr bool operator ==(const IntegerIterator rhs) const {
		return value_ == rhs.value_;
	}

	constexpr bool operator !=(const IntegerIterator rhs) const {
		return !(*this == rhs);
	}

private:
	value_type value_;

};

template<typename T>
class IntegerRange {
public:
	using const_iterator = IntegerIterator<T>;

	constexpr IntegerRange(const T begin, const T end) : begin_(begin), end_(end) {}

	constexpr const_iterator begin() const {
		return const_iterator(begin_);
	}

	constexpr const_iterator end() const {
		return const_iterator(end_);
	}

private:
	T begin_;
	T end_;

};

template<typename T>
constexpr IntegerRange<T> range(const T to) {
	return IntegerRange<T>(0, to);
}

enum GraphType {
	Weighted = 1
};

template<size_t MASK>
struct is_weighted 
{
	/// caide keep
	static constexpr bool value = (MASK & GraphType::Weighted) != 0;
};

template<typename T = long long, size_t MASK = 0>
class Graph {
public:
	using EdgesList = std::vector<size_t>;

	class Edge {
	public:
		constexpr explicit Edge(const std::vector<size_t>& from, const std::vector<size_t>& to,
			const std::vector<T>& weight, const size_t index) :
			from_(from), to_(to), weight_(weight), index_(index) {}

		size_t to() const {
			return to_[index_];
		}

		void set_index(const size_t index) {
			index_ = index;
		}

	private:
		const std::vector<size_t>& from_;
		const std::vector<size_t>& to_;
		const std::vector<T>& weight_;
		size_t index_;

	};

	template<typename Range>
	class EdgesHolder {
	public:

		template<typename BaseConstIterator>
		class EdgeConstIterator : public BaseConstIterator {
		public:
			using value_type = Edge;
			
			using const_reference = const value_type&;

			constexpr explicit EdgeConstIterator(BaseConstIterator it, const std::vector<size_t>& from,
				const std::vector<size_t>& to, const std::vector<T>& weight) :
				BaseConstIterator(it), cur_edge_(from, to, weight, 0) {}

			const_reference operator*() {
				const typename BaseConstIterator::value_type index = this->BaseConstIterator::operator*();
				cur_edge_.set_index(index);
				return cur_edge_;
			}

		private:
			Edge cur_edge_;

		};

		using const_iterator = EdgeConstIterator<typename Range::const_iterator>;
		
		constexpr explicit EdgesHolder(const Range& range, const std::vector<size_t>& from,
			const std::vector<size_t>& to, const std::vector<T>& weight) :
			begin_(range.begin(), from, to, weight), end_(range.end(), from, to, weight) {}

		constexpr const_iterator begin() const {
			return begin_;
		}

		constexpr const_iterator end() const {
			return end_;
		}

	private:
		const const_iterator begin_;
		const const_iterator end_;

	};

	Graph(const size_t vertices_count) : vertices_count_(vertices_count), edges_(vertices_count) {}

	virtual ~Graph() {
		clear();
	}

	EdgesHolder<EdgesList> edges(const size_t vertex) const {
		return EdgesHolder<EdgesList>(edges_[vertex], from_, to_, weight_);
	}

	void clear();

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void add_directed_edge(const size_t from, const size_t to) {
		push_edge(from, to);
	}

protected:
	void push_edge(const size_t from, const size_t to) {
		const size_t edge_id = from_.size();
		from_.emplace_back(from);
		to_.emplace_back(to);
		edges_[from].emplace_back(edge_id);
	}

	std::vector<EdgesList> edges_;
	std::vector<size_t> from_;
	std::vector<size_t> to_;
	std::vector<T> weight_;

	size_t vertices_count_;

private:
	
};

template<typename T, size_t MASK>
void Graph<T, MASK>::clear() {
	vertices_count_ = 0;
	edges_.clear();
	from_.clear();
	to_.clear();
	weight_.clear();
}

template<typename T = long long, size_t MASK = 0>
class UndirectedGraph : public Graph<T, MASK> {
public:
	UndirectedGraph() : UndirectedGraph(0) {}
	UndirectedGraph(const size_t vertices_count) : Graph<T, MASK>(vertices_count) {}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void add_bidirectional_edge(const size_t from, const size_t to) {
		this->add_directed_edge(from, to);
		this->add_directed_edge(to, from);
	}

};

using namespace std;

constexpr int MAXN = 55555;
constexpr int MAXK = 22;

UndirectedGraph<int> coaches;

size_t n, m;
int teams[MAXN][MAXK];
int len[MAXN];

void solve(std::istream& in, std::ostream& out) {
	srand(time(NULL));
	in >> n >> m;
	coaches = UndirectedGraph<int>(n);
	for (int i : range(m)) {
		int from, to;
		in >> from >> to;
		coaches.add_bidirectional_edge(from - 1, to - 1);
	}
	int teams_cnt = 0;
	for (int i : range(n)) {
		in >> len[i];
		for (int j : range(len[i])) {
			in >> teams[i][j];
			umax(teams_cnt, teams[i][j]);
			--teams[i][j];
		}
	}
	std::vector<int> coach_id(n);
	std::vector<int> conference(teams_cnt);
	std::vector<int> match(n);
	std::iota(all(coach_id), 0);
	bool ok = false;
	while (!ok) {
		std::random_shuffle(all(coach_id));
		conference.assign(teams_cnt, 0);
		for (int team : range(teams_cnt)) {
			conference[team] = rand() % 2;
		}
		match.assign(n, -1);
		for (int coach : coach_id) {
			vector<int> cnt(2, 0);
			for (const auto& it : coaches.edges(coach)) {
				const int to = it.to();
				const int opposite_team = match[to];
				if (opposite_team == -1) {
					continue;
				}
				cnt[conference[opposite_team]]++;
			}
			bool matched = false;
			for (int i : range(len[coach])) {
				const int team_id = teams[coach][i];
				const int conf = conference[team_id];
				if (cnt[conf] <= cnt[1 - conf]) {
					matched = true;
					match[coach] = team_id;
					break;
				}
			}
			if (!matched) {
				match[coach] = teams[coach][0];
			}
		}
		int edges = 0;
		for (int i : range(n)) {
			const int cur_team = match[i];
			const int cur_conf = conference[cur_team];
			for (const auto& it : coaches.edges(i)) {
				const int to = it.to();
				const int opposite_team = match[to];
				const int opposite_conf = conference[opposite_team];
				edges += (opposite_conf ^ cur_conf);
			}
		}
		edges /= 2;
		if (edges > m / 2) {
			for (int i : range(n)) {
				out << match[i] + 1 << " ";
			}
			out << endl;
			for (int i : range(teams_cnt)) {
				out << conference[i] + 1 << " ";
			}
			out << endl;
			break;
		}
	}
}

#include <fstream>

int main() {
    srand(time(NULL));
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;

    out << fixed << setprecision(16);
    solve(in, out);
    return 0;
}