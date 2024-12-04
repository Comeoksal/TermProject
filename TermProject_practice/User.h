#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <cstring>
class User
{
	char name[100];
	int inventory_size;
public:
	User() {
		inventory_size = 12;
	}
	const char* item[8] = { "§(고장난 손목시계)", NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	void set_Name(char* _name) {
		strcpy_s(name, 100, _name);
	}
	char* get_Name() {
		return name;
	}
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
};