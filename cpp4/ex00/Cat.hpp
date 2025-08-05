#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & copy);
		Cat & operator=(Cat const & other);
		~Cat();

	virtual void makeSound() const;
};

#endif