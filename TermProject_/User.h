#pragma once
#include <conio.h>
#include <cstring>
class User
{
	char name[100];
	int easter_egg2;
	bool easter_egg5;
	int inventory_size;

public:
	User() {
		inventory_size = 14;
		easter_egg2 = 0;
		easter_egg5 = true;
	}
	void set_Name(char* _name) {
		strcpy_s(name, 100, _name);
	}
	char* get_Name() {
		return name;
	}
	const char* item[15] = { "§(고장난 손목시계)", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	void set_inventory(const char* _item) {
		int size = sizeof(item) / sizeof(item[0]);
		for (int i = 0; i < size; i++) {
			if (item[i] == NULL) {
				item[i] = _item;
				break;
			}
		}
	}
	void remove_inventory(const char* _item) {
		int size = sizeof(item) / sizeof(item[0]);
		for (int i = 0; i < size; i++) {
			if (item[i] == _item) {
				item[i] = NULL;
				break;
			}
		}
	}
	bool find_inventory(const char* _item) {
		int size = sizeof(item) / sizeof(item[0]);
		for (int i = 0; i < size; i++) {
			if (item[i] == _item) {
				return 1;
			}
		}
		return 0;
	}
	int get_inventory_size() {
		return inventory_size;
	}
	void set_easter_egg2() {
		easter_egg2++;
	}
	int get_easter_egg2() {
		return easter_egg2;
	}
	void set_easter_egg5(bool _tf) {
		easter_egg5 = _tf;
	}
	int get_easter_egg5() {
		return easter_egg5;
	}
};