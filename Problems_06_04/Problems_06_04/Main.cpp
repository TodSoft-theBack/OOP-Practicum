#include <iostream>
#include "Matrix.h"

int main()
{

	int memeArr[4] =
	{	
		1, 3,
		6, 5
	};

	Matrix meme(memeArr, 2,2);

	std::cout << meme;

	int pepeArr[4] =
	{
		0, 1,
		1, 0
	};
	Matrix pepe(pepeArr, 2, 2);

	std::cout << pepe;

	meme *= pepe;

	std::cout << meme;
}