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
