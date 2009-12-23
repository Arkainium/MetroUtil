#include <cmath>
using namespace std;

#include "RealEquality.h"
using namespace metrobotics;

RealEquality::RealEquality(double epsilon)
:_epsilon(epsilon)
{
}

bool RealEquality::operator()(const double& lhs, const double& rhs) const
{
	return fabs(lhs - rhs) <= _epsilon;
}
