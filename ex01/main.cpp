#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t ptr;
	Data* raw;

	data.color = "purple";
	ptr = Serializer::serialize(&data);
	raw = Serializer::deserialize(ptr);

	std::cout<<"original: "<<&data<<std::endl;
	std::cout<<"serialized: "<<ptr<<std::endl;
	std::cout<<"deserialized: "<<raw<<std::endl;

	if (&data == raw)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;

	return 0;
}