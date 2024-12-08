#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include "Model.h"
#include "User.h"
#include "ConUtil.h"
class View
{
public:
	void print_Logo(Model* _model, User* _user) {
		// 'R' 
		ConUtil::fillbox(2, 2, 2, 10, RED);
		ConUtil::fillbox(2, 2, 10, 2, RED);
		ConUtil::fillbox(10, 2, 10, 5, RED);
		ConUtil::fillbox(2, 5, 10, 5, RED); //P
		ConUtil::fillbox(5, 6, 6, 6, RED);
		ConUtil::fillbox(6, 7, 7, 7, RED);
		ConUtil::fillbox(7, 8, 8, 8, RED);
		ConUtil::fillbox(8, 9, 9, 9, RED);
		ConUtil::fillbox(9, 10, 10, 10, RED);
		// 'O'
		ConUtil::fillbox(15, 2, 15, 10, RED);
		ConUtil::fillbox(15, 2, 23, 2, RED);
		ConUtil::fillbox(23, 2, 23, 10, RED);
		ConUtil::fillbox(15, 10, 23, 10, RED);
		// 'O'
		ConUtil::fillbox(28, 2, 28, 10, RED);
		ConUtil::fillbox(28, 2, 36, 2, RED);
		ConUtil::fillbox(36, 2, 36, 10, RED);
		ConUtil::fillbox(28, 10, 36, 10, RED);
		// 'M'
		ConUtil::fillbox(41, 2, 41, 10, RED);
		ConUtil::fillbox(42, 2, 43, 2, RED);
		ConUtil::fillbox(44, 3, 44, 3, RED);
		ConUtil::fillbox(45, 4, 45, 4, RED);
		ConUtil::fillbox(46, 5, 46, 5, RED);
		ConUtil::fillbox(47, 4, 47, 4, RED);
		ConUtil::fillbox(48, 3, 48, 3, RED);
		ConUtil::fillbox(49, 2, 50, 2, RED);
		ConUtil::fillbox(51, 2, 51, 10, RED);
		// 'E'
		ConUtil::fillbox(2, 15, 2, 23, RED);
		ConUtil::fillbox(2, 15, 10, 15, RED);
		ConUtil::fillbox(2, 19, 10, 19, RED);
		ConUtil::fillbox(2, 23, 10, 23, RED);
		// 'S'
		ConUtil::fillbox(15, 15, 23, 15, RED);
		ConUtil::fillbox(15, 15, 15, 19, RED);
		ConUtil::fillbox(15, 19, 23, 19, RED);
		ConUtil::fillbox(23, 19, 23, 23, RED);
		ConUtil::fillbox(15, 23, 23, 23, RED);
		// 'C'
		ConUtil::fillbox(28, 15, 28, 23, RED);
		ConUtil::fillbox(28, 15, 36, 15, RED);
		ConUtil::fillbox(28, 23, 36, 23, RED);
		// 'A'
		ConUtil::fillbox(46, 15, 46, 15, RED);
		ConUtil::fillbox(45, 16, 45, 16, RED);
		ConUtil::fillbox(47, 16, 47, 16, RED);
		ConUtil::fillbox(44, 17, 44, 17, RED);
		ConUtil::fillbox(48, 17, 48, 17, RED);
		ConUtil::fillbox(43, 18, 43, 18, RED);
		ConUtil::fillbox(49, 18, 49, 18, RED);
		ConUtil::fillbox(42, 19, 42, 19, RED);
		ConUtil::fillbox(50, 19, 50, 19, RED);
		ConUtil::fillbox(41, 20, 51, 20, RED);
		ConUtil::fillbox(41, 20, 41, 23, RED);
		ConUtil::fillbox(51, 20, 51, 23, RED);
		// 'P'
		ConUtil::fillbox(56, 15, 56, 23, RED);
		ConUtil::fillbox(56, 15, 64, 15, RED);
		ConUtil::fillbox(64, 15, 64, 18, RED);
		ConUtil::fillbox(56, 18, 64, 18, RED);
		// 'E'
		ConUtil::fillbox(69, 15, 69, 23, RED);
		ConUtil::fillbox(69, 15, 77, 15, RED);
		ConUtil::fillbox(69, 19, 77, 19, RED);
		ConUtil::fillbox(69, 23, 77, 23, RED);
		//Made by KeumSiEon press enter button
		ConUtil::set_background(WHITE);
		ConUtil::set_text(BLACK);
		ConUtil::xyputstr(56, 3, "Input your name and Press (Enter) button");
		ConUtil::fillbox(56, 4, 95, 4, WHITE);
		ConUtil::xyputstr(56, 4, "User Name : ");
		char name[100];
		cin >> name;
		_user->set_Name(name);
	}
	void print_story(Model* _model, User* _user) {
		ConUtil::clear();
		cout << _user->get_Name() << " : 후.. 긴 꿈에서 깨어났다. 꿈의 내용이 명확하게 기억나지 않지만 기분이 좋지 않네.(Press Enter)" << endl;
		cin.get(); cin.ignore();
		cout << _user->get_Name() << " : 그런데 이상하다. 오늘은 주말이고 가족들이 있을 시간인데, 집 안이 너무 조용하다.(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : 느낌이 이상한데.. 일단 거실로 나가봐야겠어,(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : 거실엔 아무도 없고, 집에 있던 창문이 모두 사라졌어. 이게 무슨 일이지?(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : 뭐야 현관문이 안에서 비밀번호가 걸려있잖아..? 갇힌 건가?!(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : 진정하고.. 일단 집 안을 조금 살펴봐야겠어.(Press Enter)" << endl;
		cin.get();
	}
	void start_escape(Model* _model, User* _user) {
		int pos_col = 1, pos_row = 9;
		int visit_room_num = 0;
		int current_room_num = 0;
		bool visited_main = false; //main_room(안방)의 첫 방문여부
		while (true) {
			if (visit_room_num == 0) { //시작 부분, 시작 스폰 지점
				if (current_room_num == 0) {
					current_room_num = 0;
					visit_room_num = locate_living_room(_model, _user, pos_col, pos_row, visited_main);
					continue;
				}
				else if (current_room_num == 1) { // 내 방 -> 거실
					pos_col = 11; pos_row = 0;
					current_room_num = 0;
					visit_room_num = locate_living_room(_model, _user, pos_col, pos_row, visited_main);
					continue;
				}
				else if (current_room_num == 2) { //안방 -> 거실
					pos_col = 39; pos_row = 9;
					current_room_num = 0;
					visit_room_num = locate_living_room(_model, _user, pos_col, pos_row, visited_main);
					continue;
				}
			}
			else if (visit_room_num == 1) { // 거실 -> 내 방
				pos_col = 6; pos_row = 9;
				current_room_num = 1;
				visit_room_num = locate_my_room(_model, _user, pos_col, pos_row);
				continue;
			}
			else if (visit_room_num == 2) { // 거실 -> 안방
				pos_col = 0; pos_row = 7;
				current_room_num = 2;
				visit_room_num = locate_main_room(_model, _user, pos_col, pos_row);
				continue;
			}
		}
	}
	//living_room(visit_room_num == 0)
	static int locate_living_room(Model* _model, User* _user, int& _pos_col, int& _pos_row, bool& _visited_main) {
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
			case 2: {
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				char last_password[5] = "0000";
				ConUtil::draw_Sign(_model, _user, "현관 비밀번호(숫자 4자리) : 0000");
				ConUtil::show_cursor();
				int start_x = 78;
				int start_y = 16;
				gotoxy(start_x, start_y);
				int p_key;
				int current_x = 0;
				while ((p_key = ConUtil::getkey())) {
					bool check_enter = false;
					switch (p_key) {
					case UPKEY:
						break;
					case DOWNKEY:
						break;
					case RIGHTKEY:
						if (start_x == 81);
						else {
							start_x++; current_x++;
						}
						gotoxy(start_x, start_y);
						break;
					case LEFTKEY:
						if (start_x == 78);
						else {
							start_x--; current_x--;
						}
						gotoxy(start_x, start_y);
						break;
					case ENTER:
						check_enter = true;
						break;
					default:
						ConUtil::xyputc(start_x, start_y, p_key);
						last_password[current_x] = p_key;
						break;
					}
					if (check_enter) {
						break;
					}
				}
				if (strcmp(last_password, "7777") == 0) {
					ConUtil::clear();
					return -1;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 비밀번호.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 3:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				if (pos_col == 11 && pos_row == 0) {
					return 1;
				}
				else if (pos_col == 39 && pos_row == 9) {
					if (!_visited_main) {
						char main_password[5] = "0000";
						ConUtil::draw_Sign(_model, _user, "안방 비밀번호(숫자 4자리) : 0000");
						ConUtil::show_cursor();
						int start_x = 78;
						int start_y = 16;
						gotoxy(start_x, start_y);
						int p_key;
						int current_x = 0;
						while ((p_key = ConUtil::getkey())) {
							bool check_enter = false;
							switch (p_key) {
								case UPKEY:
									break;
								case DOWNKEY:
									break;
								case RIGHTKEY:
									if (start_x == 81);
									else {
										start_x++; current_x++;
									}
									gotoxy(start_x, start_y);
									break;
								case LEFTKEY:
									if (start_x == 78);
									else {
										start_x--; current_x--;
									}
									gotoxy(start_x, start_y);
									break;
								case ENTER:
									check_enter = true;
									break;
								default:
									ConUtil::xyputc(start_x, start_y, p_key);
									main_password[current_x] = p_key;
									break;
							}
							if (check_enter) {
								break;
							}
						}
						if (strcmp(main_password, "4573")==0) {
							_visited_main = true;
							ConUtil::erase_cursor();
							return 2;
						}
						else {
							ConUtil::draw_Sign(_model, _user, "잘못된 비밀번호.");
							ConUtil::erase_cursor();
							break;
						}
					}
					else {
						return 2;
					}
				}
				break;
			case 4:
				ConUtil::drawCharacter(pos_col, pos_row);
				if (old_col != pos_col || old_row != pos_row) {
					ConUtil::drawCell(_model, _model->living_room, old_col, old_row);
				}
				ConUtil::draw_Sign(_model, _user, "뭐야.. 꿈 속인데 사람이 있잖아..? 설마 귀신인가..?!         의문의 할아버지 : 안방에 들어가는 비밀번호를 자네 방에서 찾을 수 있을 걸세.. 숫자 4개를 모아서 중앙에 있는 카펫과 조합을..");
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
	//my_room(visit_room_num == 1)
	static int locate_my_room(Model* _model, User* _user, int &_pos_col, int &_pos_row) {
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
					return 0;
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
				ConUtil::draw_Sign(_model, _user, "카펫에 문양이 새겨져있네.. 이게 뭐지? 사물 위치와 관련된 것 같은데.. < ←↑:4, →↑:2, ←↓:1, →↓:3 >"); //[3]:4, [5]:2, [4]:1, [7]:3 (3547->4573)
			}

		}
	}
	//main_room(visit_room_num == 2)
	static int locate_main_room(Model* _model, User* _user, int &_pos_col, int &_pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->main_room, MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, " ");
		ConUtil::write_room_name(MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT, 2);
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
					return 0;
				}
				break;
			}
		}
	}
};

