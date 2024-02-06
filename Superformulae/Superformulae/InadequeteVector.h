#pragma once
#include <iostream>
#include <string>
#include <exception>
class InadequeteVector : public std::exception
{
public:
	InadequeteVector();
	friend std::ostream& operator<<(std::ostream& os, const InadequeteVector& e);
};

