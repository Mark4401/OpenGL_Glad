#pragma once
#include"../Headers/config.h"

class Appication
{
private:

public:

	bool Start();
	bool MainWindow();
	void PoolEvents();
	bool WindowShouldClose();
	void Buffer();

	Appication();
	~Appication();
};

