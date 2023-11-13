#include "calculator-window.h"

int main (int argc, char *argv[]){
  AdwApplication *app = NULL;

  app = adw_application_new("com.github.TXG0Fk3.Simple-Calculator", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);

  return g_application_run(G_APPLICATION(app), argc, argv);
}
