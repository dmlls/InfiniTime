#pragma once

#include <array>
#include <cstdint>
#include <lvgl/lvgl.h>

#include "components/settings/Settings.h"
#include "displayapp/screens/Screen.h"

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingWatchFaceModern : public Screen {
      public:
        SettingWatchFaceModern(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~SettingWatchFaceModern() override;

        void UpdateSelected(lv_obj_t* object, lv_event_t event);

      private:
        static constexpr std::array<const char*, 2> options = {" Show", " Don't show"};
        Controllers::Settings& settingsController;
        lv_obj_t* cbOption[options.size()];
      };
    }
  }
}
