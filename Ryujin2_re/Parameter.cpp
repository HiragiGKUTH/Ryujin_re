#include "Parameter.h"

/*!
@bref パラメータのセット
*/
void Parameter::set(std::string key, int value)
{
	_map[key] = value;
}

/*!
@bref パラメータの取得
*/
int Parameter::get(std::string key) const
{
	auto itr = _map.find(key);
	return _map.end() == itr ? Error : itr->second;
}
