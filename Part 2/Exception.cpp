#include "Exception.h"

ArrayError::ArrayError(const std::string& str) noexcept : error("ArrayError: " + str) {}

const char* ArrayError::what() const noexcept {
	return error.c_str();
}

OctalError::OctalError (const std::string& str) noexcept : error("OctalError: " + str) {}

const char* OctalError::what() const noexcept {
	return error.c_str();
}

StringError::StringError (const std::string& str) noexcept : error("StringError: " + str) {}

const char* StringError::what() const noexcept {
	return error.c_str();
}

CastError::CastError(const std::string& str) noexcept : error("CastError: " + str) {}

const char* CastError::what() const noexcept {
	return error.c_str();
}