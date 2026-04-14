#include <gtk/gtk.h>

// Função que será chamada quando o botão for clicado
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Botão clicado! Olá, André!\n");
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Meu App no Ubuntu");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Criando um botão com um rótulo (label)
    GtkWidget *button = gtk_button_new_with_label("Clique Aqui");

    // Conectando o sinal "clicked" do botão à nossa função
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Adicionando o botão na janela
    gtk_window_set_child(GTK_WINDOW(window), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("org.exemplo.gui", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
