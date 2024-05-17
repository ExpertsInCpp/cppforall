#include "CppForAll.hpp"

ClassParser::Error ClassParser::ParseString( const std::wstring &content, Class &output )
{
    return ClassParser::Error::Success;
}

ClassParser::Error ClassParser::ParseFile( const std::wstring &path, Class &output )
{
    std::wstring contents;

    Error error = ReadFile( path, contents );
    if ( error != Error::Success )
        return error;

    error = ParseString( contents, output );
    return error;
}

ClassParser::Error ClassParser::ReadFile( const std::wstring &path, std::wstring &content )
{
    if (! std::filesystem::is_regular_file( path ) )
        return Error::FileNotFound;

    std::wstring npath = std::filesystem::weakly_canonical( path );
    std::wifstream in( npath, std::ios::binary );

    if (! in )
        return Error::FileNotFound;

    in.seekg( 0, std::ios::end );
    content.resize(in.tellg());
    in.seekg( 0, std::ios::beg );
    in.read( content.data(), content.size() );
    in.close();

    return Error::Success;
}

ClassParser::Error ClassParser::GetLastError( int *nLine )
{
    if ( nLine != nullptr )
        *nLine = std::get<1>( m_tLastError );
    return std::get<0>( m_tLastError );
}

std::wstring ClassParser::GetErrorDescription( Error error )
{
    switch ( error )
    {
        case Error::Success:
            return  L"Success";
        case Error::FileNotFound:
            return  L"File not found";
    }

    return  L"Unknown";
}

ClassParser::Error ClassParser::ParseLine( const std::string &line )
{
    return ClassParser::Error::Success;
}
