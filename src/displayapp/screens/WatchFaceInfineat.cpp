#include "displayapp/screens/WatchFaceInfineat.h"

#include <date/date.h>
#include <lvgl/lvgl.h>
#include <cstdio>
#include "displayapp/screens/Symbols.h"
#include "displayapp/screens/BleIcon.h"
#include "components/settings/Settings.h"
#include "components/ble/NotificationManager.h"
#include "components/ble/BleController.h"
#include "components/motion/MotionController.h"

using namespace Pinetime::Applications::Screens;

namespace {
  void event_handler(lv_obj_t* obj, lv_event_t event) {
    auto* screen = static_cast<WatchFaceInfineat*>(obj->user_data);
    screen->UpdateSelected(obj, event);
  }
}

LV_IMG_DECLARE(logo_pine);

WatchFaceInfineat::WatchFaceInfineat(DisplayApp* app,
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

  // Side Cover
  line1 = lv_line_create(lv_scr_act(), nullptr);
  line2 = lv_line_create(lv_scr_act(), nullptr);
  line3 = lv_line_create(lv_scr_act(), nullptr);
  line4 = lv_line_create(lv_scr_act(), nullptr);
  line5 = lv_line_create(lv_scr_act(), nullptr);
  line6 = lv_line_create(lv_scr_act(), nullptr);
  line7 = lv_line_create(lv_scr_act(), nullptr);
  line8 = lv_line_create(lv_scr_act(), nullptr);
  line9 = lv_line_create(lv_scr_act(), nullptr);

  lv_style_init(&line1Style);
  lv_style_set_line_width(&line1Style, LV_STATE_DEFAULT, 18);
  lv_style_set_line_color(&line1Style, LV_STATE_DEFAULT, lv_color_hex(0xfd872b));
  lv_obj_add_style(line1, LV_LINE_PART_MAIN, &line1Style);
  line1Points[0] = {30, 25};
  line1Points[1] = {68, -8};
  lv_line_set_points(line1, line1Points, 2);

  lv_style_init(&line2Style);
  lv_style_set_line_width(&line2Style, LV_STATE_DEFAULT, 15);
  lv_style_set_line_color(&line2Style, LV_STATE_DEFAULT, lv_color_hex(0xdb3316));
  lv_obj_add_style(line2, LV_LINE_PART_MAIN, &line2Style);
  line2Points[0] = {26, 167};
  line2Points[1] = {43, 216};
  lv_line_set_points(line2, line2Points, 2);

  lv_style_init(&line3Style);
  lv_style_set_line_width(&line3Style, LV_STATE_DEFAULT, 14);
  lv_style_set_line_color(&line3Style, LV_STATE_DEFAULT, lv_color_hex(0x6f1000));
  lv_obj_add_style(line3, LV_LINE_PART_MAIN, &line3Style);
  line3Points[0] = {27, 40};
  line3Points[1] = {27, 196};
  lv_line_set_points(line3, line3Points, 2);

  lv_style_init(&line4Style);
  lv_style_set_line_width(&line4Style, LV_STATE_DEFAULT, 22);
  lv_style_set_line_color(&line4Style, LV_STATE_DEFAULT, lv_color_hex(0xfd7a0a));
  lv_obj_add_style(line4, LV_LINE_PART_MAIN, &line4Style);
  line4Points[0] = {12, 182};
  line4Points[1] = {65, 249};
  lv_line_set_points(line4, line4Points, 2);

  lv_style_init(&line5Style);
  lv_style_set_line_width(&line5Style, LV_STATE_DEFAULT, 20);
  lv_style_set_line_color(&line5Style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_add_style(line5, LV_LINE_PART_MAIN, &line5Style);
  line5Points[0] = {17, 99};
  line5Points[1] = {17, 144};
  lv_line_set_points(line5, line5Points, 2);

  lv_style_init(&line6Style);
  lv_style_set_line_width(&line6Style, LV_STATE_DEFAULT, 18);
  lv_style_set_line_color(&line6Style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_add_style(line6, LV_LINE_PART_MAIN, &line6Style);
  line6Points[0] = {14, 81};
  line6Points[1] = {40, 127};
  lv_line_set_points(line6, line6Points, 2);

  lv_style_init(&line7Style);
  lv_style_set_line_width(&line7Style, LV_STATE_DEFAULT, 18);
  lv_style_set_line_color(&line7Style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_add_style(line7, LV_LINE_PART_MAIN, &line7Style);
  line7Points[0] = {14, 163};
  line7Points[1] = {40, 118};
  lv_line_set_points(line7, line7Points, 2);

  lv_style_init(&line8Style);
  lv_style_set_line_width(&line8Style, LV_STATE_DEFAULT, 52);
  lv_style_set_line_color(&line8Style, LV_STATE_DEFAULT, lv_color_hex(0xe85102));
  lv_obj_add_style(line8, LV_LINE_PART_MAIN, &line8Style);
  line8Points[0] = {-20, 124};
  line8Points[1] = {25, -11};
  lv_line_set_points(line8, line8Points, 2);

  lv_style_init(&line9Style);
  lv_style_set_line_width(&line9Style, LV_STATE_DEFAULT, 48);
  lv_style_set_line_color(&line9Style, LV_STATE_DEFAULT, lv_color_hex(0xea1c00));
  lv_obj_add_style(line9, LV_LINE_PART_MAIN, &line9Style);
  line9Points[0] = {-29, 89};
  line9Points[1] = {27, 254};
  lv_line_set_points(line9, line9Points, 2);

  logoPine = lv_img_create(lv_scr_act(), nullptr);
  lv_img_set_src(logoPine, &logo_pine);
  lv_obj_set_pos(logoPine, 14, 105);

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

  bleIcon = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_color(bleIcon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));
  lv_label_set_text(bleIcon, Symbols::bluetooth);
  lv_obj_align(bleIcon, labelDate, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);

  stepValue = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_color(stepValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));
  lv_obj_set_style_local_text_font(stepValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &teko_28);
  lv_obj_align(stepValue, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, 10, 0);
  lv_label_set_text(stepValue, "0");

  stepIcon = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_set_style_local_text_color(stepIcon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));
  lv_label_set_text(stepIcon, Symbols::shoe);
  lv_obj_align(stepIcon, stepValue, LV_ALIGN_OUT_LEFT_MID, -5, 0);

  // Setting buttons
  btnClose = lv_btn_create(lv_scr_act(), nullptr);
  btnClose->user_data = this;
  lv_obj_set_size(btnClose, 60, 60);
  lv_obj_align(btnClose, lv_scr_act(), LV_ALIGN_CENTER, 0, -80);
  lv_obj_set_style_local_bg_opa(btnClose, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_70);
  lv_obj_set_style_local_value_str(btnClose, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "X");
  lv_obj_set_event_cb(btnClose, event_handler);
  lv_obj_set_hidden(btnClose, true);

  btnNextColor = lv_btn_create(lv_scr_act(), nullptr);
  btnNextColor->user_data = this;
  lv_obj_set_size(btnNextColor, 60, 60);
  lv_obj_align(btnNextColor, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, -15, 0);
  lv_obj_set_style_local_bg_opa(btnNextColor, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_70);
  lv_obj_set_style_local_value_str(btnNextColor, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, ">");
  lv_obj_set_event_cb(btnNextColor, event_handler);
  lv_obj_set_hidden(btnNextColor, true);

  btnPrevColor = lv_btn_create(lv_scr_act(), nullptr);
  btnPrevColor->user_data = this;
  lv_obj_set_size(btnPrevColor, 60, 60);
  lv_obj_align(btnPrevColor, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 15, 0);
  lv_obj_set_style_local_bg_opa(btnPrevColor, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_70);
  lv_obj_set_style_local_value_str(btnPrevColor, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "<");
  lv_obj_set_event_cb(btnPrevColor, event_handler);
  lv_obj_set_hidden(btnPrevColor, true);

  btnToggleCover = lv_btn_create(lv_scr_act(), nullptr);
  btnToggleCover->user_data = this;
  lv_obj_set_size(btnToggleCover, 60, 60);
  lv_obj_align(btnToggleCover, lv_scr_act(), LV_ALIGN_CENTER, 0, 80);
  lv_obj_set_style_local_bg_opa(btnToggleCover, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_70);
  lv_obj_set_style_local_value_str(btnToggleCover, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "ON");
  lv_obj_set_event_cb(btnToggleCover, event_handler);
  lv_obj_set_hidden(btnToggleCover, true);

  // Button to access the settings
  btnSettings = lv_btn_create(lv_scr_act(), nullptr);
  btnSettings->user_data = this;
  lv_obj_set_size(btnSettings, 150, 150);
  lv_obj_align(btnSettings, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_local_radius(btnSettings, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 30);
  lv_obj_set_style_local_bg_opa(btnSettings, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_70);
  lv_obj_set_event_cb(btnSettings, event_handler);
  labelBtnSettings = lv_label_create(btnSettings, nullptr);
  lv_obj_set_style_local_text_font(labelBtnSettings, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_sys_48);
  lv_label_set_text_static(labelBtnSettings, Symbols::settings);
  lv_obj_set_hidden(btnSettings, true);

  taskRefresh = lv_task_create(RefreshTaskCallback, LV_DISP_DEF_REFR_PERIOD, LV_TASK_PRIO_MID, this);
  Refresh();
}

WatchFaceInfineat::~WatchFaceInfineat() {
  lv_task_del(taskRefresh);

  if(settingsController.GetShowSideCover()) {
    lv_style_reset(&line1Style);
    lv_style_reset(&line2Style);
    lv_style_reset(&line3Style);
    lv_style_reset(&line4Style);
    lv_style_reset(&line5Style);
    lv_style_reset(&line6Style);
    lv_style_reset(&line7Style);
    lv_style_reset(&line8Style);
    lv_style_reset(&line9Style);
  }

  lv_obj_clean(lv_scr_act());
}

bool WatchFaceInfineat::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  if ((event == Pinetime::Applications::TouchEvents::LongTap) && lv_obj_get_hidden(btnSettings)) {
    lv_obj_set_hidden(btnSettings, false);
    savedTick = lv_tick_get();
    return true;
  }
  return false;
}

