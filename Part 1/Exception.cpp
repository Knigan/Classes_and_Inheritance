#include "Exception.h"

LongLongError::LongLongError() noexcept: error("Attempt to divide by zero had just happened") {}

const char* LongLongError::what() const noexcept {
	return error.c_str();
}

RationalError::RationalError() noexcept: error("Attempt to divide by zero had just happened") {}

const char* RationalError::what() const noexcept {
	return error.c_str();
}