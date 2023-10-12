#include <iostream>
#include <strring>
#include <iomanip>
using namespace std;

class ExceptionLess : public exception {
};
class ExceptionGreater : public exception {
};
class ExceptionEqual : public exception {
};



class BlackBox {
public:
	int a;
	int ans = 100;
	void GuessNumber(int x) const {
		if (x > ans) {
			ExceptionLess exception;
			throw exception;
		}
		else if (x < ans) {
			ExceptionGreater exception;
			throw exception;
		}
		else {
			ExceptionEqual exception;
			throw exception;
		}
	}
};


int guess(const BlackBox& box) {
	int maximum = 101;
	int minimum = 0;
	int middle = 50;
	while (true)
	{
		try{
			box.GuessNumber(middle);
		}
		catch (const ExceptionLess& exception) {
			maximum = middle;
			middle -= abs(middle-minimum)/2;
		}
		catch (const ExceptionGreater& exception) {
			minimum = middle;
			middle += abs(maximum - middle) / 2;

		}
		catch (const ExceptionEqual& exception) {
			return middle;
		}
	}
}

int main()
{
	BlackBox a;
	cout << guess(a);
}