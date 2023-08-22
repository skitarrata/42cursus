#include <string>
#include <iostream>
#include <ctime>

struct Data
{
	int nb;
};

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data*		data = new Data;
	Data*		data2;
	uintptr_t	raw = 0;
 
	data->nb = 15;
 	raw = serialize(data);
	data2 = deserialize(raw);
	std::cout << "Numero: " << data2->nb << std::endl;
	delete data;
	return 0;
}