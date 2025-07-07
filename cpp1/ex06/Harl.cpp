#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout <<  "I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! " << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	static const Harl::levels arr[4] = {
		{"DEBUG", 1},
		{"INFO", 2},
		{"WARNING", 3},
		{"ERROR", 4}
	};

	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		if (level == arr[i]._level)
		{
			index = arr[i]._index;
			break;
		}
	}

	switch (index)
	{
		case 1:
			this->debug();
			std::cout << std::endl;
		case 2:
			this->info();
			std::cout << std::endl;
		case 3:
			this->warning();
			std::cout << std::endl;
		case 4:
			this->error();
			std::cout << std::endl;
	}
	if (index == 0)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
