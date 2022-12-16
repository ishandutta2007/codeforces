#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef __int128_t i128;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define _GLIBCXX_BITSET_BITS_PER_WORD  (__CHAR_BIT__ * __SIZEOF_LONG_LONG__)
#define _GLIBCXX_BITSET_WORDS(__n) \
  ((__n) / _GLIBCXX_BITSET_BITS_PER_WORD + \
   ((__n) % _GLIBCXX_BITSET_BITS_PER_WORD == 0 ? 0 : 1))

#define _GLIBCXX_BITSET_BITS_PER_ULL (__CHAR_BIT__ * __SIZEOF_LONG_LONG__)

  /**
   *  Base class, general case.  It is a class invariant that _Nw will be
   *  nonnegative.
   *
   *  See documentation for Bitset.
  */
  template<size_t _Nw>
    struct _Base_Bitset
    {
      typedef unsigned long long _WordT;

      /// 0 is the least significant word.
      _WordT 		_M_w[_Nw];

      _GLIBCXX_CONSTEXPR _Base_Bitset() _GLIBCXX_NOEXCEPT
      : _M_w() { }

#if __cplusplus >= 201103L
      constexpr _Base_Bitset(unsigned long long __val) noexcept
      : _M_w{ _WordT(__val)
#if __SIZEOF_LONG_LONG__ > __SIZEOF_LONG__
	       , _WordT(__val >> _GLIBCXX_BITSET_BITS_PER_WORD)
#endif
       } { }
#else
      _Base_Bitset(unsigned long __val)
      : _M_w()
      { _M_w[0] = __val; }
#endif

      static _GLIBCXX_CONSTEXPR size_t
      _S_whichword(size_t __pos) _GLIBCXX_NOEXCEPT
      { return __pos / _GLIBCXX_BITSET_BITS_PER_WORD; }

      static _GLIBCXX_CONSTEXPR size_t
      _S_whichbyte(size_t __pos) _GLIBCXX_NOEXCEPT
      { return (__pos % _GLIBCXX_BITSET_BITS_PER_WORD) / __CHAR_BIT__; }

      static _GLIBCXX_CONSTEXPR size_t
      _S_whichbit(size_t __pos) _GLIBCXX_NOEXCEPT
      { return __pos % _GLIBCXX_BITSET_BITS_PER_WORD; }

      static _GLIBCXX_CONSTEXPR _WordT
      _S_maskbit(size_t __pos) _GLIBCXX_NOEXCEPT
      { return (static_cast<_WordT>(1)) << _S_whichbit(__pos); }

      _WordT&
      _M_getword(size_t __pos) _GLIBCXX_NOEXCEPT
      { return _M_w[_S_whichword(__pos)]; }

      _GLIBCXX_CONSTEXPR _WordT
      _M_getword(size_t __pos) const _GLIBCXX_NOEXCEPT
      { return _M_w[_S_whichword(__pos)]; }

#if __cplusplus >= 201103L
      const _WordT*
      _M_getdata() const noexcept
      { return _M_w; }
#endif

      _WordT&
      _M_hiword() _GLIBCXX_NOEXCEPT
      { return _M_w[_Nw - 1]; }

      _GLIBCXX_CONSTEXPR _WordT
      _M_hiword() const _GLIBCXX_NOEXCEPT
      { return _M_w[_Nw - 1]; }

      void
      _M_do_and(const _Base_Bitset<_Nw>& __x) _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; __i++)
	  _M_w[__i] &= __x._M_w[__i];
      }

      void
      _M_do_or(const _Base_Bitset<_Nw>& __x) _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; __i++)
	  _M_w[__i] |= __x._M_w[__i];
      }

      void
      _M_do_xor(const _Base_Bitset<_Nw>& __x) _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; __i++)
	  _M_w[__i] ^= __x._M_w[__i];
      }

      void
      _M_do_left_shift(size_t __shift) _GLIBCXX_NOEXCEPT;

      void
      _M_do_right_shift(size_t __shift) _GLIBCXX_NOEXCEPT;

      void
      _M_do_flip() _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; __i++)
	  _M_w[__i] = ~_M_w[__i];
      }

      void
      _M_do_set() _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; __i++)
	  _M_w[__i] = ~static_cast<_WordT>(0);
      }

      void
      _M_do_reset() _GLIBCXX_NOEXCEPT
      { __builtin_memset(_M_w, 0, _Nw * sizeof(_WordT)); }

      bool
      _M_is_equal(const _Base_Bitset<_Nw>& __x) const _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; ++__i)
	  if (_M_w[__i] != __x._M_w[__i])
	    return false;
	return true;
      }

      template<size_t _Nb>
        bool
        _M_are_all() const _GLIBCXX_NOEXCEPT
        {
	  for (size_t __i = 0; __i < _Nw - 1; __i++)
	    if (_M_w[__i] != ~static_cast<_WordT>(0))
	      return false;
	  return _M_hiword() == (~static_cast<_WordT>(0)
				 >> (_Nw * _GLIBCXX_BITSET_BITS_PER_WORD
				     - _Nb));
	}

      bool
      _M_is_any() const _GLIBCXX_NOEXCEPT
      {
	for (size_t __i = 0; __i < _Nw; __i++)
	  if (_M_w[__i] != static_cast<_WordT>(0))
	    return true;
	return false;
      }

      size_t
      _M_do_count() const _GLIBCXX_NOEXCEPT
      {
	size_t __result = 0;
	for (size_t __i = 0; __i < _Nw; __i++)
	  __result += __builtin_popcountl(_M_w[__i]);
	return __result;
      }

      unsigned long
      _M_do_to_ulong() const;

