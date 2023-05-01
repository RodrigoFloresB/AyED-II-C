#include "weather_utils.h"
#include "array_helpers.h"
#include <stdio.h>

int min_temp_hist(WeatherTable weather){
	int min_aux = weather[0][0][0]._min_temp;

	for (unsigned int year = 0; year < YEARS; year++)
	{
		for (unsigned int month = 0; month < MONTHS; month++)
		{
			for (unsigned int day = 0; day < DAYS; day++)
			{
				if (weather[year][month][day]._min_temp < min_aux)
				{
					min_aux = weather[year][month][day]._min_temp;
				}
			}
		}
	}

	return min_aux;	
}

void max_temp_year(WeatherTable weather, int a[YEARS]){

	for (unsigned int year = 0; year < YEARS; year++)
	{
		int max_aux = 0;
		
		for (unsigned int month = 0; month < MONTHS; month++)
		{
			for (unsigned int day = 0; day < DAYS; day++)
			{
				if (weather[year][month][day]._max_temp > max_aux)
				{
					max_aux = weather[year][month][day]._max_temp;
				}
			}
		}
	
		a[year + FST_YEAR] = max_aux;
	}
}

void max_pres_month(WeatherTable weather, unsigned int a[YEARS]){

	for (unsigned int year = 0; year < YEARS; year++)
	{	
		for (unsigned int month = 0; month < MONTHS; month++)
		{
			unsigned int maxMonth = 0, maxDay = 0;

			for (unsigned int day = 0; day < DAYS; day++)
			{
				if (weather[year][month][day]._rainfall > maxDay)
				{
					maxDay = weather[year][month][day]._rainfall;
				}
			}
			
			if (maxDay > maxMonth)
			{
				a[year + FST_YEAR] = month + 1;
				maxMonth = maxDay;
			}
		}
	}
}
