#include <iostream>
#include "Serializer.hpp"

int	main() 
{
	Data	d;
	d.id		= 42;
	d.name		= "Adri";
	d.rating	= 9.9;

	std::cout << "Original pointer  : " << &d << std::endl;
	std::cout << "  id = " << d.id
	          << ", name = " << d.name
	          << ", rating = " << d.rating << std::endl;

	uintptr_t	raw = Serializer::serialize(&d);
	std::cout << "Serialized value  : " << raw << std::endl;

	Data *		copy = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr  : " << copy << std::endl;
	std::cout << "  id = " << copy->id
	          << ", name = " << copy->name
	          << ", rating = " << copy->rating << std::endl;

	std::cout << "\nSame address? "
	          << (copy == &d ? "yes ✅" : "no ❌") << std::endl;
	return 0;
}

