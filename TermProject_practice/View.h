#pragma once
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
	void play_tutorial(Model* _model, User* _user) {
		ConUtil::erase_cursor();
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::set_text(BLACK);
		ConUtil::fillbox(10, 8, 101, 23, DARKGRAY);
		ConUtil::fillbox(11, 9, 100, 22, LIGHTGRAY);
		ConUtil::xyputstr(47, 9, "<안내 사항>");
		ConUtil::xyputc(48, 11, ' ');
		cout << _user->get_Name() << "님!";
		ConUtil::xyputstr(18, 14, " 지금부터 튜토리얼을 시작합니다. 튜토리얼 내용을 꼭 숙지해주세요! (Press Enter)");
		cin.get(); cin.ignore();
		int pos_col = 1, pos_row = 1;
		locate_tutorial_room(_model, _user, pos_col, pos_row);
	}
	void print_start_story(Model* _model, User* _user) {
		ConUtil::erase_cursor();
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::set_background(WHITE);
		ConUtil::set_text(BLACK);
		ConUtil::xyputstr(16, 3, "후.. 긴 꿈에서 깨어났다. 꿈의 내용이 명확하게 기억나지 않지만 기분이 좋지 않네.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(17, 5, "그런데 이상하다.오늘은 주말이고 가족들이 있을 시간인데, 집 안이 너무 조용하다.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(34, 7, "느낌이 이상한데..일단 거실로 나가봐야겠어, (Press Enter)");
		cin.get();
		ConUtil::xyputstr(21, 9, "거실엔 아무도 없고, 집에 있던 창문이 모두 사라졌어.이게 무슨 일이지 ? (Press Enter)");
		cin.get();
		ConUtil::xyputstr(25, 11, "뭐야 현관문이 안에서 비밀번호가 걸려있잖아.. ? 갇힌 건가 ? !(Press Enter)");
		cin.get();
		ConUtil::xyputstr(34, 13, "진정하고..일단 집 안을 조금 살펴봐야겠어.(Press Enter)");
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
			else {
				break;
			}
		}
	}
	void print_ending_story(Model* _model, User* _user) {
		ConUtil::erase_cursor();
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::set_background(WHITE);
		ConUtil::set_text(BLACK);
		ConUtil::xyputstr(16, 2, "윽..! 드디어 집에서..어..? 여긴 병원..?(Press Enter)");
		cin.get();
		ConUtil::xyputstr(17, 4, "아빠 : 정신이 좀 드니? 너 이틀동안 못 일어났어.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(18, 6, "정말..꿈에서 본 기억들이 진짜였구나.. 회사는 어떻게 됐어..? (Press Enter)");
		cin.get();
		ConUtil::xyputstr(19, 8, "엄마 : 회사에는 우리가 잘 얘기해놨어.. 몇 주간 푹 쉬고, 회복에 전념하렴(Press Enter)");
		cin.get();
		ConUtil::xyputstr(20, 10, "이것도 꿈은 아니겠지? 엄마,아빠 나 좀 꼬집어줘(Press Enter)");
		cin.get();
		ConUtil::erase_cursor();
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::set_background(WHITE);
		ConUtil::set_text(BLACK);
		ConUtil::xyputstr(16, 2, "다행히 꿈은 아니었고, 그로부터 몇 년이 지났다..(Press Enter)");
		cin.get();
		ConUtil::xyputstr(17, 4, "아빠 사진 속 여기 두 분은..누구셔..?(Press Enter)");
		cin.get();
		ConUtil::xyputstr(18, 6, "아빠 : 어..? 이사짐 정리하다보니 이런 것도 찾네. 너 할아버지, 할머니셔.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(19, 8, "아빠 : 이런 사진이 남아 있었구나.. 남은 두 분 사진은 없는 줄 알았는데..(Press Enter)");
		cin.get();
		ConUtil::xyputstr(20, 10, "아빠 : 두 분 다 널 보셨다면 정말 좋아하셨을텐데..ㅎ(Press Enter)");
		cin.get();
	}
	void end_escape(Model* _model, User* _user) {
		ConUtil::erase_cursor();
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::set_background(WHITE);
		ConUtil::set_text(BLACK);
		ConUtil::fillbox(35, 3, 39, 3, WHITE);
		ConUtil::fillbox(37, 3, 37, 7, WHITE); //T
		ConUtil::fillbox(41, 3, 41, 7, WHITE);
		ConUtil::fillbox(41, 5, 45, 5, WHITE);
		ConUtil::fillbox(45, 3, 45, 7, WHITE); //H
		ConUtil::fillbox(47, 3, 51, 3, WHITE);
		ConUtil::fillbox(47, 5, 51, 5, WHITE);
		ConUtil::fillbox(47, 7, 51, 7, WHITE);
		ConUtil::fillbox(47, 3, 47, 7, WHITE); //E
		ConUtil::fillbox(56, 3, 60, 3, WHITE);
		ConUtil::fillbox(56, 5, 60, 5, WHITE);
		ConUtil::fillbox(56, 7, 60, 7, WHITE);
		ConUtil::fillbox(56, 3, 56, 7, WHITE); //E
		ConUtil::fillbox(62, 3, 62, 7, WHITE);
		ConUtil::fillbox(63, 4, 63, 4, WHITE);
		ConUtil::fillbox(64, 5, 64, 5, WHITE);
		ConUtil::fillbox(65, 6, 65, 6, WHITE);
		ConUtil::fillbox(66, 3, 66, 7, WHITE); //N
		ConUtil::fillbox(68, 3, 68, 7, WHITE);
		ConUtil::fillbox(69, 3, 70, 3, WHITE);
		ConUtil::fillbox(69, 7, 70, 7, WHITE);
		ConUtil::fillbox(71, 4, 71, 4, WHITE);
		ConUtil::fillbox(71, 6, 71, 6, WHITE);
		ConUtil::fillbox(72, 5, 72, 5, WHITE);
		ConUtil::fillbox(10, 8, 101, 23, DARKGRAY);
		ConUtil::fillbox(11, 9, 100, 22, LIGHTGRAY);
		int total_easter = 5;
		int start_x = 13;
		int start_y = 11;
		ConUtil::xyputstr(41, 9, "<발견한 이스터에그 목록>");
		if (_user->find_inventory("＠[글을 잘 읽기]")) {
			ConUtil::xyputstr(start_x, start_y, "＠ [글을 잘 읽기] / 조건 : 튜토리얼 내용을 안 읽고 비밀번호 입력");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("◑[광활한 거실]")) {
			ConUtil::xyputstr(start_x, start_y, "◑ [광활한 거실] / 조건 : 거실에서 이동 200회 이상");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("◈[왔던길도 돌아보아요]")) {
			ConUtil::xyputstr(start_x, start_y, "◈ [왔던길도 돌아보아요] / 조건 : 현관문 키를 얻지 않고 거실로 돌아가 막힌 미로 확인");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("◎[여유있는 당신]")) {
			ConUtil::xyputstr(start_x, start_y, "◎ [여유있는 당신] / 조건 : 현관문 키를 들고 바로 탈출하지 않고 내 방에 들리기");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("★[당신은 천재]")) {
			ConUtil::xyputstr(start_x, start_y, "★ [당신은 천재] / 조건 : 힌트 코드 사용없이 탈출");
			start_y += 2;
			total_easter--;
		}
		ConUtil::xyputstr(30, 22, "미발견 이스터에그 수 : ");
		ConUtil::xyputc(52, 22, ' ');
		cout << total_easter;
		ConUtil::xyputstr(70, 22, "(Enter 두 번 입력시 종료)");
		getchar();
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
			int old_col = pos_col;
			int old_row = pos_row;
			switch (key) {
			case UPKEY:
				if (pos_row - 1 >= 0 && _model->living_room[pos_row - 1][pos_col] != 1) {
					pos_row--;
					_user->set_easter_egg2();
				}
				break;
			case DOWNKEY:
				if (pos_row + 1 < LIVING_HEIGHT && _model->living_room[pos_row + 1][pos_col] != 1) {
					pos_row++;
					_user->set_easter_egg2();
				}
				break;
			case RIGHTKEY:
				if (pos_col + 1 < LIVING_WIDTH && _model->living_room[pos_row][pos_col + 1] != 1) {
					pos_col++;
					_user->set_easter_egg2();
				}
				break;
			case LEFTKEY:
				if (pos_col - 1 >= 0 && _model->living_room[pos_row][pos_col - 1] != 1) {
					pos_col--;
					_user->set_easter_egg2();
				}
				break;
			}
			switch (_model->living_room[pos_row][pos_col]) {
			case 0:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break; 
			case 2: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
				if (_user->find_inventory("♭(현관문 열쇠)")) {
					if (_user->get_easter_egg2() >= 200 && !_user->find_inventory("◑[광활한 거실]")) {
						_user->set_inventory("◑[광활한 거실]");
					}
					return 3;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "열쇠가 필요하다.");
				}
				break;
			}
			case 3:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
				if (pos_col == 11 && pos_row == 0) { //내 방 이동
					if (_user->find_inventory("♭(현관문 열쇠)")) {
						if (!_user->find_inventory("◎[여유있는 당신]")) {
							_user->set_inventory("◎[여유있는 당신]");
						}
					}
					if (_user->get_easter_egg2()>=200 && !_user->find_inventory("◑[광활한 거실]")) {
						_user->set_inventory("◑[광활한 거실]");
					}
					return 1;
				}
				else if (pos_col == 39 && pos_row == 9) { //안방 이동
					if (!_visited_main) {
						char _input_password[5] = "0000";
						ConUtil::draw_Sign(_model, _user, "안방 비밀번호(숫자 4자리) : 0000    (Press Enter)");
						ConUtil::show_cursor();
						ConUtil::make_password_line(_model, 78, 16, _input_password);
						if (strcmp(_model->get_input_password(), _model->get_main_password()) == 0) {
							_visited_main = true;
							if (_user->get_easter_egg2() >= 200 && !_user->find_inventory("◑[광활한 거실]")) {
								_user->set_inventory("◑[광활한 거실]");
							}
							memcpy(_model->living_room,_model->maze_living_room, 800*sizeof(int));
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
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
				if (!_visited_main) {
					ConUtil::draw_Sign(_model, _user, "뭐야.. 집 안인데 사람이 있잖아..? 당신 누구야..??!!         의문의 할아버지 : 안방의 비밀번호를 자네 방에서 조합할 수 있을 걸세. 문제가 너무 어렵다면, 힌트코드를 들고 내게 와서 입력하게. 힌트 코드(영어 4자리) : aaaa    (Press Enter)");
					char _input_code[5] = "aaaa";
					ConUtil::show_cursor();
					ConUtil::make_password_line(_model, 74, 19, _input_code);
					if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 1)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 휴대폰을 들고 거실의 통신 가능한 곳에 가면 몇 회 울리는지 알 수 있을 걸세.");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 2)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 연립 방정식 문제일세. 공대면 이 정도는 암산 가능하겠지?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 3)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 무지개가 어떤 색 순서로 이루어지나? 교환은 옷이 떨어져 있어도 1:1 교환이 가능하지.");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 4)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 가끔 지금이 몇 시인지 확인하는 습관이 중요하네.");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 5)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 모서리에서 각각 하나의 숫자를 얻었다면, 이 숫자를 어떤 순서로 입력해야겠나?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 그런 힌트 코드는 없다네.");
						ConUtil::erase_cursor();
						break;
					}
				}
				else {
					if (_user->find_inventory("♭(현관문 열쇠)")) {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 얼른 이 곳을 빠져 나가게. 자네가 그립겠구만..");
					}
					else {
						ConUtil::draw_Sign(_model, _user, "의문의 할아버지 : 공간이 뒤틀리면서 자네를 못 나가게 막고 있어.. 자네는 얼른 이 곳을 나가야해..");
					}
					break;
				}
				break;
			case 5:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
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
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				break;
			case 3:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				if (pos_col == 6 && pos_row == 9) {
					return 0;
				}
				break;
			case 4:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "책상위에 놓인 휴대폰을 획득했다.    [Hint Code : phon]");
				_user->set_inventory("#(휴대폰)");
				_model->my_room[pos_row][pos_col] = 1;
				ConUtil::draw_UserStatus(_model, _user);
				break;
			case 5:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				if (_user->find_inventory("#(휴대폰)")) {
					ConUtil::draw_Sign(_model, _user, "이제 이 곳에서도 전화가 연결된다. 내용은 아까와 똑같다..<신호음이[?]번 울리고 끊긴다>    [Hint Code : phon]");
				}
				break;
			case 6:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "책장의 노트에 무언가 써있다. 이게 뭐지..? 공대생의 수학 실력을 발휘해야겠어.< @+# = 9, $+% = 7, @+$ = 5, #+$ =12, 2@+% = [?] >    [Hint Code : math]");
				break;
			case 7:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "옷장에 옷이 걸려있다. 색깔이 뒤죽박죽인데.. 강박증 때문에 정리 해야겠어.< (빨 노 주 파 보 초 남)/ 최소 교환 횟수 = [?] >    [Hint Code : clot]");
				break;
			case 8:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "침대 아래에 건전지가 있다. 손목시계를 고칠 수 있겠어.              < 현재 시각 = [?] >    [Hint Code : time]");
				if (_user->find_inventory("§(고장난 손목시계)")) {
					_user->remove_inventory("§(고장난 손목시계)");
					_user->set_inventory("§(손목시계 [현재 시각 : 19시])");
					ConUtil::draw_UserStatus(_model, _user);
				}
				break;
			case 9:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "카펫에 문양이 새겨져있네.. 이게 뭐지? 사물 위치와 관련된 것 같은데.. < ←↑:4, →↑:2, ←↓:1, →↓:3 >    [Hint Code : carp]"); //[3]:4, [5]:2, [4]:1, [7]:3 (3547->4573)
			}

		}
	}
	//main_room(visit_room_num == 2)
	static int locate_main_room(Model* _model, User* _user, int &_pos_col, int &_pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->main_room, MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, "중앙에 서 있는 저 사람은 누구지? 가봐야겠어!");
		ConUtil::write_room_name(MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT, 2);
		ConUtil::erase_cursor();
		ConUtil::drawCharacter(_pos_col, _pos_row);
		int key;
		int pos_col = _pos_col;
		int pos_row = _pos_row;
		while ((key = ConUtil::getkey())) {
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
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				break;
			case 3:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				if (pos_col == 0 && pos_row == 7) {
					if (!_user->find_inventory("♭(현관문 열쇠)")) {
						if (!_user->find_inventory("◈[왔던길도 돌아보아요]")) {
							_user->set_inventory("◈[왔던길도 돌아보아요]");
						}
					}
					else {
						if (!_user->find_inventory("★[당신은 천재]") && _user->get_easter_egg5()) {
							_user->set_inventory("★[당신은 천재]");
						}
					}
					return 0;
				}
				break;
			case 4: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				if (_user->find_inventory("●(꿈)") && _user->find_inventory("◆(병원)") && _user->find_inventory("■(출근)") && _user->find_inventory("▲(자동차)")) {
					ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 드디어 기억났나보군. 자네는 자동차를 타고 회사로 출근하다가 사고가 났고, 지금 병원에 누워서 꿈을 꾸고 있는 게야! 이제 이 곳을 나갈 수 있게 됐네. 어서 현관문으로 가게. 자네가 그립겠구만..");
					_user->remove_inventory("●(꿈)");
					_user->remove_inventory("◆(병원)");
					_user->remove_inventory("■(출근)");
					_user->remove_inventory("▲(자동차)");
					_user->set_inventory("♭(현관문 열쇠)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->living_room[9][36] = 0;
				}
				else if (_user->find_inventory("♭(현관문 열쇠)")) {
					ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 어서 이 열쇠를 들고 현관문으로 나가게. 자네가 그립겠어..");
				}
				else {
					ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 내가 누군지는 중요하지 않아. 어서 현관문으로 나갈 준비를 해야해! 방 바닥에 그려진 화살표를 입구부터 순서대로 따라가 기억의 조각을 전부 내게 모아오게나. 자네 힘으로 찾는 것이 좋지만 정말 모르겠다면 힌트코드를 들고 내게 와서 알려주게.            힌트 코드(영어 4자리) : aaaa    (Press Enter)");
					char _input_code[5] = "aaaa";
					ConUtil::show_cursor();
					ConUtil::make_password_line(_model, 74, 20, _input_code);
					if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 6)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 양의 울음소리를 하나씩 잘 보도록. 그리고 숫자를 나타내는 방법에는 여러 진법이 있지");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 7)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할머니 : '기생충'이라는 영화 봤나? 전등을 껐다 켰다.. 무슨 신호?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 8)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 물건을 거울에 붙이면 어떻게 되나?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 9)) == 0) {
						ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 이걸 힌트를 달라는 게냐..? 여기까지 이동은 어떻게 한 것이냐..");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else {
						ConUtil::draw_Sign(_model, _user, "의문의 할머니 : 그런 힌트 코드는 없다네. 어서 기억의 조각을 모두 모아오게");
						ConUtil::erase_cursor();
						break;
					}
				}
				break;
			}
			case 5: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< 왼쪽 위의 양 무리 중 뭔가 다른 양의 번호를 공대생 방식으로 입력(각 양의 번호는 키보드 우측 숫자 키패드 기준)>            숫자 코드(숫자 4자리) : 0000    (Press Enter) [Hint Code : shep]");
				char _input_code[5] = "0000";
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 74, 18, _input_code);
				if (strcmp(_model->get_input_password(), _model->get_main_code(1)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, "왜 집에 양이 있지..? 양.. 양.. 여긴 꿈인가? 그렇다면 왜 꿈을 꾸고 있지 난? <기억의 조각(꿈) 획득>");
					_user->set_inventory("●(꿈)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[3][5] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 숫자 코드.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 6: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< ***-- --*** --*** ----* 이게 뭐지..? 신호인가?>                    숫자 코드(숫자 4자리) : 0000    (Press Enter) [Hint Code : hosp]");
				char _input_code[5] = "0000";
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 74, 17, _input_code);
				if (strcmp(_model->get_input_password(), _model->get_main_code(2)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, "삐..삐..? 이 소리는 마치 병실 모니터? 난 지금 병원에 잠든 채로 누워 있는 건가..? <기억의 조각(병원) 획득>");
					_user->set_inventory("◆(병원)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[3][19] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 숫자 코드.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 7:{
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< 2+2 = fish 3+3 = eight 4+4 = ? 7+7 = triangle (정답 영단어 중 앞의 4자리만 입력)>                                             영어 코드(영어 4자리) : aaaa    (Press Enter) [Hint Code : work]");
				char _input_code[5] = "0000";
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 74, 18, _input_code);
				if (strcmp(_model->get_input_password(), _model->get_main_code(3)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, "숫자랑 영어를 보니 머리 아파.. 잠깐..머리기 아프다..? 아! 난 출근을 하고 있었어! 그런데 왜 병원에? <기억의 조각(출근) 획득>");
					_user->set_inventory("■(출근)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[11][19] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 영어 코드.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 8: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< 장난감 자동차 주차를 위해서 다음 방향키를 순서대로 누르시오 (↑↑→→↑←↑↓↓) >                                              누른 방향키 : _        (Press Enter) [Hint Code : acci]");
				char _input_code[10] = "aaaaaaaaa";
				ConUtil::erase_cursor();
				ConUtil::make_direction_password_line(_model, 64, 18, _input_code);
				if (strcmp(_model->get_direction_password(), _model->get_main_code(4)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, " 장난감 자동차..? 맞아 나는 차를 타고 출근하고 있었어!       <기억의 조각(자동차) 획득>");
					_user->set_inventory("▲(자동차)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[11][5] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 입력.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 9:
			case 10:
			case 11:
			case 12:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				break;
			case 13:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "양 : 메에에에");
				break;
			case 14:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "양 : 메에애에");
				break;
			}
		}
	}
	static int locate_tutorial_room(Model* _model, User* _user, int& _pos_col, int& _pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->tutorial_room, TUTORIAL_WIDTH, TUTORIAL_HEIGHT); 
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, "이 곳은 안내문 창입니다. 게임을 진행하면서 이벤트가 발생할 시, 게임을 풀어나갈 수 있는 안내글이 이 곳에 나타납니다.           (방향키로 이동해보세요.)");
		ConUtil::write_room_name(TUTORIAL_WIDTH, TUTORIAL_HEIGHT, 3); 
		ConUtil::erase_cursor();
		ConUtil::drawCharacter(_pos_col, _pos_row);
		int key;
		int pos_col = _pos_col;
		int pos_row = _pos_row;
		while ((key = ConUtil::getkey())) {
			int old_col = pos_col;
			int old_row = pos_row;
			switch (key) {
			case UPKEY:
				if (pos_row - 1 >= 0 && _model->tutorial_room[pos_row - 1][pos_col] != 1) {
					pos_row--;
				}
				break;
			case DOWNKEY:
				if (pos_row + 1 < TUTORIAL_HEIGHT && _model->tutorial_room[pos_row + 1][pos_col] != 1) {
					pos_row++;
				}
				break;
			case RIGHTKEY:
				if (pos_col + 1 < TUTORIAL_WIDTH && _model->tutorial_room[pos_row][pos_col + 1] != 1) {
					pos_col++;
				}
				break;
			case LEFTKEY:
				if (pos_col - 1 >= 0 && _model->tutorial_room[pos_row][pos_col - 1] != 1) {
					pos_col--;
				}
				break;
			}
			switch (_model->tutorial_room[pos_row][pos_col]) {
			case 0:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				break;
			case 1:
				pos_col = old_col;
				pos_row = old_row;
				break;
			case 2:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "빨간색 공간은 최종 탈출구입니다.");
				break;
			case 3:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "노란색 공간은 다른 방으로 이동하는 구간입니다.");
				break;
			case 4:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "잘하셨습니다! 이동은 방향키로 상하좌우 이동이 가능합니다. 밝은 회색은 이동가능한 공간이며, 어두운 회색은 벽입니다.");
				break;
			case 5:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "우측 상단의 상태창은 플레이어에 대한 설명과, 보유 아이템이 보여집니다. 지금과 같이 특수한 공간을 플레이어가 밟으면 상태창과 안내문이 업데이트 됩니다. 두 공간을 꼭 읽어주세요 :)");
				break;
			case 6:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				char _input_password[5] = "0000";
				ConUtil::draw_Sign(_model, _user, "모든 비밀번호, 힌트코드에 대한 입력공간은 방향키로 문자 위치 이동이 가능하며, Enter키로 입력할 수 있습니다.(주의)한 번 입력공간에 들어오게 되면, 아무 값이나 입력해야 입력공간을 빠져나올 수 있습니다! <게임시작 비밀번호 : a1b2>                   비밀번호(영문숫자 4자리) : 0000    (Press Enter)");
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 77, 20, _input_password);
				if (strcmp(_model->get_input_password(), _model->get_tutorial_password()) == 0) {
					ConUtil::erase_cursor();
					return 2;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "잘못된 비밀번호.");
					if (!_user->find_inventory("＠[글을 잘 읽기]")) {
						_user->set_inventory("＠[글을 잘 읽기]");
					}
					ConUtil::erase_cursor();
					break;
				}
				return -1;
			}
		}
	}
};