#pragma once
#include "Model.h"
#include "View.h"
#include "User.h"
class Controller
{
	Model* _model;
	View* _view;
	User* _user;
public:
	Controller() {
		_model = new Model;
		_view = new View;
		_user = new User;
	}
	~Controller() {
		delete _model;
		delete _view;
		delete _user;
	}
	void start() {
		_view->print_Logo(_model, _user);
		_view->print_story(_model, _user);
		_view->start_escape(_model, _user);
	}
};

