#include <gtk/gtk.h>

void on_add_event_clicked(GtkWidget *widget, gpointer data) {
    g_print("Event Added!\n");
}

void on_register_clicked(GtkWidget *widget, gpointer data) {
    g_print("Participant Registered!\n");
}

void on_view_events_clicked(GtkWidget *widget, gpointer data) {
    g_print("Displaying Events...\n");
}

void on_exit_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window, *grid, *btn_add, *btn_register, *btn_view, *btn_exit;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Event Management System");
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    btn_add = gtk_button_new_with_label("Add Event");
    btn_register = gtk_button_new_with_label("Register Participant");
    btn_view = gtk_button_new_with_label("View Events");
    btn_exit = gtk_button_new_with_label("Exit");

    gtk_grid_attach(GTK_GRID(grid), btn_add, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_register, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_view, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_exit, 0, 3, 1, 1);

    g_signal_connect(btn_add, "clicked", G_CALLBACK(on_add_event_clicked), NULL);
    g_signal_connect(btn_register, "clicked", G_CALLBACK(on_register_clicked), NULL);
    g_signal_connect(btn_view, "clicked", G_CALLBACK(on_view_events_clicked), NULL);
    g_signal_connect(btn_exit, "clicked", G_CALLBACK(on_exit_clicked), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
