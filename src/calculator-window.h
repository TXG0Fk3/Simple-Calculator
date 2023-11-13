#ifndef CALCULATOR_WINDOW_H
#define CALCULATOR_WINDOW_H

#include <libadwaita-1/adwaita.h>
#include <gtk-4.0/gtk/gtk.h>
#include <string.h>
#include "resources.c"

void app_activate(GtkApplication *app);

void btn_signal(GtkButton *btn);

#endif
