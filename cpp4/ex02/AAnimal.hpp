#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const & copy);
		AAnimal & operator=(AAnimal const & other);
		virtual ~AAnimal();

		std::string getType() const;
		virtual void makeSound() const = 0;

	protected:
		std::string	type;

};

#endif