#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <bits/stdc++.h>

// example:
// using mint = modint::modint<1000000007>;
// using mint32 = modint::modint<0x100000000>;
// using mint32 = modint::modint32;
// using mint64 = modint::modint<0>;
// using mint64 = modint::modint64;

// modint::modint<MOD> should works for any MOD in [0 .. 2^64 - 1]
// (0 is a special replacement of 2^64)
// TODO: test all it !!!

namespace modint {
//#define MODINT_USE_XOR_POW
//#define MODINT_USE_UINT128

namespace impl {

template<typename int_t>
using enable_if_integral_t = std::enable_if_t<
	std::is_integral_v<int_t>
#ifdef MODINT_USE_UINT128
		|| std::is_same_v<int_t, __int128_t> || std::is_same_v<int_t, __uint128_t>
#endif
	,
	int_t
>;

template<typename value_t, typename mult_value_t, value_t md, typename src_val_t, src_val_t src_md>
struct value_helper_common {
	static constexpr value_t HALF_TYPE_CAPACITY = static_cast<value_t>(1) << (sizeof(value_t) * 8 - 1);
	static constexpr value_t P2MOD = (static_cast<value_t>(-1) % md + 1) % md;

	template<typename int_t>
	[[nodiscard]] constexpr value_t from_negative(int_t value) const noexcept
	{
		auto x = ~static_cast<std::make_unsigned_t<int_t>>(value);
		if (x >= md) {
			if constexpr (md < HALF_TYPE_CAPACITY) {
				x %= md;
			}
			else {
				x -= md;
			}
		}
		return md - 1 - x;
	}

	template<typename int_t>
	[[nodiscard]] constexpr value_t init(int_t value) const noexcept
	{
		return value < 0 ?
			from_negative(value) :
			static_cast<std::make_unsigned_t<int_t>>(value) >= md ?
				value % md :
				value;
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr int_t convert_to(value_t value) const noexcept
	{
		if constexpr (md == src_md)
			return value;
		else
			return value % src_md;
	}
	
	[[nodiscard]] constexpr value_t plus(value_t l, value_t r) const noexcept
	{
		if constexpr (md <= HALF_TYPE_CAPACITY) {
			l += r;
			if (l >= md) l -= md;
		}
		else {
			auto tmp = l;
			l += r;
			if (l < tmp) l += P2MOD;
			else if (l >= md) l -= md;
		}
		return l;
	}
	
	[[nodiscard]] constexpr value_t minus(value_t l, value_t r) const noexcept
	{
		if constexpr (md <= HALF_TYPE_CAPACITY) {
			l -= r;
			if (l >= md) l += md;
		}
		else {
			auto tmp = l;
			l -= r;
			if (l > tmp) l -= P2MOD;
		}
		return l;
	}
	
	[[nodiscard]] constexpr mult_value_t mult(value_t l, value_t r) const noexcept
	{
		return l * static_cast<mult_value_t>(r);
	}
	
	[[nodiscard]] constexpr value_t plusplus(value_t v) const noexcept
	{
		return (v == md - 1) ? 0 : v + 1;
	}
	
	[[nodiscard]] constexpr value_t minusminus(value_t v) const noexcept
	{
		return v ? v - 1 : md - 1;
	}
};

template<typename value_t, value_t md>
struct is_p2_or_zero {
	static constexpr bool value = !(md & (md - 1));
};

template<typename value_t, value_t md>
struct convert_value_helper {
	template<typename int_t, value_t md_>
	[[nodiscard]] constexpr std::enable_if_t<
		md_ == 0 || md_ == 0x100000000 || !is_p2_or_zero<value_t, md_>::value, int_t
	> to(value_t value) const
	{
		return value;
	}
	
