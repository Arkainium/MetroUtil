#ifndef METROBOTICS_REALNUMBER_H
#define METROBOTICS_REALNUMBER_H

namespace metrobotics
{
	/**
	 * \class   RealNumber
	 *
	 * \brief   A class for representing elements that belong to the set of real numbers.
	 *
	 * \details One might question why there is a need for a class that represents real numbers when
	 *          there's already a built-in floating point type, namely \c double. The problem with
	 *          the built-in \c double type is that it has relatively limited precision which can
	 *          often lead to rounding errors that ultimately results in inaccurate data. This class
	 *          attempts to alleviate these issues by allowing the user to arbitrarily set an
	 *          acceptable margin of error, namely epsilon.
	 *
	 * \remarks Given two \c RealNumber objects <b>a</b> and <b>b</b>, and an arbitrarily chosen
	 *          margin of error <b>e</b>, then <b>a == b if and only if abs(a - b) <= e</b>.
	 *
	 * \author  Mark Manashirov <mark.manashirov@gmail.com>
	 */
	class RealNumber
	{
		public:
			/**
			 * \brief   Set the acceptable margin of error for all real numbers.
			 *
			 * \arg     e is the acceptable margin of error represented as a floating point value.
			 *
			 * \note    Changing the acceptable margin of error affects calculations between
			 *          <b>all</b> real numbers.
			 */
			static void epsilon(double e) {_epsilon = e;}

			/**
			 * \brief   Get the acceptable margin of error for all real numbers.
			 */
			static double epsilon() {return _epsilon;}

			// [Constructors for automatic conversion.]
			RealNumber(double n);
			RealNumber(float  n);
			RealNumber(int    n);

			// [Accessor/Mutator]
			double value() const {return _val;}
			void value(double n) {_val = n;}

			// [Declare assignment and compound assignment as members.]
			RealNumber& operator=(const RealNumber& rhs);
			RealNumber& operator+=(const RealNumber& rhs);
			RealNumber& operator-=(const RealNumber& rhs);
			RealNumber& operator*=(const RealNumber& rhs);
			RealNumber& operator/=(const RealNumber& rhs);

		protected:
			/**
			 * \brief   The acceptable margin of error represented as a floating point value.
			 */
			static double _epsilon;

			/**
			 * \brief   The real number represented as a floating point value.
			 */
			double _val;
	};

	// [Declare computational and relational operators.]
	RealNumber operator+(const RealNumber& lhs, const RealNumber& rhs);
	RealNumber operator-(const RealNumber& lhs, const RealNumber& rhs);
	RealNumber operator*(const RealNumber& lhs, const RealNumber& rhs);
	RealNumber operator/(const RealNumber& lhs, const RealNumber& rhs);
	bool operator<(const RealNumber& lhs, const RealNumber& rhs);
	bool operator>(const RealNumber& lhs, const RealNumber& rhs);
	bool operator<=(const RealNumber& lhs, const RealNumber& rhs);
	bool operator>=(const RealNumber& lhs, const RealNumber& rhs);
	bool operator==(const RealNumber& lhs, const RealNumber& rhs);
	bool operator!=(const RealNumber& lhs, const RealNumber& rhs);
}

#endif
