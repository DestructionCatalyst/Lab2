#pragma once
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "Complex.hpp"
#include <memory>
#include <string>
#define abs(m) m>0?m:(-1)*m

using namespace Sequences;
using namespace std;

namespace Arithmetics {


	template <class T> class Polynom {
	private:
		//Sequence<T>* coef;
		T* coef;
	public:
		//Creation

		Polynom()
		{
			//coef = new ListSequence<T>();
			coef = new T();
		}
		Polynom(Complex* arr, int len)
		{
			coef = new T(arr, len);
		}
		Polynom(Sequence<Complex>* arr)
		{
			coef = new T();
			for (int i = 0; i < arr->GetLength(); i++) {
				coef->Append(arr->Get(i));
			}
		}
		Polynom(const Polynom<T>& poly) :
			coef(poly.coef)
		{
		}
		//Decomposition

		Complex Get(int index)
		{
			return coef->Get(index);
		}
		int GetLength()
		{
			return coef->GetLength();
		}

		//Operations

		void Expand() {
			coef->Append(Complex());
		}
		operator string()
		{
			string str;//full string
			string tmp = "0";//current item
			for (int i = 0; i < this->GetLength(); i++) {
				tmp = (string)Get(i);
				if (tmp != "0") {//If current element is not 0
					if (i == 0)
						str = str + tmp;//If it has no x, print it like it is
					else {
						str = str + " + ";
						//Printing the element and the variable
						str = str + tmp + "*(x^" + std::to_string(i) + ")";
					}

				}
			}
			return str;
		}

		Polynom<T>* Add(Polynom<T>& poly)
		{
			//std::cout << "Adding" << std::endl;
			Polynom<T>* tmp = new Polynom<T>(*this);
			Polynom<T>* polyPtr = new Polynom<T>(poly);
			if (this->GetLength() < poly.GetLength()) {
				tmp = polyPtr;
				polyPtr = new Polynom<T>(*this);
			}

			Sequence<Complex>* sumSeq = new T();
			for (int i = 0; i < polyPtr->GetLength(); i++) {
				sumSeq->Append(tmp->Get(i) + polyPtr->Get(i));
			}

			for (int i = polyPtr->GetLength(); i < tmp->GetLength(); i++) {
				sumSeq->Append(tmp->Get(i));
			}

			return new Polynom(sumSeq);
		}

		Polynom<T> operator + (Polynom<T>& poly)
		{
			return *Add(poly);
		}

		Polynom<T>* Multiply(Complex number)
		{
			//std::cout << "Multiplying by " << (std::string)number << std::endl;
			Sequence<Complex>* newCoef = coef->Map(
				[number](Complex a) -> Complex
				{
					return a * number;
				}
			);
			return new Polynom<T>(newCoef);
		}

		Polynom<T> operator * (Complex number)
		{
			return *Multiply(number);
		}

		Polynom<T>* CrossMultiply(Polynom<T>& poly)
		{
			//std::cout << "Cross-multiplying" << std::endl;
			int n = this->GetLength();
			int m = poly.GetLength();

			unique_ptr<Complex[]> newCoef = make_unique<Complex[]>(m + n);
			for (int i = 0; i < n + m; i++)
				newCoef[i] = Complex();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					newCoef[i + j] = newCoef[i + j] + this->Get(i) * poly.Get(j);
				}
			}
			return new Polynom<T>(newCoef.get(), n + m - 1);
		}

		Polynom<T> operator * (Polynom<T>& poly)
		{
			return *CrossMultiply(poly);
		}
		Polynom<T>* Composition(Polynom<T>& poly)
		{
			//std::cout << "Composition" << std::endl;
			int n = this->GetLength();
			int m = poly.GetLength();

			unique_ptr<Complex[]> newCoef = make_unique<Complex[]>((m - 1) * (n - 1) + 1);
			newCoef[0] = this->Get(0);
			for (int i = 1; i < (m - 1) * (n - 1) + 1; i++)
				newCoef[i] = Complex();

			Polynom<T>* res = new Polynom<T>(newCoef.get(), (m - 1) * (n - 1) + 1);
			//std::cout << "-----" << (string)*res << res->GetLength() << std::endl;
			Polynom<T>* cur = new Polynom<T>();

			for (int i = 1; i < n; i++) {
				if (Get(i) != Complex()) {
					cur = new Polynom<T>(poly);
					for (int j = 1; j < i; j++) {
						*cur = (*cur) * (poly);
					}
					*cur = (*cur) * (Get(i));
					//std::cout << "-----" << (string)*cur << cur->GetLength() << std::endl;
					*res = *res + *cur;
				}
			}

			return new Polynom<T>(*res);
		}
		Complex Calculate(Complex value) {
			Complex res;
			for (int i = 0; i < this->GetLength(); i++) {
				res = res + Get(i) * power(value, i);
			}
			return res;
		}
		
	};

}