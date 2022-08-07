#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include "xtensor/xarray.hpp"

class Level : public Node2D
{
	GODOT_CLASS(Level, Node2D);
	xt::xarray<double> _values;

public:
	static void _register_methods();
	void _init();
	void as_zeros(godot::PoolIntArray data_shape);
	void as_ones(godot::PoolIntArray data_shape);
	double from_pool_array(godot::PoolRealArray data, godot::PoolIntArray data_shape);
	godot::PoolRealArray values();
	godot::PoolIntArray shape();

private:
	std::vector<std::size_t> pool_to_vector(godot::PoolIntArray int_data);
	std::vector<double> pool_to_vector(godot::PoolRealArray real_data);
};

