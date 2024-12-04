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
		bool check;
		cout << _user->get_Name() << " : ��.. �� �޿��� �����. ���� ������ ��Ȯ�ϰ� ��ﳪ�� ������ ����� ���� �ʳ�.(Press Enter)" << endl;
		cin.get(); cin.ignore();
		cout << _user->get_Name() << " : �׷��� �̻��ϴ�. ������ �ָ��̰� �������� ���� �ð��ε�, �� ���� �ʹ� �����ϴ�.(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : ������ �̻��ѵ�.. �ϴ� �ŽǷ� �������߰ھ�,(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : �Žǿ� �ƹ��� ����, ���� �ִ� â���� ��� �������. �̰� ���� ������?(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : ���� �������� �ȿ��� ��й�ȣ�� �ɷ����ݾ�..? ���� �ǰ�?!(Press Enter)" << endl;
		cin.get();
		cout << _user->get_Name() << " : �����ϰ�.. �ϴ� �� ���� ���� ������߰ھ�.(Press Enter)" << endl;
		cin.get();
	}
	void start_escape(Model* _model, User* _user) {
		int pos_col = 1, pos_row = 9;
		ConUtil::locate_living_room(_model, _user, pos_col, pos_row);
	}
};

