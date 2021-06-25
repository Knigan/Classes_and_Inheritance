#include "String.h"

int String::count = 0;

String::String() noexcept {
	arr[0] = '0';
	++count;
}

String::String(int n, uchar* arr): Array(n + 1, arr) {
	++count;
}

int String::length() {
	return size - 1;
}

void String::sum (const Array& x, Array& res) {
	if (size + x.getsize() - 1 > maxsize)
		throw StringError("The size of the merge of the strings is too large");
	res.setsize(size + x.getsize() - 1);
	for (int i = 1; i < size; ++i)
		res[i - 1] = arr[i];
	for (int i = size; i < size + x.getsize() - 1; ++i)
		res[i] = x[i - size];
}

int String::search(const String& str) const noexcept {
	if (size < str.size)
		return 0;
	if (size == str.size) {
		for (int i = 1; i < size; ++i) {
			if (arr[i] != str[i])
				return 0;
		}
		return 1;
	}
	for (int i = 1; size - i >= str.size - 1; ++i) {
		if (arr[i] == str[1]) {	
			if (str.size == 2)
				return i;
			for (int j = 2; j < str.size && arr[j + i - 1] == str[j]; ++j) {
				if (j == str.size - 1)
					return i;
			}
		}
	}
	return 0;
}

String String::insert (const String& str, int pos) const {
	if (pos < 1 || pos >= size)
		throw StringError("The selected position is incorrect");
	String res(*this);
	res.size = size + str.size - 1;
	if (res.size > maxsize)
		throw StringError("The size of the string is too large");
	res[0] = res.size;

	for (int i = size - 1; i >= pos; --i)
		res[i + str.size - 1] = arr[i];
	for (int i = 0; i < str.size - 1; ++i)
		res[i + pos] = str[i + 1];

	return res;
}

String String::del (const String& str) const {
	String res(*this);
	int pos = res.search(str);
	while (pos != 0) {
		for (int i = 0; i + pos + str.size - 1 < res.size; ++i)
			res[i + pos] = res[i + pos + str.size - 1];
		res.size -= (str.size - 1);
		pos = res.search(str);
	}
	res[0] = res.size;
	return res;
}

int String::getcount() {
	return count;
}

std::ostream& operator << (std::ostream& out, const String& str) noexcept {
	for (int i = 1; i < str.size; ++i)
		out << str[i];
	return out;
}

std::istream& operator >> (std::istream& in, String& str) {
	int n;
	std::cout << "\nInput the size of the string\n";
	in >> n;
	if (n <= 0)
		throw ArrayError("The size of the array must be a positive integer number");
	uchar* arr = new uchar[n + 1];
	arr[0] = n;
	std::cout << "\nInput the string\n";
	for (int i = 1; i <= n; ++i)
		in >> arr[i];
	String st(n, arr);
	str = st;
	return in;
}