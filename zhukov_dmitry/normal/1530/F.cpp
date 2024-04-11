#include <stdio.h>
#include <bits/stdc++.h>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iosfwd>
#include <limits>
#include <string_view>
#include <type_traits>
#include <utility>
#pragma GCC optimize("O3")

#ifdef ROOM_311
#define OLYMP_DEBUG
#else
#define OLYMP_NDEBUG
#endif

//#include <olymp/numeric/epsilonized.h>

namespace olymp::utils {

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

}  // namespace olymp::utils

namespace olymp::utils {

// is_integral
template<typename type>
struct is_integral : public std::is_integral<type> {};

#ifdef __SIZEOF_INT128__
template<>
struct is_integral<__int128_t> : public std::true_type {};

template<>
struct is_integral<__uint128_t> : public std::true_type {};
#endif

template<typename type>
inline constexpr bool is_integral_v = is_integral<type>::value;
// end is_integral

// is_signed
template<typename type>
struct is_signed : public std::is_signed<type> {};

#ifdef __SIZEOF_INT128__
template<>
struct is_signed<__int128_t> : public std::true_type {};
#endif

template<typename type>
inline constexpr bool is_signed_v = is_signed<type>::value;
// end is_signed

// is_unsigned
template<typename type>
struct is_unsigned : public std::is_unsigned<type> {};

#ifdef __SIZEOF_INT128__
template<>
struct is_unsigned<__uint128_t> : public std::true_type {};
#endif

template<typename type>
inline constexpr bool is_unsigned_v = is_unsigned<type>::value;
// end is_unsigned

// make_unsigned
template<typename type>
struct make_signed : public std::make_signed<type> {};

#ifdef __SIZEOF_INT128__
template<>
struct make_signed<__int128_t> {
	using type = __int128_t;
};

template<>
struct make_signed<__uint128_t> {
	using type = __int128_t;
};
#endif
// end make_signed

// make_unsigned
template<typename type>
struct make_unsigned : public std::make_unsigned<type> {};

#ifdef __SIZEOF_INT128__
template<>
struct make_unsigned<__int128_t> {
	using type = __uint128_t;
};

template<>
struct make_unsigned<__uint128_t> {
	using type = __uint128_t;
};
#endif
// end make_unsigned

template<typename type>
using make_unsigned_t = typename make_unsigned<type>::type;

// is_precise
template<typename type>
struct is_precise : public is_integral<type> {};

template<typename type>
inline constexpr bool is_precise_v = is_precise<type>::value;
// end is_precise

// is_division_accurate
template<typename type>
struct is_division_accurate : public std::bool_constant<
	std::is_floating_point_v<type> && !utils::is_integral_v<type>
> {};

template<typename type>
inline constexpr bool is_division_accurate_v = is_division_accurate<type>::value;
// end is_division_accurate

// is_sqrt_accurate
template<typename type>
struct is_sqrt_accurate : public std::bool_constant<
	std::is_floating_point_v<type> && !utils::is_integral_v<type>
> {};

template<typename type>
inline constexpr bool is_sqrt_accurate_v = is_sqrt_accurate<type>::value;
// end is_sqrt_accurate

// is_fmod_positive
template<typename type>
struct is_fmod_positive : public std::false_type {};

template<typename type>
inline constexpr bool is_fmod_positive_v = is_fmod_positive<type>::value;
// end is_fmod_positive

}  // namespace olymp::utils

namespace olymp::utils {

// numeric_limits
template<typename int_t>
struct numeric_limits : public std::numeric_limits<int_t> {
};

#ifdef __SIZEOF_INT128__

namespace impl {

struct numeric_limits_int128_t {
	static constexpr bool is_specialized = true;
	// TODO: specialize all (https://en.cppreference.com/w/cpp/types/numeric_limits)

	static constexpr __int128_t min() noexcept
	{
		return static_cast<__int128_t>(static_cast<__uint128_t>(1) << 127);
	}
	static constexpr __int128_t lowest() noexcept
	{
		return static_cast<__int128_t>(static_cast<__uint128_t>(1) << 127);
	}
	static constexpr __int128_t max() noexcept
	{
		return static_cast<__int128_t>((static_cast<__uint128_t>(1) << 127) - 1);
	}
};

struct numeric_limits_uint128_t {
	static constexpr bool is_specialized = true;
	// TODO: specialize all (https://en.cppreference.com/w/cpp/types/numeric_limits)
	
	static constexpr __uint128_t min() noexcept { return 0; }
	static constexpr __uint128_t lowest() noexcept { return 0; }
	static constexpr __uint128_t max() noexcept { return static_cast<__uint128_t>(-1); }
};

template<typename f_t, typename s_t>
struct numeric_limits_pair {
	using value_type = std::pair<f_t, s_t>;

