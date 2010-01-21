#ifndef METROBOTICS_REALVECTORN_H
#define METROBOTICS_REALVECTORN_H

#include "VectorN.h"
#include "RealEquality.h"

namespace metrobotics
{
	/**
	 * \class   RealVectorN
	 *
	 * \brief   A generic vector implementation over the real numbers.
	 *
	 * \details This class is capable of representing vectors of any dimension (size) over 
	 *          the real numbers, that is values represented by type \c double.
	 *
	 * \tparam  N is an unsigned integral value that represents the dimension of the vector
	 *
	 * \author  Mark Manashirov <mark.manashirov@gmail.com>
	 */
	template <size_t N>
	class RealVectorN : public VectorN<double, N>
	{
		public:
			/**
			 * \brief   Set/change the acceptable margin of error.
			 *
			 * \details The acceptable margin of error is used in relational operations involving
			 *          vectors. For example, when determining whether two vectors are equal to each
			 *          other, the acceptable margin of error will determine the maximum variance
			 *          of equal numbers and the minimum variance of unequal numbers. See \ref
			 *          equality for more details.
			 *
			 * \arg     epsilon is the acceptable margin of error
			 *
			 * \remarks The acceptable margin of error applies to the entire vector space, that is
			 *          to all vectors of the same dimension. The acceptable margin of error is
			 *          initialized to zero by default.
			 */
			static void marginOfError(double epsilon)
			{
				_equal_to.marginOfError(epsilon);
			}

			/**
			 * \brief   Get the acceptable margin of error.
			 *
			 * \returns the acceptable margin of error
			 */
			static double marginOfError()
			{
				return _equal_to.marginOfError();
			}

			/**
			 * \brief   Construct a new empty vector.
			 *
			 * \details All new vectors are initialized to zero by default.
			 */
			RealVectorN()
			{
				// [Initialize new vectors to the zero vector.]
				for (typename RealVectorN<N>::size_type i = 0; i < N; ++i) {
					(*this)[i] = 0.0;
				}
			}

			/**
			 * \anchor  equality
			 *
			 * \brief   Equality operator.
			 *
			 * \details Two vectors \b a and \b b are \b equal if they are of the same dimension,
			 *          \b N, and for 0 <= \b i < N, <b>a[i] == b[i]</b>.
			 *
			 * \remark  Given two real numbers <b>a[0]</b> and <b>b[0]</b>, and an acceptable margin of
			 *          error <b>e</b>, then <b>a[0] == b[0] if and only if |a[0] - b[0]| <= e</b>.
			 */
			friend bool operator==(const RealVectorN<N>& lhs, const RealVectorN<N>& rhs)
			{
				// [Check each entry one at a time.]
				for (typename RealVectorN<N>::size_type i = 0; i < N; ++i) {
					if (!(_equal_to(lhs[i], rhs[i]))) {
						return false;
					}
				}
				return true;
			}

			/**
			 * \brief   Inequality operator.
			 *
			 * \details The converse of \ref equality .
			 */
			friend bool operator!=(const RealVectorN<N>& lhs, const RealVectorN<N>& rhs)
			{
				// [Delegate work to operator==().]
				return !(lhs == rhs);
			}

		private:
			/**
			 * \brief   Binary predicate used to determine whether two real numbers are equivalent.
			 *
			 * \details This binary predicate will be used for the entire vector space, that is for
			 *          all vectors of the same dimension.
			 */
			static RealEquality _equal_to;
	};

	// [Default-initialize the binary predicate.]
	template <size_t N>
	RealEquality RealVectorN<N>::_equal_to = RealEquality();
}

#endif
