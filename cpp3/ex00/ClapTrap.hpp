#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & other);
		ClapTrap & operator=(ClapTrap const & other);
		~ClapTrap();

		std::string	getName() const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	displayEnergy();

	private:
		std::string		_name;
		int				_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		void displayNotEnoughEnergy(std::string action) const;
};

#endif