#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

int main( int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *menubar;
    GtkWidget *filemenu, *item_file, *item_new, *item_open,*item_quit;
    GtkWidget *editmenu, *item_edit, *item_undo, *item_redo, *item_cut, *item_copy, *item_paste;
    GtkWidget *sep;
    GtkAccelGroup *accel_group = NULL;  //定义快捷键组

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    gtk_window_set_title(GTK_WINDOW(window), "menu better");

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    menubar = gtk_menu_bar_new();   //菜单栏构件（menubar），实际上是一个menu shell

    filemenu = gtk_menu_new();      //菜单构件(menu),也是一个menu shell

    accel_group = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);


    item_file = gtk_menu_item_new_with_mnemonic("_File");   //替代 gtk_menu_item_new_with_label("File");
    item_new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);  //替代gtk_menu_item_new_with_label("New");
    item_open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);//替代gtk_menu_item_new_with_label("Open");
    sep = gtk_separator_menu_item_new();    //生成一条分割线
    item_quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT,accel_group);//替代gtk_menu_item_new_with_label("Quit");

    gtk_widget_add_accelerator(item_quit, "activate", accel_group, GDK_q,GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item_file), filemenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), item_new);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), item_open);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), sep);       //加入分割线到file菜单中
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), item_quit); //把“quit”菜单选项被填加进file菜单中
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), item_file);  //把“file”菜单选项被填加进菜单中（menubar）

    /*这里构建Edit菜单，同上面的file菜单添加方法一样*/
    editmenu = gtk_menu_new();       //菜单构件(menu),也是一个menu shell
    item_edit = gtk_menu_item_new_with_mnemonic("_Edit");
    item_undo = gtk_image_menu_item_new_from_stock(GTK_STOCK_UNDO, NULL);
    item_redo = gtk_image_menu_item_new_from_stock(GTK_STOCK_REDO, NULL);
    sep = gtk_separator_menu_item_new();
    item_cut = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT, NULL);
    item_copy = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, NULL);
    item_paste = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, NULL);

    gtk_widget_add_accelerator(item_undo, "activate", accel_group, GDK_z,GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(item_redo, "activate", accel_group, GDK_r,GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(item_cut, "activate", accel_group, GDK_x,GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(item_copy, "activate", accel_group, GDK_c,GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(item_paste, "activate", accel_group, GDK_v,GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item_edit), editmenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_undo);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_redo);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), sep);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_cut);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_copy);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), item_paste);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), item_edit);      //把“edit”菜单选项被填加进菜单中（menubar）


    /*这里把窗口分为了上中下3个区域，最上面是menubar*/
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

    g_signal_connect(G_OBJECT(item_quit),
                     "activate",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
