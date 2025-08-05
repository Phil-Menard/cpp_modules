#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
/**========================================================================
 *!                           DYNAMIC POLYMORPHISM
 *========================================================================**/
	//CREATE OBJECTS
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;

	//DISPLAY OBJECTS TYPE
	std::cout << "Animal type : " << animal->getType() << " " << std::endl;
	std::cout << "Dog type    : " << dog->getType() << " " << std::endl;
	std::cout << "Cat type    : " << cat->getType() << " " << std::endl;

	std::cout << std::endl;

	//DISPLAY OBJECTS SOUND
	std::cout << "Animal sound : ";
	animal->makeSound();
	std::cout << "Dog sound    : ";
	dog->makeSound();
	std::cout << "Cat sound    : ";
	cat->makeSound();

	std::cout << std::endl;

	//FREE MEMORY
	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl;
/**========================================================================
 *!                        STATIC BINDING (liaison statique)
 *========================================================================**/
	//CREATE OBJECTS
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;

	//DISPLAY OBJECTS TYPE
	std::cout << "wrongAnimal type : " << wrongAnimal->getType() << " " << std::endl;
	std::cout << "wrongCat type    : " << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl;

	//DISPLAY OBJECTS SOUND
	std::cout << "wrongAnimal sound : ";
	wrongAnimal->makeSound();
	std::cout << "wrongCat sound    : ";
	wrongCat->makeSound();

	std::cout << std::endl;

	//FREE MEMORY
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}