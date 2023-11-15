#ifndef CALCULATOR_WINDOW_H
#define CALCULATOR_WINDOW_H

#include <libadwaita-1/adwaita.h>
#include <gtk-4.0/gtk/gtk.h>
#include "calculate.h"

void app_activate(GtkApplication *app);

void btn_signal(GtkButton *btn, gpointer tb);

#endif // CALCULATOR_WINDOW_H
