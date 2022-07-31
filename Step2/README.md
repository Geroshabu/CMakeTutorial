# Step2: Adding a Library

下記のような構成になっている。MyLibrary が追加したいライブラリとする。

```
Step2
  + MyLibrary
  |   + MyMethods.hpp
  |   + pow.cpp
  + tutorial.cxx
  + CMakeLists.txt
```

まず、MyLibrary内に、下記のCMakeLists.txtを作成する。

```cmake
add_library(MyLibrary pow.cxx)
```

次に、ルートの方のCMakeLists.txtに下記を追記し、MyLibraryのビルドが走るようにする。

```cmake
add_subdirectory(MyLibrary)
```

ライブラリを、Tutorialの実行ファイルにリンクする。

```cmake
target_link_libraries(Tutorial PUBLIC MyLibrary)
```

ライブラリ内のヘッダファイルを見つけられるように、インクルードディレクトリの追加。

```cmake
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_SOURCE_DIR}/MyLibrary"
                          )
```

## ライブラリを使用するか否かのオプション

次のようにすれば、USE_MYMATH というオプションを作ることができる。

```cmake
option(USE_MYMATH "Use tutorial provided math implementation" ON)
```

USE_MYMATH が ON の場合は、MyLibrary をビルド、リンクするようにする。
`if()`～`endif()`で分岐が作れる。
`list(APPEND AAA BBB)`で、AAAにBBBを追加することができる。

```cmake
if(USE_MYMATH)
  add_subdirectory(MyLibrary)
  list(APPEND EXTRA_LIBS MyLibrary)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MyLibrary")
endif()
```

リストアップしておいた `EXTRA_LIBS` や `EXTRA_INCLUDES` を使って、`add_library` や `target_include_directories` を行う。

```cmake
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
                          ${EXTRA_INCLUDES}
                          )
```

ソースコードへの反映には、Step2 と同様、`configure_file()` で、橋渡し役となるファイルを作って行う。

```cmake
configure_file(TutorialConfig.hpp.in TutorialConfig.hpp)
```

TutorialConfig.hpp.in の中身は下記のようにする。

```cpp
#cmakedefine USE_MYMATH
```

Generate で出力される TutorialConfig.hpp の中身は、USE_MYMATH が ON のときは、

```cpp
#define USE_MYMATH
```

OFF のときは

```cpp
/* #undef USE_MYMATH */
```

のように置き換わっている。

この TutorialConfig.h ファイルも、ビルド時に見つけられるようにするために、`PROJECT_BINARY_DIR` を `target_include_directories` に追加しておく。

```cmake
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
```

最後に、ソースコード中で、USE_MYMATH に応じて呼ばれるライブラリを変更するようにする。

```cpp
#include <TutorialConfig.hpp>

#ifdef USE_MYMATH
#include <MyMethods.hpp>
#endif

...(略)...

#ifdef USE_MYMATH
    cout << pow(2, 10) << endl;
#else
    cout << std::pow(2, 10) << endl;
#endif
```

こんな感じにオプションを用意しておけば、CMake を実行するときに `-D` でオプションの ON/OFF を切り替えられる。

```
cmake ../Step2 -DUSE_MYMATH=OFF
```
