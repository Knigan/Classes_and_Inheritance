#pragma once
#include <string>

class ContainerError: public std::exception {
private:
	std::string error;
public:
	ContainerError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};

class BubbleError: public std::exception {
private:
	std::string error;
public:
	BubbleError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};

class ChoiseError: public std::exception {
private:
	std::string error;
public:
	ChoiseError(const std::string& str) noexcept;
	const char* what() const noexcept override;
};