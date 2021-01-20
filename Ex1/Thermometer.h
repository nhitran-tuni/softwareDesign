#ifndef THERMOMETER_H
#define THERMOMETER_H

#include<iostream>
#include<string>

class Thermometer {
public:
    /**
     * @brief Thermometer constructor
     * @param id id of the thermometer
     * @param location location of the thermometer
     * @param temp current temperature
     */
    Thermometer(std::string id, std::string location, float temp);

    ~Thermometer();
    /**
    * @brief getCurrent get current temperature
    * @return current temperature
    */
   float getCurrent() const;
   /**
    * @brief getMax get the recorded maximum temperature
    * @return recorded maximum temperature
    */
   float getMax() const;
   /**
    * @brief getMin get the recorded minimum temperature
    * @return recorded minimum temperature
    */
   float getMin() const;
   /**
    * @brief reset set the current temperature of the thermometer
    * @param temp current temperature in the room
    */
   void reset(float temp);
   /**
    * @brief resetMax set the recorded maximum temperature to the current temperature
    */
   void resetMax();
   /**
    * @brief resetMin set the recorded minimum temperature to the current temperature
    */
   void resetMin();
private:
   float current_;
   float max_;
   float min_;
   std::string location_;
   std::string id_;
};

#endif // THERMOMETER_H
