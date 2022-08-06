#pragma once
#include "Common.h"
#include <Node2D.hpp>
class Level : public Node2D
{
	GODOT_CLASS(Level, Node2D);

public:
	static void _register_methods();
	void _init();
};

