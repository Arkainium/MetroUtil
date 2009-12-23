#ifndef METROBOTICS_REALLESSTHAN_H
#define METROBOTICS_REALLESSTHAN_H

namespace metrobotics
{
	/**
	 * \class   RealLessThan
	 *
	 * \brief   A function object that compares two real numbers using the less than relation.
	 *
	 * \details This comparison takes into account the limited precision of floating point values by
	 *          using an arbitrary acceptable margin of error.
	 *
	 * \remark  Given two floating point numbers <b>a</b> and <b>b</b>, and an acceptable margin of
	 *          error <b>e</b>, then <b>a < b if and only if (b - a) > e</b>.
	 *
	 * \author  Mark Manashirov <mark.manashirov@gmail.com>
	 */
	class RealLessThan
	{
		public:
			// [Conform to STL's specification for adaptable binary predicates.]
			typedef double first_argument_type;
			typedef double second_argument_type;
			typedef bool result_type;

			/**
			 * \brief   Construct a new predicate for comparing two real numbers using the less than
			 *          relation.
			 *
			 * \details Optionally provide an acceptable margin of error to be used in comparisons;
			 *          if no acceptable margin of error is specified then it is assumed that there
			 *          is no acceptable margin of error, that is that the margin of error is zero,
			 *          which is no different than using the built-in comparison for floating point
			 *          values.
			 *
			 * \arg     epsilon is the acceptable margin of error
			 */
			RealLessThan(double epsilon = 0.0);

			/**
			 * \brief   Function call operator.
			 *
			 * \details Treats the predicate as a function that takes two real numbers and returns
			 *          the result of their comparison. For example, given two real numbers <b>a</b>
			 *          and <b>b</b> and \c RealLessThan <b>f(e)</b> where <b>e</b> is the
			 *          acceptable margin of error, then <b>f(a, b) == [(b - a) > e]</b>.
			 */
			bool operator()(const double& lhs, const double& rhs) const;

		private:
			/**
			 * \brief   The acceptable margin of error.
			 */
			double _epsilon;
	};
}

#endif
