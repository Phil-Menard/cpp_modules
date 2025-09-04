#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const & copy);
		PmergeMe & operator=(PmergeMe const & other);
		~PmergeMe();

		void algo(std::string str);

	private:
		std::vector<int> sequenceV;
		std::vector<int> smallV;
		std::vector<std::pair<int, int> > pairsV;

		std::deque<int> sequenceD;
		std::deque<int> smallD;
		std::deque<std::pair<int, int> > pairsD;

		void fillSequence(std::string str);
};

#endif