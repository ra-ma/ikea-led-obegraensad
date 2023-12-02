#include "plugins/MultiFunctionPlugin.h"

void MultiFunctionPlugin::setup()
{
  // loading screen
  Screen.setPixel(4, 7, 1);
  Screen.setPixel(5, 7, 1);
  Screen.setPixel(7, 7, 1);
  Screen.setPixel(8, 7, 1);
  Screen.setPixel(10, 7, 1);
  Screen.setPixel(11, 7, 1);

  previousMinutes = -1;
  previousHour = -1;
}

void MultiFunctionPlugin::loop()
{
  
  if (getLocalTime(&timeinfo))
  {
    if (previousHour != timeinfo.tm_hour || previousMinutes != timeinfo.tm_min)
    {
      Screen.clear();
            
      if (previousHour <= 6) {
        Screen.setBrightness(0); 
      } else if (previousHour >= 23) {
          Screen.setBrightness(0); 
      } else if (previousHour >= 20) {
          Screen.setBrightness(5);
      } else {
        Screen.setBrightness(150);
      }
            
      Screen.drawNumbers(3, 2, {(timeinfo.tm_hour - timeinfo.tm_hour % 10) / 10, timeinfo.tm_hour % 10});
      Screen.drawNumbers(3, 8, {(timeinfo.tm_min - timeinfo.tm_min % 10) / 10, timeinfo.tm_min % 10});
    }

    previousMinutes = timeinfo.tm_min;
    previousHour = timeinfo.tm_hour;
  }
}

const char *MultiFunctionPlugin::getName() const
{
  return "MultiFunction";
}
