# Step1: A Basic Starting Point

## 基本

動作させるためにC++コンパイラが必要になる。
gccや、Visual StudioでC++コンパイラをインストールしておくこと。

CMakeLists.txt が必要。
ビルドに最低限必要な記述は下記の3行。

```cmake
cmake_minimum_required(VERSION 3.10)
project(Tutorial)
add_executable(Tutorial tutorial.cxx)
```

```
mkdir build
cd build
cmake ../
```

で、コンパイラに合ったビルド設定(.slnやMakefile)を作成し、

```
cmake --build .
```

でビルド。

## バージョン番号の利用

CMakeLists.txt でバージョン番号を定義。

```cmake
project(Tutorial VERSION 1.0)
```

バージョン番号をコード中に橋渡しするためのファイルを作成する。
名前はTutorialConfig.hpp.inとした。

```cpp
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

`@Tutorial_VERSION_MAJOR@` と `@Tutorial_VERSION_MINOR@` のところが、バージョン番号に置き換わったヘッダファイルが出来上がるらしい。

上記のファイルと、置き換え後のヘッダファイル名を、configure_fileで指定する。

```cmake
configure_file(TutorialConfig.hpp.in TutorialConfig.hpp)
```

生成されたヘッダファイルを、ビルド時に見つけられるように、ヘッダファイルを探すパスを指定する。

```cmake
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```

cxx ファイルで、ヘッダファイルをインクルードし、バージョン番号を利用する。

```cpp
#include <TutorialConfig.hpp>

...(略)...

cout << Tutorial_VERSION_MAJOR << "."
     << Tutorial_VERSION_MINOR << endl;
```

## 必要な C++ バージョンの指定

tutorial.cxxで、特定のC++バージョンの機能を使おうとするときは、必要となるC++バージョンを明示的に指定した方がよい。

下記のようにすれば、必要なC++バージョンを指定できる。(この例ではC++11を指定。)
この記述は add_executable よりも前に必要。

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
