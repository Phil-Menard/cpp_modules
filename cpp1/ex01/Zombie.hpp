#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce();
	void	setName(std::string name);

private:
	std::string _name;
};

#endif