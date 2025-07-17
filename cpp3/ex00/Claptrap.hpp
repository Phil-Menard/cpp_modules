#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class Claptrap
{
	public:
		Claptrap(std::string name);
		Claptrap(Claptrap const & other);
		~Claptrap();
		Claptrap & operator=(Claptrap const & other);

		std::string	getName() const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		_name;
		int				_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		void displayNotEnoughEnergy(std::string action) const;
};

#endif