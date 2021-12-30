#pragma once

#include <lvgl/src/lv_core/lv_obj.h>
#include <chrono>
#include <cstdint>
#include <memory>
#include "displayapp/screens/Screen.h"
#include "components/datetime/DateTimeController.h"

namespace Pinetime {
  namespace Controllers {
    class Settings;
    class Ble;
    class NotificationManager;
    class MotionController;
  }

  namespace Applications {
    namespace Screens {

      class WatchFaceModern : public Screen {
      public:
        WatchFaceModern(DisplayApp* app,
                         Controllers::DateTime& dateTimeController,
                         Controllers::Ble& bleController,
                         Controllers::NotificationManager& notificationManager,
                         Controllers::Settings& settingsController,
                         Controllers::MotionController& motionController);
        ~WatchFaceModern() override;

        void Refresh() override;

      private:
        char displayedChar[5] {};

        uint16_t currentYear = 1970;
        Pinetime::Controllers::DateTime::Months currentMonth = Pinetime::Controllers::DateTime::Months::Unknown;
        Pinetime::Controllers::DateTime::Days currentDayOfWeek = Pinetime::Controllers::DateTime::Days::Unknown;
        uint8_t currentDay = 0;

        DirtyValue<uint8_t> batteryPercentRemaining {};
        DirtyValue<bool> powerPresent {};
        DirtyValue<bool> bleState {};
        DirtyValue<std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>> currentDateTime {};
        DirtyValue<bool> motionSensorOk {};
        DirtyValue<uint32_t> stepCount {};
        DirtyValue<bool> notificationState {};

        lv_obj_t* sideCover;
        lv_obj_t* backgroundLabel;
        lv_obj_t* labelHour;
        lv_obj_t* labelMinutes;
        lv_obj_t* labelTimeAmPm;
        lv_obj_t* labelDate;
        lv_obj_t* bleIcon;
        lv_obj_t* stepIcon;
        lv_obj_t* stepValue;
        lv_obj_t* notificationIcon;

        Controllers::DateTime& dateTimeController;
        Controllers::Ble& bleController;
        Controllers::NotificationManager& notificationManager;
        Controllers::Settings& settingsController;
        Controllers::MotionController& motionController;

        lv_task_t* taskRefresh;
      };
    }
  }
}
