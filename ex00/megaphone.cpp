#include <iostream>

int main(int ac, char **av)
{
	std::string str;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			for (size_t i = 0; i < str.length(); i++)
				std::cout << (char) std::toupper(str[i]);
			
			// Put a space in between if we have multiple arguments
			if (ac > 2 && i < ac - 1)
				std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << std::endl;

	return 0;
}