	static constexpr bool is_specialized = true;
	// TODO: specialize all (https://en.cppreference.com/w/cpp/types/numeric_limits)
	
	static constexpr value_type min() noexcept {
		return std::make_pair<f_t, s_t>(
			numeric_limits<f_t>::min(),
			numeric_limits<s_t>::min()
		);
	}
	static constexpr value_type lowest() noexcept {
		return std::make_pair<f_t, s_t>(
			numeric_limits<f_t>::lowest(),
			numeric_limits<s_t>::lowest()
		);
	}
	static constexpr value_type max() noexcept {
		return std::make_pair<f_t, s_t>(
			numeric_limits<f_t>::max(),
			numeric_limits<s_t>::max()
		);
	}
};

}  // namespace impl

template<>
struct numeric_limits<__int128_t> : public std::conditional_t<
	std::numeric_limits<__int128_t>::is_specialized,
	std::numeric_limits<__int128_t>,
	impl::numeric_limits_int128_t
> {};

template<>
struct numeric_limits<__uint128_t> : public std::conditional_t<
	std::numeric_limits<__uint128_t>::is_specialized,
	std::numeric_limits<__uint128_t>,
	impl::numeric_limits_uint128_t
> {};

template<typename f_t, typename s_t>
struct numeric_limits<std::pair<f_t, s_t>> : public std::conditional_t<
	(
		std::numeric_limits<f_t>::is_specialized &&
		std::numeric_limits<s_t>::is_specialized
	),
	impl::numeric_limits_pair<f_t, s_t>,
	std::numeric_limits<std::pair<f_t, s_t>>
> {};

#endif
// end numeric_limits

}  // namespace olymp::utils

// example:
// using mint = numeric::modular<1000000007>;
// using mint32 = numeric::modular<0x100000000>;
// using mint32 = numeric::modular32;
// using mint64 = numeric::modular<0>;
// using mint64 = numeric::modular64;

// numeric::modular<MOD> should works for any MOD in [0 .. 2^64 - 1]
// (0 is a special replacement of 2^64)
// TODO: test it all !!!

namespace olymp::numeric {
//#define MODULAR_USE_XOR_POW
#ifdef __SIZEOF_INT128__
#define MODULAR_USE_UINT128
#endif

namespace impl {

template<typename int_t>
using enable_if_integral_t = std::enable_if_t<utils::is_integral_v<int_t>, int_t>;

template<typename value_t, value_t md>
struct is_p2_or_zero : public std::bool_constant<!(md & (md - 1))> {
};

template<typename value_t>
struct mult_value_helper_var;

template<>
struct mult_value_helper_var<uint32_t> {
	using type = uint64_t;
};

#ifdef MODULAR_USE_UINT128
template<>
struct mult_value_helper_var<uint64_t> {
	using type = __uint128_t;
};
#endif

template<typename value_t, uint64_t user_md>
struct mult_value_helper;

template<uint64_t user_md>
struct mult_value_helper<uint32_t, user_md> {
	using type = std::conditional_t<
		is_p2_or_zero<uint32_t, user_md>::value,
		uint32_t,
		std::conditional_t<(user_md <= 0xffff), uint32_t, uint64_t>
	>;
};

template<>
struct mult_value_helper<uint32_t, 0x100000000> {
	using type = uint32_t;
};

#ifdef MODULAR_USE_UINT128
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

template<typename value_t, value_t md>
struct calc_mult_md : public std::integral_constant<
	value_t,
	!is_p2_or_zero<value_t, md>::value && utils::numeric_limits<value_t>::max() / md >= 1 ?
		(utils::numeric_limits<value_t>::max() / md * md) :
		md
> {
};

template<typename value_t, typename mult_value_t, value_t md>
struct module_const_value_helper {
	static constexpr value_t modulus = md;
	
	static constexpr bool is_const_value = true;
	
	static constexpr bool fit_twice =
		modulus <= (static_cast<value_t>(1) << (sizeof(value_t) * 8 - 1));
	static constexpr value_t p2mod = (static_cast<value_t>(-1) % modulus + 1) % modulus;
	
	using value_type = value_t;
	using mult_value_type = mult_value_t;
	
	using mult_type = module_const_value_helper<
		mult_value_t, mult_value_t, calc_mult_md<mult_value_t, md>::value
	>;
};

template<typename value_t>
class slow_divider {
public:
	constexpr slow_divider() = default;
	explicit constexpr slow_divider(value_t md) : md_(md) {}
	
	constexpr value_t divide (value_t x) const {
		return x / md_;
	}
	
private:
	value_t md_{};
};

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
struct module_var_value_helper {
	static value_t modulus;
	
	static constexpr bool is_const_value = false;
	
