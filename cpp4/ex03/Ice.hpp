#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria
{
	protected:
		std::string _type;

	public:
		Ice();
		Ice(Ice const & copy);
		Ice & operator=(Ice const & other);
		~Ice();

		std::string const & getType() const; //Returns the materia type
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif