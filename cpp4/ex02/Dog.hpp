#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const & copy);
		Dog & operator=(Dog const & other);
		~Dog();

		virtual void makeSound() const;

	private:
		Brain *brain;
};

#endif