#if __cplusplus >= 201103L
      unsigned long long
      _M_do_to_ullong() const;
#endif

      // find first "on" bit
      size_t
      _M_do_find_first(size_t) const _GLIBCXX_NOEXCEPT;

      // find the next "on" bit that follows "prev"
      size_t
      _M_do_find_next(size_t, size_t) const _GLIBCXX_NOEXCEPT;
    };

  // Definitions of non-inline functions from _Base_Bitset.
  template<size_t _Nw>
    void
    _Base_Bitset<_Nw>::_M_do_left_shift(size_t __shift) _GLIBCXX_NOEXCEPT
    {
      if (__builtin_expect(__shift != 0, 1))
	{
	  const size_t __wshift = __shift / _GLIBCXX_BITSET_BITS_PER_WORD;
	  const size_t __offset = __shift % _GLIBCXX_BITSET_BITS_PER_WORD;

	  if (__offset == 0)
	    for (size_t __n = _Nw - 1; __n >= __wshift; --__n)
	      _M_w[__n] = _M_w[__n - __wshift];
	  else
	    {
	      const size_t __sub_offset = (_GLIBCXX_BITSET_BITS_PER_WORD
					   - __offset);
	      for (size_t __n = _Nw - 1; __n > __wshift; --__n)
		_M_w[__n] = ((_M_w[__n - __wshift] << __offset)
			     | (_M_w[__n - __wshift - 1] >> __sub_offset));
	      _M_w[__wshift] = _M_w[0] << __offset;
	    }

	  std::fill(_M_w + 0, _M_w + __wshift, static_cast<_WordT>(0));
	}
    }

  template<size_t _Nw>
    void
    _Base_Bitset<_Nw>::_M_do_right_shift(size_t __shift) _GLIBCXX_NOEXCEPT
    {
      if (__builtin_expect(__shift != 0, 1))
	{
	  const size_t __wshift = __shift / _GLIBCXX_BITSET_BITS_PER_WORD;
	  const size_t __offset = __shift % _GLIBCXX_BITSET_BITS_PER_WORD;
	  const size_t __limit = _Nw - __wshift - 1;

	  if (__offset == 0)
	    for (size_t __n = 0; __n <= __limit; ++__n)
	      _M_w[__n] = _M_w[__n + __wshift];
	  else
	    {
	      const size_t __sub_offset = (_GLIBCXX_BITSET_BITS_PER_WORD
					   - __offset);
	      for (size_t __n = 0; __n < __limit; ++__n)
		_M_w[__n] = ((_M_w[__n + __wshift] >> __offset)
			     | (_M_w[__n + __wshift + 1] << __sub_offset));
	      _M_w[__limit] = _M_w[_Nw-1] >> __offset;
	    }

	  std::fill(_M_w + __limit + 1, _M_w + _Nw, static_cast<_WordT>(0));
	}
    }

  template<size_t _Nw>
    unsigned long
    _Base_Bitset<_Nw>::_M_do_to_ulong() const
    {
      for (size_t __i = 1; __i < _Nw; ++__i)
	if (_M_w[__i])
	  __throw_overflow_error(__N("_Base_Bitset::_M_do_to_ulong"));
      return _M_w[0];
    }

