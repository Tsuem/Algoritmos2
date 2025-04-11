/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;

    /* Completar acá! */
    int items_leidos = fscanf(file, "%d %d %d %u %u %u",
      &weather._average_temp,
      &weather._max_temp,
      &weather._min_temp,
      &weather._pressure,
      &weather._moisture,
      &weather._rainfall);

    if (items_leidos != 6) {
      fprintf(stderr, "Error leyendo los datos del clima. Formato incorrecto.\n");
      exit(EXIT_FAILURE); // Termina el programa si hay error
    }

    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
