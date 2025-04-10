#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <limits>

class	BitcoinExchange
{
public:

	class	Date
	{
	public:
		size_t y;
		size_t m;
		size_t d;

		Date(std::string str_date);

		bool operator>(const Date &to_compare) const;
		bool operator<(const Date &to_compare) const;
		bool operator>=(const Date &to_compare) const;
		bool operator<=(const Date &to_compare) const;
		bool operator==(const Date &to_compare) const;
		bool operator!=(const Date &to_compare) const;
	};

/*--------------------CONSTRUCTORS-------------------*/

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &model);
	BitcoinExchange &operator=(const BitcoinExchange &model);

/*--------------------DESTRUCTORS--------------------*/

	~BitcoinExchange();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void	getData();
	void	calculate(std::string input_name);

private:
	std::map<Date, float>	data;
};
	std::ostream &operator<<(std::ostream &ret,const BitcoinExchange::Date &date);

#endif
