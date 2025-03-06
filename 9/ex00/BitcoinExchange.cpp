#include "BitcoinExchange.hpp"

/*--------------------------------------------------------------*/
/*							DATE_LOGIC							*/
/*--------------------------------------------------------------*/


bool	BitcoinExchange::Date::operator>(const Date &to_compare) const
{
	if (y > to_compare.y)
		return true;
	if (y == to_compare.y)
	{
		if (m > to_compare.m)
			return true;
		if (m == to_compare.m)
		{
			if (d > to_compare.d)
				return true;
		}
	}
	return false;
}

bool	BitcoinExchange::Date::operator<(const Date &to_compare) const
{
	if (y < to_compare.y)
		return true;
	if (y == to_compare.y)
	{
		if (m < to_compare.m)
			return true;
		if (m == to_compare.m)
		{
			if (d < to_compare.d)
				return true;
		}
	}
	return false;
}

bool	BitcoinExchange::Date::operator>=(const Date &to_compare) const
{
	if (y >= to_compare.y)
		return true;
	if (y == to_compare.y)
	{
		if (m >= to_compare.m)
			return true;
		if (m == to_compare.m)
		{
			if (d >= to_compare.d)
				return true;
		}
	}
	return false;
}

bool	BitcoinExchange::Date::operator<=(const Date &to_compare) const
{
	if (y <= to_compare.y)
		return true;
	if (y == to_compare.y)
	{
		if (m <= to_compare.m)
			return true;
		if (m == to_compare.m)
		{
			if (d <= to_compare.d)
				return true;
		}
	}
	return false;
}

bool	BitcoinExchange::Date::operator==(const Date &to_compare) const
{
	if (y == to_compare.y
	&& m == to_compare.m
	&& d == to_compare.d)
		return true;
	return false;
}

bool	BitcoinExchange::Date::operator!=(const Date &to_compare) const
{
	if (y != to_compare.y
	|| m != to_compare.m
	|| d != to_compare.d)
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &ret, const BitcoinExchange::Date &date)
{
	if (date.y < 1000)
		ret << 0;
	if (date.y < 100)
		ret << 0;
	if (date.y < 10)
		ret << 0;
	ret << date.y << "-";
	if (date.m < 10)
		ret << 0;
	ret << date.m << "-";
	if (date.d < 10)
		ret << 0;
	ret << date.d;
	return(ret);
}

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

BitcoinExchange::BitcoinExchange() {
	getData();
}

BitcoinExchange::Date::Date(std::string str_date)
{
	size_t f_del = str_date.find('-');
	size_t s_del = str_date.find_last_of('-');

	y = atoi(str_date.substr(0, f_del).c_str());
	m = atoi(str_date.substr(f_del, s_del).c_str() + 1);
	d = atoi(str_date.substr(s_del, str_date.npos).c_str() + 1);

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &model) {
	(void)model;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &model) {
	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

BitcoinExchange::~BitcoinExchange() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

bool	tryDate(std::string str_date)
{
	try
	{
		boost::gregorian::date date(boost::gregorian::from_simple_string(str_date));
		(void)date;
		return true;
	}
	catch(...)
	{
		return false;
	}
}

void	BitcoinExchange::getData()
{
	std::ifstream data_raw("data.csv");
	if(!data_raw.is_open())
		throw std::runtime_error("data not found");

	std::string buffer;
	std::getline(data_raw, buffer);
	for (; std::getline(data_raw, buffer);)
	{
		Date date(buffer.substr(0, buffer.find(',')));
		float rate = atof(buffer.substr(buffer.find(','), buffer.npos).c_str() + 1);
		data.insert(std::make_pair(date, rate));
	}
	data_raw.close();
}
void	BitcoinExchange::calculate(std::string input_name)
{
	std::ifstream input_raw(input_name.c_str());
	if(!input_raw.is_open())
		throw std::runtime_error("input not found");

	std::string buffer;
	std::getline(input_raw, buffer);
	for (; std::getline(input_raw, buffer);)
	{
		if (buffer.find('|') == buffer.npos || !tryDate(buffer.substr(0, buffer.find(' '))))
		{
			std::cout << "Error: bad input => " << buffer << std::endl;
		}
		else
		{
			Date date(buffer.substr(0, buffer.find(' ')));
			float	number = atof(buffer.substr(buffer.find_last_of(' '), buffer.npos).c_str() + 1);
			if (number < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (number >= std::numeric_limits<int>::max())
				std::cout << "Error: too large a number." << std::endl;
			else
			{
				if (data.find(date) != data.end())
					std::cout << date << " => " << number << " = " << data.find(date)->second * number <<std::endl;
				else
					std::cout << date << " => " << number << " = " << (--data.lower_bound(date))->second * number <<std::endl;
			}
		}
	}
	input_raw.close();
}