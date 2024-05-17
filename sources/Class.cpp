#include "CppForAll.hpp"

FuncParam::FuncParam( const std::string &name, ValueType type, StackAccess access )
{
	m_name = name;
	m_type = type;
	m_access = access;
}

ClassFunc::ClassFunc( const std::string &name, Type mtype, ValueType retType )
{
	m_name = name;
	m_type = mtype;
	m_retType = retType;
}

void ClassFunc::SetComment( const std::wstring &comment )
{
	m_comment = comment;
}

void ClassFunc::PushParam( const FuncParam &param )
{
	m_vParams.push_back( param );
}

Class::Class()
{

}

void Class::SetName( const std::string &name )
{
	m_name = name;
}

void Class::SetComment( const std::wstring &comment )
{
	m_comment = comment;
}

void Class::PushFunction( const ClassFunc &function )
{
	m_vFunctions.push_back( function );
}
