#include "Parameter.h"

/*!
@bref �p�����[�^�̃Z�b�g
*/
void Parameter::set(std::string key, int value)
{
	_map[key] = value;
}

/*!
@bref �p�����[�^�̎擾
*/
int Parameter::get(std::string key) const
{
	auto itr = _map.find(key);
	return _map.end() == itr ? Error : itr->second;
}
