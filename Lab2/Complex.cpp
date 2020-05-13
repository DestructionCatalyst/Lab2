#include <cmath>
#include <string>
#include "Complex.hpp"
//#define optional(val) ((val==0.)?(""):(std::format("%g", val))) 



std::string optional_string(double val) {
	if (val == 0.) {
		return "";
	}
	else {
		std::string tmp = std::to_string(val);
		if (tmp.find(".") != std::string::npos) {
			tmp.erase(tmp.find_last_not_of("0") + 1);
		}
		if (tmp.ends_with("."))
			tmp.erase(tmp.length() - 1);
		return tmp;
	}
	
}

namespace Arithmetics {
	//Creation
	Complex::Complex()
	{
		re = 0;
		im = 0;
	}
	Complex::Complex(double x, double y)
	{
		re = x;
		im = y;
	}
	//Decomposition
	double Complex::Re()
	{
		return re;
	}
	double Complex::Im()
	{
		return im;
	}
	//Opreations
	double Complex::Module()
	{
		return std::sqrt(re * re + im * im);
	}
	Complex Complex::Conjugate()
	{
		return Complex(re, -im);
	}

	Complex Complex::operator + (double x)
	{
		return Complex(this->Re() + x, this->Im());
	}
	Complex Complex::operator + (Complex z)
	{
		return Complex(this->Re() + z.Re(), this->Im() + z.Im());
	}

	Complex Complex::operator - (double x)
	{
		return Complex(this->Re() - x, this->Im());
	}
	Complex Complex::operator - (Complex z)
	{
		return Complex(this->Re() - z.Re(), this->Im() - z.Im());
	}

	Complex Complex::operator * (double x)
	{
		return Complex(this->Re() * x, this->Im() * x);
	}
	Complex Complex::operator * (Complex z)
	{
		return Complex(this->Re() * z.Re() - this->Im() * z.Im(), this->Re() * z.Im() + this->Im() * z.Re());
	}

	Complex Complex::operator / (double x)
	{
		return Complex(this->Re() / x, this->Im() / x);
	}
	Complex Complex::operator / (Complex z)
	{
		return Complex((*this * z.Conjugate()) / (z.Module() * z.Module()));
	}

	Complex::operator std::string()
	{
		if ((this->re == 0.) && (this->im == 0.))
			return "0";
		else
			return "(" + optional_string(this->re)
			+ (((this->re != 0.) && (this->im != 0.)) ? " + " : "")
			+ optional_string(this->im)
			+ ((this->im != 0.) ? "*i" : "")
			+ ")";
	}

	int Complex::operator != (Complex z) 
	{
		if ((this->Re() == z.Re()) && (this->Im() == z.Im()))
			return 0;
		else 
			return 1;
	}
}

