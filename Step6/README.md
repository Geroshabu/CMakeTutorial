# Step 6: Adding a Custom Command and Generated File

何かの処理をビルドプロセス中に行いたい場合、カスタムコマンドを利用して実現できる。

下記は、ビルドプロセス中に、File.hpp というファイルを生成して、それをビルドに使う例である。

File.hpp をつくるためのコードは、CreateFile.cpp である。
ビルドを始めると、まず CreateFile.cpp がコンパイルされ、できた実行ファイルを用いて、`COMMAND` 行が実行される。

```cmake
add_executable(CreateFile CreateFile.cpp)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/File.hpp
  COMMAND CreateFile ${CMAKE_CURRENT_BINARY_DIR}/File.hpp
  DEPENDS CreateFile
  )
```

生成された File.hpp は、ソースコードにインクルードして使用される。
そのために、File.hpp を `add_library` のリストに追加している。

```cmake
add_library(MyLibrary
            pow.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/File.hpp)
```

