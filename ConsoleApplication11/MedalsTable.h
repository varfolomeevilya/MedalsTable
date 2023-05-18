#pragma once
#include<fstream>
#include "MedalRow.h"
class MedalsTable
{
public:
	static const int maxSize{ 10 };
	 int *ptr;
private:
	MedalRow medalRows[MedalsTable::maxSize];
	int size;
	int findCountry(const char* country)const 
	{
		for (int i{ 0 }; i < size; ++i) 
		{
			if (strcmp(medalRows[i].getCountry(), country) == 0) 
			{
				return i;
			}
		}
		return -1;
	}
    
public:
	MedalsTable() : size{ 0 } {};
	MedalsTable() : MedalsTable() {};
	MedalsTable(){}
	MedalRow& operator[](const char* country)
	{
		int idx{ findCountry(country) };
		if (idx == -1)
		{
			assert(size < MedalsTable::maxSize and
				"Table is FULL!");
			idx = size++;
			medalRows[idx].setCountry(country);
		}
		return medalRows[idx];
	}
	const MedalRow& operator[](const char* country)const
	{
		int idx{ findCountry(country) };
		assert(idx != -1 and "Country not found on const "
			"table");
		return medalRows[idx];
	}
	friend std::ostream& operator<<(std::ostream out, MedalsTable& medalstable)
	{
		for (int i{ 0 }; i < medalstable.size; ++i)
		{
			out<<medalstable.medalRows[i];
			
		}
		return out;
	}
	const int operator()(const char* country)
	{
		int max=0;
		int idx = findCountry(country);
		if (idx!=-1) 
		{
			const int* row = medalRows[idx].getMedals();
			if (row[0] > row[1] && row[0] > row[2]) return row[0];
			if (row[1] > row[0] && row[1] > row[2]) return row[1];
			if (row[2] > row[0] && row[2] > row[1])return row[2];
			else return -1;
		}
	}
};
//this[idx][MedalRow::GOLD]