	template<typename int_t, value_t md_>
	[[nodiscard]] constexpr std::enable_if_t<
		md_ != 0 && md_ != 0x100000000 && is_p2_or_zero<value_t, md_>::value, int_t
	> to(value_t value) const
	{
		return value & (md_ - 1);
	}
};

template<typename value_t, value_t md>
struct value_helper_simple {
	template<typename int_t>
	[[nodiscard]] constexpr value_t init(int_t value) const noexcept
	{
		return value;
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr int_t convert_to(value_t value) const noexcept
	{
		return convert_value_helper<value_t, md>().template to<int_t, md>(value);
	}
	
	[[nodiscard]] constexpr value_t plus(value_t l, value_t r) const noexcept
	{
		return l + r;
	}
	
	[[nodiscard]] constexpr value_t minus(value_t l, value_t r) const noexcept
	{
		return l - r;
	}
	
	[[nodiscard]] constexpr value_t mult(value_t l, value_t r) const noexcept
	{
		return l * r;
	}
	
	[[nodiscard]] constexpr value_t plusplus(value_t v) const noexcept
	{
		return v + 1;
	}
	
	[[nodiscard]] constexpr value_t minusminus(value_t v) const noexcept
	{
		return v - 1;
	}
};

template<typename value_t, typename mult_value_t, value_t md, typename src_val_t, src_val_t src_md>
struct value_helper : public std::conditional_t<
	is_p2_or_zero<value_t, md>::value,
	value_helper_simple<value_t, md>,
	value_helper_common<value_t, mult_value_t, md, src_val_t, src_md>
> {};

template<typename value_t, value_t md>
struct get_mod_helper {
	constexpr value_t operator () () const
	{
		return md;
	}
};

template<>
struct get_mod_helper<uint32_t, 0> {
	constexpr uint64_t operator () () const
	{
		return 0x100000000;
	}
};

#ifdef MODINT_USE_UINT128
template<>
struct get_mod_helper<uint64_t, 0x100000000> {
	constexpr __uint128_t operator () () const
	{
		return static_cast<__uint128_t>(1) << 64;
	}
};
#else
template<>
struct get_mod_helper<uint64_t, 0x100000000> {
	constexpr uint64_t operator () () const
	{
		return 0;
	}
};
#endif

template<typename value_t, value_t md, typename value2_t, value2_t md2>
struct is_md_divides {
	static constexpr bool value = (
		(md2 == 0x100000000 && md <= std::numeric_limits<uint64_t>::max() && is_p2_or_zero<value_t, md>::value) ||
		(md2 == 0 && md <= 0xFFFFFFFF && is_p2_or_zero<value_t, md>::value) ||
		(
			md2 && md2 != 0x100000000 && (
				(!md && md2 % 0x100000000 == 0) ||
				(md && md != 0x100000000 && md2 % md == 0)
			)
		)
	);
};

template<typename int_t>
struct numeric_limits : public std::numeric_limits<int_t> {
};

#ifdef MODINT_USE_UINT128
template<>
struct numeric_limits<__uint128_t> {
	static constexpr __uint128_t max()
	{
		return static_cast<__uint128_t>(-1);
	}
};
#endif

template<typename value_t, value_t md>
struct calc_mult_md {
	static constexpr value_t value =
		!is_p2_or_zero<value_t, md>::value && numeric_limits<value_t>::max() / md / md >= 1 ?
			(numeric_limits<value_t>::max() / md / md * md * md) :
			md;
};

}  // namespace impl

/// class modint_base
template<typename val_t, typename mult_val_t, val_t md, typename src_val_t, src_val_t src_md>
class modint_base {
public:
	using value_t = val_t;
	using mult_value_t = mult_val_t;
	using mult_t = modint_base<
		mult_value_t, mult_value_t, impl::calc_mult_md<mult_value_t, src_md>::value, src_val_t, src_md
	>;
	
	modint_base() noexcept = default;

	modint_base(const modint_base &) noexcept = default;
	modint_base(modint_base &&) noexcept = default;
	
	modint_base &operator = (const modint_base &) noexcept = default;
	modint_base &operator = (modint_base &&) noexcept = default;
	
