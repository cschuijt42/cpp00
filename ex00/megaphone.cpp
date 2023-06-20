#include <iostream>

using std::string, std::cout, std::endl, std::toupper;

int main(int ac, char **av)
{
	string str;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			for (size_t i = 0; i < str.length(); i++)
				cout << (char) toupper(str[i]);
		}
	}
	else
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	cout << endl;

	return 0;
}
