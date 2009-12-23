#ifndef METROBOTICS_LERP_H
#define METROBOTICS_LERP_H

#include <map>
#include <exception>

namespace metrobotics
{
	/**
	 * \class   Lerp
	 *
	 * \brief   A generic linear interpolation class.
	 *
	 * \details The purpose of this class is to provide an interface that allows the user to
	 *          interpolate an N-dimensional point (represented by an N-dimensional vector) given
	 *          one of its dimensions (entries) such that there exists a pair of bounding data
	 *          points in the set of all recorded data points.  Put simply, this class can be used
	 *          to interpolate (i.e. "fill in") the empty points on a graph by using the set of
	 *          points that are already known together with one component from those unknown points.
	 *
	 * \tparam  vectorN is a type that is capable of representing elements that belong to an
	 *          N-dimensional vector space over an ordered field. This means that objects of this
	 *          type must be additively conformable (vector addition) and multiplicatively
	 *          conformable (scalar multiplication), and that the field under which they lie must be
	 *          comparable using the standard relational operators (e.g. less than, etc.).
	 *
	 * \author  Mark Manashirov <mark.manashirov@gmail.com>
	 */
	template <class vectorN>
	class Lerp
	{
		public:
			// [Conform to the C++ Standard Template Library type definition syntax.]
			/**
			 * \brief   The type of the individual entries (components) in the vector.
			 *
			 * \details This type represents the elements of the field that lie under the vector
			 *          space spanned by the elements of type \a vectorN. Because this field must be
			 *          ordered, these types must be comparable using the standard relational
			 *          operators, that is, specifically, the \a less \a than (\b <) operator and
			 *          the \a equal \a to (\b ==) operator.
			 */
			typedef typename vectorN::value_type key_type;

			/**
			 * \brief   The type of the elements (vectors) in the vector space.
			 *
			 * \details This type represents the actual individual elements (vectors) of the
			 *          N-dimensional vector space. Because these elements belong to a vector space,
			 *          they must be both additively and multiplicatively conformable, that is the
			 *          \a addition (\b+) operator and \a multiplication (\b*) operator must be
			 *          defined for this type.
			 */
			typedef vectorN value_type;

			/**
			 * \brief   An unsigned integral type.
			 *
			 * \details A type that is capable of representing the number of data points that
			 *          are presently in the set as well as the maximum number of data points
			 *          that the set may contain.
			 */
			typedef unsigned int size_type;

			/**
			 * \brief   Construct a linear interpolation object with no data points.
			 *
			 * \details By default, linear interpolation is done with respect to the first entry
			 *          (component) in the vectors. This behavior can be changed by constructing the
			 *          linear interpolation object with an optional integer argument that
			 *          corresponds to the position of the entry (component) by which to
			 *          interpolate.
			 *
			 * \arg     \c pos is the position of the entry (component) within the vector that is
			 *          used for interpolation; a value of zero corresponds the first entry
			 *          (component) in the vector.
			 *
			 * \note    Due to the internal implementation of keeping the set of data points
			 *          ordered, the position of the entry (component) in the vector that is used
			 *          for interpolation cannot be changed after the linear interpolation object is
			 *          created.
			 */
			Lerp(typename vectorN::size_type pos = 0)
			:_pos(pos)
			{
			}

			/**
			 * \brief   Insert a new data point into the set.
			 *
			 * \details The placement of the newly inserted point with respect to the other points
			 *          in the set will depend on the entry (component) in position \c _pos.
			 *
			 * \arg     \c vec is the N-dimensional vector that represents the N-dimensional point
			 *          to be added to the set of data points.
			 *
			 * \note    Inserting the same data point twice has no effect. More specifically, the
			 *          entry (component) in position \c _pos of one vector is the same as another
			 *          vector if and only if both vectors are equivalent.
			void insert(const vectorN& vec)
			{
			}
			 */

			/**
			 * \brief   Erase a data point from the set.
			 *
			 * \details Attempting to erase a point that is not already in the set has no effect.
			 *
			 * \arg     \c vec is the N-dimensional vector that represents the N-dimensional point
			 *          to be erased from the set of data points.
			void erase(const vectorN& vec)
			{
			}
			 */

			/**
			 * \brief   Erase all data points from the set.
			void clear()
			{
			}
			 */

			/**
			 * \brief   Test whether the set contains any data points.
			 *
			 * \returns true if the set has no data points; false if the set contains at least one
			 *          data point
			bool empty() const
			{
			}
			 */

			/**
			 * \brief   Test whether a specific data point is contained within the set of data
			 *          points.
			 *
			 * \arg     \c vec is the N-dimensional vector that represents the N-dimensional point
			 *          to find in the set of data points.
			 *
			 * \returns true if \c vec is found in the set of data points; false if \c vec is not in
			 *          the set of data points
			bool exists(const vectorN& vec) const
			{
			}
			 */

			/**
			 * \brief   The number of recorded data points.
			 *
			 * \returns the number of data points that are currently in the set
			size_type size() const
			{
			}
			 */

			/**
			 * \brief     Interpolate an N-dimensional vector.
			 *
			 * \details   Interpolate an N-dimensional vector with respect to the entry (component)
			 *            in position \c _pos using the data points that already exist in the set.
			 *
			 * \arg       \c comp is the entry (component) of the unknown vector that will be used
			 *            to interpolate its remaining entries (components) with respect to the data
			 *            points that are already in the set.
			 *
			 * \returns   an N-dimensional vector that contains the value of \c comp in position \c
			 *            _pos, and whose remaining entries have been interpolated using the data
			 *            points in the set.
			 *
			 * \exception std::domain_error is thrown when the component used for interpolation is
			 *            either lower than all the existing data points in the set or it is greater
			 *            than all the existing data points in the set; in other words, the
			 *            component would represent a vector that is outside the interval of
			 *            recorded data points.
			vectorN interpolate(const vectorN::value_type& comp)
			{
			}
			 */

		protected:
			/**
			 * \brief   The position of the entry (component) in the vector that is used for
			 *          interpolation.
			 *
			 * \details A value of zero corresponds to the first entry (component) in the vector;
			 *          the value of this attribute is initialized at object creation time, and its
			 *          value may not change during the lifetime of the object.
			 */
			const typename vectorN::size_type _pos;

			/**
			 * \brief   The set (collection) of data points.
			 *
			 * \details The set (collection) of data points is arranged in order with respect to the
			 *          entry (component) of the vector that is denoted by the \c _pos attribute.
			 */
			std::map<typename vectorN::value_type, vectorN> _data;
	};
}

#endif
