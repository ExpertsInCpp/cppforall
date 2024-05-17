#include "CppForAll.hpp"

/*
 * Simple command prompt handling to parse the classes and generate
 * the code for the CPP host and the clients {CPP, JAVA, PYTHON}.
 */
int wmain( int argc, wchar_t *argv[] )
{
    ClassParser parser;
    Class iclass;

    int nLine = 0;

    const std::wstring OutputPath = L"./output";
    std::filesystem::create_directory( OutputPath );

    for ( int i = 1; i < argc; ++i )
    {
        parser.ParseFile( argv[ i ], iclass );
        ClassParser::Error error = parser.GetLastError( &nLine );
        if ( error != ClassParser::Error::Success )
        {
            std::wstring description = ClassParser::GetErrorDescription( error );
            std::wcout << argv[ i ] << L":" << nLine << L":" << description;
            return (int)error;
        }
    }

    return 0;
}
