#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	protected:
		std::string _type;

	public:
		Cure();
		Cure(Cure const & copy);
		Cure & operator=(Cure const & other);
		~Cure();

		std::string const & getType() const; //Returns the materia type
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif