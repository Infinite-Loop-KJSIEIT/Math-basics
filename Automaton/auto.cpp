#include<iostream>
#include<string>
using namespace std;

int **chart;

void automaton();
int q(int, int);

int main()
{
	automaton();
	string S;
	cin >> S;
	int s = 0;
	for(int i = 0; i < S.length(); i++)
	{
		switch(S[i])
		{
		case 'a':
			s = q(s, 1);
			break;
		case 'b':
			s = q(s, 2);
			break;
		default:
			s = q(s, 0);
			break;
		}
	}
	if(s == 2) //Accepted state
		cout << "String is valid." << std::endl;
	else
		cout << "String is invalid." << std::endl;
	return(0);
}

void automaton()
{
	chart = new int*[3];	//chart[state][input] = new state;
	for(int i = 0; i < 3; i++)
		chart[i] = new int[3];
	//Describe each transition.
	chart[0][0] = 0;
	chart[0][1] = 1;
	chart[0][2] = 0;
	chart[1][0] = 0;
	chart[1][1] = 0;
	chart[1][2] = 2;
	chart[2][0] = 0;
	chart[2][1] = 1;
	chart[2][2] = 0;
}

int q(int s, int i)
{
	return(chart[s][i]);
}
