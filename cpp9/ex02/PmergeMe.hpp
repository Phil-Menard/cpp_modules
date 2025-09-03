#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(std::string str);
		PmergeMe(PmergeMe const & copy);
		PmergeMe & operator=(PmergeMe const & other);
		~PmergeMe();

		void algo();

	private:
		std::vector<int> sequence;
		std::vector<int> big;
		std::vector<int> small;
		std::vector<std::pair<int, int> > pairs;

		void fillSequence(std::string str);
		void displaySequence();
		void displayPairs();
		void displaySmall();
		void displayVectors();
		void createPairs(std::vector<int> & v);
		void comparePairs();
		void sortBig();
		void insertSmalls();
};

#endif