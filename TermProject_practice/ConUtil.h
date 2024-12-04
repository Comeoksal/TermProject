#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <cstring>
#include "consola.h"
#include "Keyset.h"
#include "Model.h"
#include "User.h"
using namespace std;
class ConUtil
{
public:
	static int getkey() {
		int key = _getch();
		if (key == 0xe0) {
			return ((0x00e0 << 8) | _getch());
		}
		else {
			return key;
		}
	}
	static void xyputc(int x, int y, char ch) {
		gotoxy(x, y);
		cout << ch;
	}
	static void xyputstr(int x, int y, const char str[]) {
		gotoxy(x, y);
		cout << str;
	}
	static void fillbox(int x1, int y1, int x2, int y2, char color) {
		textbackground(color);
		for (int y = y1; y <= y2; y++) {
			for (int x = x1; x <= x2; x++) {
				xyputc(x, y, ' ');
			}
		}
	}
	static void set_background(char color) {
		textbackground(color);
	}
	static void set_text(char color) {
		textcolor(color);
	}
	static void clear() {
		clrscr();
	}
	static void erase_cursor() {
		_setcursortype(1);
	}
	static void write_room_name(int _width, int _height, int _roomnum) {
		int x = (_width /2)- 2;
		int y = _height+1;
		ConUtil::set_background(YELLOW);
		ConUtil::set_text(BLACK);
		switch (_roomnum) {
		case 0:
			xyputstr(x, y, "거실");
			break;
		case 1:
			xyputstr(x, y, "내 방");
			break;
		case 2:
			xyputstr(x, y, "안방");
			break;
		}
	}
	static void draw_UserStatus(Model* _model, User* _user) {
		ConUtil::fillbox(49, 1, 101, 13, DARKGRAY);
		ConUtil::fillbox(71, 1, 71, 1, LIGHTGRAY);
		ConUtil::fillbox(78, 1, 78, 1, LIGHTGRAY);
		ConUtil::fillbox(50, 2, 100, 12, YELLOW);
		ConUtil::set_text(WHITE);
		ConUtil::set_background(DARKGRAY);
		ConUtil::xyputstr(72, 1, "상태창");
		ConUtil::set_text(BLACK);
		ConUtil::set_background(YELLOW);
		ConUtil::xyputstr(50, 2, "이름: ");
		ConUtil::xyputstr(55, 2, _user->get_Name());
		ConUtil::xyputstr(50, 3, "직업:프로그래머 / 특징:결벽증 있음");
		ConUtil::xyputstr(50, 4, "보유 아이템: ");
		int length_x = 62;
		int length_y = 4;
		for (int i = 0; i < _user->get_inventory_size(); i++) {
			if (_user->item[i]!=NULL && length_x + strlen(_user->item[i]) >= 100) {
				length_x = 62; length_y++;
			}
			else {
				;
			}
			if (_user->item[i] != NULL) {
				ConUtil::xyputstr(length_x, length_y, _user->item[i]);
			}
			else{
				break;
			}
			length_x += strlen(_user->item[i]);
		}
	}
	static void draw_Sign(Model* _model, User* _user, const char* str) {
		ConUtil::fillbox(49, 15, 116, 24, DARKGRAY);
		ConUtil::fillbox(71, 15, 71, 15, LIGHTGRAY);
		ConUtil::fillbox(78, 15, 78, 15, LIGHTGRAY);
		ConUtil::fillbox(50, 16, 115, 23, YELLOW);
		ConUtil::set_text(WHITE);
		ConUtil::set_background(DARKGRAY);
		ConUtil::xyputstr(72, 15, "안내문");
		ConUtil::set_text(BLACK);
		ConUtil::set_background(YELLOW);
		int start_x = 50;
		int start_y = 16;
		const char* current = str;  // 현재 위치를 가리키는 포인터
		int currentLength = 0;      // 현재 줄의 길이
		int maxLength = 65;
		gotoxy(start_x, start_y);
		while (*current != '\0') { 
			const char* start = current; 
			int segmentLength = 0;
			while (*current != '\0' && segmentLength < maxLength) {
				++current;
				++segmentLength;
			}
			if (*current != '\0' && *(current - 1) != ' ') {
				while (current > start && *current != ' ') {
					--current;
					--segmentLength;
				}
				if (current == start) {
					current = start + maxLength;
					segmentLength = maxLength;
				}
			}
			cout.write(start, segmentLength);
			cout << endl;
			start_y++;
			gotoxy(start_x, start_y);
			while (*current == ' ') {
				++current;
			}
		}
	}
	static void drawCharacter(int col, int row) { 
		textcolor(BLACK);
		textbackground(WHITE);
		ConUtil::xyputstr(col + 1, row + 1, "●");
	}
	//Draw Living Room 
	static void drawCell(Model* _model, int map[][40], int col, int row) {
		int cell = map[row][col];
		switch (cell) {
		case 0:
			textbackground(WHITE);
			break;
		case 1:
			textbackground(DARKGRAY);
			break;
		case 2:
			textbackground(RED);
			break;
		case 3:
			textbackground(BROWN);
			break;
		default:
			textbackground(WHITE);
			break;
		}
		gotoxy(col+1, row +1);
		puts(_model->cellSymbol[cell]);
	}
	static void drawMap(Model* _model, int map[][40], int width, int height) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				drawCell(_model, map, col, row);
			}
		}
	}
	//Draw Main Room @Overload
	static void drawCell(Model* _model, int map[][30], int col, int row) {
		int cell = map[row][col];
		switch (cell) {
		case 0:
			textbackground(WHITE);
			break;
		case 1:
			textbackground(DARKGRAY);
			break;
		case 2:
			textbackground(RED);
			break;
		case 3:
			textbackground(BROWN);
			break;
		default:
			textbackground(WHITE);
			break;
		}
		gotoxy(col + 1, row + 1);
		puts(_model->cellSymbol[cell]);
	}
	static void drawMap(Model* _model, int map[][30], int width, int height) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				drawCell(_model, map, col, row);
			}
		}
	}
	//Draw My Room & Kitchen @Overload
	static void drawCell(Model* _model, int map[][20], int col, int row) {
		int cell = map[row][col];
		switch (cell) {
		case 0:
			textbackground(WHITE);
			break;
		case 1:
			textbackground(DARKGRAY);
			break;
		case 2:
			textbackground(RED);
			break;
		case 3:
			textbackground(BROWN);
			break;
		default:
			textbackground(WHITE);
			break;
		}
		gotoxy(col + 1, row + 1);
		puts(_model->cellSymbol[cell]);
	}
	static void drawMap(Model* _model, int map[][20], int width, int height) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				drawCell(_model, map, col, row);
			}
		}
	}
};

