#define __STDC_WANT_LIB_EXT1__ 1
#include <cstddef>
#include <iostream>
#include <locale>
#include <string>

using namespace std;
int main()
{
    // {
    //     char *strHello = new char[7];
    //     strcpy_s(strHello, sizeof(char) * 7, "hello!");
    //     std::cout << strHello << std::endl;
    // }

    {
        std::string string;
        std::wstring wstring;

        // unsigned short
        // 데이터 사이즈가 큰 경우에 사용
        // unicode / wide-character
        wchar_t wc;
    }

    const std::wstring texts[] = {
        L"안녕하세요?",
        L"Ñá",
        L"forêt intérêt",
        L"Gesäß",
        L"取消波蘇日奇諾",
        L"日本人のビット",
        L"немного русский",
        L"ένα κομμάτι της ελληνικής",
        L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ",
        L"کمی از ایران ",
        L"కానీ ఈ ఏమి నరకం ఉంది?",
        L"Но какво, по дяволите, е това?"
    };

    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    for (size_t i = 0; i < 12; ++i)
        std::wcout << texts[i] << std::endl;
}