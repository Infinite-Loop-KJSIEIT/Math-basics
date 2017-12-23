#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		float s, r = 1;
		cin >> s;
		float ratio =s/r;
		while((ratio < 0.9999999 * r) || (ratio > 1.0000001 * r))
		{
			r = (r + ratio)/2;
			ratio = s/r;
		}
		cout << r << std::endl;
	}
	return(0);
}
