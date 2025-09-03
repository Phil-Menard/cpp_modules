#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(std::string str)
{
	fillSequence(str);
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	*this = copy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
	if (this != &other)
	{
		this->sequence = other.sequence;
		this->sequence = other.sequence;
		this->small = other.small;
		this->pairs = other.pairs;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

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
		this->sequence.push_back(std::atoi(number.c_str()));
		i = j;
	}
}

void PmergeMe::comparePairs()
{
	while(!this->pairs.empty())
	{
		if (this->pairs[0].first > this->pairs[0].second)
		{
			this->sequence.push_back(this->pairs[0].first);
			this->small.push_back(this->pairs[0].second);
		}
		else
		{
			this->sequence.push_back(this->pairs[0].second);
			this->small.push_back(this->pairs[0].first);
		}
		this->pairs.erase(this->pairs.begin(), this->pairs.begin()+1);
	}
}

void PmergeMe::createPairs(std::vector<int> & v)
{
	for(size_t i = 0; i < v.size(); i+=2)
	{
		if (i+1 < v.size())
			this->pairs.push_back(std::pair<int, int>(v[i], v[i+1]));
		else
			this->small.push_back(v[i]);
	}
	v.clear();
	displayPairs();
}

void PmergeMe::sortBig()
{
	std::cout << "---------SORT BIG----------" << std::endl;
	createPairs(this->sequence);
	comparePairs();
	displayVectors();
	if (this->sequence.size() > 1)
		sortBig();
}

int binarySearch(int a, std::vector<int> v)
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

void PmergeMe::insertSmalls()
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	if (this->sequence.size() > 3)
	{
		jacobsthal.push_back(3);
		//fill jacobsthal sequence
		while (1)
		{
			int a = jacobsthal[jacobsthal.size()-1] + (jacobsthal[jacobsthal.size()-2] * 2);
			if (a < static_cast<int>(this->small.size()))
			jacobsthal.push_back(a);
			else
			break;
		}
	}
	//insert smalls based on jacobsthal sequence into sequence vector
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		int index = binarySearch(this->small[jacobsthal[i]], this->sequence);
		std::vector<int>::iterator it = this->sequence.begin();
		this->sequence.insert(it + index, this->small[jacobsthal[i]]);
		displayVectors();
		std::cout << std::endl;
	}
	//remove smalls based on jacobsthal sequence vector
	for (int i = jacobsthal.size() - 1; i >= 0 ; i--)
	{
		std::vector<int>::iterator its = this->small.begin();
		this->small.erase(its + jacobsthal[i]);
	}
	displayVectors();
	//insert rest of smalls
	for (size_t i = 0; i < this->small.size(); i++)
	{
		int index = binarySearch(this->small[i], this->sequence);
		std::vector<int>::iterator it = this->sequence.begin();
		this->sequence.insert(it + index, this->small[i]);
		displayVectors();
		std::cout << std::endl;
	}
	this->small.clear();
	displayVectors();
}

void PmergeMe::algo()
{
	if (this->sequence.size() == 0)
	{
		std::cerr << "No numbers detected." << std::endl;
		return;	
	}
	if (this->sequence.size() == 1)
	{
		displayVectors();
		return;	
	}
	//create pairs and put lowers and biggests numbers in their vectors
	displayVectors();

	std::cout << std::endl;
	
	createPairs(this->sequence);
	comparePairs();
	displayVectors();

	//sort sequence recursively until there is only the biggest number in it
	sortBig();

	std::cout << std::endl;

	//insert numbers from small into sequence recursively
	insertSmalls();
}

void PmergeMe::displayVectors()
{
	displaySequence();
	displaySmall();
}

void PmergeMe::displaySequence()
{
	std::cout << "Sequence : ";
	for (size_t i = 0; i < this->sequence.size(); i++)
		std::cout << this->sequence[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displayPairs()
{
	std::cout << "Pairs : ";
	for (size_t i = 0; i < this->pairs.size(); i++)
		std::cout << "[" << this->pairs[i].first << "," << this->pairs[i].second << "] ";
	std::cout << std::endl;
}

void PmergeMe::displaySmall()
{
	std::cout << "Smalls : ";
	for (size_t i = 0; i < this->small.size(); i++)
		std::cout << this->small[i] << " ";
	std::cout << std::endl;
}
