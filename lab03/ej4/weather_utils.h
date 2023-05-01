#ifndef WEATHER_UTILS
#define WEATHER_UTILS
#include <stdbool.h>
#include "array_helpers.h"

int min_temp_hist(WeatherTable weather);

void max_temp_year(WeatherTable weather, int array[YEARS]);

void max_pres_month(WeatherTable weather, unsigned int array[YEARS]);

#endif /* WEATHER_UTILS */