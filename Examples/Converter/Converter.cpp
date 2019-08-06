#include "Converter.h"

Converter::Converter(double value) {
    this->value = value;
}

double Converter::mileToKm(double mile) {
    return mile * Converter::mileRate;
}

double Converter::kmToMile(double km) {
    return km / Converter::mileRate;
}

double Converter::poundToKg(double pound) {
    return pound * Converter::poundRate;
}

double Converter::kgToPound(double kg) {
    return kg / Converter::poundRate;
}

double Converter::feetToMeter(double feet) {
    return feet * Converter::feetRate;
}

double Converter::meterToFeet(double meter) {
    return meter / Converter::feetRate;
}

double Converter::toMile() {
    return Converter::kmToMile(this->value);
}

double Converter::toKm() {
    return Converter::mileToKm(this->value);
}

double Converter::toPound() {
    return Converter::kgToPound(this->value);
}

double Converter::toKg() {
    return Converter::poundToKg(this->value);
}

double Converter::toFeet() {
    return Converter::meterToFeet(this->value);
}

double Converter::toMeter() {
    return Converter::feetToMeter(this->value);
}
