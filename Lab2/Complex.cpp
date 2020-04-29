#include <cmath>

namespace ComplexNumbers {
	class Complex {
	private:
		double re;
		double im;
	public:
		//Creation
		Complex(double x = 0, double y = 0)
		{
			re = x;
			im = y;
		}
		//Decomposition
		double Re()
		{
			return re;
		}
		double Im()
		{
			return im;
		}
		//Opreations
		double Module()
		{
			return std::sqrt(re * re + im * im);
		}
		Complex Conjugate()
		{
			return Complex(re, -im);
		}

		Complex operator + (double x)
		{
			return Complex(this->Re() + x, this->Im());
		}
		Complex operator + (Complex z)
		{
			return Complex(this->Re() + z.Re(), this->Im() + z.Im());
		}

		Complex operator - (double x)
		{
			return Complex(this->Re() - x, this->Im());
		}
		Complex operator - (Complex z)
		{
			return Complex(this->Re() - z.Re(), this->Im() - z.Im());
		}

		Complex operator * (double x)
		{
			return Complex(this->Re() * x, this->Im() * x);
		}
		Complex operator * (Complex z)
		{
			return Complex(this->Re() * z.Re() - this->Im() * z.Im(), this->Re() * z.Im() + this->Im() * z.Re());
		}

		Complex operator / (double x)
		{
			return Complex(this->Re() / x, this->Im() / x);
		}
		Complex operator / (Complex z)
		{
			return Complex((*this * z.Conjugate()) / (z.Module() * z.Module()));
		}
		
	};
}

