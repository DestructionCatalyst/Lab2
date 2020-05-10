#pragma once
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include <memory>
#define abs(m) m>0?m:(-1)*m

using namespace Sequences;
using namespace std;

namespace Arithmetics {

	template <class T> class Polynom {
	private:
		Sequence<T>* coef;
	public:
		//Creation

		Polynom()
		{
			coef = new ArraySequence<T>();
		}
		Polynom(T* arr, int len)
		{
			coef = new ArraySequence<T>(arr, len);
		}
		Polynom(Sequence<T>* arr)
		{
			coef = new ArraySequence<T>();
			for (int i = 0; i < arr->GetLength(); i++) {
				coef->Append(arr->Get(i));
			}
		}
		Polynom(Polynom<T>& poly):
			coef(poly.coef)
		{
		}
		//Decomposition

		T Get(int index)
		{
			return coef->Get(index);
		}
		int GetLength()
		{
			return coef->GetLength();
		}
		
		//Operations

		void Expand() {
			coef->Append(T());
		}
		operator string()
		{
			string str;//full string
			string tmp = "0";//current item
			for (int i = 0; i < this->GetLength(); i++) {
				tmp = (string)Get(i);
				//if (tmp != "0") {//If current element is not 0
					if (i == 0)
						str = str + tmp;//If it has no x, print it like it is
					else {
						str = str + " + ";
						//Printing the element and the variable
						str = str + tmp + "*(x^" + std::to_string(i) + ")";
					}

				//}
			}
			return str;
		}

		Polynom<T>* Add(Polynom<T>& poly)
		{
			std::cout << "Adding" << std::endl;
			Polynom<T>* tmp = new Polynom<T>(*this);
			Polynom<T>* polyPtr = new Polynom<T>(poly);
			if (this->GetLength() < poly.GetLength()) {
				tmp = polyPtr;
				polyPtr = new Polynom<T>(*this);
			}

			int startLength = polyPtr->GetLength();

			for (int i = 0; i <= tmp->GetLength() - startLength; i++) {
				polyPtr->Expand();
			}

			//std::cout << "+--------" << (string)*polyPtr << polyPtr->GetLength() << std::endl;

			Sequence<T>* sumSeq = new ArraySequence<T>();
			for (int i = 0; i < tmp->GetLength(); i++) {
				sumSeq->Append(tmp->Get(i) + polyPtr->Get(i));
			}
			return new Polynom(sumSeq);
		}

		Polynom<T> operator + (Polynom<T>& poly)
		{
			return *Add(poly);
		}

		Polynom<T>* Multiply(T number)
		{
			std::cout << "Multiplying by " << (std::string)number << std::endl;
			Sequence<T>* newCoef = coef->Map(
				[number](T a) -> T
				{
					return a * number;
				}
			);
			return new Polynom<T>(newCoef);
		}

		Polynom<T> operator * (T number)
		{
			return *Multiply(number);
		}

		Polynom<T>* CrossMultiply(Polynom<T>& poly)
		{
			std::cout << "Cross-multiplying" << std::endl;
			int n = this->GetLength();
			int m = poly.GetLength();

			unique_ptr<T[]> newCoef = make_unique<T[]>(m + n);
			for (int i = 0; i < n + m; i++)
				newCoef[i] = T();

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
			std::cout << "Composition" << std::endl;
			int n = this->GetLength();
			int m = poly.GetLength();

			unique_ptr<T[]> newCoef = make_unique<T[]>((m - 1) * (n - 1) + 1);
			newCoef[0] = this->Get(0);
			for (int i = 1; i < (m - 1) * (n - 1) + 1; i++)
				newCoef[i] = T();

			Polynom<T>* res = new Polynom<T>(newCoef.get(), (m - 1) * (n - 1) + 1);
			//std::cout << "-----" << (string)*res << res->GetLength() << std::endl;
			Polynom<T>* cur = new Polynom<T>(); 

			for (int i = 1; i < n; i++) {
				if (Get(i) != T()) {
					cur = new Polynom<T>(poly);
					for (int j = 1; j < i; j++) {
						*cur = (*cur) * (poly);
					}
					*cur = (*cur) * (Get(i));
					//std::cout << "-----" << (string)*cur << cur->GetLength() << std::endl;
					*res = *res + *cur;
				}
			}
			
			return new Polynom(*res);
		}
	};
}