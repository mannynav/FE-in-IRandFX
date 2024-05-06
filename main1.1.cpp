
//Exercise 1.1 - write an interchange() function that exchanges two variables.

#include <iostream>
#include <ostream>

void interchange(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}





int main()
{
	int x = 6;
	int y = 9;

	interchange(x, y);

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;

}