#pragma once
#include <string>

class ArrayError: public std::exception {
private:
	std::string error;
public:
	ArrayError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};

class OctalError: public std::exception {
private:
	std::string error;
public:
	OctalError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};

class StringError: public std::exception {
private:
	std::string error;
public:
	StringError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};

class CastError: public std::exception {
private:
	std::string error;
public:
	CastError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};