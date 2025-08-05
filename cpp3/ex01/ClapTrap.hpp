#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hitPoints, unsigned int energy, unsigned int damage);
		ClapTrap(ClapTrap const & other);
		ClapTrap & operator=(ClapTrap const & other);
		~ClapTrap();

		std::string	getName() const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	displayEnergy();

	protected:
		std::string		_name;
		int				_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		void displayNotEnoughEnergy(std::string action) const;
};

#endif