#if __cplusplus >= 201103L
  template<size_t _Nw>
    unsigned long long
    _Base_Bitset<_Nw>::_M_do_to_ullong() const
    {
      const bool __dw = sizeof(unsigned long long) > sizeof(unsigned long);
      for (size_t __i = 1 + __dw; __i < _Nw; ++__i)
	if (_M_w[__i])
	  __throw_overflow_error(__N("_Base_Bitset::_M_do_to_ullong"));

      if (__dw)
	return _M_w[0] + (static_cast<unsigned long long>(_M_w[1])
			  << _GLIBCXX_BITSET_BITS_PER_WORD);
      return _M_w[0];
    }
#endif

  template<size_t _Nw>
    size_t
    _Base_Bitset<_Nw>::
    _M_do_find_first(size_t __not_found) const _GLIBCXX_NOEXCEPT
    {
      for (size_t __i = 0; __i < _Nw; __i++)
	{
	  _WordT __thisword = _M_w[__i];
	  if (__thisword != static_cast<_WordT>(0))
	    return (__i * _GLIBCXX_BITSET_BITS_PER_WORD
		    + __builtin_ctzl(__thisword));
	}
      // not found, so return an indication of failure.
      return __not_found;
    }

  template<size_t _Nw>
    size_t
    _Base_Bitset<_Nw>::
    _M_do_find_next(size_t __prev, size_t __not_found) const _GLIBCXX_NOEXCEPT
    {
      // make bound inclusive
      ++__prev;

      // check out of bounds
      if (__prev >= _Nw * _GLIBCXX_BITSET_BITS_PER_WORD)
	return __not_found;

      // search first word
      size_t __i = _S_whichword(__prev);
      _WordT __thisword = _M_w[__i];

      // mask off bits below bound
      __thisword &= (~static_cast<_WordT>(0)) << _S_whichbit(__prev);

      if (__thisword != static_cast<_WordT>(0))
	return (__i * _GLIBCXX_BITSET_BITS_PER_WORD
		+ __builtin_ctzl(__thisword));

      // check subsequent words
      __i++;
      for (; __i < _Nw; __i++)
	{
	  __thisword = _M_w[__i];
	  if (__thisword != static_cast<_WordT>(0))
	    return (__i * _GLIBCXX_BITSET_BITS_PER_WORD
		    + __builtin_ctzl(__thisword));
	}
      // not found, so return an indication of failure.
      return __not_found;
    } // end _M_do_find_next