	template<
		typename int_t,
		typename impl::enable_if_integral_t<int_t> * = nullptr
	>
	constexpr modint_base(int_t value) noexcept :
		value_(impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().init(value))
	{}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2,
		typename std::enable_if_t<
			impl::is_md_divides<src_val_t, src_md, src_val2_t, src_md2>::value, value2_t
		> * = nullptr
	>
	constexpr modint_base(modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> r) noexcept :
		modint_base(static_cast<src_val2_t>(r))
	{}
	
	template<
		typename int_t,
		typename impl::enable_if_integral_t<int_t> * = nullptr
	>
	[[nodiscard]] constexpr explicit operator int_t() const noexcept
	{
		return impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().template convert_to<int_t>(value_);
	}
	
	constexpr modint_base &operator += (modint_base r) noexcept
	{
		value_ = impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().plus(value_, r.value_);
		return *this;
	}
	
	constexpr modint_base &operator -= (modint_base r) noexcept
	{
		value_ = impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().minus(value_, r.value_);
		return *this;
	}
	
	constexpr modint_base &operator *= (modint_base r) noexcept
	{
		auto mres = impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().mult(
			static_cast<src_val_t>(*this), static_cast<src_val_t>(r)
		);
		if constexpr (std::is_same_v<value_t, src_val_t>)
			mres %= src_md;
		value_ = mres;
		return *this;
	}
	
	constexpr modint_base &operator ++ () noexcept
	{
		value_ = impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().plusplus(value_);
		return *this;
	}
	
	constexpr modint_base operator ++ (int) noexcept
	{
		modint_base tmp = *this;
		++*this;
		return tmp;
	}
	
	constexpr modint_base &operator -- () noexcept
	{
		value_ = impl::value_helper<value_t, mult_value_t, md, src_val_t, src_md>().minusminus(value_);
		return *this;
	}
	
	constexpr modint_base operator -- (int) noexcept
	{
		modint_base tmp = *this;
		--*this;
		return tmp;
	}
	
	constexpr modint_base operator - () noexcept
	{
		return modint_base(0) - *this;
	}
	
