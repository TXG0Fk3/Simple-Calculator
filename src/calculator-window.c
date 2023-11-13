#include "calculator-window.h"

void app_activate(GtkApplication *app){
  GtkWidget *win;
  GtkWidget *vbox;
  GtkWidget *tv;
  GtkTextBuffer *tb;
  GtkWidget *grid;
  GtkWidget *btn;
  GtkBuilder *builder;
  char vle1[10], opr, vle2[10];
  
  win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(win), "Simple Calculator");
  
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  grid = gtk_grid_new();
}
