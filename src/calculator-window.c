#include "calculator-window.h"

void app_activate(GtkApplication *app){
  GtkWidget *win;
  GtkWidget *tv;
  GtkTextBuffer *tb;
  GtkWidget *btn;
  GtkBuilder *builder;
  char btns[] = "0123456789C=+-*/";
  char vle1[10], opr, vle2[10];
  unsigned int qtd = 0;
  
  builder = gtk_builder_new_from_resource("/com/github/TXG0Fk3/Simple-Calculator/src/calculator-window.ui");

  win = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
  gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
  
  tv = GTK_WIDGET(gtk_builder_get_object(builder, "tv"));
  tb = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));

  for (int i = 0; i < 16; i++){
    const char *id = g_strdup_printf("%c", btns[i]);
    btn = GTK_WIDGET(gtk_builder_get_object(builder, id));

    g_signal_connect(btn, "clicked", G_CALLBACK(btn_signal), NULL);
  }

  gtk_window_present(GTK_WINDOW(win));
}

void btn_signal(GtkButton *btn, gpointer *tb){
  // TODO
}
