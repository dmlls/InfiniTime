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

      class WatchFaceInfineat : public Screen {
      public:
        WatchFaceInfineat(DisplayApp* app,
                         Controllers::DateTime& dateTimeController,
                         Controllers::NotificationManager& notificationManager,
                         Controllers::Settings& settingsController,
                         Controllers::MotionController& motionController);
        ~WatchFaceInfineat() override;

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

        // Lines making up the side cover
        lv_obj_t* line1;
        lv_obj_t* line2;
        lv_obj_t* line3;
        lv_obj_t* line4;
        lv_obj_t* line5;
        lv_obj_t* line6;
        lv_obj_t* line7;
        lv_obj_t* line8;
        lv_obj_t* line9;

        lv_style_t line1Style;
        lv_style_t line2Style;
        lv_style_t line3Style;
        lv_style_t line4Style;
        lv_style_t line5Style;
        lv_style_t line6Style;
        lv_style_t line7Style;
        lv_style_t line8Style;
        lv_style_t line9Style;

        lv_point_t line1Points[2];
        lv_point_t line2Points[2];
        lv_point_t line3Points[2];
        lv_point_t line4Points[2];
        lv_point_t line5Points[2];
        lv_point_t line6Points[2];
        lv_point_t line7Points[2];
        lv_point_t line8Points[2];
        lv_point_t line9Points[2];

        lv_obj_t* logoPine;

        lv_obj_t* labelHour;
        lv_obj_t* labelMinutes;
        lv_obj_t* labelTimeAmPm;
        lv_obj_t* labelDate;
        lv_obj_t* stepIcon;
        lv_obj_t* stepValue;
        lv_obj_t* notificationIcon;

        Controllers::DateTime& dateTimeController;
        Controllers::NotificationManager& notificationManager;
        Controllers::Settings& settingsController;
        Controllers::MotionController& motionController;

        lv_task_t* taskRefresh;
      };
    }
  }
}
