#if defined(_WIN32)
#  if defined(EXPORTING_PRINT)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

namespace mymodule {
    void DECLSPEC print();
}
