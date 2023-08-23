#include <gtk/gtk.h>
 
gint delete_event( GtkWidget *widget, GdkEvent  *event, gpointer   data )
{
    g_print ("delete event occurred\n");
    /* 改 TRUE 为 FALSE 程序会关闭。*/
    return FALSE;
}
 
/* 另一个回调函数 */
void destroy( GtkWidget *widget, gpointer   data )
{
    gtk_main_quit ();
}
void hello( GtkWidget *widget, gpointer   data )
{
    g_print ("Hello World\n");
}
void New_window( GtkWidget *widget, gpointer   data )
{
    GtkWidget *window;
    GtkWidget *button;
 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);
    g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    button = gtk_button_new_with_label ("Hello world !");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (hello), "1");
    gtk_container_add (GTK_CONTAINER (window), button);
 
    gtk_widget_show (button);
    gtk_widget_show (window);
 
    g_print ("Hello World\n");//temp(data );
}
int main( int   argc, char *argv[] )
{
    GtkWidget *window;
    GtkWidget *button;
    
    gtk_init (&argc, &argv);
    
    /* 创建一个新窗口 */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);
    g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    button = gtk_button_new_with_label ("Open hello world");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (New_window), "1");
    gtk_container_add (GTK_CONTAINER (window), button);
 
    gtk_widget_show (button);
    gtk_widget_show (window);
 
    gtk_main ();
    
    return 0;
}
