#include <gtk/gtk.h>

int main(int argc ,char *argv[])
{
	gtk_init(&argc ,&argv);

	GtkWidget *window;
	GtkWidget *box;
	GtkWidget *image;
	GtkWidget *button;

	window = gtk_window_new(GTK_WINDOW_POPUP);//no boundary
	gtk_window_set_title(GTK_WINDOW(window), "Splash窗口");

	//gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	box = gtk_box_new(FALSE, 0);

	gtk_container_add(GTK_CONTAINER(window), box);
	image = gtk_image_new_from_file("computer.svg");
	gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 0);

	button = gtk_button_new_with_label("Splash窗口");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}
