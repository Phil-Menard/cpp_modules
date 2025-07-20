#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class Claptrap
{
	public:
		Claptrap();
		Claptrap(std::string name);
		Claptrap(std::string name, int hitPoints, unsigned int energy, unsigned int damage);
		Claptrap(Claptrap const & other);
		Claptrap & operator=(Claptrap const & other);
		~Claptrap();

		std::string	getName() const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		int				_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		void displayNotEnoughEnergy(std::string action) const;
};

#endif