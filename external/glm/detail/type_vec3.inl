/// @ref core
/// @file glm/detail/type_tvec3.inl

namespace glm
{
	// -- Implicit basic constructors --

#	if !GLM_HAS_DEFAULTED_FUNCTIONS || !defined(GLM_FORCE_NO_CTOR_INIT)
		template<typename T, precision P>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec()
#			ifndef GLM_FORCE_NO_CTOR_INIT 
				: x(0), y(0), z(0)
#			endif
		{}
#	endif//!GLM_HAS_DEFAULTED_FUNCTIONS

#	if !GLM_HAS_DEFAULTED_FUNCTIONS
		template<typename T, precision P>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<3, T, P> const & v)
			: x(v.x), y(v.y), z(v.z)
		{}
#	endif//!GLM_HAS_DEFAULTED_FUNCTIONS

	template<typename T, precision P>
	template<precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<3, T, Q> const & v)
		: x(v.x), y(v.y), z(v.z)
	{}

	// -- Explicit basic constructors --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_CTOR vec<3, T, P>::vec(ctor)
	{}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar)
	{}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(T a, T b, T c)
		: x(a), y(b), z(c)
	{}

	// -- Conversion scalar constructors --

	template<typename T, precision P>
	template<typename A, typename B, typename C>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(A a, B b, C c) :
		x(static_cast<T>(a)),
		y(static_cast<T>(b)),
		z(static_cast<T>(c))
	{}

	template<typename T, precision P>
	template<typename A, typename B, typename C>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<1, A, P> const & a, vec<1, B, P> const & b, vec<1, C, P> const & c) :
		x(static_cast<T>(a)),
		y(static_cast<T>(b)),
		z(static_cast<T>(c))
	{}

	// -- Conversion vector constructors --

	template<typename T, precision P>
	template<typename A, typename B, precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<2, A, Q> const & a, B b) :
		x(static_cast<T>(a.x)),
		y(static_cast<T>(a.y)),
		z(static_cast<T>(b))
	{}

	template<typename T, precision P>
	template<typename A, typename B, precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<2, A, Q> const & a, vec<1, B, Q> const & b) :
		x(static_cast<T>(a.x)),
		y(static_cast<T>(a.y)),
		z(static_cast<T>(b.x))
	{}

	template<typename T, precision P>
	template<typename A, typename B, precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(A a, vec<2, B, Q> const & b) :
		x(static_cast<T>(a)),
		y(static_cast<T>(b.x)),
		z(static_cast<T>(b.y))
	{}

	template<typename T, precision P>
	template<typename A, typename B, precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<1, A, Q> const & a, vec<2, B, Q> const & b) :
		x(static_cast<T>(a.x)),
		y(static_cast<T>(b.x)),
		z(static_cast<T>(b.y))
	{}

	template<typename T, precision P>
	template<typename U, precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<3, U, Q> const & v) :
		x(static_cast<T>(v.x)),
		y(static_cast<T>(v.y)),
		z(static_cast<T>(v.z))
	{}

	template<typename T, precision P>
	template<typename U, precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, P>::vec(vec<4, U, Q> const & v) :
		x(static_cast<T>(v.x)),
		y(static_cast<T>(v.y)),
		z(static_cast<T>(v.z))
	{}

	// -- Component accesses --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER T & vec<3, T, P>::operator[](typename vec<3, T, P>::length_type i)
	{
		assert(i >= 0 && i < this->length());
		return (&x)[i];
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER T const & vec<3, T, P>::operator[](typename vec<3, T, P>::length_type i) const
	{
		assert(i >= 0 && i < this->length());
		return (&x)[i];
	}

	// -- Unary arithmetic operators --

#	if !GLM_HAS_DEFAULTED_FUNCTIONS
		template<typename T, precision P>
		GLM_FUNC_QUALIFIER vec<3, T, P>& vec<3, T, P>::operator=(vec<3, T, P> const & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}
#	endif//!GLM_HAS_DEFAULTED_FUNCTIONS

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P>& vec<3, T, P>::operator=(vec<3, U, P> const & v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator+=(vec<1, U, P> const & v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.x);
		this->z += static_cast<T>(v.x);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator+=(vec<3, U, P> const & v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator-=(vec<1, U, P> const & v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.x);
		this->z -= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator-=(vec<3, U, P> const & v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator*=(vec<1, U, P> const & v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.x);
		this->z *= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator*=(vec<3, U, P> const & v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator/=(U v)
	{
		this->x /= static_cast<T>(v);
		this->y /= static_cast<T>(v);
		this->z /= static_cast<T>(v);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator/=(vec<1, U, P> const & v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.x);
		this->z /= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator/=(vec<3, U, P> const & v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		return *this;
	}

	// -- Increment and decrement operators --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template<typename T, precision P> 
	GLM_FUNC_QUALIFIER vec<3, T, P> vec<3, T, P>::operator++(int)
	{
		vec<3, T, P> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, precision P> 
	GLM_FUNC_QUALIFIER vec<3, T, P> vec<3, T, P>::operator--(int)
	{
		vec<3, T, P> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary bit operators --

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator%=(U scalar)
	{
		this->x %= scalar;
		this->y %= scalar;
		this->z %= scalar;
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator%=(vec<1, U, P> const & v)
	{
		this->x %= v.x;
		this->y %= v.x;
		this->z %= v.x;
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator%=(vec<3, U, P> const & v)
	{
		this->x %= v.x;
		this->y %= v.y;
		this->z %= v.z;
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator&=(U scalar)
	{
		this->x &= scalar;
		this->y &= scalar;
		this->z &= scalar;
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator&=(vec<1, U, P> const & v)
	{
		this->x &= v.x;
		this->y &= v.x;
		this->z &= v.x;
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator&=(vec<3, U, P> const & v)
	{
		this->x &= v.x;
		this->y &= v.y;
		this->z &= v.z;
		return *this;
	}

	template<typename T, precision P>
	template<typename U>
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator|=(U scalar)
	{
		this->x |= scalar;
		this->y |= scalar;
		this->z |= scalar;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator|=(vec<1, U, P> const & v)
	{
		this->x |= v.x;
		this->y |= v.x;
		this->z |= v.x;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator|=(vec<3, U, P> const & v)
	{
		this->x |= v.x;
		this->y |= v.y;
		this->z |= v.z;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator^=(U scalar)
	{
		this->x ^= scalar;
		this->y ^= scalar;
		this->z ^= scalar;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator^=(vec<1, U, P> const & v)
	{
		this->x ^= v.x;
		this->y ^= v.x;
		this->z ^= v.x;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator^=(vec<3, U, P> const & v)
	{
		this->x ^= v.x;
		this->y ^= v.y;
		this->z ^= v.z;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator<<=(U scalar)
	{
		this->x <<= scalar;
		this->y <<= scalar;
		this->z <<= scalar;
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator<<=(vec<1, U, P> const & v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.x);
		this->z <<= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator<<=(vec<3, U, P> const & v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator>>=(vec<1, U, P> const & v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.x);
		this->z >>= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, precision P>
	template<typename U> 
	GLM_FUNC_QUALIFIER vec<3, T, P> & vec<3, T, P>::operator>>=(vec<3, U, P> const & v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		return *this;
	}

	// -- Unary arithmetic operators --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator+(vec<3, T, P> const & v)
	{
		return v;
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator-(vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			-v.x, 
			-v.y, 
			-v.z);
	}

	// -- Binary arithmetic operators --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator+(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator+(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x + scalar.x,
			v.y + scalar.x,
			v.z + scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator+(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator+(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x + v.x,
			scalar.x + v.y,
			scalar.x + v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator+(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator-(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator-(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x - scalar.x,
			v.y - scalar.x,
			v.z - scalar.x);
	}

	template<typename T, precision P> 
	GLM_FUNC_QUALIFIER vec<3, T, P> operator-(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z);
	}

	template<typename T, precision P> 
	GLM_FUNC_QUALIFIER vec<3, T, P> operator-(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x - v.x,
			scalar.x - v.y,
			scalar.x - v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator-(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator*(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator*(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x * scalar.x,
			v.y * scalar.x,
			v.z * scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator*(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator*(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x * v.x,
			scalar.x * v.y,
			scalar.x * v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator*(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator/(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator/(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x / scalar.x,
			v.y / scalar.x,
			v.z / scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator/(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator/(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x / v.x,
			scalar.x / v.y,
			scalar.x / v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator/(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z);
	}

	// -- Binary bit operators --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator%(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x % scalar,
			v.y % scalar,
			v.z % scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator%(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x % scalar.x,
			v.y % scalar.x,
			v.z % scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator%(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar % v.x,
			scalar % v.y,
			scalar % v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator%(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x % v.x,
			scalar.x % v.y,
			scalar.x % v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator%(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x % v2.x,
			v1.y % v2.y,
			v1.z % v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator&(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x & scalar,
			v.y & scalar,
			v.z & scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator&(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x & scalar.x,
			v.y & scalar.x,
			v.z & scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator&(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar & v.x,
			scalar & v.y,
			scalar & v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator&(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x & v.x,
			scalar.x & v.y,
			scalar.x & v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator&(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x & v2.x,
			v1.y & v2.y,
			v1.z & v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator|(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x | scalar,
			v.y | scalar,
			v.z | scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator|(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x | scalar.x,
			v.y | scalar.x,
			v.z | scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator|(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar | v.x,
			scalar | v.y,
			scalar | v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator|(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x | v.x,
			scalar.x | v.y,
			scalar.x | v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator|(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x | v2.x,
			v1.y | v2.y,
			v1.z | v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator^(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x ^ scalar,
			v.y ^ scalar,
			v.z ^ scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator^(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x ^ scalar.x,
			v.y ^ scalar.x,
			v.z ^ scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator^(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar ^ v.x,
			scalar ^ v.y,
			scalar ^ v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator^(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x ^ v.x,
			scalar.x ^ v.y,
			scalar.x ^ v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator^(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x ^ v2.x,
			v1.y ^ v2.y,
			v1.z ^ v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator<<(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x << scalar,
			v.y << scalar,
			v.z << scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator<<(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x << scalar.x,
			v.y << scalar.x,
			v.z << scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator<<(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar << v.x,
			scalar << v.y,
			scalar << v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator<<(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x << v.x,
			scalar.x << v.y,
			scalar.x << v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator<<(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x << v2.x,
			v1.y << v2.y,
			v1.z << v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator>>(vec<3, T, P> const & v, T scalar)
	{
		return vec<3, T, P>(
			v.x >> scalar,
			v.y >> scalar,
			v.z >> scalar);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator>>(vec<3, T, P> const & v, vec<1, T, P> const & scalar)
	{
		return vec<3, T, P>(
			v.x >> scalar.x,
			v.y >> scalar.x,
			v.z >> scalar.x);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator>>(T scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar >> v.x,
			scalar >> v.y,
			scalar >> v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator>>(vec<1, T, P> const & scalar, vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			scalar.x >> v.x,
			scalar.x >> v.y,
			scalar.x >> v.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER vec<3, T, P> operator>>(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return vec<3, T, P>(
			v1.x >> v2.x,
			v1.y >> v2.y,
			v1.z >> v2.z);
	}

	template<typename T, precision P> 
	GLM_FUNC_QUALIFIER vec<3, T, P> operator~(vec<3, T, P> const & v)
	{
		return vec<3, T, P>(
			~v.x,
			~v.y,
			~v.z);
	}

	// -- Boolean operators --

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER bool operator==(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER bool operator!=(vec<3, T, P> const & v1, vec<3, T, P> const & v2)
	{
		return (v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z);
	}

	template<precision P>
	GLM_FUNC_QUALIFIER vec<3, bool, P> operator&&(vec<3, bool, P> const & v1, vec<3, bool, P> const & v2)
	{
		return vec<3, bool, P>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z);
	}

	template<precision P>
	GLM_FUNC_QUALIFIER vec<3, bool, P> operator||(vec<3, bool, P> const & v1, vec<3, bool, P> const & v2)
	{
		return vec<3, bool, P>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z);
	}
}//namespace glm
