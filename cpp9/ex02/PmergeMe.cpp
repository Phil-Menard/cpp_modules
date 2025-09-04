#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	*this = copy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
	if (this != &other)
	{
		this->sequenceV = other.sequenceV;
		this->sequenceV = other.sequenceV;
		this->smallV = other.smallV;
		this->pairsV = other.pairsV;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

template<typename T>
void displaySequence(T sequence)
{
	std::cout << "Sequence : ";
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void displayPairs(T pairs)
{
	std::cout << "Pairs : ";
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << "[" << pairs[i].first << "," << pairs[i].second << "] ";
	std::cout << std::endl;
}

template<typename T>
void displaySmall(T small)
{
	std::cout << "Smalls : ";
	for (size_t i = 0; i < small.size(); i++)
		std::cout << small[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void displayVectors(T sequence, T small)
{
	displaySequence(sequence);
	displaySmall(small);
}

void PmergeMe::fillSequence(std::string str)
{
	size_t i = 0;
	while ((str[i] <= 9 && str[i] >= 13) || str[i] == ' ')
		i++;
	for (; i < str.size(); i++)
	{
		size_t j = i;
		for (; j < str.size() && str[j] != ' '; j++);
		std::string number = str.substr(i, j);
		int a = std::atoi(number.c_str());
		if (a < 0)
		{
			this->sequenceD.clear();
			this->sequenceV.clear();
			return;
		}
		this->sequenceV.push_back(a);
		this->sequenceD.push_back(a);
		i = j;
	}
}

template<typename T, typename P>
void comparePairs(T & sequence, P & pairs, T & small)
{
	while(!pairs.empty())
	{
		if (pairs[0].first > pairs[0].second)
		{
			sequence.push_back(pairs[0].first);
			small.push_back(pairs[0].second);
		}
		else
		{
			sequence.push_back(pairs[0].second);
			small.push_back(pairs[0].first);
		}
		pairs.erase(pairs.begin(), pairs.begin()+1);
	}
}

template<typename T, typename P>
void createPairs(T & v, P & pairs, T & small)
{
	for(size_t i = 0; i < v.size(); i+=2)
	{
		if (i+1 < v.size())
			pairs.push_back(std::pair<int, int>(v[i], v[i+1]));
		else
			small.push_back(v[i]);
	}
	v.clear();
	displayPairs(pairs);
}

template<typename T, typename P>
void sortSequence(T & sequence, P & pairs, T & small)
{
	std::cout << "---------SORT SEQUENCE----------" << std::endl;
	createPairs(sequence, pairs, small);
	comparePairs(sequence, pairs, small);
	displayVectors(sequence, small);
	if (sequence.size() > 1)
		sortSequence(sequence, pairs, small);
}

template<typename T>
int binarySearch(int a, T v)
{
	int begin = 0;
	int end = v.size() - 1;
	while (begin <= end)
	{
		int middle = (begin + end) / 2;
		if (a > v[middle])
			begin = middle + 1;
		else if (a < v[middle])
			end = middle - 1;
		else
			return middle;
	}
	return begin;
}

template<typename T>
void insertSmalls(T & sequence, T & small)
{
	T jacobsthal;
	jacobsthal.push_back(1);
	if (small.size() > 3)
	{
		jacobsthal.push_back(3);
		//fill jacobsthal sequence
		while (1)
		{
			int a = jacobsthal[jacobsthal.size()-1] + (jacobsthal[jacobsthal.size()-2] * 2);
			if (a < static_cast<int>(small.size()))
				jacobsthal.push_back(a);
			else
				break;
		}
	}
	//insert smalls based on jacobsthal sequence into sequence vector
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		int index = binarySearch(small[jacobsthal[i]], sequence);
		typename T::iterator it = sequence.begin();
		sequence.insert(it + index, small[jacobsthal[i]]);
		displayVectors(sequence, small);
		std::cout << std::endl;
	}
	//remove smalls based on jacobsthal sequence vector
	for (int i = jacobsthal.size() - 1; i >= 0 ; i--)
	{
		typename T::iterator its = small.begin();
		small.erase(its + jacobsthal[i]);
	}
	displayVectors(sequence, small);
	std::cout << std::endl;

	//insert rest of smalls in reverse order
	for (int i = small.size() - 1; i >= 0; i--)
	{
		int index = binarySearch(small[i], sequence);
		typename T::iterator it = sequence.begin();
		sequence.insert(it + index, small[i]);
		displayVectors(sequence, small);
		std::cout << std::endl;
	}
	small.clear();
	displayVectors(sequence, small);
}

void PmergeMe::algo(std::string str)
{
	this->fillSequence(str);
	if (this->sequenceV.size() == 0)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	if (this->sequenceV.size() == 1)
	{
		displayVectors(this->sequenceV, this->smallV);
		displayVectors(this->sequenceD, this->smallD);
		return;
	}
	//--------------VECTORS--------------
	displayVectors(this->sequenceV, this->smallV);
	std::cout << std::endl;
	
	//create pairs and put lowers and biggests numbers in their vectors
	createPairs(this->sequenceV, this->pairsV, this->smallV);
	comparePairs(this->sequenceV, this->pairsV, this->smallV);
	displayVectors(this->sequenceV, this->smallV);

	//sort sequence recursively until there is only the biggest number in it
	sortSequence(this->sequenceV, this->pairsV, this->smallV);

	std::cout << std::endl;

	//insert numbers from small into sequence
	insertSmalls(this->sequenceV, this->smallV);


	//-------------DEQUE--------------
	displayVectors(this->sequenceV, this->smallV);
	std::cout << std::endl;
	
	//create pairs and put lowers and biggests numbers in their vectors
	createPairs(this->sequenceD, this->pairsD, this->smallD);
	comparePairs(this->sequenceD, this->pairsD, this->smallD);
	displayVectors(this->sequenceD, this->smallD);

	//sort sequence recursively until there is only the biggest number in it
	sortSequence(this->sequenceD, this->pairsD, this->smallD);

	std::cout << std::endl;

	//insert numbers from small into sequence
	insertSmalls(this->sequenceD, this->smallD);

}
