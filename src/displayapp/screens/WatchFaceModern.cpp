#include "displayapp/screens/WatchFaceModern.h"

#include <date/date.h>
#include <lvgl/lvgl.h>
#include <cstdio>
#include "displayapp/screens/BleIcon.h"
#include "displayapp/screens/Symbols.h"
#include "components/ble/BleController.h"
#include "components/ble/NotificationManager.h"
#include "components/motion/MotionController.h"
#include "components/settings/Settings.h"

using namespace Pinetime::Applications::Screens;

LV_IMG_DECLARE(side_cover);

WatchFaceModern::WatchFaceModern(DisplayApp* app,
                                   Controllers::DateTime& dateTimeController,
                                   Controllers::Ble& bleController,
                                   Controllers::NotificationManager& notificationManager,
                                   Controllers::Settings& settingsController,
                                   Controllers::MotionController& motionController)
  : Screen(app),
    currentDateTime {{}},
    dateTimeController {dateTimeController},
    bleController {bleController},
    notificationManager {notificationManager},
    settingsController {settingsController},
    motionController {motionController} {
  settingsController.SetClockFace(3);
  
  if(settingsController.GetShowSideCover()) {
    sideCover = lv_img_create(lv_scr_act(), nullptr);
    lv_img_set_src(sideCover, &side_cover);
    lv_obj_set_height(sideCover, 240);
    lv_obj_align(sideCover, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 0, 0);
  }

  notificationIcon = lv_obj_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_bg_color(notificationIcon, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xE85102));
  lv_obj_set_style_local_radius(notificationIcon, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
  lv_obj_set_size(notificationIcon, 13, 13);
  lv_obj_set_hidden(notificationIcon, true);

  labelHour = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_font(labelHour, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &bebas_neue_120);
  lv_label_set_text(labelHour, "01");
  lv_obj_align(labelHour, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 5);

  labelMinutes = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_font(labelMinutes, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &bebas_neue_120);
  lv_label_set_text(labelMinutes, "00");
  lv_obj_align(labelMinutes, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, -15);

  labelTimeAmPm = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_font(labelTimeAmPm, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &teko_28);
  lv_label_set_text(labelTimeAmPm, "");

  labelDate = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_color(labelDate, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));
  lv_obj_set_style_local_text_font(labelDate, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &teko_28);
  lv_obj_align(labelDate, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, 0, 0);
  lv_label_set_text(labelDate, "Mon 01");

  stepValue = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_color(stepValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));
  lv_obj_set_style_local_text_font(stepValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &teko_28);
  lv_obj_align(stepValue, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, 8, 0);
  lv_label_set_text(stepValue, "0");

  stepIcon = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_color(stepIcon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));
  lv_label_set_text(stepIcon, Symbols::shoe);
  lv_obj_align(stepIcon, stepValue, LV_ALIGN_OUT_LEFT_MID, -5, 0);

  taskRefresh = lv_task_create(RefreshTaskCallback, LV_DISP_DEF_REFR_PERIOD, LV_TASK_PRIO_MID, this);
  Refresh();
}

WatchFaceModern::~WatchFaceModern() {
  lv_task_del(taskRefresh);
  lv_obj_clean(lv_scr_act());
}

void WatchFaceModern::Refresh() {
  notificationState = notificationManager.AreNewNotificationsAvailable();
  if (notificationState.IsUpdated()) {
    lv_obj_set_hidden(notificationIcon, !notificationState.Get());
    lv_obj_align(notificationIcon, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, 0, 0);
  }

  currentDateTime = dateTimeController.CurrentDateTime();

  if (currentDateTime.IsUpdated()) {
    auto newDateTime = currentDateTime.Get();

    auto dp = date::floor<date::days>(newDateTime);
    auto time = date::make_time(newDateTime - dp);
    auto yearMonthDay = date::year_month_day(dp);

    auto year = static_cast<int>(yearMonthDay.year());
    auto month = static_cast<Pinetime::Controllers::DateTime::Months>(static_cast<unsigned>(yearMonthDay.month()));
    auto day = static_cast<unsigned>(yearMonthDay.day());
    auto dayOfWeek = static_cast<Pinetime::Controllers::DateTime::Days>(date::weekday(yearMonthDay).iso_encoding());

    int hour = time.hours().count();
    auto minute = time.minutes().count();

    char minutesChar[3];
    sprintf(minutesChar, "%02d", static_cast<int>(minute));

    char hoursChar[3];
    char ampmChar[3];

    if (settingsController.GetClockType() == Controllers::Settings::ClockType::H12) {
      if (hour < 12) {
        if (hour == 0) {
          hour = 12;
        }
        sprintf(ampmChar, "AM");
      } else { // hour >= 12
        if (hour != 12) {
          hour = hour - 12;
        }
        sprintf(ampmChar, "PM");
      }
    }
    sprintf(hoursChar, "%02d", hour);

    if ((hoursChar[0] != displayedChar[0]) || (hoursChar[1] != displayedChar[1]) || (minutesChar[0] != displayedChar[2]) ||
        (minutesChar[1] != displayedChar[3])) {
      displayedChar[0] = hoursChar[0];
      displayedChar[1] = hoursChar[1];
      displayedChar[2] = minutesChar[0];
      displayedChar[3] = minutesChar[1];

      lv_label_set_text_fmt(labelHour, "%s", hoursChar);
      lv_label_set_text_fmt(labelMinutes, "%s", minutesChar);
    }

    if (settingsController.GetClockType() == Controllers::Settings::ClockType::H12) {
      lv_label_set_text(labelTimeAmPm, ampmChar);
      lv_obj_align(labelTimeAmPm, labelHour, LV_ALIGN_OUT_RIGHT_TOP, 5, 28);
    }

    if ((year != currentYear) || (month != currentMonth) || (dayOfWeek != currentDayOfWeek) || (day != currentDay)) {
      lv_label_set_text_fmt(labelDate, "%s %02d", dateTimeController.DayOfWeekShortToStringLow(), day);
      lv_obj_align(labelDate, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, 0, 0);
      lv_obj_set_size(labelDate, 5, 5);

      currentYear = year;
      currentMonth = month;
      currentDayOfWeek = dayOfWeek;
      currentDay = day;
    }
  }

  stepCount = motionController.NbSteps();
  motionSensorOk = motionController.IsSensorOk();
  if (stepCount.IsUpdated() || motionSensorOk.IsUpdated()) {
    lv_label_set_text_fmt(stepValue, "%lu", stepCount.Get());
    lv_obj_align(stepValue, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 8, 0);
    lv_obj_align(stepIcon, stepValue, LV_ALIGN_OUT_LEFT_MID, -5, 0);
  }
}
