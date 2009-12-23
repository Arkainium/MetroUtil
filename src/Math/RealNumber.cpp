#include <cmath>
using namespace std;

#include "RealNumber.h"
using namespace metrobotics;


RealNumber::RealNumber(double n)
:_val(n) { }
RealNumber::RealNumber(float n)
:_val(static_cast<double>(n)) { }
RealNumber::RealNumber(int n)
:_val(static_cast<double>(n)) { }

RealNumber& RealNumber::operator=(const RealNumber& rhs)
{
	_val = rhs._val;
	return *this;
}

RealNumber& RealNumber::operator+=(const RealNumber& rhs)
{
	_val += rhs._val;
	return *this;
}

RealNumber& RealNumber::operator-=(const RealNumber& rhs)
{
	_val -= rhs._val;
	return *this;
}

RealNumber& RealNumber::operator*=(const RealNumber& rhs)
{
	_val *= rhs._val;
	return *this;
}

RealNumber& RealNumber::operator/=(const RealNumber& rhs)
{
	_val /= rhs._val;
	return *this;
}

RealNumber operator+(const RealNumber& lhs, const RealNumber& rhs)
{
	return RealNumber(lhs.value() + rhs.value());
}

RealNumber operator-(const RealNumber& lhs, const RealNumber& rhs)
{
	return RealNumber(lhs.value() - rhs.value());
}

RealNumber operator*(const RealNumber& lhs, const RealNumber& rhs)
{
	return RealNumber(lhs.value() * rhs.value());
}

RealNumber operator/(const RealNumber& lhs, const RealNumber& rhs)
{
	return RealNumber(lhs.value() / rhs.value());
}

bool operator<(const RealNumber& lhs, const RealNumber& rhs)
{
	return (rhs.value() - lhs.value()) > RealNumber::epsilon();
}

bool operator>(const RealNumber& lhs, const RealNumber& rhs)
{
	return (lhs.value() - rhs.value()) > RealNumber::epsilon();
}

bool operator<=(const RealNumber& lhs, const RealNumber& rhs)
{
	return ::operator<(lhs, rhs) || ::operator==(lhs, rhs);
}

bool operator>=(const RealNumber& lhs, const RealNumber& rhs)
{
	return ::operator>(lhs, rhs) || ::operator==(lhs, rhs);
}

bool operator==(const RealNumber& lhs, const RealNumber& rhs)
{
	return abs(lhs.value() - rhs.value()) <= RealNumber::epsilon();
}

bool operator!=(const RealNumber& lhs, const RealNumber& rhs)
{
	return !(::operator==(lhs, rhs));
}
