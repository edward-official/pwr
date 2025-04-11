#include<iostream>
using namespace std;


class CTemperature {
private:
  double d_value_in_celsius;
public:
  CTemperature(double dValueInCelsius);
  CTemperature operator+(const CTemperature& cOther);
  void viewDetails();
};


CTemperature::CTemperature(double dValueInCelsius) : d_value_in_celsius(dValueInCelsius) {}
CTemperature CTemperature::operator+(const CTemperature& cOther) {return CTemperature(d_value_in_celsius + cOther.d_value_in_celsius);}


CTemperature operator"" _celsius(long double dTemperatureInCelsius) {return CTemperature(dTemperatureInCelsius);}
CTemperature operator"" _fahrenheit(long double dTemperatureInFahrenheit) {
  double d_temperature_in_celsius = (dTemperatureInFahrenheit - 32) * 5 / 9;
  return CTemperature(d_temperature_in_celsius);
}
CTemperature operator"" _kelvin(unsigned long long iTemperatureInKelvin) {
  double d_temperature_in_celsius = iTemperatureInKelvin - 273;
  return CTemperature(d_temperature_in_celsius);
}


void CTemperature::viewDetails() {
  cout << d_value_in_celsius << endl;
}


void operationDefault() {
  CTemperature c_temperature = 87.8_fahrenheit + 300_kelvin + 12.5_celsius;
  c_temperature.viewDetails();
}