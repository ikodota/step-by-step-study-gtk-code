#include <gtk/gtk.h>
int main( int argc, char *argv[])
{
    GtkWidget *window;
    /*gtk初始化*/
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /*gtk_window_set_title() 这个函数就可以为window 设置一个标题，如果我们不用这个
    函数的话，GTK+将用源文件的名字来作为窗口的标题。*/

    gtk_window_set_title(GTK_WINDOW(window), "Hello world");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);      //设置窗体大小
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//把窗口设定在显示器的中央
    gtk_widget_show(window);                                        //显示窗体
    g_signal_connect_swapped(G_OBJECT(window), "destroy",           //当点击关闭按钮时候退出gtk。
                             G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return 0;
}
