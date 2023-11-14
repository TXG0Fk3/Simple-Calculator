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
  
  builder = gtk_builder_new_from_resource("/com/github/TXG0Fk3/Simple-Calculator/src/calculator-window.ui");

  win = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
  gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
  
  gtk_window_present(GTK_WINDOW(win));
}

void btn_signal(GtkButton *btn){
  //TODO
}
