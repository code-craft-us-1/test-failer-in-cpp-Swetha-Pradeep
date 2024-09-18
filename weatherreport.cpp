#include <assert.h>
#include <string>
#include <iostream>

using std::cout, std::endl, std::string;

namespace WeatherSpace {
class IWeatherSensor {
 public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
};

/// This is a stub for a weather sensor. For the sake of testing
/// we create a stub that generates weather data and allows us to
/// test the other parts of this application in isolation
/// without needing the actual Sensor during development

class SensorStub : public IWeatherSensor {
    int Humidity() const override {
        return 72;
    }

    int Precipitation() const override {
        return 70;
    }

    double TemperatureInC() const override {
        return 26;
    }

    int WindSpeedKMPH() const override {
        return 52;
    }
};

class SensorDynamicStub : public IWeatherSensor {
    int HumidityIn = 0;
    int precipitationIn = 0;
    double tempratureIncIn = 0.0;
    int windspeedkmphIn = 0;

 public:
    SensorDynamicStub(int humidity, int precipitation,
        double tempratureInc, int windspeedkmph) {
        HumidityIn = humidity;
        precipitationIn = precipitation;
        tempratureIncIn = tempratureInc;
        windspeedkmphIn = windspeedkmph;
    }

    int Humidity() const override {
        return  HumidityIn;
    }

    int Precipitation() const override {
        return precipitationIn;
    }

    double TemperatureInC() const override {
        return tempratureIncIn;
    }

    int WindSpeedKMPH() const override {
        return windspeedkmphIn;
    }
};

// This is a function to predict the weather, based on readings
// from a sensor

string Report(const IWeatherSensor& sensor) {
    int precipitation = sensor.Precipitation();
    std::cout << "precipitation" << precipitation << "\n";
    std::cout << "WindSpeedKMPH" << sensor.WindSpeedKMPH() << "\n";
    // precipitation < 20 is a sunny day
    string report = "Sunny day";

    if (sensor.TemperatureInC() > 25) {
        if (precipitation >= 20 && precipitation < 60)
            report = "Partly cloudy";
        else if (sensor.WindSpeedKMPH() > 50)
            report = "Alert, Stormy with heavy rain";
    }
    return report;
}

// Test a rainy day

void TestRainy() {
    SensorStub sensor;
    string report = Report(sensor);
    cout << report << endl;
    assert(report.find("rain") != string::npos);
}

// Test another rainy day

void TestHighPrecipitationAndLowWindspeed() {
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    SensorDynamicStub *sensorDyn = new SensorDynamicStub(72, 62, 26.0, 49);
    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    string report = Report(*sensorDyn);
    std::cout << report << "\n";
    assert(report.find("rain") != string::npos);
    // assert(report.length() > 0);
}
}  // namespace WeatherSpace

int main() {
    WeatherSpace::TestHighPrecipitationAndLowWindspeed();
    WeatherSpace::TestRainy();
    
    cout << "All is well (maybe)\n";
    return 0;
}
