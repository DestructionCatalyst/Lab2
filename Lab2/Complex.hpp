#pragma once
#include <string>

namespace Arithmetics {
	class Complex {
	private:
		double re;
		double im;
	public:
		//Creation
		Complex();
		Complex(double x, double y = 0);
		//Decomposition
		double Re();
		double Im();
		//Opreations
		double Module();
		Complex Conjugate();
		Complex operator + (double x);
		Complex operator + (Complex z);
		Complex operator - (double x);
		Complex operator - (Complex z);
		Complex operator * (double x);
		Complex operator * (Complex z);
		Complex operator / (double x);
		Complex operator / (Complex z);
		int operator != (Complex z);
		operator std::string();
	};
}