	[[nodiscard]] inline constexpr friend modint_base operator + (modint_base l, modint_base r) noexcept
	{
		return modint_base(l) += r;
	}

	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		mult_t
	> operator + (modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> l, modint_base r) noexcept
	{
		return modint_base(static_cast<src_val_t>(l)) += r;
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		mult_t
	> operator + (modint_base l, modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> r) noexcept
	{
		return modint_base(l) += static_cast<src_val_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend modint_base operator - (modint_base l, modint_base r) noexcept
	{
		return modint_base(l) -= r;
	}

	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		mult_t
	> operator - (modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> l, modint_base r) noexcept
	{
		return modint_base(static_cast<src_val_t>(l)) -= r;
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		mult_t
	> operator - (modint_base l, modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> r) noexcept
	{
		return modint_base(l) -= static_cast<src_val_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend mult_t operator * (modint_base l, modint_base r) noexcept
	{
		return mult_t(static_cast<src_val_t>(l)) *= static_cast<src_val_t>(r);
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		mult_t
	> operator * (modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> l, modint_base r) noexcept
	{
		return mult_t(static_cast<src_val_t>(l)) *= static_cast<src_val_t>(r);
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		mult_t
	> operator * (modint_base l, modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> r) noexcept
	{
		return mult_t(static_cast<src_val_t>(l)) *= static_cast<src_val_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend bool operator == (modint_base l, modint_base r) noexcept
	{
		return static_cast<src_val_t>(l) == static_cast<src_val_t>(r);
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		bool
	> operator == (modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> l, modint_base r) noexcept
	{
		return static_cast<src_val_t>(l) == static_cast<src_val_t>(r);
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		bool
	> operator == (modint_base l, modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> r) noexcept
	{
		return static_cast<src_val_t>(l) == static_cast<src_val_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend bool operator != (modint_base l, modint_base r) noexcept
	{
		return !(l == r);
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		bool
	> operator != (modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> l, modint_base r) noexcept
	{
		return !(l == r);
	}
	
	template<
		typename value2_t, typename mult_value2_t, value2_t md2, typename src_val2_t, src_val2_t src_md2
	>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, modint_base> &&
			std::is_same_v<modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2>, mult_t>,
		bool
	> operator != (modint_base l, modint_base<value2_t, mult_value2_t, md2, src_val2_t, src_md2> r) noexcept
	{
		return !(l == r);
	}
	
	template<typename int_t>
	constexpr modint_base &pow_this(int_t k) noexcept
	{
		modint_base tmp = *this;
		*this = 1;
		for (;;) {
			if (k & 1) *this *= tmp;
			k >>= 1;
			if (!k) break;
			tmp *= tmp;
		}
		return *this;
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr mult_t pow(int_t k) const noexcept
	{
		return mult_t(*this).pow_this(k);
	}

#ifdef MODINT_USE_XOR_POW
	template<typename int_t>
	constexpr modint_base &operator ^= (int_t k) noexcept
	{
		return pow_this(k);
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr modint_base operator ^ (int_t k) const noexcept
	{
		return modint_base(*this) ^= k;
	}
#endif
	
	[[nodiscard]] constexpr value_t load() const noexcept
	{
		return value_;
	}
	
	static constexpr auto get_mod() noexcept
	{
		return impl::get_mod_helper<src_val_t, src_md>()();
	}
	
private:
	static_assert(
		md != 0 || std::is_same_v<val_t, uint32_t>,
		"Use `val_t`=`uint32_t` for module=2**32"
	);
	static_assert(
		md != 0 || std::is_same_v<mult_val_t, uint32_t>,
		"Use `mult_val_t`=`uint32_t` for module=2**32"
	);
	static_assert(
		md != 0x100000000 || std::is_same_v<val_t, uint64_t>,
		"Use `val_t`=`uint64_t` for module=2**64"
	);
	static_assert(
		md != 0x100000000 || std::is_same_v<mult_val_t, uint64_t>,
		"Use `mult_val_t`=`uint64_t` for module=2**64"
	);
	static_assert(
		!md || md == 0x100000000 || md <= impl::numeric_limits<val_t>::max(),
		"`val_t` is too small for `md`"
	);
	
	value_t value_{0};
};

template<typename value_t, typename mult_value_t, value_t md, typename src_val_t, src_val_t src_md>
std::istream &operator >> (std::istream &is, modint_base<value_t, mult_value_t, md, src_val_t, src_md> &r)
{
	src_val_t x;
	is >> x;
	r = x;
	return is;
}

template<typename value_t, typename mult_value_t, value_t md, typename src_val_t, src_val_t src_md>
std::ostream &operator << (std::ostream &os, modint_base<value_t, mult_value_t, md, src_val_t, src_md> r)
{
	return os << static_cast<src_val_t>(r);
}

namespace impl {

template<uint64_t user_md>
using modint_base_value_t = std::conditional_t<
	(user_md > 0 && user_md <= static_cast<uint64_t>(impl::numeric_limits<uint32_t>::max()) + 1),
	uint32_t,
	uint64_t
>;

template<uint64_t user_md, typename value_t, typename mult_value_t>
struct modint_helper {
	using type = modint_base<value_t, mult_value_t, user_md, value_t, user_md>;
};

template<typename value_t, typename mult_value_t>
struct modint_helper<0, value_t, mult_value_t> {
	using type = modint_base<value_t, mult_value_t, 0x100000000, value_t, 0x100000000>;
};

template<typename value_t, typename mult_value_t>
struct modint_helper<0x100000000, value_t, mult_value_t> {
	using type = modint_base<value_t, mult_value_t, 0, value_t, 0>;
};

template<typename value_t, uint64_t user_md>
struct mult_value_helper;

template<uint64_t user_md>
struct mult_value_helper<uint32_t, user_md> {
	using type = std::conditional_t<is_p2_or_zero<uint32_t, user_md>::value, uint32_t, uint64_t>;
};

template<>
struct mult_value_helper<uint32_t, 0x100000000> {
	using type = uint32_t;
};

#ifdef MODINT_USE_UINT128
template<uint64_t user_md>
struct mult_value_helper<uint64_t, user_md> {
	using type = std::conditional_t<is_p2_or_zero<uint64_t, user_md>::value, uint64_t, __uint128_t>;
};
#endif

template<>
struct mult_value_helper<uint64_t, 0> {
	using type = uint64_t;
};

template<typename value_t, uint64_t user_md>
using mult_value_t = typename mult_value_helper<value_t, user_md>::type;

}  // namespace impl

template<
	uint64_t m,
	typename value_t = impl::modint_base_value_t<m>,
	typename mult_value_t = impl::mult_value_t<value_t, m>
>
using modint = typename impl::modint_helper<m, value_t, mult_value_t>::type;

using modint32 = modint<0x100000000>;
using modint64 = modint<0>;

}  // namespace modint

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;

const int MOD = 1000000007;
using imd = modint::modint<MOD>;

#define MAXP 1000008
int b[((MAXP+1) >> 5) + 10];
int c[MAXP + 8];

__attribute__((constructor)) void gen_primes()
{
	memset(b, 0, sizeof(b));
	int sq = (int)(sqrt(MAXP) + 2);
	c[2] = 1;
	for(int j = 4; j <= MAXP; j += 2)
	{
		b[j >> 5] |= 1 << j;
		c[j] = 2;
	}
	for(int i=3; i<=sq; i+=2)
	{
		if (b[i >> 5] & (1 << i)) continue;
		c[i] = i;
		int j = i * i;
		while (j <= MAXP)
		{
			b[j >> 5] |= 1 << j;
			if (!c[j]) c[j] = i;
			j += i * 2;
		}
	}
	b[1 >> 5] |= 1 << 1;
	for(int i=2; i<=MAXP; i++)
	{
		if (!(b[i >> 5] & (1 << i)))
		{
			c[i] = i;
		}
	}
}

int qq;
imd f[1024000];
imd rf[1024000];
imd cs[22];

/*inline int mypow(int a, int k, int p)
{
	if (!k) return 1;
	if (k == 1) return a % p;
	int ans = mypow(a, k / 2, p);
	ans = ans * (i64)ans % p;
	if (k & 1) ans = ans * (i64)a % p;
	return ans;
}

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

inline void add2(u64 &a, u64 b)
{
	a += b;
	if (a >= MOD2) a -= MOD2;
}
*/
void precalc()
{
	f[0] = 1;
	rf[0] = 1;
	For(i, 1, 1000100)
	{
		f[i] = f[i - 1] * i;
	}
	For(i, 1, 1000000)
	{
		rf[i] = rf[i - 1] * imd(i).pow(MOD - 2);
	}
}

inline imd calc_c(int n, int k)
{
	return f[n] * rf[k] * rf[n - k];
}

inline void rec(int *e, int k, imd::mult_t &ans)
{
	imd::mult_t pr = 1;
	forn(s, k)
	{
		imd::mult_t cur = 0;
		forn(i, e[s] + 1)
		{
			cur += cs[e[s] - i];
		}
		cur = cur * 2 - cs[e[s]];
		pr *= cur;
	}
	ans += pr;
}

int calc(int r, int n)
{
	imd::mult_t ans = 0;
	int e[42];
	int k = 0;
	int x = n;
	int ma = 0;
	while (x > 1)
	{
		int z = c[x];
		e[k] = 1;
		x /= z;
		while (x % z == 0)
		{
			x /= z;
			e[k]++;
		}
		ma = max(ma, e[k]);
		k++;
	}
	if (!r) return 1 << k;
	forn(i, ma + 1)
	{
		cs[i] = calc_c(r - 1 + i, r - 1);
	}
	rec(e, k, ans);

	return static_cast<int>(ans);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	precalc();
//	qq = 1000000;
	scanf("%d", &qq);
//	i64 sum = 0;
	forn(i, qq)
	{
		int r, n;
//		r = 1000000;
//		n = 942480;
		scanf("%d%d", &r, &n);
		int ans = calc(r, n);
//		sum += ans;
		printf("%d\n", ans);
	}
//	printf("%lld\n", sum);
	
	return 0;
}