	static bool fit_twice;
	static value_t p2mod;
	
	using divider_t = divider_tmpl<value_t>;
	static divider_t divider;
	
	using value_type = value_t;
	using mult_value_type = mult_value_t;
	using mult_type = module_var_value_helper<
		tag, mult_value_t, mult_value_t, divider_tmpl
	>;
	
	static constexpr void init_value(value_t val)
	{
		do_init_value(val, val);
	}

	static constexpr bool is_p2_or_zero(mult_value_t md)
	{
		return !(md & (md - 1));
	}
	
	static constexpr mult_value_t calc_mult_md(mult_value_t md)
	{
		return (
			!module_var_value_helper::is_p2_or_zero(md) &&
			utils::numeric_limits<mult_value_t>::max() / md >= 1
		) ?
			(utils::numeric_limits<mult_value_t>::max() / md * md) :
			md;
	}
	
	static constexpr void do_init_value(value_t val, value_t src_val)
	{
		module_var_value_helper::modulus = val;
		module_var_value_helper::fit_twice =
			val <= (static_cast<value_t>(1) << (sizeof(value_t) * 8 - 1));
		module_var_value_helper::p2mod = (static_cast<value_t>(-1) % val + 1) % val;
		module_var_value_helper::divider = divider_t(src_val);
		if constexpr (!std::is_same_v<module_var_value_helper, mult_type>) {
			mult_type::do_init_value(module_var_value_helper::calc_mult_md(val), src_val);
		}
	}
};

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline value_t module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::modulus = 0;

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline bool module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::fit_twice = false;

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline value_t module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::p2mod = 0;

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline divider_tmpl<value_t> module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::divider;

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper_var {
	typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (std::is_same_v<typename src_module_info_t::value_type, value_t>)
			return value - src_module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else if constexpr (std::is_same_v<typename module_info_t::value_type, value_t>)
			return value - module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else
			return value % src_module_info_t::modulus;
	}
};

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper_var_noinline {
	__attribute__((noinline)) typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (std::is_same_v<typename src_module_info_t::value_type, value_t>)
			return value - src_module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else if constexpr (std::is_same_v<typename module_info_t::value_type, value_t>)
			return value - module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else
			return value % src_module_info_t::modulus;
	}
};

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper {
	constexpr typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (src_module_info_t::is_const_value)
			return value % src_module_info_t::modulus;
		else
			return fast_mod_helper_var<value_t, module_info_t, src_module_info_t>()(value);
	}
};

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper_noinline {
	constexpr typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (src_module_info_t::is_const_value)
			return value % src_module_info_t::modulus;
		else
			return fast_mod_helper_var_noinline<value_t, module_info_t, src_module_info_t>()(value);
	}
};

template<typename module_info_t, typename src_module_info_t>
struct value_helper_common {
	using value_t = typename module_info_t::value_type;
	using mult_value_t = typename module_info_t::mult_value_type;

	template<typename int_t>
	[[nodiscard]] constexpr value_t from_negative(int_t value) const noexcept
	{
		using uint_t = utils::make_unsigned_t<int_t>;
		uint_t x = ~(static_cast<uint_t>(value));
		if (x >= module_info_t::modulus) {
			if /*constexpr */(sizeof(int_t) > sizeof(value_t) || module_info_t::fit_twice) {
				x = fast_mod_helper_noinline<uint_t, module_info_t, src_module_info_t>()(x);
			}
			else {
				x -= module_info_t::modulus;
			}
		}
		return module_info_t::modulus - 1 - x;
	}

	template<typename int_t>
	[[nodiscard]] constexpr value_t init(int_t value) const noexcept
	{
		using uint_t = utils::make_unsigned_t<int_t>;
		return value < 0 ?
			from_negative(value) :
			static_cast<uint_t>(value) >= module_info_t::modulus ?
				fast_mod_helper_noinline<
					uint_t, module_info_t, src_module_info_t
				>()(static_cast<uint_t>(value)) :
				value;
	}
	
