

#include "rand_gen.hpp"

#include <iostream>


int main()
{
	auto rand_gen = RAND_GEN::make();
	rand_gen->set_range(1, 10000);

	for (unsigned i = 0; i < 20; ++i)
	{
		if (i != 0)
		{
			std::cout << std::endl;
		}
		std::cout << rand_gen->get();
	}
	std::cout << std::endl;

	return 0;
}
