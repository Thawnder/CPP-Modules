# include "Serializer.hpp"

int main(void)
{
	Data test = {2};

	std::cout << test.nb << std::endl;

	uintptr_t res1 = Serializer::serialize(&test);

	std::cout << res1 << std::endl;

	Data *res2 = Serializer::deserialize(res1);

	if (res2 == &test)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;

	return 0;
}