	[[nodiscard]] constexpr value_t init(bool value) const noexcept
	{
		return init(static_cast<uint32_t>(value));
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr int_t convert_to(value_t value) const noexcept
	{
		if constexpr (std::is_same_v<module_info_t, src_module_info_t>)
			return value;
		else
			return fast_mod_helper<value_t, module_info_t, src_module_info_t>()(value);
	}
	
	[[nodiscard]] constexpr value_t plus(value_t l, value_t r) const noexcept
	{
		if /*constexpr */(module_info_t::fit_twice) {
			l += r;
			if (l >= module_info_t::modulus) l -= module_info_t::modulus;
		}
		else {
			auto tmp = l;
			l += r;
			if (l < tmp) l += module_info_t::p2mod;
			else if (l >= module_info_t::modulus) l -= module_info_t::modulus;
		}
		return l;
	}
	
	[[nodiscard]] constexpr value_t minus(value_t l, value_t r) const noexcept
	{
		if /*constexpr */(module_info_t::fit_twice) {
			l -= r;
			if (l >= module_info_t::modulus) l += module_info_t::modulus;
		}
		else {
			auto tmp = l;
			l -= r;
			if (l > tmp) l -= module_info_t::p2mod;
		}
		return l;
	}
	
	[[nodiscard]] constexpr mult_value_t mult(value_t l, value_t r) const noexcept
	{
		return l * static_cast<mult_value_t>(r);
	}
	
	[[nodiscard]] constexpr value_t plusplus(value_t v) const noexcept
	{
		return (v == module_info_t::modulus - 1) ? 0 : v + 1;
	}
	
	[[nodiscard]] constexpr value_t minusminus(value_t v) const noexcept
	{
		return v ? v - 1 : module_info_t::modulus - 1;
	}
};

struct convert_value_helper {
	template<typename value_t, typename int_t, value_t md>
	[[nodiscard]] constexpr std::enable_if_t<
		md == 0 || md == 0x100000000 || !is_p2_or_zero<value_t, md>::value, int_t
	> to(value_t value) const
	{
		return value;
	}
	
