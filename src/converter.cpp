#include "converter.hpp"

template <typename UnitType>
double UnitConverter::convert(double value, UnitType from, UnitType to)
{
    return fromBaseUnit(toBaseUnit(value, from), to);
}



double UnitConverter::toBaseUnit(double value, LengthUnit unit)
{
    switch (unit) {
        case LengthUnit::Kilometer:  return value * 1000.0;
        case LengthUnit::Meter:      return value;
        case LengthUnit::Centimeter: return value / 100.0;
        case LengthUnit::Millimeter: return value / 1000.0;
        case LengthUnit::Micrometer: return value / 1000000.0;
        case LengthUnit::Nanometer:  return value / 1000000000.0;

        case LengthUnit::Mile:       return value * 1609.35;
        case LengthUnit::Yard:       return value * 0.9144;
        case LengthUnit::Foot:       return value * 0.3048;
        case LengthUnit::Inch:       return value * 0.0254;

        case LengthUnit::Size:       return 0.0;
    }

    return 0.0;
}

double UnitConverter::toBaseUnit(double value, MassUnit unit)
{
    switch (unit) {
        case MassUnit::Metric_Ton:   return value * 1000000.0;
        case MassUnit::Kilogram:     return value * 1000.0;
        case MassUnit::Gram:         return value;
        case MassUnit::Centigram:    return value / 100.0;
        case MassUnit::Milligram:    return value / 1000.0;
        case MassUnit::Microgram:    return value / 1000000.0;

        case MassUnit::Imperial_Ton: return value * 1016046.08;
        case MassUnit::US_Ton:       return value * 907184.0;
        case MassUnit::Pound:        return value * 453.592;
        case MassUnit::Ounce:        return value * 28.3495;

        case MassUnit::Size:         return 0.0;
    }

    return 0.0;
}

double UnitConverter::toBaseUnit(double value, TemperatureUnit unit)
{
    switch (unit) {
        case TemperatureUnit::Kelvin:     return value;
        case TemperatureUnit::Celsius:    return value + 273.15;
        case TemperatureUnit::Fahrenheit: return value * 0.555555555555555 + 255.372222222222222;

        case TemperatureUnit::Size:       return 0.0;
    }

    return 0.0;
}

double UnitConverter::toBaseUnit(double value, AngleUnit unit)
{
    switch (unit) {
        case AngleUnit::Arcsecond:     return value / 3600.0;
        case AngleUnit::Degree:        return value;
        case AngleUnit::Gradian:       return value * 0.9;
        case AngleUnit::Milliradian:   return value * 0.05729577951308232088;
        case AngleUnit::Minute_of_Arc: return value / 60;
        case AngleUnit::Radian:        return value * 57.2957795130823208768;

        case AngleUnit::Size:          return 0.0;
    }

    return 0.0;
}

double UnitConverter::toBaseUnit(double value, DigitalStorageUnit unit)
{
    switch (unit) {
        case DigitalStorageUnit::Bit:      return value;
        case DigitalStorageUnit::Kilobit:  return value * 1000.0;
        case DigitalStorageUnit::Megabit:  return value * 1000000.0;
        case DigitalStorageUnit::Gigabit:  return value * 1000000000.0;
        case DigitalStorageUnit::Terabit:  return value * 1000000000000.0;
        case DigitalStorageUnit::Petabit:  return value * 1000000000000000.0;

        case DigitalStorageUnit::Byte:     return value * 8.0;
        case DigitalStorageUnit::Kilobyte: return value * 8000.0;
        case DigitalStorageUnit::Megabyte: return value * 8000000.0;
        case DigitalStorageUnit::Gigabyte: return value * 8000000000.0;
        case DigitalStorageUnit::Terabyte: return value * 8000000000000.0;
        case DigitalStorageUnit::Petabyte: return value * 8000000000000000.0;

        case DigitalStorageUnit::Size:     return 0.0;
    }

    return 0.0;
}



double UnitConverter::fromBaseUnit(double value, LengthUnit unit)
{
    switch (unit) {
        case LengthUnit::Kilometer:  return value / 1000.0;
        case LengthUnit::Meter:      return value;
        case LengthUnit::Centimeter: return value * 100;
        case LengthUnit::Millimeter: return value * 1000;
        case LengthUnit::Micrometer: return value * 1000000;
        case LengthUnit::Nanometer:  return value * 1000000000;

        case LengthUnit::Mile:       return value / 1609.35;
        case LengthUnit::Yard:       return value / 0.9144;
        case LengthUnit::Foot:       return value / 0.3048;
        case LengthUnit::Inch:       return value / 0.0254;

        case LengthUnit::Size:       return 0.0;
    }

    return 0.0;
}

double UnitConverter::fromBaseUnit(double value, MassUnit unit)
{
    switch (unit) {
        case MassUnit::Metric_Ton:   return value / 1000000.0;
        case MassUnit::Kilogram:     return value / 1000.0;
        case MassUnit::Gram:         return value;
        case MassUnit::Centigram:    return value * 100.0;
        case MassUnit::Milligram:    return value * 1000.0;
        case MassUnit::Microgram:    return value * 1000000.0;

        case MassUnit::Imperial_Ton: return value / 1016046.08;
        case MassUnit::US_Ton:       return value / 907184.0;
        case MassUnit::Pound:        return value / 453.592;
        case MassUnit::Ounce:        return value / 28.3495;

        case MassUnit::Size:         return 0.0;
    }

    return 0.0;
}

double UnitConverter::fromBaseUnit(double value, TemperatureUnit unit)
{
    switch (unit) {
        case TemperatureUnit::Kelvin:     return value;
        case TemperatureUnit::Celsius:    return value - 273.15;
        case TemperatureUnit::Fahrenheit: return value * 1.8 - 459.67;

        case TemperatureUnit::Size:       return 0.0;
    }

    return 0.0;
}

double UnitConverter::fromBaseUnit(double value, AngleUnit unit)
{
    switch (unit) {
        case AngleUnit::Arcsecond:     return value * 3600.0;
        case AngleUnit::Degree:        return value;
        case AngleUnit::Gradian:       return value / 0.9;
        case AngleUnit::Milliradian:   return value / 0.05729577951308232088;
        case AngleUnit::Minute_of_Arc: return value * 60;
        case AngleUnit::Radian:        return value / 57.2957795130823208768;

        case AngleUnit::Size:          return 0.0;
    }

    return 0.0;
}

double UnitConverter::fromBaseUnit(double value, DigitalStorageUnit unit)
{
    switch (unit) {
        case DigitalStorageUnit::Bit:      return value;
        case DigitalStorageUnit::Kilobit:  return value / 1000.0;
        case DigitalStorageUnit::Megabit:  return value / 1000000.0;
        case DigitalStorageUnit::Gigabit:  return value / 1000000000.0;
        case DigitalStorageUnit::Terabit:  return value / 1000000000000.0;
        case DigitalStorageUnit::Petabit:  return value / 1000000000000000.0;

        case DigitalStorageUnit::Byte:     return value / 8.0;
        case DigitalStorageUnit::Kilobyte: return value / 8000.0;
        case DigitalStorageUnit::Megabyte: return value / 8000000.0;
        case DigitalStorageUnit::Gigabyte: return value / 8000000000.0;
        case DigitalStorageUnit::Terabyte: return value / 8000000000000.0;
        case DigitalStorageUnit::Petabyte: return value / 8000000000000000.0;

        case DigitalStorageUnit::Size:     return 0.0;
    }

    return 0.0;
}
