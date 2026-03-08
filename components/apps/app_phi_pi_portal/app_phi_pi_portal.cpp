#include "app_phi_pi_portal.hpp"
#include "lvgl.h"

REGISTER_APP("PhiPiPortal", PhiPiPortalApp);

PhiPiPortalApp::PhiPiPortalApp()
    : AppBase("Phi-Π Portal", LV_SYMBOL_REFRESH)
{}

void PhiPiPortalApp::onLaunch() {
    lv_obj_t *scr = lv_scr_act();
    lv_obj_clean(scr);

    lv_obj_t *title = lv_label_create(scr);
    lv_label_set_text(title, "Φ-π Portal");
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 20);

    amp_label = lv_label_create(scr);
    lv_label_set_text(amp_label, "Amplitude: --");
    lv_obj_align(amp_label, LV_ALIGN_CENTER, 0, 0);

    kernel_timer = lv_timer_create(kernel_tick_cb, 100, this);
}

void PhiPiPortalApp::onExit() {
    if (kernel_timer) {
        lv_timer_del(kernel_timer);
        kernel_timer = nullptr;
    }
}

void PhiPiPortalApp::kernel_tick_cb(lv_timer_t *timer) {
    PhiPiPortalApp *app = (PhiPiPortalApp*)timer->user_data;

    static float t = 0.0f;
    t += 0.1f;
    float amp = 0.5f + 0.5f * sinf(t);

    lv_label_set_text_fmt(app->amp_label, "Amplitude: %.2f", amp);
}

