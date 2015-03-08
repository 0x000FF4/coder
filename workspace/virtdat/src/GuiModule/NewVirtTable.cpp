/*
 * NewVirtTable.cpp
 *
 *  Created on: 8.03.2015 г.
 *      Author: x000ff4
 */

#include "NewVirtTable.h"
int numberOfColumns;
GtkGrid *table;

std::vector<GtkEntry*> entries;
std::vector<GtkWidget*> autoIncrs;
std::vector<GtkWidget*> isNulls;
std::vector<GtkComboBoxText*> types;


void createTableButton(GtkWidget *widget, gpointer data) {
	std::vector<std::VirtColum> columns;
	std::VirtColum column1("column1", std::TYPE::TEXT, false, false);
	std::VirtColum column2("column2", std::TYPE::BOOLEAN, true, false);
	std::VirtColum column3("column3", std::TYPE::BLOB, false, true);
	std::VirtColum column4("column4", std::TYPE::INTEGER, true, true);
	std::VirtColum column5("column5", std::TYPE::TEXT, false, true);
	columns.push_back(column1);
	columns.push_back(column2);
	columns.push_back(column3);
	columns.push_back(column4);
	columns.push_back(column5);
}
void callBack(GtkWidget *widget, gpointer data) {

	numberOfColumns++;
	printf("11 \n");
	autoIncrs.push_back(gtk_check_button_new());
	isNulls.push_back(gtk_check_button_new());
	types.push_back(GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new()));
	entries.push_back(GTK_ENTRY(gtk_entry_new()));
	gtk_combo_box_text_append_text(types.back(),"TEXT");
	gtk_combo_box_text_append_text(types.back(),"BOOLEAN");
	gtk_combo_box_text_append_text(types.back(),"INTEGER");
	gtk_combo_box_text_append_text(types.back(),"BLOB");
	gtk_combo_box_text_append_text(types.back(),"REAL");
	gtk_grid_attach(table, GTK_WIDGET(entries.back()), 0, numberOfColumns, 1, 1);
	gtk_grid_attach(table,GTK_WIDGET( types.back()), 1, numberOfColumns, 1, 1);
	gtk_grid_attach(table, autoIncrs.back(), 2, numberOfColumns, 1, 1);
	gtk_grid_attach(table, isNulls.back(), 3, numberOfColumns, 1, 1);
	gtk_widget_show(GTK_WIDGET(entries.back()));
	gtk_widget_show(GTK_WIDGET(types.back()));
	gtk_widget_show(autoIncrs.back());
	gtk_widget_show(isNulls.back());
}
void NewVirtTable::createNewTable() {
	GtkWidget *new_window;
	GtkButton *newColumn;
	GtkButton *createTable;

	GtkWidget *name;
	GtkWidget *typeName;
	GtkWidget *autoIncrement;
	GtkWidget *notNull;
	GtkEntry *entry;
	GtkWidget *isAutoIncr;
	GtkWidget *isNull;
	GtkWidget *frame;
	GtkComboBoxText *type;
	numberOfColumns = 1;
	name  = gtk_label_new("Име");
	typeName = gtk_label_new("Тип");
	autoIncrement = gtk_label_new("Самоувеличаване  ");
	notNull = gtk_label_new("Задължително  ");
	isAutoIncr = gtk_check_button_new();
	isNull = gtk_check_button_new();
	type  = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
	entry = GTK_ENTRY(gtk_entry_new());
	table = GTK_GRID(gtk_grid_new());
	newColumn = GTK_BUTTON(gtk_button_new());
	createTable = GTK_BUTTON(gtk_button_new_with_label("Създай таблица"));
	gtk_combo_box_text_append_text(type,"TEXT");
	gtk_combo_box_text_append_text(type,"BOOLEAN");
	gtk_combo_box_text_append_text(type,"INTEGER");
	gtk_combo_box_text_append_text(type,"BLOB");
	gtk_combo_box_text_append_text(type,"REAL");
	gtk_button_set_image(newColumn, gtk_image_new_from_file("newColumn.png"));
	gtk_widget_set_size_request(GTK_WIDGET(newColumn), 50, 50);
	gtk_widget_set_size_request(GTK_WIDGET(entry), 10, 10);
	gtk_widget_set_size_request(GTK_WIDGET(createTable), 150, 30);

	new_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	frame = gtk_fixed_new();
	gtk_container_add((GtkContainer*) new_window, (GtkWidget*) frame);

	gtk_widget_set_size_request(new_window, 400, 500);
	gtk_window_set_position(GTK_WINDOW(new_window), GTK_WIN_POS_CENTER);

	gtk_grid_attach(table, name, 0, 0, 1, 1);
	gtk_grid_attach(table, typeName, 1, 0, 1, 1);
	gtk_grid_attach(table,autoIncrement , 2, 0, 1, 1);
	gtk_grid_attach(table, notNull, 3, 0, 1, 1);

	gtk_grid_attach(table, GTK_WIDGET(entry), 0, 1, 1, 1);
	gtk_grid_attach(table, GTK_WIDGET(type), 1, 1, 1, 1);
	gtk_grid_attach(table, isAutoIncr, 2, 1, 1, 1);
	gtk_grid_attach(table, isNull, 3, 1, 1, 1);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(table), 100, 50);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(newColumn), 10, 10);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(createTable), 230, 450);

	gtk_widget_set_events(new_window,
			GDK_EXPOSURE_MASK | GDK_LEAVE_NOTIFY_MASK | GDK_BUTTON_PRESS_MASK
					| GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK
					| GDK_POINTER_MOTION_HINT_MASK);
	g_signal_connect(newColumn, "clicked", G_CALLBACK(callBack), NULL);
	gtk_widget_show_all(new_window);
	gtk_main();
}
NewVirtTable::NewVirtTable(CommandAndControll* comAndcontrol) {
	this->comAndcontrol = comAndcontrol;

}

NewVirtTable::~NewVirtTable() {
	// TODO Auto-generated destructor stub
}
