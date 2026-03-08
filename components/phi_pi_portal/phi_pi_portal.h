#pragma once
#include "lvgl.h"
#include "app_base.h"   // Whatever the repo uses for base app class

class PhiPiPortalApp : public AppBase {
public:
    PhiPiPortalApp();
    void onLaunch() override;
    void onExit() override;

private:
    lv_obj_t *amp_label = nullptr;
    lv_timer_t *kernel_timer = nullptr;

    static void kernel_tick_cb(lv_timer_t *timer);
};