	template<typename value_t, typename int_t, value_t md>
	[[nodiscard]] constexpr std::enable_if_t<
		md != 0 && md != 0x100000000 && is_p2_or_zero<value_t, md>::value, int_t
	> to(value_t value) const
	{
		return value & (md - 1);
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
		return convert_value_helper().to<value_t, int_t, md>(value);
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

template<typename module_info_t, typename src_module_info_t>
struct value_helper : public value_helper_common<module_info_t, src_module_info_t> {
};

template<
	typename value_t, typename mult_value_t, value_t md,
	typename src_value_t, typename src_mult_value_t, src_value_t src_md
>
struct value_helper<
	module_const_value_helper<value_t, mult_value_t, md>,
	module_const_value_helper<src_value_t, src_mult_value_t, src_md>
> : public std::conditional_t<
	is_p2_or_zero<value_t, md>::value,
	value_helper_simple<value_t, md>,
	value_helper_common<
		module_const_value_helper<value_t, mult_value_t, md>,
		module_const_value_helper<src_value_t, src_mult_value_t, src_md>
	>
> {
};

template<typename module_info_t>
struct get_mod_helper;

template<typename value_t, typename mult_value_t, value_t md>
struct get_mod_helper<module_const_value_helper<value_t, mult_value_t, md>> {
	constexpr value_t operator () () const
	{
		return md;
	}
};

template<>
struct get_mod_helper<module_const_value_helper<uint32_t, uint32_t, 0>> {
	constexpr uint64_t operator () () const
	{
		return 0x100000000;
	}
};

#ifdef MODULAR_USE_UINT128
template<>
struct get_mod_helper<module_const_value_helper<uint64_t, uint64_t, 0x100000000>> {
	constexpr __uint128_t operator () () const
	{
		return static_cast<__uint128_t>(1) << 64;
	}
};
#else
template<>
struct get_mod_helper<module_const_value_helper<uint64_t, uint64_t, 0x100000000>> {
	constexpr uint64_t operator () () const
	{
		return 0;
	}
};
#endif

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
struct get_mod_helper<module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>> {
	value_t operator () () const
	{
		return module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::modulus;
	}
};

template<typename value_t, value_t md, typename value2_t, value2_t md2>
struct is_md_divides_base : public std::bool_constant<
	(
		(
			md2 == 0x100000000 &&
			md <= utils::numeric_limits<uint64_t>::max() &&
			is_p2_or_zero<value_t, md>::value
		) ||
		(md2 == 0 && md <= 0xFFFFFFFF && is_p2_or_zero<value_t, md>::value) ||
		(
			md2 && md2 != 0x100000000 && (
				(!md && md2 % 0x100000000 == 0) ||
				(md && md != 0x100000000 && md2 % md == 0)
			)
		)
	)
> {
};

template<typename module_info_t, typename module_info2_t>
struct is_md_divides : public is_md_divides_base<
	typename module_info_t::value_type, module_info_t::modulus,
	typename module_info2_t::value_type, module_info2_t::modulus
> {
};

template<
	typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl,
	typename tag2, typename value2_t, typename mult_value2_t, template<typename> typename divider2_tmpl
>
struct is_md_divides<
	module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>,
	module_var_value_helper<tag2, value2_t, mult_value2_t, divider2_tmpl>
> : public std::false_type {
};

template<typename module_info_t>
struct modular_base_checker : public std::true_type {
};

template<typename value_t, typename mult_value_t, value_t md>
struct modular_base_checker<
	module_const_value_helper<value_t, mult_value_t, md>
> : public std::true_type {
	static_assert(
		md != 0 || std::is_same_v<value_t, uint32_t>,
		"Use `val_t`=`uint32_t` for module=2**32"
	);
	static_assert(
		md != 0 || std::is_same_v<mult_value_t, uint32_t>,
		"Use `mult_val_t`=`uint32_t` for module=2**32"
	);
	static_assert(
		md != 0x100000000 || std::is_same_v<value_t, uint64_t>,
		"Use `val_t`=`uint64_t` for module=2**64"
	);
	static_assert(
		md != 0x100000000 || std::is_same_v<mult_value_t, uint64_t>,
		"Use `mult_val_t`=`uint64_t` for module=2**64"
	);
	static_assert(
		!md || md == 0x100000000 || md <= utils::numeric_limits<value_t>::max(),
		"`val_t` is too small for `md`"
	);
};

/// class modular_base
template<typename module_info_t, typename src_module_info_t>
class modular_base {
public:
	static_assert(
		std::is_same_v<
			typename module_info_t::mult_value_type,
			typename src_module_info_t::mult_value_type
		>,
		"inconsistent mult_value_type in module_info_t and src_module_info_t"
	);
	using value_t = typename module_info_t::value_type;
	using mult_value_t = typename module_info_t::mult_value_type;
	using mult_t = modular_base<typename module_info_t::mult_type, src_module_info_t>;
	using module_info_type = module_info_t;
	
	using src_value_t = typename src_module_info_t::value_type;
	using src_mult_value_t = typename src_module_info_t::mult_value_type;
	using src_module_info_type = src_module_info_t;
	using src_t = modular_base<src_module_info_t, src_module_info_t>;
	
	friend class modular_base<src_module_info_t, src_module_info_t>;
	friend class modular_base<typename module_info_t::mult_type, src_module_info_t>;
	
	struct modular_value_t {
		constexpr modular_value_t(value_t value) : value(value) {}
		
		value_t value;
	};
	
	modular_base() noexcept = default;

	modular_base(const modular_base &) noexcept = default;
	modular_base(modular_base &&) noexcept = default;
	
	modular_base &operator = (const modular_base &) noexcept = default;
	modular_base &operator = (modular_base &&) noexcept = default;
	
	template<
		typename int_t,
		typename impl::enable_if_integral_t<int_t> * = nullptr
	>
	constexpr modular_base(int_t value) noexcept :
		value_(value_helper<module_info_t, src_module_info_t>().init(value))
	{}
	
	constexpr modular_base(modular_value_t value) noexcept :
		value_(value.value)
	{}
	
	template<
		typename module_info2_t, typename src_module_info2_t,
		typename std::enable_if_t<
			(
				is_md_divides<src_module_info_t, src_module_info2_t>::value &&
				!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, src_t>
			),
			void
		> * = nullptr
	>
	constexpr modular_base(modular_base<module_info2_t, src_module_info2_t> r) noexcept :
		modular_base(static_cast<typename src_module_info2_t::value_type>(r))
	{}
	
	template<
		typename modular_base2_t,
		typename std::enable_if_t<
			!std::is_same_v<modular_base2_t, modular_base> &&
				std::is_same_v<modular_base2_t, src_t>,
			void
		> * = nullptr
	>
	constexpr modular_base(modular_base2_t r) noexcept :
		modular_base(modular_value_t(r.value_))
	{}
	
	template<
		typename module_info2_t, typename src_module_info2_t,
		typename std::enable_if_t<
			!src_module_info2_t::is_const_value, void
		> * = nullptr
	>
	constexpr modular_base(modular_base<module_info2_t, src_module_info2_t> r) noexcept :
		modular_base(static_cast<typename src_module_info2_t::value_type>(r))
	{
		OLYMP_ASSERT_USER(src_module_info2_t::modulus % src_module_info_t::modulus == 0);
	}
	
	template<
		typename int_t,
		typename impl::enable_if_integral_t<int_t> * = nullptr
	>
	[[nodiscard]] explicit constexpr operator int_t() const noexcept
	{
		return value_helper<module_info_t, src_module_info_t>().template convert_to<int_t>(value_);
	}
	
	constexpr modular_base &operator += (modular_base r) noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().plus(value_, r.value_);
		return *this;
	}
	
	constexpr modular_base &operator -= (modular_base r) noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().minus(value_, r.value_);
		return *this;
	}
	
	constexpr modular_base &operator *= (modular_base r) noexcept
	{
		auto mres = value_helper<module_info_t, src_module_info_t>().mult(
			static_cast<src_value_t>(*this),
			static_cast<src_value_t>(r)
		);
		if constexpr (std::is_same_v<module_info_t, src_module_info_t>) {
			mres = fast_mod_helper<
				mult_value_t, module_info_t, src_module_info_t
			>()(mres);
		}
		value_ = mres;
		return *this;
	}
	
