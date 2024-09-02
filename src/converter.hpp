#pragma once


class UnitConverter
{
public:
    enum class LengthUnit
    {
        Kilometer,
        Meter,
        Centimeter,
        Millimeter,
        Micrometer,
        Nanometer,

        Mile,
        Yard,
        Foot,
        Inch,

        Size,
        Begin = 0
    };

    enum class MassUnit
    {
        Metric_Ton,
        Kilogram,
        Gram,
        Centigram,
        Milligram,
        Microgram,

        Imperial_Ton,
        US_Ton,
        Pound,
        Ounce,

        Size,
        Begin = 0
    };

    enum class TemperatureUnit
    {
        Celsius,
        Fahrenheit,
        Kelvin,

        Size,
        Begin = 0
    };

    enum class AngleUnit
    {
        Arcsecond,
        Degree,
        Gradian,
        Milliradian,
        Minute_of_Arc,
        Radian,

        Size,
        Begin = 0
    };

    enum class DigitalStorageUnit
    {
        Bit,
        Kilobit,
        Megabit,
        Gigabit,
        Terabit,
        Petabit,

        Byte,
        Kilobyte,
        Megabyte,
        Gigabyte,
        Terabyte,
        Petabyte,

        Size,
        Begin = 0
    };

    template <typename UnitType>
    double convert(double value, UnitType from, UnitType to);

private:
    double toBaseUnit(double value, LengthUnit unit);
    double toBaseUnit(double value, MassUnit unit);
    double toBaseUnit(double value, TemperatureUnit unit);
    double toBaseUnit(double value, AngleUnit unit);
    double toBaseUnit(double value, DigitalStorageUnit unit);

    double fromBaseUnit(double value, LengthUnit unit);
    double fromBaseUnit(double value, MassUnit unit);
    double fromBaseUnit(double value, TemperatureUnit unit);
    double fromBaseUnit(double value, AngleUnit unit);
    double fromBaseUnit(double value, DigitalStorageUnit unit);
};
