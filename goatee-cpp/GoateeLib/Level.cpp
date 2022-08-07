#include "Level.h"
#include <cstddef>
#include "xtensor/xarray.hpp"
#include <xtensor/xadapt.hpp>
#include <xtensor/xaxis_iterator.hpp>
#include <xtensor/xio.hpp>

void Level::_register_methods()
{
	register_method("as_zeros", &Level::as_zeros);
	register_method("as_ones", &Level::as_ones);
	register_method("from_pool_array", &Level::from_pool_array);
	register_method("values", &Level::values);
	register_method("shape", &Level::shape);
}

void Level::_init()
{
}

void Level::as_zeros(godot::PoolIntArray data_shape)
{
	std::vector<std::size_t> std_data_shape = pool_to_vector(data_shape);
	_values = xt::zeros<double>(std_data_shape);
}

void Level::as_ones(godot::PoolIntArray data_shape)
{
	std::vector<std::size_t> std_data_shape = pool_to_vector(data_shape);
	_values = xt::ones<double>(std_data_shape);
}

double Level::from_pool_array(godot::PoolRealArray data, godot::PoolIntArray data_shape)
{
	std::vector<double> std_data = pool_to_vector(data);
	std::vector<std::size_t> std_data_shape = pool_to_vector(data_shape);
	_values = xt::adapt(std_data, std_data_shape);
}

godot::PoolRealArray Level::values()
{
	godot::PoolRealArray values_pool = godot::PoolRealArray();
	std::vector<double> values_vector(_values.begin(), _values.end());
	for (double val : values_vector)
	{
		values_pool.append(val);
	}
	return values_pool;
}

godot::PoolIntArray Level::shape()
{
	godot::PoolIntArray shape_pool = godot::PoolIntArray();
	for (double val : _values.shape()) 
	{
		shape_pool.append(val);
	}
	return shape_pool;
}

std::vector<std::size_t> Level::pool_to_vector(godot::PoolIntArray int_data)
{
	std::vector<std::size_t> data;
	for (int idx = 0; idx < int_data.size(); ++idx) {
		data.push_back(int_data[idx]);
	}
	return data;
}

std::vector<double> Level::pool_to_vector(godot::PoolRealArray real_data)
{
	std::vector<double> data;
	for (int idx = 0; idx < real_data.size(); ++idx) {
		data.push_back(real_data[idx]);
	}
	return data;
}