// coding: utf-8
/* Copyright (c) 2013, Niklas Hauser
* All Rights Reserved.
*
* The file is part of my bachelor thesis and is released under the 3-clause BSD
* license. See the file `LICENSE` for the full license governing this code.
*/
// ----------------------------------------------------------------------------
#ifndef TASK_TEMPERATURE_HPP
#	error	"Don't include this file directly, use 'task_temperature.hpp' instead!"
#endif

#undef	XPCC_LOG_LEVEL
#define	XPCC_LOG_LEVEL xpcc::log::DEBUG

task::Temperature::Temperature()
:	readTimer(250), temperatures{0,0,0,0,0}, numberOfSensors(1)
{
}

uint8_t
task::Temperature::addSensor(xpcc::Tmp102<Twi> *sensor)
{
	sensorList[numberOfSensors-1] = sensor;
	numberOfSensors++;
	XPCC_LOG_INFO << "Adding temperature sensor No " << numberOfSensors << xpcc::endl;
	return numberOfSensors;
}

uint8_t
task::Temperature::getNumberOfSensors()
{
	return numberOfSensors;
}

bool
task::Temperature::configureSensors()
{
	xpcc::Timeout<> configTimeout;
	bool success(true);
	bool allSuccessful(true);

	configTimeout.restart(1000);
	while(!(success = sensor0.configure()) && !configTimeout.isExpired())
		;
	if (!success) {
		XPCC_LOG_ERROR << "On Board Sensor config timed out!" << xpcc::endl;
		allSuccessful = false;
	}

	XPCC_LOG_INFO << "On Board Sensor configured" << xpcc::endl;

	for (uint8_t ii = 0; ii < numberOfSensors-1; ++ii)
	{
		configTimeout.restart(1000);
		while(!(success = sensor1.configure()) && !configTimeout.isExpired())
			;
		if (!success) {
			XPCC_LOG_ERROR << "Temp Sensor " << ii+1 << " config timed out!" << xpcc::endl;
			allSuccessful = false;
		}
		XPCC_LOG_INFO << "Temp Sensor " << ii+1 << " configured" << xpcc::endl;
	}

	return allSuccessful;
}

float
task::Temperature::getAverage()
{
	float sum(0);
	for (uint8_t ii=0; ii < numberOfSensors; ii++)
	{
		sum += temperatures[ii];
	}

	return sum / numberOfSensors;
}

float
task::Temperature::getTemperature(uint8_t sensor)
{
	if (sensor >= numberOfSensors) return NAN;
	return temperatures[sensor];
}

bool
task::Temperature::update()
{
	sensor0.update();

	for (uint8_t ii = 0; ii < numberOfSensors-1; ++ii)
	{
		sensorList[ii]->update();
	}

	PT_BEGIN();

	while(true)
	{
		if (readTimer.isExpired())
		{
			sensor0.readTemperature();

			for (uint8_t ii = 0; ii < numberOfSensors-1; ++ii)
			{
				sensorList[ii]->readTemperature();
			}

			// display the current temperature on the led.
			float temp = getTemperature(0);
			temp -= 20;
			temp *= 2.65;
			uint16_t raw = temp < 0 ? 0 : temp;
			uint8_t value = raw > 180 ? 180 : raw;
			rgbLed.fadeTo(250, xpcc::color::Hsv(180-value, 255, 255));
		}

		if (sensor0.isNewDataAvailable())
		{
			sensor0.getData();
			temperatures[0] = sensor0.getTemperature();
		}

		for (uint8_t ii = 0; ii < numberOfSensors-1; ++ii)
		{
			if (sensorList[ii]->isNewDataAvailable())
			{
				temperatures[ii+1] = sensorList[ii]->getTemperature();
			}
		}

		PT_YIELD();
	}

	// return is included in PT_END();
	PT_END();
}
