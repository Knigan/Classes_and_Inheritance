#include "Exception.h"

ContainerError::ContainerError(const std::string& str) noexcept: error("ContainerError: " + str) {}

const char* ContainerError::what() const noexcept {
	return error.c_str();
}

BubbleError::BubbleError(const std::string& str) noexcept: error("BubbleError: " + str) {}

const char* BubbleError::what() const noexcept {
	return error.c_str();
}

ChoiseError::ChoiseError(const std::string& str) noexcept: error("ChoiseError: " + str) {}

const char* ChoiseError::what() const noexcept {
	return error.c_str();
}