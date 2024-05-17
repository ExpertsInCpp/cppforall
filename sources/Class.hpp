#pragma once

/**
 * The vaue types supported by the parser
 */
enum class ValueType
{
	Void,
	WString,
	String,
	Boolean,
	UInteger,
	Integer,
	Float,
	Double,
	ULongLong
};

/**
 * A representation of a class function.
 */
class FuncParam
{

public:

	/**
	 * The accessibility in the stack
	 */
	enum class StackAccess
	{
		In,
		Out,
		InOut
	};
	
	FuncParam( const std::string &name, ValueType type, StackAccess access = StackAccess::Out );

protected:

	StackAccess m_access = StackAccess::Out;
	ValueType m_type = ValueType::Void;
	std::string m_name;

};

/**
 * An representation of a class function
 */
class ClassFunc
{

public:

	/**
	 * The type of function
	 */
	enum class Type
	{
		Construtor,
		Destructor,
		Member
	};

	ClassFunc( const std::string &name, Type type = Type::Member, ValueType retType = ValueType::Void );
	void SetComment( const std::wstring &comment );
	void PushParam( const FuncParam &param );

protected:

	ValueType m_retType = ValueType::Void;
	std::vector<FuncParam> m_vParams;
	Type m_type = Type::Member;
	std::wstring m_comment;
	std::string m_name;

};

/**
 * An intermediate class definition to represent a class universal ABI interface.
 */
class Class
{

public:

	Class();

	void SetName( const std::string &name );
	void SetComment( const std::wstring &comment );
	void PushFunction( const ClassFunc &function );

protected:

	std::vector<ClassFunc> m_vFunctions;
	std::wstring m_comment;
	std::string m_name;

};
