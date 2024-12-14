#pragma once
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
	static void show_cursor() {
		_setcursortype(0);
	}
	static void erase_cursor() {
		_setcursortype(1);
	}
	//방의 크기와 방 번호를 매개변수로 받아 방 아래위치를 구해서 방 이름 출력
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
		case 3:
			xyputstr(x, y, "튜토리얼");
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
		ConUtil::xyputstr(50, 3, "직업:프로그래머 / 특징:정리 강박증, 공대식 생각");
		ConUtil::xyputstr(50, 4, "보유 아이템: ");
		int length_x = 62;
		int length_y = 4;
		for (int i = 0; i < _user->get_inventory_size(); i++) {
			if (_user->item[i] != NULL && length_x + strlen(_user->item[i]) >= 100) {
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
		int maxLength = 65;			// 줄의 최대 길이(안내문 범위)
		gotoxy(start_x, start_y);
		while (*current != '\0') { 
			const char* start = current; 
			int segmentLength = 0;
			while (*current != '\0' && segmentLength < maxLength) {
				current++;
				segmentLength++;
			}
			if (*current != '\0' && *(current - 1) != ' ') {
				while (current > start && *current != ' ') {
					current--;
					segmentLength--;
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
	static void make_passable_Cell(Model* _model, int _pos_col, int _pos_row, int _old_col, int _old_row, int _room_num) {
		if (_room_num == 0) {
			ConUtil::drawCharacter(_pos_col, _pos_row);
			if (_old_col != _pos_col || _old_row != _pos_row) {
				ConUtil::drawCell(_model, _model->living_room, _old_col, _old_row);
			}
		}
		else if (_room_num == 1) {
			ConUtil::drawCharacter(_pos_col, _pos_row);
			if (_old_col != _pos_col || _old_row != _pos_row) {
				ConUtil::drawCell(_model, _model->my_room, _old_col, _old_row);
			}
		}
		else if (_room_num == 2) {
			ConUtil::drawCharacter(_pos_col, _pos_row);
			if (_old_col != _pos_col || _old_row != _pos_row) {
				ConUtil::drawCell(_model, _model->main_room, _old_col, _old_row);
			}
		}
		else if (_room_num == 3) {
			ConUtil::drawCharacter(_pos_col, _pos_row);
			if (_old_col != _pos_col || _old_row != _pos_row) {
				ConUtil::drawCell(_model, _model->tutorial_room, _old_col, _old_row);
			}
		}
	}
	static void make_password_line(Model* _model, int _start_x, int _start_y, char _input_code[]) {
		gotoxy(_start_x, _start_y);
		int p_key;
		int current_x = 0;
		int max_x = _start_x + 3;
		int min_x = _start_x;
		while ((p_key = ConUtil::getkey())) {
			bool check_enter = false;
			switch (p_key) {
			case UPKEY:
				break;
			case DOWNKEY:
				break;
			case RIGHTKEY:
				if (_start_x == max_x);
				else {
					_start_x++;  current_x++;
				}
				gotoxy(_start_x, _start_y);
				break;
			case LEFTKEY:
				if (_start_x == min_x);
				else {
					_start_x--;  current_x--;
				}
				gotoxy(_start_x, _start_y);
				break;
			case ENTER:
				check_enter = true;
				break;
			default:
				ConUtil::xyputc(_start_x, _start_y, p_key);
				_input_code[current_x] = p_key;
				break;
			}
			if (check_enter) {
				_model->set_input_password(_input_code);
				break;
			}
		}
	}
	static void make_direction_password_line(Model* _model, int _start_x, int _start_y, char _input_code[]) {
		gotoxy(_start_x, _start_y);
		int p_key;
		int current_x = 0;
		while ((p_key = ConUtil::getkey())) {
			bool check_enter = false;
			switch (p_key) {
			case UPKEY:
				if (current_x < 9) {
					_input_code[current_x] = 'u';
					current_x++;
					ConUtil::xyputstr(_start_x, _start_y, "↑");
				}
				else {
					ConUtil::xyputstr(_start_x, _start_y, "입력완료");
				}
				break;
			case DOWNKEY:
				if (current_x < 9) {
					_input_code[current_x] = 'd';
					current_x++;
					ConUtil::xyputstr(_start_x, _start_y, "↓");
				}
				else {
					ConUtil::xyputstr(_start_x, _start_y, "입력완료");
				}
				break;
			case RIGHTKEY:
				if (current_x < 9) {
					_input_code[current_x] = 'r';
					current_x++;
					ConUtil::xyputstr(_start_x, _start_y, "→");
				}
				else {
					ConUtil::xyputstr(_start_x, _start_y, "입력완료");
				}
				break;
			case LEFTKEY:
				if (current_x < 9) {
					_input_code[current_x] = 'l';
					current_x++;
					ConUtil::xyputstr(_start_x, _start_y, "←");
				}
				else {
					ConUtil::xyputstr(_start_x, _start_y, "입력완료");
				}
				break;
			case ENTER:
				check_enter = true;
				break;
			default:
				ConUtil::xyputstr(_start_x, _start_y, "방향키를 입력하세요.");
				break;
			}
			if (check_enter) {
				_model->set_direction_password(_input_code);
				break;
			}
		}
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
		puts(_model->living_room_cellSymbol[cell]);
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
		puts(_model->main_room_cellSymbol[cell]);
	}
	static void drawMap(Model* _model, int map[][30], int width, int height) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				drawCell(_model, map, col, row);
			}
		}
	}
	//Draw My Room @Overload
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
		puts(_model->my_room_cellSymbol[cell]);
	}
	static void drawMap(Model* _model, int map[][20], int width, int height) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				drawCell(_model, map, col, row);
			}
		}
	}
};