	template<typename modular_base2_t>
	inline constexpr std::enable_if_t<
		std::is_same_v<modular_base2_t, modular_base<src_module_info_t, src_module_info_t>>,
		modular_base &
	> operator *= (modular_base2_t r) noexcept
	{
		auto mres = value_helper<module_info_t, src_module_info_t>().mult(
			static_cast<src_value_t>(*this),
			static_cast<src_value_t>(r)
		);
		if constexpr (!std::is_same_v<mult_value_t, value_t>) {
			OLYMP_ASSERT_LIB(false);
		}
		value_ = mres;
		return *this;
	}
	
	constexpr modular_base &operator ++ () noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().plusplus(value_);
		return *this;
	}
	
	constexpr modular_base operator ++ (int) noexcept
	{
		modular_base tmp = *this;
		++*this;
		return tmp;
	}
	
	constexpr modular_base &operator -- () noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().minusminus(value_);
		return *this;
	}
	
	constexpr modular_base operator -- (int) noexcept
	{
		modular_base tmp = *this;
		--*this;
		return tmp;
	}
	
	constexpr modular_base operator - () noexcept
	{
		return modular_base(0) - *this;
	}
	
	[[nodiscard]] inline constexpr friend modular_base operator + (modular_base l, modular_base r) noexcept
	{
		return modular_base(l) += r;
	}

	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator + (modular_base<module_info2_t, src_module_info2_t> l, modular_base r) noexcept
	{
		return modular_base(static_cast<src_value_t>(l)) += r;
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator + (modular_base l, modular_base<module_info2_t, src_module_info2_t> r) noexcept
	{
		return modular_base(l) += static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend modular_base operator - (modular_base l, modular_base r) noexcept
	{
		return modular_base(l) -= r;
	}

	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator - (modular_base<module_info2_t, src_module_info2_t> l, modular_base r) noexcept
	{
		return modular_base(static_cast<src_value_t>(l)) -= r;
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator - (modular_base l, modular_base<module_info2_t, src_module_info2_t> r) noexcept
	{
		return modular_base(l) -= static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend mult_t operator * (modular_base l, modular_base r) noexcept
	{
		if constexpr (std::is_same_v<module_info_t, src_module_info_t>) {
			auto mres = value_helper<typename mult_t::module_info_type, src_module_info_t>().mult(
				static_cast<src_value_t>(l),
				static_cast<src_value_t>(r)
			);
			return mult_t(mres);
		}
		else {
			return mult_t(static_cast<src_value_t>(l)) *= static_cast<src_value_t>(r);
		}
	}
	
	template<typename modular_base_mult_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base_mult_t, modular_base> &&
			std::is_same_v<modular_base_mult_t, mult_t>,
		mult_t
	> operator * (modular_base_mult_t l, modular_base r) noexcept
	{
		return l *= static_cast<src_value_t>(r);
	}
	
	template<typename modular_base_mult_t = mult_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base_mult_t, modular_base> &&
			std::is_same_v<modular_base_mult_t, mult_t>,
		mult_t
	> operator * (modular_base l, modular_base_mult_t r) noexcept
	{
		return r *= static_cast<src_value_t>(l);
	}
	
	[[nodiscard]] inline constexpr friend bool operator == (modular_base l, modular_base r) noexcept
	{
		return static_cast<src_value_t>(l) == static_cast<src_value_t>(r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator == (modular_base<module_info2_t, src_module_info2_t> l, modular_base r) noexcept
	{
		return static_cast<src_value_t>(l) == static_cast<src_value_t>(r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator == (modular_base l, modular_base<module_info2_t, src_module_info2_t> r) noexcept
	{
		return static_cast<src_value_t>(l) == static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend bool operator != (modular_base l, modular_base r) noexcept
	{
		return !(l == r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator != (modular_base<module_info2_t, src_module_info2_t> l, modular_base r) noexcept
	{
		return !(l == r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, modular_base> &&
			std::is_same_v<modular_base<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator != (modular_base l, modular_base<module_info2_t, src_module_info2_t> r) noexcept
	{
		return !(l == r);
	}
	
	template<typename int_t>
	constexpr modular_base &pow_this(int_t k) noexcept
	{
		if constexpr (utils::is_signed_v<int_t>) OLYMP_ASSERT_USER(k >= 0);
		modular_base tmp = *this;
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

#ifdef MODULAR_USE_XOR_POW
	template<typename int_t>
	constexpr modular_base &operator ^= (int_t k) noexcept
	{
		return pow_this(k);
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr modular_base operator ^ (int_t k) const noexcept
	{
		return modular_base(*this) ^= k;
	}
#endif
	
	[[nodiscard]] constexpr value_t load() const noexcept
	{
		return value_;
	}
	
	static constexpr auto get_mod() noexcept
	{
		return get_mod_helper<src_module_info_t>()();
	}
	
	static constexpr auto get_real_mod() noexcept
	{
		return get_mod_helper<module_info_t>()();
	}
	
	template<typename type = module_info_t>
	static constexpr std::enable_if_t<
		std::is_same_v<type, module_info_t> && !type::is_const_value, void
	> init_module(value_t md) noexcept
	{
		type::init_value(md);
	}
	
private:
	using static_checker = modular_base_checker<module_info_t>;
	static_assert(static_checker::value, "static checker failed");

	value_t value_{0};
};

template<typename module_info_t>
struct limits_max_helper {
	using value_type = typename module_info_t::value_type;
	
	constexpr value_type operator () () const noexcept
	{
		return module_info_t::modulus - 1;
	}
};

template<>
struct limits_max_helper<module_const_value_helper<uint32_t, uint32_t, 0>> {
	constexpr uint32_t operator () () const
	{
		return static_cast<uint32_t>(-1);
	}
};

template<>
struct limits_max_helper<module_const_value_helper<uint64_t, uint64_t, 0x100000000>> {
	constexpr uint64_t operator () () const
	{
		return static_cast<uint64_t>(-1);
	}
};

}  // namespace impl
}  // namespace olymp::numeric

namespace olymp::utils {

template<typename module_info_t, typename src_module_info_t>
struct numeric_limits<numeric::impl::modular_base<module_info_t, src_module_info_t>> {
	static constexpr typename module_info_t::value_type min() noexcept { return 0; }
	static constexpr typename module_info_t::value_type lowest() noexcept { return 0; }
	static constexpr typename module_info_t::value_type max() noexcept
	{
		return numeric::impl::limits_max_helper<src_module_info_t>()();
	}
};

}  // namespace olymp::utils

namespace olymp::numeric {
namespace impl {

template<typename module_info_t, typename src_module_info_t>
std::istream &operator >> (std::istream &is, modular_base<module_info_t, src_module_info_t> &r)
{
	typename src_module_info_t::value_type x;
	is >> x;
	r = x;
	return is;
}

template<typename module_info_t, typename src_module_info_t>
std::ostream &operator << (std::ostream &os, modular_base<module_info_t, src_module_info_t> r)
{
	return os << static_cast<typename src_module_info_t::value_type>(r);
}

template<uint64_t user_md>
using modular_base_value_t = std::conditional_t<
	(user_md > 0 && user_md <= static_cast<uint64_t>(utils::numeric_limits<uint32_t>::max()) + 1),
	uint32_t,
	uint64_t
>;

template<typename module_info_t>
struct modular_helper {
	using type = modular_base<module_info_t, module_info_t>;
};

template<uint64_t user_md, typename value_t, typename mult_value_t>
struct module_info_const_helper {
	using type = module_const_value_helper<value_t, mult_value_t, user_md>;
};

template<typename value_t, typename mult_value_t>
struct module_info_const_helper<0, value_t, mult_value_t> {
	using type = module_const_value_helper<value_t, mult_value_t, 0x100000000>;
};

template<typename value_t, typename mult_value_t>
struct module_info_const_helper<0x100000000, value_t, mult_value_t> {
	using type = module_const_value_helper<value_t, mult_value_t, 0>;
};

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
struct module_info_var_helper {
	using type = module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>;
};

}  // namespace impl

template<
	uint64_t m,
	typename value_t = impl::modular_base_value_t<m>,
	typename mult_value_t = impl::mult_value_t<value_t, m>
>
using modular = typename impl::modular_helper<
	typename impl::module_info_const_helper<m, value_t, mult_value_t>::type
>::type;

using modular32 = modular<0x100000000>;
using modular64 = modular<0>;

template<typename tag, typename value_t>
using modular_var_slow = typename impl::modular_helper<
	typename impl::module_info_var_helper<
		tag, value_t, typename impl::mult_value_helper_var<value_t>::type, impl::slow_divider
	>::type
>::type;

}  // namespace olymp::numeric

namespace olymp::utils {

using std::swap;

uint64_t rnd_data = 0xDEADBEEFDULL;
inline void srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int rand(uint32_t n) { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return ((rnd_data >> 17) & 0x7FFFFFFF) % n; }
template <typename T> void random_shuffle(T b, T e) { for (decltype(e - b) i = 1; i < (e - b); ++i) { swap(b[i], b[rand(i + 1)]); } }

}  // namespace olymp::utils

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(std::make_signed_t<std::decay_t<decltype(en)>> i=(st); i<=static_cast<std::make_signed_t<std::decay_t<decltype(en)>>>(en); ++i)
#define Ford(i, st, en) for(std::make_signed_t<std::decay_t<decltype(st)>> i=(st); i>=static_cast<std::make_signed_t<std::decay_t<decltype(st)>>>(en); --i)
#define forn(i, n) for(std::make_signed_t<std::decay_t<decltype(n)>> i=0; i<static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n); ++i)
#define ford(i, n) for(auto i=static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n)-1; i>=0; --i)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef OLYMP_DEBUG
#ifndef OLYMP_PRINT_EXEC_TIME
#define OLYMP_PRINT_EXEC_TIME 1
#endif
#endif

namespace olymp {

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

__attribute__((constructor)) inline void init_main()
{
	init_exec_time();
}

__attribute__((destructor)) inline void fini_main()
{
	print_exec_time();
}

}  // namespace olymp

using olymp::utils::rand;
using olymp::utils::srand;
using olymp::utils::random_shuffle;

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

using namespace olymp;
using namespace std;
using utils::uax;
using utils::uin;

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
using ld = long double;
//using ld = numeric::epsilonized<long double, 9>;
using i64 = int64_t;
using u64 = uint64_t;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

const int MOD = 31607;
using mint = numeric::modular<MOD, uint16_t, uint32_t>;

//int (*a)[sizeof(mint::mult_t)] = 1;

int n;
mint a[21][21];
array<mint, 4> d[3][1 << 21];
mint mlt[MOD];
mint mlt2[MOD][2];

string to_bin(int x)
{
	string res(n + 4, '0');
	forn(i, 1 << (n + 4))
	{
		if (x & (1 << i)) res[i] = '1';
	}
	return res;
}

void precalc(mint p, mint *mlt)
{
	forn(i, MOD)
	{
		mlt[i] = p * i;
	}
}

void precalc2(mint p, mint q, mint mlt2[][2])
{
	forn(i, MOD)
	{
		mlt2[i][0] = p * i;
		mlt2[i][1] = q * i;
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#define BIG 1
#endif
	
	scanf("%d", &n);
#ifdef BIG
	n = 21;
#endif
	forn(i, n)
	{
		forn(j, n)
		{
			int x;
#ifdef BIG
			x = rand() % 9999 + 1;
//			x = 1;
#else
			scanf("%d", &x);
#endif
			a[i][j] = x * mint(10000).pow(MOD - 2);
		}
	}
	
	clr(d);
	d[0][0][0] = 1;
	int km = 1 << n;
//	int total1 = 0, total2 = 0;
	forn(i, n)
	{
		auto &dc = d[0];
		auto &dn = d[1];
		memmove(dn, dc, sizeof(d[0]));
		forn(j, n)
		{
			if (j == i || j == n - i - 1) continue;
			int mm = 1 << j;
			mint qq = a[i][j];
			mint pp = 1 - qq;
			precalc2(pp, qq, mlt2);
//			for (int mask = 0; mask < km; mask = (mask + mm + 1) & ~mm)
			forn(mask, km)
			{
				if (mask & mm) continue;
				int nm = mask | mm;
				forn(j, 4)
				{
//					++total1;
					auto x = uint16_t(dn[mask][j]);
					dn[nm][j] += mlt2[x][0];
					dn[mask][j] = mlt2[x][1];
				}
			}
		}
		auto &dt = d[2];
		forn(j, n)
		{
			if (!(j == i || j == n - i - 1)) continue;
			memset(dt, 0, sizeof(d[0]));
			int mm = 1 << j;
			int m2 = 0;
			if (j == i) m2 |= 1;
			if (j == n - i - 1) m2 |= 2;
			mint qq = a[i][j];
			mint pp = 1 - qq;
			precalc2(pp, qq, mlt2);
			forn(mask, km)
			{
				int nm = mask | mm;
				forn(j, 4)
				{
//					++total2;
					auto x = uint16_t(dn[mask][j]);
					dt[nm][j | m2] += mlt2[x][0];
					dt[mask][j] += mlt2[x][1];
				}
			}
			memmove(dn, dt, sizeof(d[0]));
		}
		mint z = 1;
		forn(j, n)
		{
			z *= a[i][j];
		}
		precalc(z, mlt);
		forn(mask, km)
		{
			forn(j, 4)
			{
				dc[mask][j] = dn[mask][j] - mlt[uint16_t(dc[mask][j])];
			}
//			dc[mask] = dn[mask] - dc[mask] * z;
		}
	}
	mint ans = d[0][km - 1][3];
	
//	cerr << total1 << " " << total2 << "\n";
	ans = 1 - ans;
	printf("%d\n", (int)ans);
	
	return 0;
}