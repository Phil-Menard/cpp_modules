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
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::fillSequence(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		int a = std::atoi(argv[i]);
		int b = a;
		std::string comp;
		if (a == 0)
			comp = "0";
		while (b > 0)
		{
			comp += (b % 10) + '0';
			b /= 10;
		}
		std::reverse(comp.begin(), comp.end());
		if (a < 0 || comp != argv[i])
		{
			this->sequenceD.clear();
			this->sequenceV.clear();
			return;
		}
		this->sequenceV.push_back(a);
		this->sequenceD.push_back(a);
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
}

template<typename T, typename P>
void sortSequence(T & sequence, P & pairs, T & small)
{
	createPairs(sequence, pairs, small);
	comparePairs(sequence, pairs, small);
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
	}
	//remove smalls based on jacobsthal sequence vector
	for (int i = jacobsthal.size() - 1; i >= 0 ; i--)
	{
		typename T::iterator its = small.begin();
		small.erase(its + jacobsthal[i]);
	}

	//insert rest of smalls in reverse order
	for (int i = small.size() - 1; i >= 0; i--)
	{
		int index = binarySearch(small[i], sequence);
		typename T::iterator it = sequence.begin();
		sequence.insert(it + index, small[i]);
	}
	small.clear();
}

void PmergeMe::algo(char **argv)
{
	this->fillSequence(argv);
	if (this->sequenceV.size() < 2)
	{
		std::cerr << "Error" << std::endl;
		return;
	}

	std::cout << "Before : ";
	displaySequence(this->sequenceV);

	clock_t start, end;
	double time;
	//--------------VECTORS--------------
	//create pairs and put lowers and biggests numbers in their vectors
	start = clock();
	createPairs(this->sequenceV, this->pairsV, this->smallV);
	comparePairs(this->sequenceV, this->pairsV, this->smallV);

	//sort sequence recursively until there is only the biggest number in it
	sortSequence(this->sequenceV, this->pairsV, this->smallV);

	//insert numbers from small into sequence
	insertSmalls(this->sequenceV, this->smallV);
	std::cout << "After :  ";
	displaySequence(this->sequenceV);

	end = clock();
	time = static_cast<double>((end - start)) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of 5 elements with std::vector : " << std::fixed << std::setprecision(5) << time << " ms" << std::endl;
	//-------------DEQUE--------------
	//create pairs and put lowers and biggests numbers in their vectors
	start = clock();
	createPairs(this->sequenceD, this->pairsD, this->smallD);
	comparePairs(this->sequenceD, this->pairsD, this->smallD);

	//sort sequence recursively until there is only the biggest number in it
	sortSequence(this->sequenceD, this->pairsD, this->smallD);

	//insert numbers from small into sequence
	insertSmalls(this->sequenceD, this->smallD);
	displaySequence(this->sequenceV);

	end = clock();
	time = static_cast<double>((end - start)) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of 5 elements with std::deque : " << std::fixed << std::setprecision(5) << time << " ms" << std::endl;
}
