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
		ConUtil::xyputstr(47, 9, "<�ȳ� ����>");
		ConUtil::xyputc(48, 11, ' ');
		cout << _user->get_Name() << "��!";
		ConUtil::xyputstr(18, 14, " ���ݺ��� Ʃ�丮���� �����մϴ�. Ʃ�丮�� ������ �� �������ּ���! (Press Enter)");
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
		ConUtil::xyputstr(16, 3, "��.. �� �޿��� �����. ���� ������ ��Ȯ�ϰ� ��ﳪ�� ������ ����� ���� �ʳ�.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(17, 5, "�׷��� �̻��ϴ�.������ �ָ��̰� �������� ���� �ð��ε�, �� ���� �ʹ� �����ϴ�.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(34, 7, "������ �̻��ѵ�..�ϴ� �ŽǷ� �������߰ھ�, (Press Enter)");
		cin.get();
		ConUtil::xyputstr(21, 9, "�Žǿ� �ƹ��� ����, ���� �ִ� â���� ��� �������.�̰� ���� ������ ? (Press Enter)");
		cin.get();
		ConUtil::xyputstr(25, 11, "���� �������� �ȿ��� ��й�ȣ�� �ɷ����ݾ�.. ? ���� �ǰ� ? !(Press Enter)");
		cin.get();
		ConUtil::xyputstr(34, 13, "�����ϰ�..�ϴ� �� ���� ���� ������߰ھ�.(Press Enter)");
		cin.get();
	}
	void start_escape(Model* _model, User* _user) {
		int pos_col = 1, pos_row = 9;
		int visit_room_num = 0;
		int current_room_num = 0;
		bool visited_main = false; //main_room(�ȹ�)�� ù �湮����
		while (true) {
			if (visit_room_num == 0) { //���� �κ�, ���� ���� ����
				if (current_room_num == 0) {
					current_room_num = 0;
					visit_room_num = locate_living_room(_model, _user, pos_col, pos_row, visited_main);
					continue;
				}
				else if (current_room_num == 1) { // �� �� -> �Ž�
					pos_col = 11; pos_row = 0;
					current_room_num = 0;
					visit_room_num = locate_living_room(_model, _user, pos_col, pos_row, visited_main);
					continue;
				}
				else if (current_room_num == 2) { //�ȹ� -> �Ž�
					pos_col = 39; pos_row = 9;
					current_room_num = 0;
					visit_room_num = locate_living_room(_model, _user, pos_col, pos_row, visited_main);
					continue;
				}
			}
			else if (visit_room_num == 1) { // �Ž� -> �� ��
				pos_col = 6; pos_row = 9;
				current_room_num = 1;
				visit_room_num = locate_my_room(_model, _user, pos_col, pos_row);
				continue;
			}
			else if (visit_room_num == 2) { // �Ž� -> �ȹ�
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
		ConUtil::xyputstr(16, 2, "��..! ���� ������..��..? ���� ����..?(Press Enter)");
		cin.get();
		ConUtil::xyputstr(17, 4, "�ƺ� : ������ �� ���? �� ��Ʋ���� �� �Ͼ��.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(18, 6, "����..�޿��� �� ������ ��¥������.. ȸ��� ��� �ƾ�..? (Press Enter)");
		cin.get();
		ConUtil::xyputstr(19, 8, "���� : ȸ�翡�� �츮�� �� ����س���.. �� �ְ� ǫ ����, ȸ���� �����Ϸ�(Press Enter)");
		cin.get();
		ConUtil::xyputstr(20, 10, "�̰͵� ���� �ƴϰ���? ����,�ƺ� �� �� ��������(Press Enter)");
		cin.get();
		ConUtil::erase_cursor();
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::set_background(WHITE);
		ConUtil::set_text(BLACK);
		ConUtil::xyputstr(16, 2, "������ ���� �ƴϾ���, �׷κ��� �� ���� ������..(Press Enter)");
		cin.get();
		ConUtil::xyputstr(17, 4, "�ƺ� ���� �� ���� �� ����..������..?(Press Enter)");
		cin.get();
		ConUtil::xyputstr(18, 6, "�ƺ� : ��..? �̻��� �����ϴٺ��� �̷� �͵� ã��. �� �Ҿƹ���, �ҸӴϼ�.(Press Enter)");
		cin.get();
		ConUtil::xyputstr(19, 8, "�ƺ� : �̷� ������ ���� �־�����.. ���� �� �� ������ ���� �� �˾Ҵµ�..(Press Enter)");
		cin.get();
		ConUtil::xyputstr(20, 10, "�ƺ� : �� �� �� �� ���̴ٸ� ���� �����ϼ����ٵ�..��(Press Enter)");
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
		ConUtil::xyputstr(41, 9, "<�߰��� �̽��Ϳ��� ���>");
		if (_user->find_inventory("��[���� �� �б�]")) {
			ConUtil::xyputstr(start_x, start_y, "�� [���� �� �б�] / ���� : Ʃ�丮�� ������ �� �а� ��й�ȣ �Է�");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("��[��Ȱ�� �Ž�]")) {
			ConUtil::xyputstr(start_x, start_y, "�� [��Ȱ�� �Ž�] / ���� : �Žǿ��� �̵� 200ȸ �̻�");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("��[�Դ��浵 ���ƺ��ƿ�]")) {
			ConUtil::xyputstr(start_x, start_y, "�� [�Դ��浵 ���ƺ��ƿ�] / ���� : ������ Ű�� ���� �ʰ� �ŽǷ� ���ư� ���� �̷� Ȯ��");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("��[�����ִ� ���]")) {
			ConUtil::xyputstr(start_x, start_y, "�� [�����ִ� ���] / ���� : ������ Ű�� ��� �ٷ� Ż������ �ʰ� �� �濡 �鸮��");
			start_y += 2;
			total_easter--;
		}
		if (_user->find_inventory("��[����� õ��]")) {
			ConUtil::xyputstr(start_x, start_y, "�� [����� õ��] / ���� : ��Ʈ �ڵ� ������ Ż��");
			start_y += 2;
			total_easter--;
		}
		ConUtil::xyputstr(30, 22, "�̹߰� �̽��Ϳ��� �� : ");
		ConUtil::xyputc(52, 22, ' ');
		cout << total_easter;
		ConUtil::xyputstr(70, 22, "(Enter �� �� �Է½� ����)");
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
				if (_user->find_inventory("��(������ ����)")) {
					if (_user->get_easter_egg2() >= 200 && !_user->find_inventory("��[��Ȱ�� �Ž�]")) {
						_user->set_inventory("��[��Ȱ�� �Ž�]");
					}
					return 3;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "���谡 �ʿ��ϴ�.");
				}
				break;
			}
			case 3:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
				if (pos_col == 11 && pos_row == 0) { //�� �� �̵�
					if (_user->find_inventory("��(������ ����)")) {
						if (!_user->find_inventory("��[�����ִ� ���]")) {
							_user->set_inventory("��[�����ִ� ���]");
						}
					}
					if (_user->get_easter_egg2()>=200 && !_user->find_inventory("��[��Ȱ�� �Ž�]")) {
						_user->set_inventory("��[��Ȱ�� �Ž�]");
					}
					return 1;
				}
				else if (pos_col == 39 && pos_row == 9) { //�ȹ� �̵�
					if (!_visited_main) {
						char _input_password[5] = "0000";
						ConUtil::draw_Sign(_model, _user, "�ȹ� ��й�ȣ(���� 4�ڸ�) : 0000    (Press Enter)");
						ConUtil::show_cursor();
						ConUtil::make_password_line(_model, 78, 16, _input_password);
						if (strcmp(_model->get_input_password(), _model->get_main_password()) == 0) {
							_visited_main = true;
							if (_user->get_easter_egg2() >= 200 && !_user->find_inventory("��[��Ȱ�� �Ž�]")) {
								_user->set_inventory("��[��Ȱ�� �Ž�]");
							}
							memcpy(_model->living_room,_model->maze_living_room, 800*sizeof(int));
							ConUtil::erase_cursor();
							return 2;
						}
						else {
							ConUtil::draw_Sign(_model, _user, "�߸��� ��й�ȣ.");
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
					ConUtil::draw_Sign(_model, _user, "����.. �� ���ε� ����� ���ݾ�..? ��� ������..??!!         �ǹ��� �Ҿƹ��� : �ȹ��� ��й�ȣ�� �ڳ� �濡�� ������ �� ���� �ɼ�. ������ �ʹ� ��ƴٸ�, ��Ʈ�ڵ带 ��� ���� �ͼ� �Է��ϰ�. ��Ʈ �ڵ�(���� 4�ڸ�) : aaaa    (Press Enter)");
					char _input_code[5] = "aaaa";
					ConUtil::show_cursor();
					ConUtil::make_password_line(_model, 74, 19, _input_code);
					if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 1)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : �޴����� ��� �Ž��� ��� ������ ���� ���� �� ȸ �︮���� �� �� ���� �ɼ�.");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 2)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : ���� ������ �����ϼ�. ����� �� ������ �ϻ� �����ϰ���?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 3)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : �������� � �� ������ �̷������? ��ȯ�� ���� ������ �־ 1:1 ��ȯ�� ��������.");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 4)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : ���� ������ �� ������ Ȯ���ϴ� ������ �߿��ϳ�.");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 5)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : �𼭸����� ���� �ϳ��� ���ڸ� ����ٸ�, �� ���ڸ� � ������ �Է��ؾ߰ڳ�?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : �׷� ��Ʈ �ڵ�� ���ٳ�.");
						ConUtil::erase_cursor();
						break;
					}
				}
				else {
					if (_user->find_inventory("��(������ ����)")) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : �� �� ���� ���� ������. �ڳװ� �׸��ڱ���..");
					}
					else {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �Ҿƹ��� : ������ ��Ʋ���鼭 �ڳ׸� �� ������ ���� �־�.. �ڳ״� �� �� ���� ��������..");
					}
					break;
				}
				break;
			case 5:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 0);
				if (_user->find_inventory("#(�޴���)")) {
					ConUtil::draw_Sign(_model, _user, "��ȭ�� ����Ǵ� ���̴�. �޴����� ����ؼ� �����մϴ�..(��ȣ���� [3]�� �︮�� �����)");
					_model->my_room[pos_col][pos_row] = 5;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "��ȭ�� ����Ǵ� ���̴�. �޴����� �ʿ��ϴ�.");
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
				ConUtil::draw_Sign(_model, _user, "å������ ���� �޴����� ȹ���ߴ�.    [Hint Code : phon]");
				_user->set_inventory("#(�޴���)");
				_model->my_room[pos_row][pos_col] = 1;
				ConUtil::draw_UserStatus(_model, _user);
				break;
			case 5:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				if (_user->find_inventory("#(�޴���)")) {
					ConUtil::draw_Sign(_model, _user, "���� �� �������� ��ȭ�� ����ȴ�. ������ �Ʊ�� �Ȱ���..<��ȣ����[?]�� �︮�� �����>    [Hint Code : phon]");
				}
				break;
			case 6:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "å���� ��Ʈ�� ���� ���ִ�. �̰� ����..? ������� ���� �Ƿ��� �����ؾ߰ھ�.< @+# = 9, $+% = 7, @+$ = 5, #+$ =12, 2@+% = [?] >    [Hint Code : math]");
				break;
			case 7:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "���忡 ���� �ɷ��ִ�. ������ ���׹����ε�.. ������ ������ ���� �ؾ߰ھ�.< (�� �� �� �� �� �� ��)/ �ּ� ��ȯ Ƚ�� = [?] >    [Hint Code : clot]");
				break;
			case 8:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "ħ�� �Ʒ��� �������� �ִ�. �ո�ð踦 ��ĥ �� �ְھ�.              < ���� �ð� = [?] >    [Hint Code : time]");
				if (_user->find_inventory("��(���峭 �ո�ð�)")) {
					_user->remove_inventory("��(���峭 �ո�ð�)");
					_user->set_inventory("��(�ո�ð� [���� �ð� : 19��])");
					ConUtil::draw_UserStatus(_model, _user);
				}
				break;
			case 9:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 1);
				ConUtil::draw_Sign(_model, _user, "ī�꿡 ������ �������ֳ�.. �̰� ����? �繰 ��ġ�� ���õ� �� ������.. < ���:4, ���:2, ���:1, ���:3 >    [Hint Code : carp]"); //[3]:4, [5]:2, [4]:1, [7]:3 (3547->4573)
			}

		}
	}
	//main_room(visit_room_num == 2)
	static int locate_main_room(Model* _model, User* _user, int &_pos_col, int &_pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->main_room, MAIN_ROOM_WIDTH, MAIN_ROOM_HEIGHT);
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, "�߾ӿ� �� �ִ� �� ����� ������? �����߰ھ�!");
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
					if (!_user->find_inventory("��(������ ����)")) {
						if (!_user->find_inventory("��[�Դ��浵 ���ƺ��ƿ�]")) {
							_user->set_inventory("��[�Դ��浵 ���ƺ��ƿ�]");
						}
					}
					else {
						if (!_user->find_inventory("��[����� õ��]") && _user->get_easter_egg5()) {
							_user->set_inventory("��[����� õ��]");
						}
					}
					return 0;
				}
				break;
			case 4: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				if (_user->find_inventory("��(��)") && _user->find_inventory("��(����)") && _user->find_inventory("��(���)") && _user->find_inventory("��(�ڵ���)")) {
					ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : ���� ��ﳵ������. �ڳ״� �ڵ����� Ÿ�� ȸ��� ����ϴٰ� ��� ����, ���� ������ ������ ���� �ٰ� �ִ� �Ծ�! ���� �� ���� ���� �� �ְ� �Ƴ�. � ���������� ����. �ڳװ� �׸��ڱ���..");
					_user->remove_inventory("��(��)");
					_user->remove_inventory("��(����)");
					_user->remove_inventory("��(���)");
					_user->remove_inventory("��(�ڵ���)");
					_user->set_inventory("��(������ ����)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->living_room[9][36] = 0;
				}
				else if (_user->find_inventory("��(������ ����)")) {
					ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : � �� ���踦 ��� ���������� ������. �ڳװ� �׸��ھ�..");
				}
				else {
					ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : ���� �������� �߿����� �ʾ�. � ���������� ���� �غ� �ؾ���! �� �ٴڿ� �׷��� ȭ��ǥ�� �Ա����� ������� ���� ����� ������ ���� ���� ��ƿ��Գ�. �ڳ� ������ ã�� ���� ������ ���� �𸣰ڴٸ� ��Ʈ�ڵ带 ��� ���� �ͼ� �˷��ְ�.            ��Ʈ �ڵ�(���� 4�ڸ�) : aaaa    (Press Enter)");
					char _input_code[5] = "aaaa";
					ConUtil::show_cursor();
					ConUtil::make_password_line(_model, 74, 20, _input_code);
					if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 6)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : ���� �����Ҹ��� �ϳ��� �� ������. �׸��� ���ڸ� ��Ÿ���� ������� ���� ������ ����");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 7)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : '�����'�̶�� ��ȭ �ó�? ������ ���� �״�.. ���� ��ȣ?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 8)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : ������ �ſ￡ ���̸� ��� �ǳ�?");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else if (strcmp(_model->get_input_password(), _model->get_hint_code(_user, 9)) == 0) {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : �̰� ��Ʈ�� �޶�� �Գ�..? ������� �̵��� ��� �� ���̳�..");
						_user->set_easter_egg5(false);
						ConUtil::erase_cursor();
						break;
					}
					else {
						ConUtil::draw_Sign(_model, _user, "�ǹ��� �ҸӴ� : �׷� ��Ʈ �ڵ�� ���ٳ�. � ����� ������ ��� ��ƿ���");
						ConUtil::erase_cursor();
						break;
					}
				}
				break;
			}
			case 5: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< ���� ���� �� ���� �� ���� �ٸ� ���� ��ȣ�� ����� ������� �Է�(�� ���� ��ȣ�� Ű���� ���� ���� Ű�е� ����)>            ���� �ڵ�(���� 4�ڸ�) : 0000    (Press Enter) [Hint Code : shep]");
				char _input_code[5] = "0000";
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 74, 18, _input_code);
				if (strcmp(_model->get_input_password(), _model->get_main_code(1)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, "�� ���� ���� ����..? ��.. ��.. ���� ���ΰ�? �׷��ٸ� �� ���� �ٰ� ���� ��? <����� ����(��) ȹ��>");
					_user->set_inventory("��(��)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[3][5] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "�߸��� ���� �ڵ�.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 6: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< ***-- --*** --*** ----* �̰� ����..? ��ȣ�ΰ�?>                    ���� �ڵ�(���� 4�ڸ�) : 0000    (Press Enter) [Hint Code : hosp]");
				char _input_code[5] = "0000";
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 74, 17, _input_code);
				if (strcmp(_model->get_input_password(), _model->get_main_code(2)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, "��..��..? �� �Ҹ��� ��ġ ���� �����? �� ���� ������ ��� ä�� ���� �ִ� �ǰ�..? <����� ����(����) ȹ��>");
					_user->set_inventory("��(����)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[3][19] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "�߸��� ���� �ڵ�.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 7:{
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< 2+2 = fish 3+3 = eight 4+4 = ? 7+7 = triangle (���� ���ܾ� �� ���� 4�ڸ��� �Է�)>                                             ���� �ڵ�(���� 4�ڸ�) : aaaa    (Press Enter) [Hint Code : work]");
				char _input_code[5] = "0000";
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 74, 18, _input_code);
				if (strcmp(_model->get_input_password(), _model->get_main_code(3)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, "���ڶ� ��� ���� �Ӹ� ����.. ���..�Ӹ��� ������..? ��! �� ����� �ϰ� �־���! �׷��� �� ������? <����� ����(���) ȹ��>");
					_user->set_inventory("��(���)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[11][19] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "�߸��� ���� �ڵ�.");
					ConUtil::erase_cursor();
					break;
				}
				break;
			}
			case 8: {
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "< �峭�� �ڵ��� ������ ���ؼ� ���� ����Ű�� ������� �����ÿ� (����������) >                                              ���� ����Ű : _        (Press Enter) [Hint Code : acci]");
				char _input_code[10] = "aaaaaaaaa";
				ConUtil::erase_cursor();
				ConUtil::make_direction_password_line(_model, 64, 18, _input_code);
				if (strcmp(_model->get_direction_password(), _model->get_main_code(4)) == 0) {
					ConUtil::erase_cursor();
					ConUtil::draw_Sign(_model, _user, " �峭�� �ڵ���..? �¾� ���� ���� Ÿ�� ����ϰ� �־���!       <����� ����(�ڵ���) ȹ��>");
					_user->set_inventory("��(�ڵ���)");
					ConUtil::draw_UserStatus(_model, _user);
					_model->main_room[11][5] = 0;
					break;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "�߸��� �Է�.");
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
				ConUtil::draw_Sign(_model, _user, "�� : �޿�����");
				break;
			case 14:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 2);
				ConUtil::draw_Sign(_model, _user, "�� : �޿��ֿ�");
				break;
			}
		}
	}
	static int locate_tutorial_room(Model* _model, User* _user, int& _pos_col, int& _pos_row) {
		ConUtil::set_background(BLACK);
		ConUtil::clear();
		ConUtil::drawMap(_model, _model->tutorial_room, TUTORIAL_WIDTH, TUTORIAL_HEIGHT); 
		ConUtil::draw_UserStatus(_model, _user);
		ConUtil::draw_Sign(_model, _user, "�� ���� �ȳ��� â�Դϴ�. ������ �����ϸ鼭 �̺�Ʈ�� �߻��� ��, ������ Ǯ��� �� �ִ� �ȳ����� �� ���� ��Ÿ���ϴ�.           (����Ű�� �̵��غ�����.)");
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
				ConUtil::draw_Sign(_model, _user, "������ ������ ���� Ż�ⱸ�Դϴ�.");
				break;
			case 3:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "����� ������ �ٸ� ������ �̵��ϴ� �����Դϴ�.");
				break;
			case 4:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "���ϼ̽��ϴ�! �̵��� ����Ű�� �����¿� �̵��� �����մϴ�. ���� ȸ���� �̵������� �����̸�, ��ο� ȸ���� ���Դϴ�.");
				break;
			case 5:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				ConUtil::draw_Sign(_model, _user, "���� ����� ����â�� �÷��̾ ���� �����, ���� �������� �������ϴ�. ���ݰ� ���� Ư���� ������ �÷��̾ ������ ����â�� �ȳ����� ������Ʈ �˴ϴ�. �� ������ �� �о��ּ��� :)");
				break;
			case 6:
				ConUtil::make_passable_Cell(_model, pos_col, pos_row, old_col, old_row, 3);
				char _input_password[5] = "0000";
				ConUtil::draw_Sign(_model, _user, "��� ��й�ȣ, ��Ʈ�ڵ忡 ���� �Է°����� ����Ű�� ���� ��ġ �̵��� �����ϸ�, EnterŰ�� �Է��� �� �ֽ��ϴ�.(����)�� �� �Է°����� ������ �Ǹ�, �ƹ� ���̳� �Է��ؾ� �Է°����� �������� �� �ֽ��ϴ�! <���ӽ��� ��й�ȣ : a1b2>                   ��й�ȣ(�������� 4�ڸ�) : 0000    (Press Enter)");
				ConUtil::show_cursor();
				ConUtil::make_password_line(_model, 77, 20, _input_password);
				if (strcmp(_model->get_input_password(), _model->get_tutorial_password()) == 0) {
					ConUtil::erase_cursor();
					return 2;
				}
				else {
					ConUtil::draw_Sign(_model, _user, "�߸��� ��й�ȣ.");
					if (!_user->find_inventory("��[���� �� �б�]")) {
						_user->set_inventory("��[���� �� �б�]");
					}
					ConUtil::erase_cursor();
					break;
				}
				return -1;
			}
		}
	}
};