void WatchFaceInfineat::CloseMenu() {
  settingsController.SaveSettings();
  lv_obj_set_hidden(btnClose, true);
  lv_obj_set_hidden(btnNextColor, true);
  lv_obj_set_hidden(btnPrevColor, true);
  lv_obj_set_hidden(btnToggleCover, true);
}

bool WatchFaceInfineat::OnButtonPushed() {
  if (!lv_obj_get_hidden(btnClose)) {
    CloseMenu();
    return true;
  }
  return false;
}

void WatchFaceInfineat::UpdateSelected(lv_obj_t* object, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    if (object == btnSettings) {
        lv_obj_set_hidden(btnSettings, true);
        lv_obj_set_hidden(btnClose, false);
        lv_obj_set_hidden(btnNextColor, false);
        lv_obj_set_hidden(btnPrevColor, false);
        lv_obj_set_hidden(btnToggleCover, false);
    }
    if (object == btnClose) {
      CloseMenu();
    }
    if (object == btnToggleCover) {
      bool hidden = ToggleShowSideCover();
      const char *labelToggle = hidden ? "OFF" : "ON";
      lv_obj_set_style_local_value_str(btnToggleCover, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, labelToggle);
    }
    // TODO
  }
}

void WatchFaceInfineat::Refresh() {
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

  bleState = bleController.IsConnected();
  if (bleState.IsUpdated()) {
    lv_label_set_text(bleIcon, BleIcon::GetIcon(bleState.Get()));
    lv_obj_align(bleIcon, labelDate, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
  }

  stepCount = motionController.NbSteps();
  motionSensorOk = motionController.IsSensorOk();
  if (stepCount.IsUpdated() || motionSensorOk.IsUpdated()) {
    lv_label_set_text_fmt(stepValue, "%lu", stepCount.Get());
    lv_obj_align(stepValue, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 10, 0);
    lv_obj_align(stepIcon, stepValue, LV_ALIGN_OUT_LEFT_MID, -5, 0);
  }

  if (!lv_obj_get_hidden(btnSettings)) {
    if ((savedTick > 0) && (lv_tick_get() - savedTick > 3000)) {
      lv_obj_set_hidden(btnSettings, true);
      savedTick = 0;
    }
  }
}

bool WatchFaceInfineat::ToggleShowSideCover() {
  bool visible = !settingsController.GetShowSideCover();
  settingsController.SetShowSideCover(visible);
  lv_obj_set_hidden(logoPine, visible);
  lv_obj_set_hidden(line1, visible);
  lv_obj_set_hidden(line2, visible);
  lv_obj_set_hidden(line3, visible);
  lv_obj_set_hidden(line4, visible);
  lv_obj_set_hidden(line5, visible);
  lv_obj_set_hidden(line6, visible);
  lv_obj_set_hidden(line7, visible);
  lv_obj_set_hidden(line8, visible);
  lv_obj_set_hidden(line9, visible);
  return visible;
}
