#include <gtk/gtk.h>
int main( int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *menubar;
    GtkWidget *filemenu, *item_file, *item_new, *item_quit;
    GtkWidget *editmenu, *item_edit, *item_undo, *item_redo, *item_cut, *item_copy, *item_paste;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    gtk_window_set_title(GTK_WINDOW(window), "menu demo");

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    menubar = gtk_menu_bar_new();   //菜单栏构件（menubar），实际上是一个menu shell

    filemenu = gtk_menu_new();      //菜单构件(menu),也是一个menu shell
    item_file = gtk_menu_item_new_with_label("File");
    item_new = gtk_menu_item_new_with_label("New");
    item_quit = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item_file), filemenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), item_new);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), item_quit); //把“quit”菜单选项被填加进file菜单中
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), item_file);  //把“file”菜单选项被填加进菜单中（menubar）

    /*这里构建Edit菜单，同上面的file菜单添加方法一样*/
    editmenu = gtk_menu_new();       //菜单构件(menu),也是一个menu shell
    item_edit = gtk_menu_item_new_with_label("Edit");
    item_undo = gtk_menu_item_new_with_label("Undo");
    item_redo = gtk_menu_item_new_with_label("Redo");
    item_cut = gtk_menu_item_new_with_label("Cut");
    item_copy = gtk_menu_item_new_with_label("Copy");
    item_paste = gtk_menu_item_new_with_label("Paste");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item_edit), editmenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_redo);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_cut);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_copy);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_paste);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), item_edit);      //把“edit”菜单选项被填加进菜单中（menubar）


    /*这里把窗口分为了上中下3个区域，最上面是menubar*/
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);


    g_signal_connect_swapped(G_OBJECT(window),
                             "destroy",G_CALLBACK(gtk_main_quit), NULL);
    /*信号：当你单击“quit”菜单按钮，程序就会退出。*/
    g_signal_connect(G_OBJECT(item_quit),
                     "activate",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
