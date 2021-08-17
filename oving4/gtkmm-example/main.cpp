#include <glib.h>
#include <gtkmm.h>
#include <string>

using namespace std;

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label first_name_label;
  Gtk::Entry first_name;
  Gtk::Label last_name_label;
  Gtk::Entry last_name;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    set_title("Øving 4");
    set_default_size(300, 200);

    first_name_label.set_text("First Name");
    last_name_label.set_text("Last Name");

    button.set_label("Combine names");
    button.set_sensitive(false);

    vbox.pack_start(first_name_label);
    vbox.pack_start(first_name);
    vbox.pack_start(last_name_label);
    vbox.pack_start(last_name);
    vbox.pack_start(button);
    vbox.pack_start(label);

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets

    first_name.signal_changed().connect([this]() {
      bool activate = first_name.get_text_length() > 0 && last_name.get_text_length() > 0;
      button.set_sensitive(activate);
    });

    last_name.signal_changed().connect([this]() {
      bool activate = first_name.get_text_length() > 0 && last_name.get_text_length() > 0;
      button.set_sensitive(activate);
    });

    button.signal_clicked().connect([this]() {
      string combined_name = first_name.get_text() + " " + last_name.get_text();
      label.set_text("Names combined: " + combined_name);
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
