#include<iostream>
#include<iomanip>
using namespace std;

typedef unsigned long long ull;

float pi;

ull factorial(ull);
float power(float, int);
float mod(float);
void menu();
float sin(float);
float cos(float);

int main()
{
	char op;
	pi = 0;
	float t = 1;
	int C, i;
	C = i = 1;
	while(((t-pi) < -0.000001) || ((t-pi) > 0.000001))
	{
		int coeff = ((C++ % 2) == 0) ? -1 : 1;
		t = pi;
		pi += (float) coeff / (float) i;
		i+=2;
	}
	pi *= 4;
	menu();
	float x, c;
	std::cin >> op;
	while(op != 'q')
	{
		std::cin >> x;
		float X = x;
		while(x >= 360)
			x -=360;
		x *= (pi/180.);		
		switch(op)
		{
		case 's':
			std::cout << "sin(" << X << ") = "<< std::setprecision(3) << sin(x) <<std::endl;
			break;
		case 'c':
			std::cout << "cos(" << X << ") = "<< std::setprecision(3) << cos(x) << std::endl;
			break;
		case 't':
			c = cos(x);
			if(c != 0)
				std::cout << "tan(" << X << ") = "<< std::setprecision(3) << sin(x)/c << std::endl;
			else
				std::cout << "tan(" << X << ") = ∞"<< std::endl;
			break;
		default:
			break;
		}
		cin.ignore();
		menu();
		std::cin >> op;
	}
	return(0);
}

ull factorial(ull n)
{
	if(n == 1)
		return(n);
	else
		return(n * factorial(n-1));
}

float power(float x, int n)
{
	float p = 1;
	for(int i = 0; i < n; i++)
		p *= x;
	return(p);
}

float mod(float x)
{
	if(x < 0)
		return(-x);
	return(x);
}

void menu()
{
	std::cout << "\t\tTriginometric ratios\n\ns: sin(x)\tc: cos(x)\tt: tan(x)\tq: Quit\nThe operand should be in degrees.\nPlease make a choice: ";
}

float cos(float x)
{
	if(x > 3.66)
		return(2 * power(cos(x/2), 2) - 1);
	float c, t;
	c =1;
	t = 0;
	int C = 1;
	for(int i = 2; ((t - c) < -0.000001) || ((t - c) > 0.000001); i+=2)
	{
		int coeff = ((C++ % 2) == 0) ? 1 : -1;
		t =c;
		c += coeff * power(x, i) / ((float) factorial(i));
	}
	if(mod(c) < 0.0001)
		c = 0;
	return(c);
}

float sin(float x)
{
	if(x > 3.66)
		return(2 * sin(x/2) * cos(x/2));
	float s, t;
	s =0;
	t = 1;
	int C =1;
	for(int i = 1; ((t - s) < -0.000001) || ((t - s) > 0.000001); i+=2)
	{
		int coeff = ((C++ % 2) == 0) ? -1 : 1;
		t =s;
		s += coeff * power(x, i) / ((float) factorial(i));
	}
	if(mod(s) < 0.0001)
		s = 0;
	return(s);
}
