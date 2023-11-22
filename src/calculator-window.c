#include "calculator-window.h"

int res = 1;

void app_activate(GtkApplication *app){
  GtkWidget *win;
  GtkWidget *tv;
  GtkTextBuffer *tb;
  GtkWidget *btn;
  GtkBuilder *builder;
  char btns[] = "0123456789C=+-*/.()";
  
  builder = gtk_builder_new_from_resource("/com/github/TXG0Fk3/Simple-Calculator/src/calculator-window.ui");

  win = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
  gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
  
  tv = GTK_WIDGET(gtk_builder_get_object(builder, "tv"));
  tb = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));

  for (int i = 0; i < 19; i++){
    const char *id = g_strdup_printf("%c", btns[i]);
    btn = GTK_WIDGET(gtk_builder_get_object(builder, id));

    g_signal_connect(btn, "clicked", G_CALLBACK(btn_signal), tb);
  }

  btn = GTK_WIDGET(gtk_builder_get_object(builder, "e"));
  g_signal_connect(btn, "clicked", G_CALLBACK(erase), tb);

  gtk_window_present(GTK_WINDOW(win));
}

void btn_signal(GtkButton *btn, gpointer tb){
  const gchar *label = gtk_button_get_label(btn);
  GtkTextIter end;
  gchar *text;

  if (g_strcmp0(label, "C") == 0){
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(tb), "", -1);
    res = 1;
  } else if (g_strcmp0(label, "=") == 0){
    GtkTextIter start;
    res = 0;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(tb), &start);
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(tb), &end);
    text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(tb), &start, &end, FALSE);

    double result = calculate(text);
    g_free(text);

    text = g_strdup_printf("%f", result);
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(tb), text, -1);
    g_free(text);
  } else if (res){
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(tb), &end);
    gtk_text_buffer_insert(GTK_TEXT_BUFFER(tb), &end, label, -1);
  }
  g_print("%s", label);
}

void erase(GtkButton *btn, gpointer tb){
  if (res){
    GtkTextIter start;
    GtkTextIter end;
    gchar *text;

    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(tb), &start);
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(tb), &end);
    text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(tb), &start, &end, FALSE);
    if (text && *text){
      *(text + strlen(text) - 1) = '\0';
    }
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(tb), text, -1);
    g_free(text);
  }
}
