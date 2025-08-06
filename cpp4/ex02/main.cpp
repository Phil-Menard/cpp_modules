#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	int n = 10;
	AAnimal *animals[n];

	//CREATING THE OBJECTS IN ANIMAL ARRAY
	for (int i = 0; i < n; i++)
	{
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
	
	std::cout << std::endl;

	//MAKING DEEP COPY
	Cat cat;
	std::cout << std::endl;
	Cat cat2(cat);
	std::cout << std::endl;
	Cat cat3 = cat2;
	cat.makeSound();
	cat2.makeSound();
	cat3.makeSound();
	
	std::cout << std::endl;

	//DOES NOT WORK AS AANIMAL IS AN ABSTRACT CLASS
	// const AAnimal *animal = new AAnimal();
	
	return 0;
}
