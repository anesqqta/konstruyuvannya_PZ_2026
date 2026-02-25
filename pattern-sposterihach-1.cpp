#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

//інтерфейси
class Observer {
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
    virtual ~Observer() {}
};

class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

//конкретний суб'єкт
class WeatherStation : public Subject {
private:
    float temperature;
    float humidity;
    float pressure;
    vector<Observer*> observers;

public:
    void registerObserver(Observer* o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() override {
        for (auto* obs : observers) {
            obs->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float t, float h, float p) {
        temperature = t;
        humidity = h;
        pressure = p;
        notifyObservers();
    }
};

//конкретний спостерігач
//умови
class CurrentConditionsDisplay : public Observer {
public:
    void update(float temp, float humidity, float pressure) override {
        cout << "<Поточні умови> Температура: " << temp
             << "C, Вологість: " << humidity
             << "%, Тиск: " << pressure << "P" << endl;
    }
};

//cтатистика
class StatisticsDisplay : public Observer {
private:
    float sumTemp = 0;
    int count = 0;
public:
    void update(float temp, float humidity, float pressure) override {
        sumTemp += temp;
        count++;
        cout << "<Статистика> Середня температура: "
             << (sumTemp / count) << "C" << endl;
    }
};

//прогноз
class ForecastDisplay : public Observer {
private:
    float lastPressure = 1013.0; // нормальний тиск
public:
    void update(float temp, float humidity, float pressure) override {
        cout << "<Прогноз> ";
        if (pressure > lastPressure) {
            cout << "Погода покращується!\n" << endl;
        } else if (pressure < lastPressure) {
            cout << "Очікується дощ або похолодання!\n" << endl;
        } else {
            cout << "Погода без змін.\n" << endl;
        }
        lastPressure = pressure;
    }
};

int main() {
    system("chcp 65001 > nul");

    WeatherStation station;

    CurrentConditionsDisplay currentDisplay;
    StatisticsDisplay statsDisplay;
    ForecastDisplay forecastDisplay; //додавання нового спостерігача

    //підписування спостерігачів
    station.registerObserver(&currentDisplay);
    station.registerObserver(&statsDisplay);
    station.registerObserver(&forecastDisplay);

    //зміни погоди
    station.setMeasurements(20.5, 65, 1013);
    station.setMeasurements(22.3, 60, 1015);
    station.setMeasurements(19.8, 70, 1012);

    //відписування
    station.removeObserver(&currentDisplay);

    cout << "\n\t Поточний дисплей відписався\n" << endl;
    station.setMeasurements(23.0, 50, 1015);

    return 0;
}
