#ifndef IN_CONVERTER_CONVERTER_H
#define IN_CONVERTER_CONVERTER_H

class Converter {
private:
    double value;
protected:
public:
    explicit Converter(double value);

    double toMile();
    double toKm();

    double toPound();
    double toKg();

    double toFeet();
    double toMeter();

    static double mileToKm(double mile);
    static double kmToMile(double km);

    static double poundToKg(double pound);
    static double kgToPound(double kg);

    static double feetToMeter(double feet);
    static double meterToFeet(double meter);

    static constexpr double mileRate  = 1.609344;
    static constexpr double poundRate = 2.20462262;
    static constexpr double feetRate  = 3.2808399;
};

#endif //IN_CONVERTER_CONVERTER_H
