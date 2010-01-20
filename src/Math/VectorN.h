#ifndef METROBOTICS_VECTORN_H
#define METROBOTICS_VECTORN_H

#include <stdexcept>

namespace metrobotics
{
	/**
	 * \class   VectorN
	 *
	 * \brief   A generic vector implementation.
	 *
	 * \details This class is capable of representing vectors of any dimension (size) over any
	 *          numeric field, that is a field (type) whose objects can be added together,
	 *          subtracted from each other, multiplied by one another, and compared to each other
	 *          for equality.
	 *
	 * \anchor  operations
	 * \tparam  T is a type that is capable of the following operations:
	 *          <ol>
	 *            <li>
	 *                Addition
	 *                \code
	 *                    T a, b;
	 *                    // ...
	 *                    // Assume that a and b have been given values.
	 *                    // ...
	 *                    T c = a + b; // This statement must be legal!
	 *                \endcode
	 *            </li>
	 *            <li>
	 *                Subtraction
	 *                \code
	 *                    T a, b;
	 *                    // ...
	 *                    // Assume that a and b have been given values.
	 *                    // ...
	 *                    T c = a - b; // This statement must be legal!
	 *                \endcode
	 *            </li>
	 *            <li>
	 *                Multiplication
	 *                \code
	 *                    T a, b;
	 *                    // ...
	 *                    // Assume that a and b have been given values.
	 *                    // ...
	 *                    T c = a * b; // This statement must be legal!
	 *                \endcode
	 *            </li>
	 *            <li>
	 *                Equality
	 *                \code
	 *                    T a, b;
	 *                    // ...
	 *                    // Assume that a and b have been given values.
	 *                    // ...
	 *                    bool equality = a == b; // This statement must be legal!
	 *                \endcode
	 *            </li>
	 *          </ol>
	 *
	 * \tparam  N is an unsigned integral value that represents the dimension of the vector
	 *
	 * \author  Mark Manashirov <mark.manashirov@gmail.com>
	 */
	template <class T, size_t N>
	class VectorN
	{
		public:
			// [Adhere to the C++ Standard Template Library naming convention for type definitions.]
			/**
			 * \brief   An unsigned integral type.
			 */
			typedef unsigned long   size_type;
			/**
			 * \brief   A signed integral type.
			 */
			typedef   signed long   difference_type;
			/**
			 * \brief   The type of the individual entries (components) in the vector.
			 *
			 * \details This type represents the elements of the field that constitute the vector.
			 *          For more information on this type, see the restrictions that are imposed on
			 *          its \ref operations.
			 */
			typedef            T    value_type;
			typedef            T*   pointer;
			typedef            T&   reference;
			typedef      const T&   const_reference;

			/**
			 * \brief   Default constructor.
			 *
			 * \details All new vectors are implicitly initialized to be empty by default.
			 */
			VectorN()
			{
			}

			/**
			 * \brief   Copy constructor.
			 */
			VectorN(const VectorN& v)
			{
				// [Delegate work to the assignment operator.]
				*this = v;
			}

			/**
			 * \brief   Destructor.
			 */
			virtual ~VectorN()
			{
			}

			/**
			 * \brief   Assignment operator.
			 */
			VectorN& operator=(const VectorN& v)
			{
				if (this != &v) {
					// [Copy the vector entry by entry.]
					for (size_type i = 0; i < N; ++i) {
						_data[i] = v[i];
					}
				}
				return *this;
			}

			/**
			 * \brief   Index into a vector to randomly access its entries.
			 */
			T& operator[](size_t index)
			{
				if (index >= N) {
					throw std::domain_error("VectorN: out of bounds");
				} else {
					return _data[index];
				}
			}

			/**
			 * \brief   Index into a vector to randomly access its entries (constant version).
			 */
			const T& operator[](size_t index) const
			{
				if (index >= N) {
					throw std::domain_error("VectorN: out of bounds");
				} else {
					return _data[index];
				}
			}

			/**
			 * \brief   Equal-to operator.
			 */
			friend bool operator==(const VectorN<T, N>& lhs, const VectorN<T, N>& rhs)
			{
				// [Check each entry one at a time.]
				for (typename VectorN<T, N>::size_type i = 0; i < N; ++i) {
					if (!(lhs[i] == rhs[i])) {
						return false;
					}
				}
				return true;
			}

			/**
			 * \brief   Not-equal-to operator.
			 */
			friend bool operator!=(const VectorN<T, N>& lhs, const VectorN<T, N>& rhs)
			{
				// [Delegate work to operator==().]
				return !(lhs == rhs);
			}

			/**
			 * \brief   Addition operator.
			 */
			friend const VectorN<T, N> operator+(const VectorN<T, N>& lhs, const VectorN<T, N>& rhs)
			{
				VectorN<T, N> ret;
				// [Add entries in like positions.]
				for (size_type i = 0; i < N; ++i) {
					ret[i] = lhs[i] + rhs[i];
				}
				return ret;
			}

			/**
			 * \brief   Subtraction operator.
			 */
			friend const VectorN<T, N> operator-(const VectorN<T, N>& lhs, const VectorN<T, N>& rhs)
			{
				VectorN<T, N> ret;
				// [Subtract entries in like positions.]
				for (size_type i = 0; i < N; ++i) {
					ret[i] = lhs[i] - rhs[i];
				}
				return ret;
			}

			/**
			 * \brief   Scalar multiplication (from the left) operator.
			 */
			friend const VectorN<T, N> operator*(const T& lhs, const VectorN<T, N>& rhs)
			{
				VectorN<T, N> ret;
				// [Multiply all entries by the scalar.]
				for (size_type i = 0; i < N; ++i) {
					ret[i] = lhs * rhs[i];
				}
				return ret;
			}

			/**
			 * \brief   Scalar multiplication (from the right) operator.
			 */
			friend const VectorN<T, N> operator*(const VectorN<T, N>& lhs, const T& rhs)
			{
				VectorN<T, N> ret;
				// [Multiply all entries by the scalar.]
				for (size_type i = 0; i < N; ++i) {
					ret[i] = lhs[i] * rhs;
				}
				return ret;
			}

		private:
			T _data[N];
	};
}

#endif
