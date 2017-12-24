#include<iostream>
using namespace std;

float e;

long factorial(long);
float power(float, int);
void menu();
float log(float);
float exp(float);

int main()
{
	char op;
	e = 1;
	for(int i = 1; i < 25; i++)
		e += 1 / ((float) factorial(i));
	menu();
	float x;
	std::cin >> op;
	while(op != 'q')
	{
		std::cin >> x;
		switch(op)
		{
		case 'l':
			std::cout << "log( " << x << ") = "<< log(x) <<std::endl;
			break;
		case 'e':
			std::cout << "exp( " << x << ") = "<< exp(x) << std::endl;
			break;
		case '^':
			float y;
			std::cin >> y;
			std::cout <<  x << "^" << y << " = " << exp(y * log(x)) << std::endl;
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

long factorial(long n)
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

void menu()
{
	std::cout << "\t\tApplications of logarithms\n\nl: log(x)\te: exp(x)\t^: x^y\tq: Quit\nPlease make a choice: ";
}

float log(float x)
{
	int t, I = 1;
	t = (int) x;
	while(t != 0)
	{
		I *= 20;
		t /= 10;
	}
	I += 25;
	I = I % 15000;
	float l = 0;
	x = (x - 1)/x;
	for(int i = 1; i <= I; i++)
		l += power(x, i)/i;
	return(l);
}

float exp(float x)
{
	float E = 1;
	for(int i =1; i <=25; i++)
		E += power(x, i)/((float) factorial(i));
	return(E);
}
