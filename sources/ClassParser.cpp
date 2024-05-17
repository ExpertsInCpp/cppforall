#include "CppForAll.hpp"

ClassParser::Error ClassParser::ParseString( const std::string &content, Class &output )
{
    return ClassParser::Error::Success;
}

ClassParser::Error ClassParser::ParseFile( const std::wstring &path, Class &output )
{
    return ClassParser::Error::Success;
}

ClassParser::Error ClassParser::GetLastError( int *nLine, int *nColumn )
{
    return ClassParser::Error::Success;
}

ClassParser::Error ClassParser::ParseLine( const std::string &line, Class &output )
{
    return ClassParser::Error::Success;
}
