#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	int n = 10;
	Animal *animals[n];

	//CREATING THE OBJECTS IN ANIMAL ARRAY
	for (int i = 0; i < n; i++)
	{
		std::cout << std::endl;
		if (i < n / 2)
		{
			std::cout << "Creating a new dog object." << std::endl;
			animals[i] = new Dog();
		}
		else
		{
			std::cout << "Creating a new cat object." << std::endl;
			animals[i] = new Cat();
		}
		std::cout << std::endl;
	}

	//DELETING THE OBJECTS IN ANIMAL ARRAY TO FREE MEMORY
	for (int i = 0; i < n; i++)
	{
		delete animals[i];
	}

	return 0;
}