template<size_t _Nb>
    class Bitset
    : public _Base_Bitset<_GLIBCXX_BITSET_WORDS(_Nb)>
    {
    public:
      typedef _Base_Bitset<_GLIBCXX_BITSET_WORDS(_Nb)> _Base;
      typedef unsigned long long _WordT;

      template<class _CharT, class _Traits, class _Alloc>
      void
      _M_check_initial_position(const std::basic_string<_CharT, _Traits, _Alloc>& __s,
                size_t __position) const
      {
    if (__position > __s.size())
      __throw_out_of_range_fmt(__N("Bitset::Bitset: __position "
                       "(which is %zu) > __s.size() "
                       "(which is %zu)"),
                   __position, __s.size());
      }

      void _M_check(size_t __position, const char *__s) const
      {
    if (__position >= _Nb)
      __throw_out_of_range_fmt(__N("%s: __position (which is %zu) "
                       ">= _Nb (which is %zu)"),
                   __s, __position, _Nb);
      }

      friend struct std::hash<Bitset>;

    public:
      class reference
      {
    friend class Bitset;

    _WordT* _M_wp;
    size_t  _M_bpos;

    // left undefined
    reference();

      public:
    reference(Bitset& __b, size_t __pos) _GLIBCXX_NOEXCEPT
    {
      _M_wp = &__b._M_getword(__pos);
      _M_bpos = _Base::_S_whichbit(__pos);
    }

#if __cplusplus >= 201103L
    reference(const reference&) = default;
#endif

    ~reference() _GLIBCXX_NOEXCEPT
    { }

    // For b[i] = __x;
    reference&
    operator=(bool __x) _GLIBCXX_NOEXCEPT
    {
      if (__x)
        *_M_wp |= _Base::_S_maskbit(_M_bpos);
      else
        *_M_wp &= ~_Base::_S_maskbit(_M_bpos);
      return *this;
    }

    // For b[i] = b[__j];
    reference&
    operator=(const reference& __j) _GLIBCXX_NOEXCEPT
    {
      if ((*(__j._M_wp) & _Base::_S_maskbit(__j._M_bpos)))
        *_M_wp |= _Base::_S_maskbit(_M_bpos);
      else
        *_M_wp &= ~_Base::_S_maskbit(_M_bpos);
      return *this;
    }

    // Flips the bit
    bool
    operator~() const _GLIBCXX_NOEXCEPT
    { return (*(_M_wp) & _Base::_S_maskbit(_M_bpos)) == 0; }

    // For __x = b[i];
    operator bool() const _GLIBCXX_NOEXCEPT
    { return (*(_M_wp) & _Base::_S_maskbit(_M_bpos)) != 0; }

    // For b[i].flip();
    reference&
    flip() _GLIBCXX_NOEXCEPT
    {
      *_M_wp ^= _Base::_S_maskbit(_M_bpos);
      return *this;
    }
      };
      friend class reference;

      // 23.3.5.1 constructors:
      /// All bits set to zero.
      _GLIBCXX_CONSTEXPR Bitset() _GLIBCXX_NOEXCEPT
      { }

      /// Initial bits bitwise-copied from a single word (others set to zero).
#if __cplusplus >= 201103L
      constexpr Bitset(unsigned long long __val) noexcept
      : _Base(_Sanitize_val<_Nb>::_S_do_sanitize_val(__val)) { }
#else
      Bitset(unsigned long __val)
      : _Base(__val)
      { _M_do_sanitize(); }
#endif

      /**
       *  Use a subset of a string.
       *  @param  __s  A string of @a 0 and @a 1 characters.
       *  @param  __position  Index of the first character in @a __s to use;
       *                    defaults to zero.
       *  @throw  std::out_of_range  If @a pos is bigger the size of @a __s.
       *  @throw  std::invalid_argument  If a character appears in the string
       *                                 which is neither @a 0 nor @a 1.
       */
      template<class _CharT, class _Traits, class _Alloc>
    explicit
    Bitset(const std::basic_string<_CharT, _Traits, _Alloc>& __s,
           size_t __position = 0)
    : _Base()
    {
      _M_check_initial_position(__s, __position);
      _M_copy_from_string(__s, __position,
                  std::basic_string<_CharT, _Traits, _Alloc>::npos,
                  _CharT('0'), _CharT('1'));
    }

      /**
       *  Use a subset of a string.
       *  @param  __s  A string of @a 0 and @a 1 characters.
       *  @param  __position  Index of the first character in @a __s to use.
       *  @param  __n    The number of characters to copy.
       *  @throw std::out_of_range If @a __position is bigger the size
       *  of @a __s.
       *  @throw  std::invalid_argument  If a character appears in the string
       *                                 which is neither @a 0 nor @a 1.
       */
      template<class _CharT, class _Traits, class _Alloc>
    Bitset(const std::basic_string<_CharT, _Traits, _Alloc>& __s,
           size_t __position, size_t __n)
    : _Base()
    {
      _M_check_initial_position(__s, __position);
      _M_copy_from_string(__s, __position, __n, _CharT('0'), _CharT('1'));
    }

      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 396. what are characters zero and one.
      template<class _CharT, class _Traits, class _Alloc>
    Bitset(const std::basic_string<_CharT, _Traits, _Alloc>& __s,
           size_t __position, size_t __n,
           _CharT __zero, _CharT __one = _CharT('1'))
    : _Base()
    {
      _M_check_initial_position(__s, __position);
      _M_copy_from_string(__s, __position, __n, __zero, __one);
    }

      // 23.3.5.2 Bitset operations:
      ///@{
      /**
       *  Operations on Bitsets.
       *  @param  __rhs  A same-sized Bitset.
       *
       *  These should be self-explanatory.
       */
      Bitset<_Nb>&
      operator&=(const Bitset<_Nb>& __rhs) _GLIBCXX_NOEXCEPT
      {
    this->_M_do_and(__rhs);
    return *this;
      }

      Bitset<_Nb>&
      operator|=(const Bitset<_Nb>& __rhs) _GLIBCXX_NOEXCEPT
      {
    this->_M_do_or(__rhs);
    return *this;
      }

      Bitset<_Nb>&
      operator^=(const Bitset<_Nb>& __rhs) _GLIBCXX_NOEXCEPT
      {
    this->_M_do_xor(__rhs);
    return *this;
      }
      ///@}

      ///@{
      /**
       *  Operations on Bitsets.
       *  @param  __position  The number of places to shift.
       *
       *  These should be self-explanatory.
       */
      Bitset<_Nb>&
      operator<<=(size_t __position) _GLIBCXX_NOEXCEPT
      {
    if (__builtin_expect(__position < _Nb, 1))
      {
        this->_M_do_left_shift(__position);
        this->_M_do_sanitize();
      }
    else
      this->_M_do_reset();
    return *this;
      }

      Bitset<_Nb>&
      operator>>=(size_t __position) _GLIBCXX_NOEXCEPT
      {
    if (__builtin_expect(__position < _Nb, 1))
      {
        this->_M_do_right_shift(__position);
        this->_M_do_sanitize();
      }
    else
      this->_M_do_reset();
    return *this;
      }
      ///@}

      ///@{
      /**
       *  These versions of single-bit set, reset, flip, and test are
       *  extensions from the SGI version.  They do no range checking.
       *  @ingroup SGIextensions
       */
      Bitset<_Nb>&
      _Unchecked_set(size_t __pos) _GLIBCXX_NOEXCEPT
      {
    this->_M_getword(__pos) |= _Base::_S_maskbit(__pos);
    return *this;
      }

      Bitset<_Nb>&
      _Unchecked_set(size_t __pos, int __val) _GLIBCXX_NOEXCEPT
      {
    if (__val)
      this->_M_getword(__pos) |= _Base::_S_maskbit(__pos);
    else
      this->_M_getword(__pos) &= ~_Base::_S_maskbit(__pos);
    return *this;
      }

      Bitset<_Nb>&
      _Unchecked_reset(size_t __pos) _GLIBCXX_NOEXCEPT
      {
    this->_M_getword(__pos) &= ~_Base::_S_maskbit(__pos);
    return *this;
      }

      Bitset<_Nb>&
      _Unchecked_flip(size_t __pos) _GLIBCXX_NOEXCEPT
      {
    this->_M_getword(__pos) ^= _Base::_S_maskbit(__pos);
    return *this;
      }

      _GLIBCXX_CONSTEXPR bool
      _Unchecked_test(size_t __pos) const _GLIBCXX_NOEXCEPT
      { return ((this->_M_getword(__pos) & _Base::_S_maskbit(__pos))
        != static_cast<_WordT>(0)); }
      ///@}

      // Set, reset, and flip.
      /**
       *  @brief Sets every bit to true.
       */
      Bitset<_Nb>&
      set() _GLIBCXX_NOEXCEPT
      {
    this->_M_do_set();
    return *this;
      }

      /**
       *  @brief Sets a given bit to a particular value.
       *  @param  __position  The index of the bit.
       *  @param  __val  Either true or false, defaults to true.
       *  @throw  std::out_of_range  If @a pos is bigger the size of the %set.
       */
      Bitset<_Nb>&
      set(size_t __position, bool __val = true)
      {
    this->_M_check(__position, __N("Bitset::set"));
    return _Unchecked_set(__position, __val);
      }

      /**
       *  @brief Sets every bit to false.
       */
      Bitset<_Nb>&
      reset() _GLIBCXX_NOEXCEPT
      {
    this->_M_do_reset();
    return *this;
      }

      /**
       *  @brief Sets a given bit to false.
       *  @param  __position  The index of the bit.
       *  @throw  std::out_of_range  If @a pos is bigger the size of the %set.
       *
       *  Same as writing @c set(pos,false).
       */
      Bitset<_Nb>&
      reset(size_t __position)
      {
    this->_M_check(__position, __N("Bitset::reset"));
    return _Unchecked_reset(__position);
      }

      /**
       *  @brief Toggles every bit to its opposite value.
       */
      Bitset<_Nb>&
      flip() _GLIBCXX_NOEXCEPT
      {
    this->_M_do_flip();
    return *this;
      }

      /**
       *  @brief Toggles a given bit to its opposite value.
       *  @param  __position  The index of the bit.
       *  @throw  std::out_of_range  If @a pos is bigger the size of the %set.
       */
      Bitset<_Nb>&
      flip(size_t __position)
      {
    this->_M_check(__position, __N("Bitset::flip"));
    return _Unchecked_flip(__position);
      }

      /// See the no-argument flip().
      Bitset<_Nb>
      operator~() const _GLIBCXX_NOEXCEPT
      { return Bitset<_Nb>(*this).flip(); }

      ///@{
      /**
       *  @brief  Array-indexing support.
       *  @param  __position  Index into the %Bitset.
       *  @return A bool for a <em>const %Bitset</em>.  For non-const
       *           Bitsets, an instance of the reference proxy class.
       *  @note  These operators do no range checking and throw no exceptions,
       *         as required by DR 11 to the standard.
       *
       *  _GLIBCXX_RESOLVE_LIB_DEFECTS Note that this implementation already
       *  resolves DR 11 (items 1 and 2), but does not do the range-checking
       *  required by that DR's resolution.  -pme
       *  The DR has since been changed:  range-checking is a precondition
       *  (users' responsibility), and these functions must not throw.  -pme
       */
      reference
      operator[](size_t __position)
      { return reference(*this, __position); }

      _GLIBCXX_CONSTEXPR bool
      operator[](size_t __position) const
      { return _Unchecked_test(__position); }
      ///@}

      /// Returns the number of bits which are set.
      size_t
      count() const _GLIBCXX_NOEXCEPT
      { return this->_M_do_count(); }

      /// Returns the total number of bits.
      _GLIBCXX_CONSTEXPR size_t
      size() const _GLIBCXX_NOEXCEPT
      { return _Nb; }

      ///@{
      /// These comparisons for equality/inequality are, well, @e bitwise.
      bool
      operator==(const Bitset<_Nb>& __rhs) const _GLIBCXX_NOEXCEPT
      { return this->_M_is_equal(__rhs); }

#if __cpp_impl_three_way_comparison < 201907L
      bool
      operator!=(const Bitset<_Nb>& __rhs) const _GLIBCXX_NOEXCEPT
      { return !this->_M_is_equal(__rhs); }
#endif
      ///@}

      /**
       *  @brief Tests the value of a bit.
       *  @param  __position  The index of a bit.
       *  @return  The value at @a pos.
       *  @throw  std::out_of_range  If @a pos is bigger the size of the %set.
       */
      bool
      test(size_t __position) const
      {
    this->_M_check(__position, __N("Bitset::test"));
    return _Unchecked_test(__position);
      }

      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // DR 693. std::Bitset::all() missing.
      /**
       *  @brief Tests whether all the bits are on.
       *  @return  True if all the bits are set.
       */
      bool
      all() const _GLIBCXX_NOEXCEPT
      { return this->template _M_are_all<_Nb>(); }

      /**
       *  @brief Tests whether any of the bits are on.
       *  @return  True if at least one bit is set.
       */
      bool
      any() const _GLIBCXX_NOEXCEPT
      { return this->_M_is_any(); }

      /**
       *  @brief Tests whether any of the bits are on.
       *  @return  True if none of the bits are set.
       */
      bool
      none() const _GLIBCXX_NOEXCEPT
      { return !this->_M_is_any(); }

      ///@{
      /// Self-explanatory.
      Bitset<_Nb>
      operator<<(size_t __position) const _GLIBCXX_NOEXCEPT
      { return Bitset<_Nb>(*this) <<= __position; }

      Bitset<_Nb>
      operator>>(size_t __position) const _GLIBCXX_NOEXCEPT
      { return Bitset<_Nb>(*this) >>= __position; }
      ///@}

      /**
       *  @brief  Finds the index of the first "on" bit.
       *  @return  The index of the first bit set, or size() if not found.
       *  @ingroup SGIextensions
       *  @sa  _Find_next
       */
      size_t
      _Find_first() const _GLIBCXX_NOEXCEPT
      { return this->_M_do_find_first(_Nb); }

      /**
       *  @brief  Finds the index of the next "on" bit after prev.
       *  @return  The index of the next bit set, or size() if not found.
       *  @param  __prev  Where to start searching.
       *  @ingroup SGIextensions
       *  @sa  _Find_first
       */
      size_t
      _Find_next(size_t __prev) const _GLIBCXX_NOEXCEPT
      { return this->_M_do_find_next(__prev, _Nb); }
    };

  // 23.3.5.3 Bitset operations:
  ///@{
  /**
   *  @brief  Global bitwise operations on Bitsets.
   *  @param  __x  A Bitset.
   *  @param  __y  A Bitset of the same size as @a __x.
   *  @return  A new Bitset.
   *
   *  These should be self-explanatory.
  */
  template<size_t _Nb>
    inline Bitset<_Nb>
    operator&(const Bitset<_Nb>& __x, const Bitset<_Nb>& __y) _GLIBCXX_NOEXCEPT
    {
      Bitset<_Nb> __result(__x);
      __result &= __y;
      return __result;
    }

  template<size_t _Nb>
    inline Bitset<_Nb>
    operator|(const Bitset<_Nb>& __x, const Bitset<_Nb>& __y) _GLIBCXX_NOEXCEPT
    {
      Bitset<_Nb> __result(__x);
      __result |= __y;
      return __result;
    }

  template <size_t _Nb>
    inline Bitset<_Nb>
    operator^(const Bitset<_Nb>& __x, const Bitset<_Nb>& __y) _GLIBCXX_NOEXCEPT
    {
      Bitset<_Nb> __result(__x);
      __result ^= __y;
      return __result;
    }
  ///@}

