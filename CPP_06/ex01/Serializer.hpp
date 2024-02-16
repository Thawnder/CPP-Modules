#pragma once

# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const & base);
		Serializer & operator=(Serializer const & base);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};