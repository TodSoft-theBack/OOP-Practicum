#include <iostream>
#include <fstream>

const char RES_FILE[] = "result.txt";

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::ofstream saveStream(RES_FILE);
	if (!saveStream.is_open())
		return -1;
	saveStream << a + b << " " << a - b << std::endl;
	saveStream.close();

	std::ifstream reader(RES_FILE);
	if (!reader.is_open())
		return -1;

	int sum, diff;
	reader >> sum >> diff;

	int orgA = (sum + diff)/2, orgB = (sum - diff)/2;
	reader.close();

	std::cout << sum << " " << diff << " " << orgA << " " << orgB << std::endl;
}