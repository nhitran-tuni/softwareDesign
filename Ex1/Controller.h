#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Thermometer.h"
#include <iostream>
#include <map>
#include <string>

class Controller {
public:
    Controller();
    ~Controller();
    /**
     * @brief Get current temperature of chosen thermometer
     * @param id
     * @return current temperature
     */
    float getCurrent(std::string id);

    /**
     * @brief Get maximum temperature of thermometer
     * @param id
     * @return max_temperature
     */
    float getMax(std::string id);

    /**
     * @brief Get minimum temperature of thermometer
     * @param id
     * @return min_temperature
     */
    float getMin(std::string id);

    /**
     * @brief Add a new thermometer at given location
     * @param location
     * @return new thermometer
     */
    Thermometer addNewThermometer(std::string location);

    /**
     * @brief Remove a thermometer
     * @param id
     * @return
     */
    Thermometer remove(std::string id);

    /**
     * @brief Reset the min and max of given thermometer
     * @param id
     */
    void reset(std::string id);
private:
    std::map<std::string, Thermometer> thermometerList;
};

#endif // CONTROLLER_H