const int N=100010,M=23056,P=2410;
const int S=528,PSS=8,PS=100,B=8;

int n,m,C,q,a[N];

int p[N],pcnt,v[N],mu[N];
Bitset<P> bs[N],d[N];
void init(int n){
    v[1]=mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i]){
            v[i]=i,p[++pcnt]=i,mu[i]=-1;
            if(pcnt<P) bs[i][pcnt]=1;
        }
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>n/i) break;
            v[p[j]*i]=p[j],bs[p[j]*i]=bs[i];
            if(j<P) bs[p[j]*i][j]=1;
            mu[p[j]*i]=(i%p[j]?-mu[i]:0);
        }
    }
}

pii qu[N];
void calc(int l,int r,const vi &q){
    if(l>r||q.empty()) return;
    static Bitset<P> pre[N/2],suf[N/2];int mid=(l+r)/2;
    pre[0]=bs[a[mid]];
    for(int i=mid-1;i>=l;i--) pre[mid-i]=bs[a[i]]|pre[mid-i-1];
    suf[0]=bs[a[mid]];
    for(int i=mid+1;i<=r;i++) suf[i-mid]=suf[i-mid-1]|bs[a[i]];
    vi q1,q2;
    for(auto id:q){
        if(qu[id].se<mid) q1.pb(id);
        else if(qu[id].fi>mid) q2.pb(id);
        else d[id]=pre[mid-qu[id].fi]|suf[qu[id].se-mid];
    }
    calc(l,mid-1,q1),calc(mid+1,r,q2);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(N-1);
    n=rdi(),m=rdi(),C=rdi(),q=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=q;i++) qu[i].fi=rdi(),qu[i].se=rdi();
    vi qid(q);iota(qid.begin(),qid.end(),1);calc(1,n,qid);
    static int val[N],tot;
    static Bitset<M> pr[PS];
    for(int i=2;i<=C;i++){
        if(!mu[i]) continue;
        int x=i;while(x!=v[x]) x/=v[x];
        if(x<S){
            val[++tot]=mu[i]*(C/i);
            for(int j=1;p[j]<S;j++) 
                if(bs[i][j]) pr[j][tot]=1;
        }
    }
    
    static int quo[N];
    for(int i=1;i<=pcnt;i++) quo[i]=C/p[i];

    static int cnt[S][(1<<PSS)+1],sum[S],s1[(M/B)+1][(1<<B)+1];
    for(int i=1;i<S;i++){
        int s=0;
        for(int j=1;j<=PSS;j++) if(i%p[j]==0) s|=(1<<(j-1));
        for(int j=0;j<(1<<PSS);j++) cnt[i][j]=cnt[i-1][j]+((j&s)>0);
        sum[i]=sum[i-1]+(i>1&&v[i]==i);
    }
    for(int i=0;i<tot/B+2;i++){
        s1[i][0]=0;
        for(int s=1;s<(1<<B);s++)
            s1[i][s]=s1[i][s&(s-1)]+val[__builtin_ctz(s)+i*B];
    }

    auto calc = [&](int C,i128 stat){
        int low=(stat&(1<<PSS)-1);
        int ret=C-cnt[C][low];
        for(int l=23,r;l<=C;l=r+1){
            int v=C/l;r=C/v;
            int pl=sum[l-1]+1,pr=sum[r];
            ret-=__builtin_popcountll(stat>>(pl-1)&(1ll<<(pr-pl+1))-1)*(v-cnt[v][low]);
        }
        return ret;
    };

    for(int i=1;p[i]<S;i++) pr[i]=~pr[i];
    for(int i=1;i<=q;i++){
        static Bitset<M> pos;pos.set();
        for(int j=1;p[j]<S;j++) 
            if(!d[i][j]) pos&=pr[j];
        int res=C;
        /*for(int j=1;j<=tot;j++)
            if(pos[j]) res+=val[j];*/
        static const int USIZ=sizeof(unsigned long long)*__CHAR_BIT__;
        for(int j=0,id=0;j<=(tot+1)/USIZ;j++){
            auto nw=pos._M_w[j];
            for(int k=0;k<USIZ/B;k++,id++)
                res+=s1[id][nw&(1<<B)-1],nw>>=B;
        }
        i128 stat=0;
        for(int j=1;j<=PS;j++) stat|=(i128)d[i][j]<<(j-1);
        for(int j=1,v,lst=-1,lstv=0;p[j]<=min(C,m);j++){
            if(p[j]<S||!d[i][j]) continue;
            v=quo[j],res-=(v==lst?lstv:lstv=calc(v,stat)),lst=v;
        }
        cout<<res<<'\n';
    }
    return 0;
}