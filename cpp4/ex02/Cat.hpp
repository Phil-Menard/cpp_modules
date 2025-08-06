#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat const & copy);
		Cat & operator=(Cat const & other);
		~Cat();

	virtual void makeSound() const;

	private:
		Brain *brain;
};

#endif