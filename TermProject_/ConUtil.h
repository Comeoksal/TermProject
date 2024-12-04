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
		int x = (_width / 2) - 2;
		int y = _height + 1;
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
			xyputstr(x, y, "부엌");
			break;
		case 3:
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
		ConUtil::xyputstr(50, 3, "직업:프로그래머");
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
			else {
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
		int length_x = 50;
		int length_y = 16;
		const char* current = str;  // 현재 위치를 가리키는 포인터
		int currentLength = 0;      // 현재 줄의 길이
		int maxLength = 65;
		gotoxy(length_x, length_y);
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
			length_y++;
			gotoxy(length_x, length_y);
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
		gotoxy(col + 1, row + 1);
		puts(_model->cellSymbol[cell]);
	}
	static void drawMap(Model* _model, int map[][40], int width, int height) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				drawCell(_model, map, col, row);
			}
		}
	}
	//Draw Main Room @Override
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
	//Draw My Room & Kitchen @Override
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
	//locate_living_room(0)
	static void locate_living_room(Model* _model, User* _user, int _pos_col, int _pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->living_room, LIVING_WIDTH, LIVING_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, " ");
		ConUtil::write_room_name(LIVING_WIDTH, LIVING_HEIGHT, 0);
		ConUtil::erase_cursor();
		ConUtil::drawCharacter(_pos_col, _pos_row);
		int key;
		int password = 0;
		bool first_visit_main = true;
		int pos_col = _pos_col;
		int pos_row = _pos_row;
		while ((key = ConUtil::getkey())) {
			//이벤트 발생 후 상태창, 안내문 업데이트
			if (_model->living_room[pos_row][pos_col] != 0 && _model->living_room[pos_row][pos_col] != 3) {
				ConUtil::draw_UserStatus(_model, _user);
				ConUtil::draw_Sign(_model, _user, " ");
			}
			int old_col = pos_col;
			int old_row = pos_row;
			switch (key) {
			case UPKEY:
				if (pos_row - 1 >= 0 && _model->living_room[pos_row - 1][pos_col] != 1) {
					pos_row--;
				}
				break;
			case DOWNKEY:
				if (pos_row + 1 < LIVING_HEIGHT && _model->living_room[pos_row + 1][pos_col] != 1) {
					pos_row++;
				}
				break;
			case RIGHTKEY:
				if (pos_col + 1 < LIVING_WIDTH && _model->living_room[pos_row][pos_col + 1] != 1) {
					pos_col++;
				}
				break;
			case LEFTKEY:
				if (pos_col - 1 >= 0 && _model->living_room[pos_row][pos_col - 1] != 1) {
					pos_col--;
				}
				break;
			}
			/*gotoxy(50, 10);
			cout << "pos_row : " << pos_row << endl;
			gotoxy(50, 11);
			cout << "pos_col : " << pos_col << endl;*/
			switch (_model->living_room[pos_row][pos_col]) {
			case 0:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "현관 비밀번호(숫자 4자리) : ");
				cin >> password;
				if (password == 1234) {
					ConUtil::set_background(WHITE);
					ConUtil::clear();
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 비밀번호.");
					password = 0;
					break;
				}
				break;
			case 3:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				if (pos_col == 11 && pos_row == 0) {
					ConUtil::locate_my_room(_model, _user, 6, 9);
				}
				else if (pos_col == 27 && pos_row == 19) {
					ConUtil::locate_kitchen(_model, _user, 13, 0);
				}
				else if (pos_col == 39 && pos_row == 9) {
					if (first_visit_main) {
						ConUtil::draw_Sign(_model, _user, "안방 비밀번호(숫자 4자리) : ");
						cin >> password;
						if (password == 4573) {
							first_visit_main = false;
							ConUtil::locate_main_room(_model, _user, 0, 7);
						}
						else {
							ConUtil::draw_Sign(_model, _user, "잘못된 비밀번호.");
							password = 0;
							break;
						}
					}
					else {
						ConUtil::locate_main_room(_model, _user, 0, 7);
					}
				}
				break;
			case 4:
				break;
			case 5:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				if (_user->find_inventory("#(휴대폰)")) {
					ConUtil::draw_Sign(_model, _user, "전화가 연결되는 곳이다. 휴대폰을 사용해서 연결합니다..(신호음이 [3]번 울리고 끊긴다)");
					_model->my_room[pos_col][pos_row] = 5;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "전화가 연결되는 곳이다. 휴대폰이 필요하다.");
				}
				break;
			}
		}
	}
	//locate_my_room(1)
	static void locate_my_room(Model* _model, User* _user, int _pos_col, int _pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->my_room, MY_ROOM_WIDTH, MY_ROOM_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, " ");
		ConUtil::write_room_name(MY_ROOM_WIDTH, MY_ROOM_HEIGHT, 1);
		ConUtil::erase_cursor();
		ConUtil::drawCharacter(_pos_col, _pos_row);
		int key;
		int pos_col = _pos_col;
		int pos_row = _pos_row;
		while ((key = ConUtil::getkey())) {
			//이벤트 발생 후 상태창, 안내문 업데이트
			if (_model->my_room[pos_row][pos_col] != 0 && _model->my_room[pos_row][pos_col] != 3) {
				ConUtil::draw_UserStatus(_model, _user);
				ConUtil::draw_Sign(_model, _user, " ");
			}
			int old_col = pos_col;
			int old_row = pos_row;
			switch (key) {
			case UPKEY:
				if (pos_row - 1 >= 0 && _model->my_room[pos_row - 1][pos_col] != 1) {
					pos_row--;
				}
				break;
			case DOWNKEY:
				if (pos_row + 1 < MY_ROOM_HEIGHT && _model->my_room[pos_row + 1][pos_col] != 1) {
					pos_row++;
				}
				break;
			case RIGHTKEY:
				if (pos_col + 1 < MY_ROOM_WIDTH && _model->my_room[pos_row][pos_col + 1] != 1) {
					pos_col++;
				}
				break;
			case LEFTKEY:
				if (pos_col - 1 >= 0 && _model->my_room[pos_row][pos_col - 1] != 1) {
					pos_col--;
				}
				break;
			}
			/*gotoxy(50, 10);
			cout << "pos_row : " << pos_row << endl;
			gotoxy(50, 11);
			cout << "pos_col : " << pos_col << endl;*/
			switch (_model->my_room[pos_row][pos_col]) {
			case 0:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				break;
			case 3:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				if (pos_col == 6 && pos_row == 9) {
					ConUtil::locate_living_room(_model, _user, 11, 0);
				}
				break;
			case 4:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "책상위에 놓인 휴대폰을 획득했다.");
				_user->set_inventory("#(휴대폰)");
				_model->my_room[pos_row][pos_col] = 1;
				break;
			case 5:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				if (_user->find_inventory("#(휴대폰)")) {
					ConUtil::draw_Sign(_model, _user, "이제 이 곳에서도 전화가 연결된다. 내용은 아까와 똑같다..<신호음이[?]번 울리고 끊긴다>");
				}
				break;
			case 6:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "책장의 노트에 무언가 써있다. 이게 뭐지..? 공대생의 수학 실력을 발휘해야겠어.< @+# = 9, $+% = 7, @+$ = 5, #+$ =12, 2@+% = [?] >");
				break;
			case 7:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "옷장에 옷이 걸려있다. 색깔이 뒤죽박죽인데.. 결벽증 때문에 정리 해야겠어.< (빨 노 주 파 보 초 남)/ 최소 교환 횟수 = [?] >");
				break;
			case 8:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "침대 아래에 건전지가 있다. 좋아 이거로 손목시계를 고칠 수 있겠어. < 현재 시각 = [?] >");
				if (_user->find_inventory("§(고장난 손목시계)")) {
					_user->remove_inventory("§(고장난 손목시계)");
					_user->set_inventory("§(손목시계 [현재 시각 : 19시])");
				}
				break;
			case 9:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->my_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "카펫에 문양이 새겨져있네. 사물 위치와 관련된 것 같은데..? < ←↑:4, →↑:2, ←↓:1, →↓:3 >"); //[3]:4, [5]:2, [4]:1, [7]:3 (3547->4573)
			}

		}
	}
	//locate_kitchen(2)
	static void locate_kitchen(Model* _model, User* _user, int _pos_col, int _pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->kitchen, KITCHEN_WIDTH, KITCHEN_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, " ");
		ConUtil::write_room_name(KITCHEN_WIDTH, KITCHEN_HEIGHT, 2);
		ConUtil::erase_cursor();
		ConUtil::drawCharacter(_pos_col, _pos_row);
		int key;
		int pos_col = _pos_col;
		int pos_row = _pos_row;
		while ((key = ConUtil::getkey())) {
			if (_model->kitchen[pos_row][pos_col] != 0 && _model->kitchen[pos_row][pos_col] != 3) {
				ConUtil::draw_UserStatus(_model, _user);
				ConUtil::draw_Sign(_model, _user, " ");
			}
			int old_col = pos_col;
			int old_row = pos_row;
			switch (key) {
			case UPKEY:
				if (pos_row - 1 >= 0 && _model->kitchen[pos_row - 1][pos_col] != 1) {
					pos_row--;
				}
				break;
			case DOWNKEY:
				if (pos_row + 1 < KITCHEN_HEIGHT && _model->kitchen[pos_row + 1][pos_col] != 1) {
					pos_row++;
				}
				break;
			case RIGHTKEY:
				if (pos_col + 1 < KITCHEN_WIDTH && _model->kitchen[pos_row][pos_col + 1] != 1) {
					pos_col++;
				}
				break;
			case LEFTKEY:
				if (pos_col - 1 >= 0 && _model->kitchen[pos_row][pos_col - 1] != 1) {
					pos_col--;
				}
				break;
			}
			/*gotoxy(50, 10);
			cout << "pos_row : " << pos_row << endl;
			gotoxy(50, 11);
			cout << "pos_col : " << pos_col << endl;*/
			switch (_model->kitchen[pos_row][pos_col]) {
			case 0:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->kitchen, old_col, old_row);
				}
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				break;
			case 3:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->kitchen, old_col, old_row);
				}
				if (pos_col == 13 && pos_row == 0) {
					ConUtil::locate_living_room(_model, _user, 27, 19);
				}
				break;
			}
		}
	}
	//locate_main_room(3)
	static void locate_main_room(Model* _model, User* _user, int _pos_col, int _pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->main_room, MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, " ");
		ConUtil::write_room_name(MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT, 3);
		ConUtil::erase_cursor();
		ConUtil::drawCharacter(_pos_col, _pos_row);
		int key;
		int pos_col = _pos_col;
		int pos_row = _pos_row;
		while ((key = ConUtil::getkey())) {
			if (_model->main_room[pos_row][pos_col] != 0 && _model->main_room[pos_row][pos_col] != 3) {
				ConUtil::draw_UserStatus(_model, _user);
				ConUtil::draw_Sign(_model, _user, " ");
			}
			int old_col = pos_col;
			int old_row = pos_row;
			switch (key) {
			case UPKEY:
				if (pos_row - 1 >= 0 && _model->main_room[pos_row - 1][pos_col] != 1) {
					pos_row--;
				}
				break;
			case DOWNKEY:
				if (pos_row + 1 < MAIN_ROOM_HEIGHT && _model->main_room[pos_row + 1][pos_col] != 1) {
					pos_row++;
				}
				break;
			case RIGHTKEY:
				if (pos_col + 1 < MAIN_ROOM_WIDTH && _model->main_room[pos_row][pos_col + 1] != 1) {
					pos_col++;
				}
				break;
			case LEFTKEY:
				if (pos_col - 1 >= 0 && _model->main_room[pos_row][pos_col - 1] != 1) {
					pos_col--;
				}
				break;
			}
			/*gotoxy(50, 10);
			cout << "pos_row : " << pos_row << endl;
			gotoxy(50, 11);
			cout << "pos_col : " << pos_col << endl;*/
			switch (_model->main_room[pos_row][pos_col]) {
			case 0:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->main_room, old_col, old_row);
				}
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				break;
			case 3:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->main_room, old_col, old_row);
				}
				if (pos_col == 0 && pos_row == 7) {
					ConUtil::locate_living_room(_model, _user, 39, 9);
				}
				break;
			}
		}
	}
};

