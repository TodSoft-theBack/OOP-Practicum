#include <iostream>
#include "Matrix.h"

int main()
{

	int memeArr[] =
	{	
		0, 6
	};

	Matrix meme(memeArr, 1, 2);

	std::cout << meme << std::endl;

	int pepeArr[] =
	{
		1,
		0,
	};
	Matrix pepe(pepeArr, 2, 1);

	std::cout << pepe << std::endl;

	std::cout << meme * pepe << std::endl;
}